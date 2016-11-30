#include <iostream>
#include <fstream>
#include <algorithm>

#include "cmodel.h"
#include "argsparser.h"


/***********************************************************
    constructor
************************************************************/
CM::CM () {}


/***********************************************************
    build hash table
************************************************************/
void CM::buildHashTable(){
  uint8_t contextDepth = getContextDepth();       // get context depth
  uint32_t alphaDen = getAlphaDenom(); // get alpha denominator
  std::string fileName = getFileAddress();        // get file address
  bool isInvertedRepeat = getInvertedRepeat();    // get inverted repeat
    
  Functions funcObj;  // object of class Functions
    
  std::ifstream fileIn(fileName, std::ios::in);           // open file located in fileName
  bool isFileOk = funcObj.fileOpenErrorHandle(fileName);  // check if file is opened correctly
    
  if(isFileOk){   // file opened correctly
    std::string context(contextDepth, 'A');    // context, that slides in the dataset
        
    hashTable_t hTable;                         // create hash table
    hTable.insert({context, {0, 0, 0, 0, 0}});  // initialize hash table with 0'z
        
    std::string datasetLine;                    // to keep each line of file
    std::getline(fileIn, datasetLine);          // read first line of file
    datasetLine = context + datasetLine;        // add "AA..." to beginning of first line of file
        
    // iterator for each line of file.
    // at first line, it starts from index CONTEXT_DEPTH. at other lines, it starts from index 0
    size_t lineIter = contextDepth;
    do{
      // fill hash table by number of occurrences of symbols A, C, T, G, N
      for(size_t i = lineIter; i != datasetLine.size(); ++i){
      // considering inverted repeats to update hash table
        if(isInvertedRepeat){
          std::string invRepeat = context + datasetLine[ i ];
        
          // A <-> T  ,  C <-> G  ,  N <-> N (N unchanged)
          for(char &ch : invRepeat)
            ch = (ch == 'A') ? 'T' :
            (ch == 'C') ? 'G' :
            (ch == 'T') ? 'A' :
            (ch == 'G') ? 'C' :
            'N';
        
          // reverse the string
          std::reverse( invRepeat.begin(), invRepeat.end() );
          
          // inverted repeat context
          std::string invRepeatContext = invRepeat.substr(0, invRepeat.size() - 1);
        
          // update hash table for inverted repeats
          switch(invRepeat[ invRepeat.size() - 1 ]){
            case 'A':   ++(hTable[ invRepeatContext ])[ 0 ];    break;
            case 'C':   ++(hTable[ invRepeatContext ])[ 1 ];    break;
            case 'T':   ++(hTable[ invRepeatContext ])[ 2 ];    break;
            case 'G':   ++(hTable[ invRepeatContext ])[ 3 ];    break;
            case 'N':   ++(hTable[ invRepeatContext ])[ 4 ];    break;
            default:                                            break;
            }
          }
                
        switch(datasetLine[ i ]){
          case 'A':   ++(hTable[ context ])[ 0 ]; break;
          case 'C':   ++(hTable[ context ])[ 1 ]; break;
          case 'T':   ++(hTable[ context ])[ 2 ]; break;
          case 'G':   ++(hTable[ context ])[ 3 ]; break;
          case 'N':   ++(hTable[ context ])[ 4 ]; break;
          default:                                break;
          }
                
       // update context
        context = (contextDepth == 1)
        ? std::string("") + datasetLine[ i ]
        : context.substr(1, contextDepth - 1) + datasetLine[ i ];
        }
            
      lineIter = 0;   // iterator for non-first lines of file becomes 0
      } 
    while(std::getline(fileIn, datasetLine));
        
    fileIn.close();     // close file
        
    // return hTable;      // return the made hash table
    CM::hashTable = hTable;    // save the built hash table
    }
  }


/***********************************************************
    print hash table
************************************************************/
void CM::printHashTable (hashTable_t hTable){
    
    /***********************************************************
        test
    ************************************************************/
    std::cout << "\tA\tC\tT\tG\tN"
              //              << "\tP_A\tP_C\tP_T\tP_G\tP_N"
              << "\n"
              << "\t-----------------------------------"
              //              << "------------------------------------------"
              << "\n";
    
    int sum;
    int alpha = 1;
    
    for (hashTable_t::iterator it = hTable.begin(); it != hTable.end(); ++it)
    {
        sum = 0;
        std::cout << it->first << "\t";
        for (int i : it->second)
        {
            std::cout << i << "\t";
            sum += i;
        }

//        for (int i = 0; i < 5; ++i)
//        {
//            std::cout << std::fixed << std::setprecision(1)
//                      << (float) (it->second[ i ] + alpha) /
//                         (sum + ALPHABET_SIZE * alpha) << "\t";
//        }
        std::cout << "\n";
    }
}


/***********************************************************
    getters and setters
************************************************************/
uint8_t CM::getContextDepth () const { return contextDepth; }
void CM::setContextDepth (uint8_t ctxDp) { CM::contextDepth = ctxDp; }
uint32_t CM::getAlphaDenom () const { return alphaDenom; }
void CM::setAlphaDenom (uint32_t alphaDen) { CM::alphaDenom = alphaDen; }
bool CM::getInvertedRepeat () const { return invertedRepeat; }
void CM::setInvertedRepeat (bool invRep) { CM::invertedRepeat = invRep; }
const hashTable_t &CM::getHashTable () const { return hashTable; }
void CM::setHashTable (const hashTable_t &hT) { CM::hashTable = hT; }
const std::string &CM::getFileAddress () const { return fileAddress; }
void CM::setFileAddress (const std::string &fA) { CM::fileAddress = fA; }




