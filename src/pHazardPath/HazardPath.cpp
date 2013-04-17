/************************************************************/
/*    NAME:                                                 */
/*    ORGN: MIT                                             */
/*    FILE: HazardPath.cpp                                  */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "HazardPath.h"

using namespace std;

//---------------------------------------------------------
// Constructor

HazardPath::HazardPath()
{
  m_iterations = 0;
  m_timewarp   = 1;

  update_path.clear();
  update_path = "-200,-130:-90,-420:-57,-402:-170,-120:-129,-104:-22,-388:20,-370:-84,-85:-42,-69:59,-354:100,-339:-2,-53:39,-34:140,-322:175,-311:80,-23:121,-7:216,-290:256,-275:167,3:203,14:296,-260:330,-244:244,6";

  vertices_known = false;
}

//---------------------------------------------------------
// Destructor

HazardPath::~HazardPath()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool HazardPath::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key   = msg.GetKey();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool HazardPath::OnConnectToServer()
{
  // register for variables here
  // possibly look at the mission file?
  // m_MissionReader.GetConfigurationParam("Name", <string>);
  // m_Comms.Register("VARNAME", 0);
  
  RegisterVariables();
  return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool HazardPath::Iterate()
{
  AppCastingMOOSApp::Iterate();

  m_iterations++;

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool HazardPath::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.GetConfiguration(GetAppName(), sParams);

  //  m_MissionReader.EnableVerbatimQuoting(false);

  STRING_LIST::iterator p;

  for(p=sParams.begin(); p!=sParams.end(); p++) {
    string sLine = *p;
    string sVarName = stripBlankEnds(biteString(sLine, '='));
    sLine = stripBlankEnds(sLine);
    
    if(sVarName == "swath_width") {
      swath_width = atoi(sLine.c_str());//handled
    }
    else if(sVarName == "vertices") {
      //      cout << "Read vertices in Config" << endl;
      vertices = sLine;
      vertices_known = true;
      //      cout << "Begin read_vertices()" << endl;
      read_vertices(vertices);
      //      cout << "Begin generate_path()" << endl;
      generate_path();
    }
  }
  
  
  //m_timewarp = GetMOOSTimeWarp();
  
  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void HazardPath::RegisterVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  // m_Comms.Register("FOOBAR", 0);
}

//---------------------------------------------------------
// Procedure: buildReport

bool HazardPath::buildReport()
{
  m_msgs << "pHazardPath is present \n \n";
  m_msgs << "Current Path: \n \n";
  m_msgs << update_path;
  return(true);
}

//---------------------------------------------------------
// Procedure: read_vertices

void HazardPath::read_vertices(std::string str)
{
  //  cout << "Reading vertices!!" << endl;
  xpoints.clear();
  ypoints.clear();

  //  cout << "Parsing from Config" << endl;
  std::vector<std::string> input = parseString(str,':');
  //  cout << "Parsed from Config" << endl;
  std::vector<std::string> point;
  std::string x;
  std::string y;

  //  cout << "Begin parsing pairs" << endl;
  //cout << "XY pair: ";
  //cout << input[0] << endl;

  for (int i=0; i<input.size(); i++){
    // for each XY pair:
    std::string inputstr = input[i];
    //    cout << "XY pair: " << inputstr << endl;
    point = parseString(inputstr,','); // contains [x=#] [y=#]
    //cout << "XY pair separated" << endl;

    for (int i2=0; i2<point.size(); i2++){
      std::string sval  = point[i2];
      std::string param = biteString(sval,'=');
      param = stripBlankEnds(param);
      
      if(param=="x"){
	//	cout << "New X value: " << sval << endl;
	xpoints.push_back(atof(sval.c_str()));
	//	cout << "xpoints[" << i << "] = " << xpoints[i] << endl;
      }
      else if(param=="y"){
	//	cout << "New Y value: " << sval << endl;
	ypoints.push_back(atof(sval.c_str()));
	//	cout << "ypoints[" << i << "] = " << ypoints[i] << endl;
      }
    } 
  }
}

//---------------------------------------------------------
// Procedure: generate_path

void HazardPath::generate_path()
{
  // where the next element will go
  int ind = 1;
  int step = swath_width;
  
  cout << "Begin at: " << ind << endl;
  
  std::vector<double> xpointslast;
  std::vector<double> ypointslast;
  
  xpointslast.push_back(xpoints[2]);
  xpointslast.push_back(xpoints[3]);
  ypointslast.push_back(ypoints[2]);
  ypointslast.push_back(ypoints[3]);
  
  xpoints.erase(xpoints.end()-1);
  xpoints.erase(xpoints.end()-1);
  ypoints.erase(ypoints.end()-1);
  ypoints.erase(ypoints.end()-1);
  
  /*
  cout << "xpoints[" << ind << "] = " << xpoints[ind] << endl;
  cout << "ypoints[" << ind << "] = " << ypoints[ind] << endl;
  cout << "swath_width = " << swath_width << endl;
  cout << "xpointslast[last] = " << xpointslast[xpointslast.size()-1] << endl;
  */

  bool add_four_pts = false;
  
  //  cout << "Projection: " << xpoints[ind]+swath_width << endl;
  //  cout << "End: " << xpointslast[xpointslast.size()-1] << endl;

  add_four_pts = xpoints[ind]+swath_width < xpoints[xpointslast.size()];
  
  //  cout << "Left IF statement, result: " << add_four_pts << endl;
  
  for(int i=0; add_four_pts; i++){
    
    //    cout << "Begin for-loop" << endl;
    //    cout << ind << endl;
    
    ind++;
    
    //    cout << "Before 1st insert" << endl;
    //    cout << ind << endl;
    
    xpoints.push_back(xpoints[ind-1]+step);
    //    cout << "Before 2nd insert" << endl;
    ypoints.push_back(ypoints[1]);
    
    //    cout << "after 1st point" << endl;
    //    cout << ind << endl;
    
    ind++;
    
    //    cout << "xpoints.size() = " << xpoints.size() << endl;
    //    cout << "Before 3rd insert" << endl; 
    xpoints.push_back(xpoints[ind-1]);
    //    cout << "Before 4th insert" << endl;
    ypoints.push_back(ypoints[0]);
    
    //    cout << "after 2nd point" << endl;
    //    cout << ind << endl;
    
    ind++;
    xpoints.push_back(xpoints[ind-1]+step);
    ypoints.push_back(ypoints[0]);
    
    //    cout << "after 3rd point" << endl;
    //    cout << ind << endl;
    
    ind++;
    xpoints.push_back(xpoints[ind-1]);
    ypoints.push_back(ypoints[1]);
    //    cout << "before add_four_points" << endl;    
    //    cout << ind << endl;
    
    add_four_pts = xpoints[ind]+swath_width < xpointslast[xpointslast.size()-1];
    //    cout << xpoints[ind]+swath_width << " < " <<  xpointslast[xpointslast.size()-1] << " : " << add_four_pts << endl;
    //    cout << add_four_pts << endl;
  }
  
  //  cout << "after FOR loop" << endl;
  
  if ((xpoints[ind]+step)<xpoints[xpoints.size()-1]){
    // add one last leg north-ward
    ind++;
    xpoints.push_back(xpoints[ind-1]+step);
    ypoints.push_back(ypoints[1]);
    
    ind++;
    xpoints.push_back(xpoints[ind-1]);
    ypoints.push_back(ypoints[0]);
    
    // invert travel direction for final leg
    ind++;
    xpoints.push_back(xpointslast[1]);
    xpoints.push_back(xpointslast[0]);
    ypoints.push_back(ypointslast[1]);
    ypoints.push_back(ypointslast[0]);
  }
  
  else{
    // insert final leg
    ind++;
    xpoints.push_back(xpointslast[0]);
    xpoints.push_back(xpointslast[1]);
    ypoints.push_back(ypointslast[0]);
    ypoints.push_back(ypointslast[1]);
  }
  
  std::ostringstream sstr;
  
  sstr << "points=";
  
  for(int i=0; i<xpoints.size(); i++){
    sstr << xpoints[i] << "," << ypoints[i] << ":";
  }
  
  update_path = sstr.str();
  update_path = update_path.substr(0,update_path.length()-1);
  
  m_Comms.Notify("UPDATE_PATH",update_path);
}
