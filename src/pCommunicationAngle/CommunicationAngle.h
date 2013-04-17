/****************************************************************/
/*    NAME: Michael Benjamin -- MODIFIED BY: Oscar Viquez       */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA    */
/*    FILE: CommunicationAngle.h                                       */
/*    DATE: Feb 18th, 2013                                      */
/****************************************************************/

#ifndef P_COMMUNICATIONANGLE_VAR_HEADER
#define P_COMMUNICATIONANGLE_VAR_HEADER

//#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <list>
#include "CommObj.h"

//class CommunicationAngle : public CMOOSApp
class CommunicationAngle : public AppCastingMOOSApp
{
 public:
  CommunicationAngle();
  virtual ~CommunicationAngle() {};

  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();
  void RegisterVariables();

  void setCollaborator(std::string s) {collab_name=s;};

 protected:
  
  CommObj s;

  //  double surface_sound_speed;
  //  double sound_speed_gradient;
  //  double water_depth;
  double time_interval;
  double last_run;

  std::string self_name;
  std::string collab_name;
  bool collabNameKnown;

  /*
  double self_x;
  double self_y;
  double self_depth;
  double self_heading;
  double self_speed;

  double collab_x;
  double collab_y;
  double collab_depth;
  double collab_heading;
  double collab_speed;
  */
 
  std::string path_str;
  std::string location_str;

  bool buildReport();
};

#endif 
