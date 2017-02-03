/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/12/16
File: lab8.h
Description: Function definitions used to calculate the centroid of a triangle 
             given 3 points by the user.
*/

#include <iostream>
#include <string>
#include "lab8.h"
using namespace std;

void getInput(short & var1, short & var2)
{
  static short num = 1;
  cout << "Enter the " << firstSecThird(num) << " point of the "
       << "triangle:    ";
  cin >> var1 >> var2;
  num++;
  return;
}

string firstSecThird(const short num)
{
  string ret;
  if(num == 1)
    ret = "first";
  else
    ret = num == 2 ? "second" : "third";
  return ret;
}

void calcCentroid(point point1, point point2, point point3)
{
  float x = (point1.xCoord + point2.xCoord + point3.xCoord)/3.0;
  float y = (point1.yCoord + point2.yCoord + point3.yCoord)/3.0;
  outputPoint("The centroid of the triangle is: ", x, y);
  return;
}

    
