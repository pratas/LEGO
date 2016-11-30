#include <iostream>
#include <fstream>

#include "messages.h"
#include "defs.h"

//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SHOW CONSTRUCTOR
//
Messages::Messages(){}

//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SHOW USAGE GUIDE
//
void Messages::help (void){
    std::cout                                                       << "\n"
            << "Synopsis:"                                          << "\n"
            << "    LEGO [OPTION]... -t [TARGET] -r [REFERENCE]"    << "\n"
                                                                    << "\n"
            << "Options:"                                           << "\n"
            << "    -h,  --help"                                    << "\n"
            << "         usage guide"                               << "\n"
                                                                    << "\n"
            << "    -V,  --version"                                 << "\n"
            << "         version number"                            << "\n"
                                                                    << "\n"
            << "    -v,  --verbose"                                 << "\n"
            << "         verbose mode (more information)"           << "\n"
                                                                    << "\n"
            << "    -i,  --inverted_repeat"                         << "\n"
            << "         considers inverted repeats"                << "\n"
                                                                    << "\n"
            << "    -n [NUMBER],  --number [NUMBER]"                << "\n"
            << "         number of something."                      << "\n"
            << "         requires an integer number (NUMBER)"       << "\n"
                                                                    << "\n"
            << "    -d [NUMBER],  --fnumber [NUMBER]"               << "\n"
            << "         number of something."                      << "\n"
            << "         requires a float number (NUMBER)"          << "\n"
                                                                    << "\n"
            << "    -t [TARGET],  --target [TARGET]"                << "\n"
            << "         target file"                               << "\n"
                                                                    << "\n"
            << "    -r [REFERENCE],  --reference [REFERENCE]"       << "\n"
            << "         reference file"                            << "\n"
                                                                    << "\n";
}

//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SHOW ABOUT LEGO
//
void Messages::about (void){
  std::cout                                                       << "\n"
  << "LEGO v" << VERSION_LEGO << "." << RELEASE_LEGO              << "\n"
  << "================"                                           << "\n"
  << "L. E. G. O. description"                                    << "\n"
                                                                  << "\n"
  << "Diogo Pratas, Morteza Hosseini, Armando J. Pinho"           << "\n"
  << "Copyright (C) 2017 University of Aveiro"                    << "\n"
                                                                  << "\n"
  << "This is a Free software, under GPLv3. You may redistribute" << "\n"
  << "copies of it under the terms of the GNU - General Public"   << "\n"
  << "License v3 <http://www.gnu.org/licenses/gpl.html>. There"   << "\n"
  << "is NOT ANY WARRANTY, to the extent permitted by law."       << "\n"
                                                                  << "\n";
  }


//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SHOW VERBOSE MODE
//
void Messages::verbose (void){
  std::cout << "verbose mode.\n"; // for test
  }


//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SHOW INTEGER MODE NUMBER
//
void Messages::number (int num){
  std::cout << "integer number mode (n=" << num << ")\n"; // for test
  }


//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SHOW FLOAT MODE NUMBER
//
void Messages::fnumber (float num){
  std::cout << "float number mode (d=" << num << ")\n"; // for test
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//////////////////////////////////////////////////////////////////////////////

