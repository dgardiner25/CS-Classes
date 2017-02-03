//Programmer: DAVID GARDINER          Date: 10/16/16
//File: pileIdentifier.cpp            Class: CS1570 A
//Purpose: Identify the various trash piles throughout
//         the city of Springfield.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "pileIdentifier.h"
using namespace std;

int main()
{
  //Initialize arrays  
  pile pileList[NUM_ENTRIES];
  offender offenderList[NUM_ENTRIES];
  
  //Seed the RNG
  srand(time(NULL));
  
  //Greet the user
  greeting();
  
  //Assign random values to all elements of the given array
  assignPileVals(pileList, NUM_ENTRIES);

  //Sort the array
  sortArray(pileList, NUM_ENTRIES);
  
  //Output the list of piles
  outputPiles(pileList, NUM_ENTRIES);

  cout << endl;
  
  //Assign random names and guilt values to all elements of the given array
  assignOffenderVals(offenderList, NUM_ENTRIES);
  
  //Sort the array
  sortArray(offenderList, NUM_ENTRIES);
  
  //Output the list of offenders
  outputOffenders(offenderList, NUM_ENTRIES);
  
  cout << endl;

  //Output the two most guilty offenders
  outputTopTwo(offenderList);
  
  cout << endl;
  
  //Output the offenders holding the top 50% of the weight of all piles
  outputTopPercentage(pileList, offenderList, NUM_ENTRIES);
  
  cout << endl;
  
  //Output the weights categorized by sector
  outputSectorWeights(pileList, NUM_ENTRIES);
  
  //Ask the user which pile they want to know the owner of
  identifyPiles(pileList, offenderList, NUM_ENTRIES);
  
  //Display a sign-off
  signoff();
  
  return 0;
}
