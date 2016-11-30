#include <iostream>
#include <fstream>
#include <cstring>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#if defined(_MSC_VER)
#include <io.h>
#else
#include <unistd.h>
#endif

#include "defs.h"
#include "msg.h"
#include "argsparser.h"

int32_t main (int argc, char *argv[]){

  highResClock::time_point exeStartTime = highResClock::now();
  
  // for access to Functions (object 'function' on memory stack)
  Functions function;
  function.commandLineParser(argc, argv); // parse the command line
  
  // Record end time
  highResClock::time_point exeFinishTime = highResClock::now();

  // calculate and show duration in seconds
  std::chrono::duration< double > elapsed = exeFinishTime - exeStartTime;
  std::cout << "\nElapsed time: " << elapsed.count() << " s\n";
    
  return 0;
  }
