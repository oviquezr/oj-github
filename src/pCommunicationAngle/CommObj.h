/****************************************************************/
/*    NAME: Michael Benjamin -- MODIFIED BY: Oscar Viquez       */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA    */
/*    FILE: CommObj.h                                          */
/*    DATE: Feb 18th, 2013                                      */
/****************************************************************/

//#include "MOOS/libMOOS/MOOSLib.h"
//#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

//#define PI 3.14159265

class CommObj
{
 protected:
  double dx;
  double dy;
  double dDepth;

  double dist;
  double h;
  double R;
  
  double theta1;    // angle between horizontal and straight line between vehicles
  double theta0;    // elev_angle
  double theta_rec; // rec_angle
  
  double c_z(double zin){return(c0 + g*zin);}  //{c_z = c0 + g*zin; return c_z;}
  //  double z_max(){return (c_z(self_depth)/(g*cos(theta0)) - c0/g);}

  //  double J(double s){return }
  //  double ps(double s){return (1/(4*PI)*sqrt(abs((c_z(z(s))*cos(theta0)/(c_z(self_depth)*J(s))))));}
  //double z_max;


  void find_path();
  double find_TL();     // TL: transmission loss


 public:
  CommObj();
  virtual ~CommObj() {};

  double c0; //surface_sound_speed;
  double g;  //sound_speed_gradient;
  double water_depth;

  double self_x;
  double self_y;
  double self_depth;
  //  double self_heading;
  //  double self_speed;

  double collab_x;
  double collab_y;
  double collab_depth;
  //  double collab_heading;
  //  double collab_speed;

  bool direct_line;
  //double elev_angle;
  double transmission_loss;

  double connect_x;
  double connect_y;
  double connect_depth;

  std::string get_path_str();
  std::string get_location_str();
  
};

