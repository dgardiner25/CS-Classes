/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/19/16
File: lab9.cpp
Description: Create a gradebook, calculate the letter grades of students, and
             calculate the class average.
*/

#include <iostream>
#include "lab9.h"
using namespace std;

int main()
{
  //Initialize the array of students
  student sList[NUM_STUDENTS];

  //Greet the user
  greeting();
  
  //Get input from the user and assign to array elements
  getInput(sList, NUM_STUDENTS);  
  
  //Calculate the grades off all students
  grader(sList, NUM_STUDENTS);
  
  //Display the grades of each student
  display(sList, NUM_STUDENTS);
  
  //Display the class average
  average(sList, NUM_STUDENTS);
  
  return 0;
}
