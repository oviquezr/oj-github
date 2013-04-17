/****************************************************************/
/*    NAME: Michael Benjamin -- MODIFIED BY: Oscar Viquez       */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA    */
/*    FILE: PrimeFactor.h                                       */
/*    DATE: Feb 18th, 2013                                      */
/****************************************************************/

#ifndef P_PRIMEFACTOR_VAR_HEADER
#define P_PRIMEFACTOR_VAR_HEADER

//#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <list>

//class PrimeFactor : public CMOOSApp
class PrimeFactor : public AppCastingMOOSApp
{
 public:
  PrimeFactor();
  virtual ~PrimeFactor() {};

  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();
  void RegisterVariables();

 protected:
  int buffer;
  bool newData;
  int lost;

  uint64_t num_value;   // placeholder for data input

  struct num_entry {    // contain all relevant data for a given input
    uint64_t original;
    uint64_t tested_top;

    int rec_index;
    double start_time;
    std::list<int> prime_factors;
  };
  
  int rec_index_top;
  int calc_index;       // calc_index is set based on the order of computation
  double calc_time;
  num_entry s_result;   // placeholder for data formatting prior to output
 
  num_entry s_empty;    // placeholder for default values

  std::list<int> cache_primes;
  uint64_t cache_tested_top;

  num_entry* queue;

  int curr_ind;

  double iter_start_time;

  // iterator to manage active prime_factors list entry
  // -- use at Iterate() --
  std::list<int>::iterator it;

  std::string username;
  std::string prime_result;

  void formatResult();

  void selectNext();

  bool buildReport();
};

#endif 
