/*****************************************************************/
/*    NAME: Oscar Viquez					 */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: PrimeFactorTest.cpp                                      */
/*    DATE: Feb 18th, 2013					 */
/*****************************************************************/

#include <cmath>
#include <iterator>
#include "PrimeFactorTest.h"
#include "MBUtils.h"
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//---------------------------------------------------------
// Constructor

PrimeFactorTest::PrimeFactorTest()
{
  prime_result.clear();

  original  = 0;
  prime_factors.clear();

  newData = false;
  valid = true;
  
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactorTest::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::reverse_iterator p;
  for(p = NewMail.rbegin(); p!=NewMail.rend(); p++) {
    CMOOSMsg &msg = *p;
    string key   = msg.GetKey();
    string val   = msg.GetString();
    
    if(key == "PRIME_RESULT") {
      prime_result = val;

      newData = true;
    }
  }
  return(true);
}


//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PrimeFactorTest::OnConnectToServer()
{
  RegisterVariables();  
  return(true);
}


//------------------------------------------------------------
// Procedure: RegisterVariables

void PrimeFactorTest::RegisterVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  m_Comms.Register("PRIME_RESULT", 0);
}


//---------------------------------------------------------
// Procedure: Iterate()

bool PrimeFactorTest::Iterate()
{

  AppCastingMOOSApp::Iterate();
  
  if(newData) {
    
    string strs = prime_result;
    
    for(int i=0; i<5; i++) {                     //p = sParams.begin();p!=sParams.end();p++) {
      string sParam   = MOOSChomp(strs, ",");
      
      string sVarName = MOOSChomp(sParam, "=");
      sParam = stripBlankEnds(sParam);
      
      if (sVarName == "orig"){
	original = atoi(sParam.c_str());
	
	cout << "Original number: " << original << endl;
      }
      else if (sVarName == "primes"){

	bool done = false;
	int found = sParam.find(":");

	while (!done){
	  string newPrime = MOOSChomp(sParam,":");
	  sParam = stripBlankEnds(sParam);
	  
	  prime_factors.insert(prime_factors.end(),atoi(newPrime.c_str()));

	  cout << "Added: " << atoi(newPrime.c_str()) << endl;

	  found = sParam.find(":");
	  if (found == std::string::npos){
	    done = true;
	  }
	}
	prime_factors.insert(prime_factors.end(),atoi(sParam.c_str()));
	
	cout << "Added: " << atoi(sParam.c_str()) << endl;
      }
      
    }
    
    
    
    
    
    
    // first test all known primes
    cout << "testing known primes" << endl;
    
    // simplify bool task:
    int it_val = 0;
    int remainder = 0;
    
    valid = true;
    
    for (it = prime_factors.begin();
	 (it != prime_factors.end()) && (it_val < original);
	 it++){
      it_val = *it;
      remainder = original % *it;
      
      cout << original << " % " << *it << " = " << remainder << endl;
      
      if((original % *it) != 0){
	valid = false;
      }
    }
    
    
    cout << "leaving cached primes list loop" << endl;
    
    //m_Comms.Notify("PRIME_RESULT_VALID_DEBUGGING",prime_result);

    if(valid){
      prime_result += ",valid=true"; 
    }
    else {
      prime_result += ",valid=false";
    }
    
    m_Comms.Notify("PRIME_RESULT_VALID",prime_result);
    
    prime_result.clear();
    prime_factors.clear();

    newData = false;
  }

  AppCastingMOOSApp::PostReport();
  
  return(true);
}



//---------------------------------------------------------
// Procedure: OnStartUp()
//      Note: happens before connection is open

bool PrimeFactorTest::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.GetConfiguration(GetAppName(), sParams);
    
  STRING_LIST::iterator p;
  for(p = sParams.begin();p!=sParams.end();p++) {
    string sLine     = *p;
    string sVarName  = MOOSChomp(sLine, "=");
    sLine = stripBlankEnds(sLine);

  }

  RegisterVariables();
  return(true);
}


bool PrimeFactorTest::buildReport()
{
  //m_msgs << "Total Distance Traveled: " << total_distance << endl;

  return(true);
}

