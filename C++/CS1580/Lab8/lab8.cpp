/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/12/16
File: lab8.cpp
Description: Calculate the centroid of a triangle given 3 points by
             the user.
*/

#include <iostream>
#include <string>
#include "lab8.h"
using namespace std;

int main()
{
  //Three points of the triangle
  point p1;
  point p2; 
  point p3;
  
  //Get the points of the triangle
  getInput(p1.xCoord, p1.yCoord);
  getInput(p2.xCoord, p2.yCoord);
  getInput(p3.xCoord, p3.yCoord);
  
  cout << endl;       //For formatting
  
  //Output the points to the screen
  outputPoint("First point", p1.xCoord, p1.yCoord);
  cout << endl;
  outputPoint("Second point", p2.xCoord, p2.yCoord);
  cout << endl;
  outputPoint("Third point", p3.xCoord, p3.yCoord);
  cout << endl << endl;    
  
  //Calculate centroid  and output
  calcCentroid(p1, p2, p3);
  
  return 0;
}
