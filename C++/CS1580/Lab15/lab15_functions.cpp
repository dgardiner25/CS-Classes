/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 12/7/16
File: lab15_functions.cpp
Description: 
*/

#include "lab15.h"
using namespace std;

//------Function Definitions------//
void fizzBuzz()
{
  for(int i=1; i<=LOOP_TIMES; i++)
  {
    if(i%3 && i%5)
      cout << i;
    else
    {    
      if(i%3==0)
        cout << MULT_OF_THREE;
      if(i%5==0)
        cout << MULT_OF_FIVE;
    }
    cout << endl;
  }
  return;
}

short dollarProblem()
{
  short moves = 0;
  short total = DOLLARS_TO_START;
  
  while((total+1)*2 <= DOLLARS_TO_GET)
  {
    total = (total+1) * 2;
    moves++;
  }
  while(total < DOLLARS_TO_GET)
  {
    total++;
    moves++;
  }
  return moves;
}
