/*****************************************************************/
/*    NAME: Oscar Viquez					 */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: CommunicationAngle.cpp                                      */
/*    DATE: Feb 18th, 2013					 */
/*****************************************************************/

#include <cmath>
#include <iterator>
#include "CommunicationAngle.h"
#include "MBUtils.h"
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//---------------------------------------------------------
// Constructor

CommunicationAngle::CommunicationAngle()
{
  collabNameKnown = false;
  last_run = MOOSTime();
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool CommunicationAngle::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::reverse_iterator p;
  for(p = NewMail.rbegin(); p!=NewMail.rend(); p++) {
    CMOOSMsg &msg = *p;
    string key   = msg.GetKey();
    string valstr = msg.GetString();
    double valnum   = msg.GetDouble();
    
    // Set name elements
    if(key == "VEHICLE_NAME") {
      self_name = valstr;
    }
    else if(key == "COLLABORATOR_NAME") {
      collab_name = valstr;
      collabNameKnown = true;
      RegisterVariables();
    }

    // Set self-positioning elements
    else if(key == "NAV_X") {
      s.self_x = valnum;
    }
    else if(key == "NAV_Y") {
      s.self_y = valnum;
    }
    else if(key == "NAV_DEPTH") {
      s.self_depth = valnum;
    }
    /*
    else if(key == "NAV_HEADING") {
      self_heading = valnum;
    }
    else if(key == "NAV_SPEED") {
      self_speed = valnum;
    }
    */

    // Set collaborator's positioning elements
    else if(key == (collab_name+"_NAV_X")) {
      s.collab_x = valnum;
    }
    else if(key == (collab_name+"_NAV_Y")) {
      s.collab_y = valnum;
    }
    else if(key == (collab_name+"_NAV_DEPTH")) {
      s.collab_depth = valnum;
    }
    /*
    else if(key == (collab_name+"_NAV_HEADING")) {
      collab_heading = valnum;
    }
    else if(key == (collab_name+"_NAV_SPEED")) {
      collab_speed = valnum;
    }
    */
  }
  return(true);
}


//---------------------------------------------------------
// Procedure: OnConnectToServer

bool CommunicationAngle::OnConnectToServer()
{
  RegisterVariables();  
  return(true);
}


//------------------------------------------------------------
// Procedure: RegisterVariables

void CommunicationAngle::RegisterVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  m_Comms.Register("VEHICLE_NAME", 0);
  m_Comms.Register("COLLABORATOR_NAME", 0);

  m_Comms.Register("NAV_X", 0);
  m_Comms.Register("NAV_Y", 0);
  m_Comms.Register("NAV_DEPTH", 0);
  m_Comms.Register("NAV_HEADING", 0);
  m_Comms.Register("NAV_SPEED", 0);

  if (collabNameKnown) { 
    m_Comms.Register((collab_name+"_NAV_X"), 0);
    m_Comms.Register((collab_name+"_NAV_Y"), 0);
    m_Comms.Register((collab_name+"_NAV_DEPTH"), 0);
    m_Comms.Register((collab_name+"_NAV_HEADING"), 0);
    m_Comms.Register((collab_name+"_NAV_SPEED"), 0);
  }
}


//---------------------------------------------------------
// Procedure: Iterate()

bool CommunicationAngle::Iterate()
{
  AppCastingMOOSApp::Iterate();
  
  path_str     = s.get_path_str();
  location_str = s.get_location_str();
  
  if((MOOSTime()-last_run)>time_interval) {
    m_Comms.Notify("ACOUSTIC_PATH",path_str);
    m_Comms.Notify("CONNECTIVITY_LOCATION",location_str);
    last_run = MOOSTime();
  }
  
  AppCastingMOOSApp::PostReport();
  
  return(true);
}



//---------------------------------------------------------
// Procedure: OnStartUp()
//      Note: happens before connection is open

bool CommunicationAngle::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.GetConfiguration(GetAppName(), sParams);
    
  STRING_LIST::iterator p;
  for(p = sParams.begin();p!=sParams.end();p++) {
    string sLine     = *p;
    string sVarName  = MOOSChomp(sLine, "=");
    sLine = stripBlankEnds(sLine);

    if(MOOSStrCmp(sVarName, "surface_sound_speed")) {
      if(!strContains(sLine, " "))
	s.c0 = double(atof(stripBlankEnds(sLine).c_str()));
    }
    
    else if(MOOSStrCmp(sVarName, "sound_speed_gradient")) {
      if(!strContains(sLine, " "))
        s.g = double(atof(stripBlankEnds(sLine).c_str()));
    }

    else if(MOOSStrCmp(sVarName, "water_depth")) {
      if(!strContains(sLine, " "))
        s.water_depth = double(atof(stripBlankEnds(sLine).c_str()));
    }

    else if(MOOSStrCmp(sVarName, "time_interval")) {
      if(!strContains(sLine, " "))
        time_interval = double(atof(stripBlankEnds(sLine).c_str()));
    }

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


bool CommunicationAngle::buildReport()
{
  //m_msgs << "Total Distance Traveled: " << total_distance << endl;

  return(true);
}

