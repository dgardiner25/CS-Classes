//Programmer: David Gardiner               Date: 1/28/2017
//File: fishbomb.cpp                       Class: 1510 C
//Purpose: Help Bender figure out how many fish he will catch by throwing
//         sticks of dynamite in various locations.

#include <iostream>
#include "fishbomb.h"
using namespace std;

int main()
{
  int num_tests;            //Number of tests the user would like to do

  cin >> num_tests;

  for(int i=0; i<num_tests; i++)
    runTest(i);

  return 0;
}
