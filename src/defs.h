#ifndef LEGO_DEF_H
#define LEGO_DEF_H

#include <chrono>           // time
#include <unordered_map>    // hash table

/***********************************************************
    About LEGO
************************************************************/
#define VERSION_LEGO 1
#define RELEASE_LEGO 0

/***********************************************************
    typedef
************************************************************/
// for calculating execution time
typedef std::chrono::high_resolution_clock highResClock;

// TODO
// vaghti bishtar az 65,535 (uint16_t max) shod, hameye adad ha nesf mishan.
// ye variable ro ham tanzim kon ke maloom she chand bar nesf kardim
//typedef std::unordered_map< std::string, std::array<uint16_t, ALPHABET_SIZE> > hashTable_t;

#endif //LEGO_DEF_H
