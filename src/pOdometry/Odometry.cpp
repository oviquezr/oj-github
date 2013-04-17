/*****************************************************************/
/*    NAME: Michael Benjamin -- MODIFIED BY: Oscar Viquez        */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: Odometry.cpp                                         */
/*    DATE: June 26th, 2008 -- MODIFIED: February 14th, 2013     */
/*                                                               */
/* This program is free software; you can redistribute it and/or */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation; either version  */
/* 2 of the License, or (at your option) any later version.      */
/*                                                               */
/* This program is distributed in the hope that it will be       */
/* useful, but WITHOUT ANY WARRANTY; without even the implied    */
/* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR       */
/* PURPOSE. See the GNU General Public License for more details. */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with this program; if not, write to the Free    */
/* Software Foundation, Inc., 59 Temple Place - Suite 330,       */
/* Boston, MA 02111-1307, USA.                                   */
/*****************************************************************/

#include <cmath>
#include <iterator>
#include "Odometry.h"
#include "MBUtils.h"

using namespace std;

//---------------------------------------------------------
// Constructor

Odometry::Odometry()
{
  m_tally_recd = 0;
  m_tally_sent = 0;
  m_iterations = 0;

  m_start_time_postings   = 0;
  m_start_time_iterations = 0;

  first_reading  = true;
  current_x      = 0;
  current_y      = 0;
  previous_x     = 0;
  previous_y     = 0;
  total_distance = 0;
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Odometry::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::reverse_iterator p;
  for(p = NewMail.rbegin(); p!=NewMail.rend(); p++) {
    CMOOSMsg &msg = *p;
    string key   = msg.GetKey();
    double val   = msg.GetDouble();
    if(key == "NAV_X") {
      previous_x = current_x;
      current_x = val;
    }
    else if(key == "NAV_Y") {
      previous_y = current_y;
      current_y = val;
    }

  }
  return(true);
}


//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Odometry::OnConnectToServer()
{
  RegisterVariables();  
  return(true);
}


//------------------------------------------------------------
// Procedure: RegisterVariables

void Odometry::RegisterVariables()
{
  AppCastingMOOSApp::RegisterVariables();

  m_Comms.Register("NAV_X", 0);
  m_Comms.Register("NAV_Y", 0);
  
  //  if(m_incoming_var != "")
  //    m_Comms.Register(m_incoming_var, 0);
}


//---------------------------------------------------------
// Procedure: Iterate()

bool Odometry::Iterate()
{

  AppCastingMOOSApp::Iterate();

  //  m_iterations++;

  double delta_x, delta_y, current_dist;
  
  delta_x = current_x - previous_x;
  delta_y = current_y - previous_y;

  current_dist = sqrt( pow(delta_x,2) + pow(delta_y,2));

  total_distance += current_dist;

  m_Comms.Notify("ODOMETRY_DIST",total_distance);



  if(m_start_time_iterations == 0) {
    m_start_time_iterations = MOOSTime();
    m_start_time_postings = MOOSTime();
    first_reading = false;
  }
      

  /*
  unsigned int i, amt = (m_tally_recd - m_tally_sent);
  for(i=0; i<amt; i++) {
    m_tally_sent++;
    m_Comms.Notify(m_outgoing_var, m_tally_sent);
  }
  
  // If this is the first iteration just note the start time, otherwise
  // note the currently calculated frequency and post it to the DB.
  if(m_start_time_iterations == 0)
    m_start_time_iterations = MOOSTime();
  else {
    double delta_time = (MOOSTime() - m_start_time_iterations) + 0.01;
    double frequency  = (double)(m_iterations) / delta_time;
    m_Comms.Notify(m_outgoing_var+"_ITER_HZ", frequency);
  }
    

  // If this is the first time a received msg has been noted, just
  // note the start time, otherwise calculate and post the frequency.
  if(amt > 0) {
    if(m_start_time_postings == 0)
      m_start_time_postings = MOOSTime();
    else {
      double delta_time = (MOOSTime() - m_start_time_postings) + 0.01;
      double frequency = (double)(m_tally_sent) / delta_time;
      m_Comms.Notify(m_outgoing_var+"_POST_HZ", frequency);
    }
  }
  */

  AppCastingMOOSApp::PostReport();

  return(true);
}



//---------------------------------------------------------
// Procedure: OnStartUp()
//      Note: happens before connection is open

bool Odometry::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.GetConfiguration(GetAppName(), sParams);
    
  STRING_LIST::iterator p;
  for(p = sParams.begin();p!=sParams.end();p++) {
    string sLine     = *p;
    string sVarName  = MOOSChomp(sLine, "=");
    sLine = stripBlankEnds(sLine);
    
    /*
    if(MOOSStrCmp(sVarName, "INCOMING_VAR")) {
      if(!strContains(sLine, " "))
	m_incoming_var = stripBlankEnds(sLine);
    }
    
    else if(MOOSStrCmp(sVarName, "OUTGOING_VAR")) {
      if(!strContains(sLine, " "))
	m_outgoing_var = stripBlankEnds(sLine);
    }
    */
  }

  RegisterVariables();
  return(true);
}

bool Odometry::buildReport()
{
  m_msgs << "Total Distance Traveled: " << total_distance << endl;

  return(true);
}
