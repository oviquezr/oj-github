/************************************************************/
/*    NAME:                                                 */
/*    ORGN: MIT                                             */
/*    FILE: HazardPath.h                                    */
/*    DATE:                                                 */
/************************************************************/

#ifndef HazardPath_HEADER
#define HazardPath_HEADER

//#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class HazardPath : public AppCastingMOOSApp
{
 public:
   HazardPath();
   ~HazardPath();

 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();
   bool buildReport();
   void read_vertices(std::string str);
   void generate_path();

   double swath_width;
   std::vector<double> xpoints;
   std::vector<double> ypoints;
   std::string vertices;
   std::string update_path;
   bool vertices_known;

 private: // Configuration variables

 private: // State variables
   unsigned int m_iterations;
   double       m_timewarp;
};

#endif 
