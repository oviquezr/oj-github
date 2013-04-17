/*****************************************************************/
/*    NAME: Oscar Viquez					 */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: PrimeFactor.cpp                                      */
/*    DATE: Feb 18th, 2013					 */
/*****************************************************************/

#include <cmath>
#include <iterator>
#include "PrimeFactor.h"
#include "MBUtils.h"
#include <cstdlib>

using namespace std;

//---------------------------------------------------------
// Constructor

PrimeFactor::PrimeFactor()
{
  buffer = 10;

  newData = false;

  num_value  = 0;

  cache_primes.clear();
  cache_primes.insert(cache_primes.end(), 2);
  cache_tested_top = 2;

  s_empty.original      = 0;
  s_empty.tested_top    = 0;
  s_empty.rec_index     = 0;
  s_empty.start_time    = MOOSTime();
  s_empty.prime_factors.clear();

  rec_index_top = 0;
  calc_index    = 0;
  calc_time     = 0;

  queue = new num_entry[buffer];

  for (int i = 0; i < buffer; i++) {
    queue[i] = s_empty;
  }

  curr_ind = 0;

  username = "oviquezr";

  prime_result.clear();

  lost = 0;
  //m_Comms.Notify("lost_messages",lost);

}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactor::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::reverse_iterator p;
  for(p = NewMail.rbegin(); p!=NewMail.rend(); p++) {
    CMOOSMsg &msg = *p;
    string key   = msg.GetKey();
    double val   = msg.GetDouble();
    
    if(key == "NUM_VALUE") {
      num_value = uint64_t(val);
      newData = true;

      // locate empty slot in allocated memory -- 
      bool stored = false;
      for (int i = 0; ((i < buffer) && !stored); i++) {
	if (queue[i].original == s_empty.original) {
	  queue[i].original = num_value;
	  queue[i].rec_index = rec_index_top;
	  rec_index_top++;
	  queue[i].start_time = MOOSTime();

	  selectNext();

	  stored = true;
	}
      }
      
      if (!stored) {
	// if there are no empty slots in the buffer, the incoming message will be ignored.
	lost++;
	m_Comms.Notify("lost_messages",lost);

      }
    }


  }
  return(true);
}


//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PrimeFactor::OnConnectToServer()
{
  RegisterVariables();  
  return(true);
}


//------------------------------------------------------------
// Procedure: RegisterVariables

void PrimeFactor::RegisterVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  m_Comms.Register("NUM_VALUE", 0);
}


//---------------------------------------------------------
// Procedure: Iterate()

bool PrimeFactor::Iterate()
{

  AppCastingMOOSApp::Iterate();

  iter_start_time = MOOSTime();

  //selectNext();

  // send state messages for debugging and optimization
  //  m_Comms.Notify("num_value_local",queue[curr_ind].original);
  //  m_Comms.Notify("baseline",queue[curr_ind].tested_top);
  //  m_Comms.Notify("lost_messages",lost);

  //cout << newData;

  if (newData) {
    
    int baseline = queue[curr_ind].tested_top;
    if (baseline == 0) {
      queue[curr_ind].start_time = MOOSTime();
    }
    
    
    if (baseline < cache_tested_top){
      // first test all known primes
      //cout << "testing known primes" << endl;

      int it_val = 0;
      int remainder = 0;

      for (it = cache_primes.begin();
	   (it != cache_primes.end()) && (it_val < queue[curr_ind].original);
	   it++){
	it_val = *it;
	remainder = queue[curr_ind].original % *it;

	//cout << queue[curr_ind].original << " % " << *it << " = " << remainder << endl;

	if((queue[curr_ind].original % *it) == 0){
	  queue[curr_ind].prime_factors.insert(queue[curr_ind].prime_factors.end(), *it);
	}
	
	queue[curr_ind].tested_top = *it;

      }

      queue[curr_ind].tested_top = cache_tested_top;

      //cout << "leaving cached primes list for: loop" << endl;
    }
    
    else {
      // perform incremental tests to expand cache_primes
      //cout << "expanding cache" << endl;
      
      for ( int i = baseline; (i < baseline + 10000) && (i <= queue[curr_ind].original); i++){
	
	// first test to see if new number is valid prime
	bool is_prime = true;
	
	for (it = cache_primes.begin();
	     (it != cache_primes.end()) && (*it <= queue[curr_ind].original);
	     it++){
	  
	  if ((i % *it) == 0){
	    is_prime = false;
	  }
	}
	
	if(is_prime){
	  cache_primes.insert(cache_primes.end(), i);
	  
	  if ((queue[curr_ind].original % i) == 0){
	    queue[curr_ind].prime_factors.insert(queue[curr_ind].prime_factors.end(), i);
	  }
	}
	
	cache_tested_top = i;
	queue[curr_ind].tested_top = i;
      } 
    }
    
    if (queue[curr_ind].tested_top >= queue[curr_ind].original){
      formatResult();
      m_Comms.Notify("PRIME_RESULT",prime_result);
      
      //cout << "sending results" << endl;
      
      queue[curr_ind] = s_empty;

      queue[curr_ind].original      = s_empty.original;
      queue[curr_ind].tested_top    = s_empty.tested_top;
      queue[curr_ind].rec_index     = s_empty.rec_index;
      queue[curr_ind].start_time    = s_empty.start_time;
      queue[curr_ind].prime_factors.clear();

      selectNext();
    }
  }
  
  AppCastingMOOSApp::PostReport();
  
  return(true);
}



//---------------------------------------------------------
// Procedure: OnStartUp()
//      Note: happens before connection is open

bool PrimeFactor::OnStartUp()
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


bool PrimeFactor::buildReport()
{
  //m_msgs << "Total Distance Traveled: " << total_distance << endl;

  return(true);
}



void PrimeFactor::formatResult()   // generate string according to formatting convention
{
  std::ostringstream strs;
  std::string strs_rm;

  s_result = queue[curr_ind];

  calc_time = MOOSTime() - s_result.start_time;

  strs << "orig=" << s_result.original << ",received=" << s_result.rec_index << ",calculated=" << calc_index << ",solve_time=" << calc_time << ",primes=";

  //prime_result += ",primes=" + prime_factors;  // must break down list<>
  for(it=s_result.prime_factors.begin();
      it!=s_result.prime_factors.end();
      it++)
    {
      strs << *it << ":";
    }
  
  strs_rm = strs.str();
  strs_rm = strs_rm.substr(0,strs_rm.length()-1);
  strs_rm += ",username=" + username;

  prime_result = strs_rm;
  
  calc_index++;
}



void PrimeFactor::selectNext()   // selects entry from memory to be processed next
{
  curr_ind = 0;
  
  for (int i = 0; i < buffer; i++){
    if(queue[curr_ind].original == 0){ // if zero, move along memory
      curr_ind = i;
    }
    // if smaller, nonzero is available, select the smaller value
    else if((queue[i].original < queue[curr_ind].original) && (queue[i].original > 0)){
      curr_ind = i;
    }
    // if equal, prioritize by order received
    else if ((queue[i].original == queue[curr_ind].original) && (queue[i].original > 0)){
      if (queue[i].rec_index < queue[curr_ind].rec_index){
	curr_ind = i;
      }
    }
  }

  if (queue[curr_ind].original == s_empty.original){
    newData = false;
  }
}
