/*****************************************************************/
/*   NAME: Michael Benjamin                                      */
/*   MODIFIED BY: Oscar Viquez                                   */
/*   ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA      */
/*   FILE: PrimeFactorTest_Info.cpp                              */
/*   DATE: Jan 12th, 2012                                        */
/*   MODIFIED: Feb 20th, 2013                                    */
/*                                                               */
/* This program is free software; you can redistribute it and/or */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation; either version  */
/* 2 of the License, or (at your option) any later version.      */
/*                                                               */
/* This program is distributed in the hope that it will be       */
/* useful, but WITHOUT ANY WARRANTY; without even the implied    */
/* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR       */
/* PURPOSE. See the GNU General Public License for more details. */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with this program; if not, write to the Free    */
/* Software Foundation, Inc., 59 Temple Place - Suite 330,       */
/* Boston, MA 02111-1307, USA.                                   */
/*****************************************************************/

#include <cstdlib>
#include <iostream>
#include "PrimeFactorTest_Info.h"
#include "ColorParse.h"
#include "ReleaseInfo.h"

using namespace std;

//----------------------------------------------------------------
// Procedure: showSynopsis

void showSynopsis()
{
  blk("SYNOPSIS:                                                       ");
  blk("------------------------------------                            ");
  blk("  The purpose of the pPrimeFactorTest application is to test    ");
  blk("  the performance of pPrimeFactor, and assert whether its output");
  blk("  string has been formatted correctly.                          ");
}

//----------------------------------------------------------------
// Procedure: showHelpAndExit

void showHelpAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("Usage: pPrimeFactorTest file.moos [OPTIONS]                     ");
  blu("=============================================================== ");
  blk("                                                                ");
  showSynopsis();
  blk("                                                                ");
  blk("Options:                                                        ");
  mag("  --alias","=<ProcessName>                                      ");
  blk("      Launch pXRelayTest with the given process name rather     ");
  blk("      than pXRelayTest.                                         ");
  mag("  --example, -e                                                 ");
  blk("      Display example MOOS configuration block.                 ");
  mag("  --help, -h                                                    ");
  blk("      Display this help message.                                ");
  //  mag("  --in","=<varname>                                             ");
  //  blk("      Use <varname> as the Relay incoming variable              ");
  mag("  --interface, -i                                               ");
  blk("      Display MOOS publications and subscriptions.              ");
  //  mag("  --out","=<varname>                                            ");
  //  blk("      Use <varname> as the Relay outgoing variable              ");
  blk("                                                                ");
  blk("Note: If argv[2] does not otherwise match a known option,       ");
  blk("      then it will be interpreted as a run alias. This is       ");
  blk("      to support pAntler launching conventions.                 ");
  blk("                                                                ");
  exit(0);
}

//----------------------------------------------------------------
// Procedure: showExampleConfigAndExit

void showExampleConfigAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("pPrimeFactorTest Example MOOS Configuration                     ");
  blu("=============================================================== ");
  blk("                                                                ");
  blk("ProcessConfig = pPrimeFactor                                    ");
  blk("{                                                               ");
  blk("  AppTick   = 4                                                 ");
  blk("  CommsTick = 4                                                 ");
  blk("}                                                               ");
  blk("                                                                ");
  exit(0);
}


//----------------------------------------------------------------
// Procedure: showInterfaceAndExit

void showInterfaceAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("pOdometry INTERFACE                                               ");
  blu("=============================================================== ");
  blk("                                                                ");
  showSynopsis();
  blk("                                                                ");
  blk("SUBSCRIPTIONS:                                                  ");
  blk("------------------------------------                            ");
  blk("  PRIME_RESULT: contains a pre-formatted string with all        ");
  blk("  computation parameters from pPrimeFactor                      ");
  //  blk("  Whatever variable is specified by the INCOMING_VAR            ");
  //  blk("  configuration parameter.                                      ");
  blk("                                                                ");
  blk("PUBLICATIONS:                                                   ");
  blk("------------------------------------                            ");
  blk("  PRIME_RESULT_VALID: contains the original pre-formatted string");
  blk("   with all computation parameters, as well as a validity flag. ");
  //  blk("  Whatever variable is specified by the OUTGOING_VAR            ");
  //  blk("  configuration parameter.                                      ");
  blk("                                                                ");
  exit(0);
}

