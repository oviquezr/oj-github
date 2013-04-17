/****************************************************************/
/*    NAME: Michael Benjamin -- MODIFIED BY: Oscar Viquez       */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA    */
/*    FILE: Relayer.h                                           */
/*    DATE: Jun 26th 2008 -- MODIFIED: February 14th, 2013      */
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
/****************************************************************/

#ifndef P_ODOMETRY_VAR_HEADER
#define P_ODOMETRY_VAR_HEADER

//#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

//class Odometry : public CMOOSApp
class Odometry : public AppCastingMOOSApp
{
 public:
  Odometry();
  virtual ~Odometry() {};

  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();
  void RegisterVariables();

  void setIncomingVar(std::string s) {m_incoming_var=s;};
  void setOutgoingVar(std::string s) {m_outgoing_var=s;};

 protected:
  unsigned long int m_tally_recd;
  unsigned long int m_tally_sent;
  unsigned long int m_iterations;

  std::string       m_incoming_var;
  std::string       m_outgoing_var;

  double            m_start_time_postings;
  double            m_start_time_iterations;

  bool              first_reading;
  double            current_x;
  double            current_y;
  double            previous_x;
  double            previous_y;
  double            total_distance;

  bool buildReport();
};

#endif 
