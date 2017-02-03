/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/05/16
File: lab7_functions.cpp
Description: Function definitions used to swap two values given by the user.
*/

#include <iostream>
#include <string> 
#include "lab7.h"
using namespace std;

void greeting()
{
  cout << "Welcome to the number swap!" << endl;
  return;
}

short getVal()
{
  static short numCount = 1;
  short val;
  cout << "\nEnter a value for number " << numCount << ":     ";
  cin >> val;
  numCount++;
  return val;
}

void swapVals(short & val1, short & val2)
{
  short temp = val1;
  val1 = val2;
  val2 = temp;
  return;
}

void outputVals(const string beforeAfter, const short val1, const short val2)
{
  cout << "\nThe value of number 1 is " << val1 << " and the value of number 2"
       << " is " << val2 << " " << beforeAfter << " swapping." << endl;
  return;
}

void signoff()
{
  cout << "\nThank you, have a good day!" << endl;
}
