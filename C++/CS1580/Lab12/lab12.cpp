/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/09/16
File: lab12.cpp
Description: Get the names and marks of students and output them to a file.
*/

#include "student.h"
#include "lab12.h"
using namespace std;

int main()
{
  student s1;   //1st student object
  student s2;   //2nd student object
  student s3;   //3rd student object
  
  getInfo(s1, s2, s3);  //Get the names and marks of each student
  
  incrementMarks(s1, s2, s3);   //Increment the marks of each student
  
  outputToFile(s1, s2, s3);   //Output the names and marks to the output file

  return 0;
}
