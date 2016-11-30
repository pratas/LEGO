#ifndef LEGO_MESSAGES_H
#define LEGO_MESSAGES_H

#include <iostream>

class Messages{
  public:
    Messages();              // constructor
    void help      (void);   // show usage guide
    void about     (void);   // show About LEGO
    void verbose   (void);   // show verbose mode
    void number    (int);    // show integer number mode
    void fnumber   (float);  // show float number mode
  };

#endif //LEGO_MESSAGES_H
