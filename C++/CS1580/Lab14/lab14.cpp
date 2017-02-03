/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/30/16
File: lab14.cpp
Description: Use a templated class to add and output complex numbers.
*/

#include <iostream>
#include "complex.hpp"
using namespace std;

int main()
{
  //Declare and initialize complex numbers
  complex<int> c1(7,3);
  complex<int> c2(6,0);
  complex<float> c3(-3.2,7.5);
  complex<float> c4(4.9,-2.2);
  complex<int> c5 = c1 + c2;
  complex<float> c6 = c3 + c4;
  
  //Output
  cout << "The result of addition of complex numbers 1 and 2 is: " << c5 
       << endl;
  cout << "The result of addition of complex numbers 3 and 4 is: " << c6 
       << endl;
  return 0;
}
