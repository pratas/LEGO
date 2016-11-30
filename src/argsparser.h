#ifndef LEGO_ARGSPARSER_H
#define LEGO_ARGSPARSER_H

#include <iostream>

class Functions{
  public:
    Functions ();                                     // constructor
    int8_t commandLineParser   (int, char**);         // parse command line
    bool fileOpenErrorHandle   (const std::string&);  // handle errors while opening file
  };


#endif // LEGO_ARGSPARSER_H
