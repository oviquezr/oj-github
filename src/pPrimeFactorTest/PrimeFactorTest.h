/****************************************************************/
/*    NAME: Michael Benjamin -- MODIFIED BY: Oscar Viquez       */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA    */
/*    FILE: PrimeFactor.h                                       */
/*    DATE: Feb 18th, 2013                                      */
/****************************************************************/

#ifndef P_PRIMEFACTORTEST_VAR_HEADER
#define P_PRIMEFACTORTEST_VAR_HEADER

//#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <list>

//class PrimeFactorTest : public CMOOSApp
class PrimeFactorTest : public AppCastingMOOSApp
{
 public:
  PrimeFactorTest();
  virtual ~PrimeFactorTest() {};

  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();
  void RegisterVariables();

 protected:
  std::string prime_result;

  uint64_t original;
  
  std::list<int> prime_factors;
  
  bool newData;
  bool valid;
  
  // iterator to manage active prime_factors list entry
  // -- use at Iterate() --
  std::list<int>::iterator it;
  
 
  bool buildReport();
};

#endif 
