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
  m_cache_primes.clear();
  m_cache_primes.push_back(2);
  m_cache_test_top = 2;
  
  m_queue.clear();

  m_rec_index  = 0;
  m_calc_index = 0;

  m_username = "oviquezr";

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
      m_new_entry.set_entry(uint64_t(val),m_rec_index);
      m_new_entry.set_user(m_username);
      m_queue.insert(m_queue.end(),m_new_entry);
      m_rec_index++;
      selectNext();

      //cout << "Created new entry" << endl;
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

  uint64_t curr_num = m_curr_entry.get_num();
  int curr_top = m_cache_test_top;
  int this_prime = 0;

  //-----------------------------------
  // Initiate entry: add start time
  //-----------------------------------
  if (!m_curr_entry.started()){
    m_curr_entry.set_start(MOOSTime());
    //cout << "Started entry" << endl;
  }

  //-----------------------------------
  // Test new numbers: expand cache
  //-----------------------------------
  if (m_cache_test_top <= curr_num){
    //cout << "Expanding cache -- curr_num: " << curr_num << endl;
    for (int i = curr_top; i <= curr_top+10000;i++){
        bool is_prime = true;
	for (std::vector<int>::iterator it=m_cache_primes.begin(); it!=m_cache_primes.end(); it++){
	  if ((i % *it) == 0){
	    is_prime = false;
	  }
	}
	if(is_prime){
	  m_cache_primes.push_back(i);
	  //cout << i << " is a prime. The size of m_cache_primes is now " << m_cache_primes.size() << endl;
	}
	m_cache_test_top = i;
    }
  }

  //-----------------------------------
  // Identify prime factors for num_val
  //-----------------------------------
  else {
    /*
    cout << "Looking for primes." << endl;
    cout << "Current entry: " << curr_num << endl;
    cout << "Current test top: " << curr_top << endl;
    cout << "Size of cache: " << m_cache_primes.size() << endl;
    cout << "Highest prime: " << m_cache_primes.at(m_cache_primes.size()-1) << endl;
    */

    m_curr_entry.find_primes(m_cache_primes);
    string result = m_curr_entry.get_string(MOOSTime(), m_calc_index);
    m_curr_entry.set_done();

    m_calc_index++;
    m_Comms.Notify("PRIME_RESULT",result);
    selectNext();
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

  RegisterVariables();
  return(true);
}


//---------------------------------------------------------
// Procedure: buildReport()

bool PrimeFactor::buildReport()
{
  //m_msgs << "Total Distance Traveled: " << total_distance << endl;
  return(true);
}


//---------------------------------------------------------
// Procedure: selectNext()
//      Note: selects entry from memory to be processed next

void PrimeFactor::selectNext()
{
  if (m_curr_entry.is_done()){
    m_curr_entry = *m_queue.begin();
    m_queue.erase(m_queue.begin());
  }
  for (std::list<PrimeObj>::iterator it=m_queue.begin(); it!=m_queue.end();it++){
    PrimeObj temp = *it;
    if (temp.get_num() < m_curr_entry.get_num()){
      m_queue.insert(m_queue.end(),m_curr_entry);
      m_curr_entry = *it;
      it = m_queue.erase(it);
    }
  }
}
