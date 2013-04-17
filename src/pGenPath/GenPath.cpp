/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: GenPath.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "GenPath.h"
#include <cmath>

using namespace std;

//---------------------------------------------------------
// Constructor

GenPath::GenPath()
{
  m_vessel_name="unknown";
  m_recd_last = false;
  m_path_ready = true;
  m_input_size=0;
  m_total_visited = 0;
  m_total_unvisited = 0;
  m_allX.clear();
  m_allY.clear();
  m_timewarp   = 1;
}

//---------------------------------------------------------
// Destructor

GenPath::~GenPath()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool GenPath::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    
    string key   = msg.GetKey();
    string sval  = msg.GetString(); 
    double dval  = msg.GetDouble(); 
    
    if((key=="NAV_X")){
      m_nav_x = dval;
    }
    else if((key=="NAV_Y")){
      m_nav_y = dval;
    }
    else if((key=="HOLD")){
      m_total_visited   = 0;
      m_total_unvisited = m_pathX.size();;
    }
    else if((key=="WPT_HIT")&&(m_path_ready)&&(m_total_unvisited>0)){
      m_total_visited++;
      m_total_unvisited--;
      std::ostringstream path_status;
      path_status << "total_visited=" << m_total_visited;
      path_status << ", total_unvisited=" << m_total_unvisited;
      path_status << ", vname=" << m_vessel_name;
      m_Comms.Notify("PATH_STATUS", path_status.str());
    }
    else if((key=="VISIT_POINT")){ //&&(id_counter<=100)
      
      if(sval=="last"){
	m_recd_last = true;
      }
      else{
	std::vector<std::string> visit_point;
	visit_point = parseString(sval, ',');
	
	for(int i=0; i<visit_point.size(); i++){
	  string str = visit_point[i];
	  string param = biteString(str,'=');
	  
	  if(param=="x"){
	    m_allX.push_back(atoi(str.c_str()));
	  }
	  else if(param=="y"){
	    m_allY.push_back(atoi(str.c_str()));
	  }
	}
	m_input_size++;
      }
    }
  }
  
  return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool GenPath::OnConnectToServer()
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

bool GenPath::Iterate()
{
  AppCastingMOOSApp::Iterate();

  //m_iterations++;

  if (m_recd_last){
    // sort points (generate path)
    std::vector<double> remainX = m_allX;
    std::vector<double> remainY = m_allY;
    double thisX = m_nav_x;
    double thisY = m_nav_y;
    
    double dist, dist2;
    int ix;
    
    for(int i1=0; i1<m_input_size; i1++){
      // start with distance to first point in remain* vectors
      dist = sqrt(pow(thisX-remainX[0],2)+pow(thisY-remainY[0],2));
      ix = 0;

      for(int i2=0; i2<remainX.size(); i2++){
	// find closest element to active point
	dist2 = sqrt(pow(thisX-remainX[i2],2)+pow(thisY-remainY[i2],2));
	if(dist2<dist){
	  // set distance to smallest
	  dist = dist2;
	  ix = i2;
	}
      }
      // add closest element to path
      m_pathX.push_back(remainX[ix]);
      m_pathY.push_back(remainY[ix]);

      // set active point to closest element for next iteration
      thisX = remainX[ix];
      thisY = remainY[ix];

      // remove new active point from remain* vectors
      remainX.erase(remainX.begin()+ix);
      remainY.erase(remainY.begin()+ix);
    }
    
    std::ostringstream path_str;
    path_str << "points=";
    for(int i=0; i<m_pathX.size(); i++){
      path_str << m_pathX[i] << "," << m_pathY[i] << ":";
    }
    std::string update_str = path_str.str();
    update_str = update_str.substr(0,update_str.length()-1);
    m_Comms.Notify("UPDATES_VAR",update_str);
    
    m_recd_last = false;

    m_total_unvisited = m_pathX.size();
    m_path_ready = true;
  }

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool GenPath::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  // m_host_community set in superclass OnStartUp()
  m_vessel_name = m_host_community;

  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      if(param == "FOO") {
        //handled
      }
      else if(param == "BAR") {
        //handled
      }
    }
  }
  
  m_timewarp = GetMOOSTimeWarp();

  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void GenPath::RegisterVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  m_Comms.Register("VISIT_POINT", 0);
  m_Comms.Register("NAV_X", 0);
  m_Comms.Register("NAV_Y", 0);
  m_Comms.Register("WPT_HIT", 0);
  m_Comms.Register("HOLD", 0);
  // m_Comms.Register("FOOBAR", 0);
}

bool GenPath::buildReport()
{
  /*
  m_msgs << "Total Message Report: \n";
  m_msgs << "# of good messages: " << m_good_message_count << endl;
  m_msgs << "# of bad messages: " << m_bad_message_count << endl;
  */

  return(true);
}
