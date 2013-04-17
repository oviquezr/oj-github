/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: GenPath.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef GenPath_HEADER
#define GenPath_HEADER

//#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class GenPath : public AppCastingMOOSApp
{
 public:
   GenPath();
   ~GenPath();

 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();
   bool buildReport();

   bool m_recd_last;
   bool m_path_ready;
   std::vector<double> m_allX;
   std::vector<double> m_allY;
   std::vector<double> m_pathX;
   std::vector<double> m_pathY;
   double m_nav_x;
   double m_nav_y;
   int m_input_size;
   int m_total_visited;
   int m_total_unvisited;
   std::string m_vessel_name;

 private: // Configuration variables

   // private: // State variables
   //   unsigned int m_iterations;
   double       m_timewarp;
};

#endif 
