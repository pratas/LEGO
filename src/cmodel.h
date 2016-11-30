#ifndef LEGO_CMODEL_H
#define LEGO_CMODEL_H

#include <iostream>
#include "defs.h"

class CM{
  public:
    CM ();                                      // constructor
      
    void buildHashTable     ();                       // build hash table
    void printHashTable     (hashTable_t);            // print hash table
      
    uint8_t getContextDepth () const;                 // getter of context depth
    void setContextDepth    (uint8_t);                // setter of context depth
    uint32_t getAlphaDenom  () const;                 // getter of alpha denominator
    void setAlphaDenom      (uint32_t);               // setter of alpha denominator
    bool getInvertedRepeat  () const;                 // getter of inverted repeat
    void setInvertedRepeat  (bool);                   // setter of inverted repeat
    const hashTable_t       &getHashTable () const;   // getter of hash table
    void setHashTable       (const hashTable_t&);     // setter of hash table
    const std::string       &getFileAddress () const; // getter of file address
    void setFileAddress     (const std::string&);     // setter of file address

  private:
    uint8_t contextDepth;                       // context depth
    uint32_t alphaDenom;                        // alpha denominator
    bool invertedRepeat;                        // inverted repeat
    hashTable_t hashTable;                      // hash table
    std::string fileAddress;                    // file address
  };

#endif // LEGO_CMODEL_H
