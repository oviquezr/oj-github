/*****************************************************************/
/*    NAME: Oscar Viquez					 */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: PrimeFactor.cpp                                      */
/*    DATE: Feb 18th, 2013					 */
/*****************************************************************/

/*
#include <cmath>
#include <iterator>
#include "PrimeFactor.h"
#include "MBUtils.h"
#include <cstdlib>
*/

#include "PrimeObj.h"
#include <sstream>

using namespace std;

//---------------------------------------------------------
// Constructor

PrimeObj::PrimeObj()
{
m_started = false;
m_done = false;
}


//---------------------------------------------------------
// Procedure: get_string

string PrimeObj::get_string(double endtime, int calc_index)
{
  std::ostringstream str1;
  std::string str2;
  
  double calc_time = endtime - m_start_time;
  
  str1 << "orig=" << m_num_value;
  str1 << ",received=" << m_rec_index;
  str1 << ",calculated=" << calc_index;
  str1 << ",solve_time=" << calc_time;

  str1 << ",primes=";
  for (std::vector<int>::iterator it=m_primes.begin(); it!=m_primes.end(); it++)
    {
      str1 << *it << ":";
    }
  
  str2 = str1.str();
  str2 = str2.substr(0,str2.length()-1); // remove last ":"
  str2 += ",username=" + m_username;
  
  return str2;
}


void PrimeObj::find_primes(std::vector<int> cache_primes)
{
  int this_prime = 0;

  for (std::vector<int>::iterator it=cache_primes.begin();
       (it!=cache_primes.end()) && this_prime <= m_num_value; it++){
      
    this_prime = *it;
    if ((m_num_value % *it) == 0){
	m_primes.push_back(*it);
    }
  }
  m_done = true;
}

