/****************************************************************/
/*    NAME: Michael Benjamin -- MODIFIED BY: Oscar Viquez       */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA    */
/*    FILE: PrimeObj.h                                          */
/*    DATE: Feb 18th, 2013                                      */
/****************************************************************/

//#ifndef P_PRIMEFACTOR_VAR_HEADER
//#define P_PRIMEFACTOR_VAR_HEADER

//#include "MOOS/libMOOS/MOOSLib.h"
//#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string.h>


class PrimeObj
{
 protected:
  std::string m_username;

  // Basic entry information
  uint64_t m_num_value;
  int      m_rec_index;

  // Prime test parameters
  double   m_start_time;
  //uint64_t m_test_top;
  std::vector<int> m_primes;

  bool m_started;
  bool m_done;


 public:
  PrimeObj();
  virtual ~PrimeObj() {};
  
  void set_user       (std::string user)           {m_username = user;}
  void set_entry      (uint64_t num, int rec) {m_num_value = num; m_rec_index = rec;}
  void set_start      (double time)           {m_started = true; m_start_time = time;}
  //void set_start_time (double time)           {m_start_time = time;}
  //void set_test_top   (uint64_t top)          {m_test_top = top;}

  void add_prime      (int new_prime)         {m_primes.insert(m_primes.end(),new_prime);}
  void find_primes      (std::vector<int> cache_primes);   //(int new_prime)         {m_primes.push_back(new_prime);}

  void set_done(){m_done = true;}

  bool started(){return m_started;}
  bool is_done(){return m_done;}
  uint64_t get_num(){return m_num_value;}
  std::string get_string(double endtime, int calc_index);

};

//#endif 
