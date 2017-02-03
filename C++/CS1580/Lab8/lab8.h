/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/12/16
File: lab8.h
Description: Function prototypes, templates and structures to calculate the   
             centroid of a triangle given 3 points by the user.
*/

#ifndef LAB8_H
#define LAB8_H

#include <iostream>
#include <string>
using namespace std;

struct point
{
  short xCoord;
  short yCoord;
};

//Description: Output the point given the point number, x, and y values.
//Pre: None.
//Post: The point is output to the screen.
template <typename T>
void outputPoint(const string pt, const T x, const T y)
{
  cout << pt << ": (" << x << ", " << y << ")";
  return;
}

//Description: Get input from the user.
//Pre: Parameters must be modifiable.
//Post: Input is returned through pass by reference.
void getInput(short & var1, short & var2);

//Description: Determine if num is first, second, or third.
//Pre: num must be either 1, 2, or 3.
//Post: A spelled out version of the number is returned.
string firstSecThird(const short num);

//Description: Calculate the centroid given 3 points.
//Pre: None.
//Post: The centroid is calculated and output.
void calcCentroid(point p1, point p2, point p3);

#endif
