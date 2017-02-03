/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 12/7/16
File: lab15.cpp
Description: 
*/

#include <iostream>
#include "lab15.h"
using namespace std;

int main()
{
  //FizzBuzz problem
  cout << "The solution to the FizzBuzz problem is:" << endl;
  fizzBuzz();
  
  //Dollar problem
  cout << "The smallest number of moves to get you to $200 is: \n" 
       << dollarProblem() << " moves." << endl;

  return 0;
}
