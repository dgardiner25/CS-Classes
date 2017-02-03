/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/09/16
File: student.cpp
Description: Function definitions for the student class.
*/

#include "student.h"
using namespace std;

string student::getName() const
{
  return name;
}

void student::setName(string s)
{
  name = s;
  return;
}

short student::getMarks() const
{
  return marks;
}

void student::setMarks(short n)
{
  if(n > MIN_MARKS && n < MAX_MARKS)
    marks = n;
  else
  {
    cout << "Marks not in range! Exiting..." << endl;
    exit(1);
  }
}

void student::increment(short n)
{
  marks+=n;
  return;
}
