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
#include "PrimeObj.h"

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
  bool buildReport();
  void selectNext();

 protected:
  std::string m_username;

  PrimeObj m_new_entry;
  PrimeObj m_curr_entry;
  std::list<PrimeObj> m_queue;

  //uint64_t m_num_value;   // placeholder for data input
  int m_rec_index;
  int m_calc_index;       // calc_index is set based on the order of computation
  
  std::vector<int> m_cache_primes;
  uint64_t m_cache_test_top;

  //  std::list<int>::iterator current;

};

#endif 
