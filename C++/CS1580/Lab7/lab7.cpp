/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/05/16
File: lab7.cpp
Description: Swap two values given by the user.
*/

#include <iostream>
#include <string>
#include "lab7.h"
using namespace std;

int main()
{
  short num1, num2;     //Values to be swapped

  //Output greeting
  greeting();
  
  //Get values from user
  num1 = getVal();
  num2 = getVal();
  
  //Output values before they are swapped
  outputVals("before", num1, num2);
  
  //Swap values
  swapVals(num1, num2);
  
  //Output values after they are swapped
  outputVals("after", num1, num2);

  //Sign-off
  signoff();

  return 0;
}
