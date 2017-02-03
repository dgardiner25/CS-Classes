/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/19/16
File: lab9_functions.cpp
Description: Function definitions to create a gradebook, calculate the letter 
             grades of students, and calculate the class average.
*/

#include <iostream>
#include "lab9.h"
using namespace std;

void greeting()
{
  cout << "Welcome to the grade calculator!\n" << endl;
  return;
} 

void getInput(student s[], const int size)
{
  bool inRange;
  for(int i=0; i<size; i++)
  {
    cout << "Enter the name of student " << i+1 << ": ";
    cin >> s[i].name;
    do
    {
      cout << "Enter marks of student " << i+1 << ": ";
      cin >> s[i].marks;
      inRange = s[i].marks >= LOWEST_GRADE && s[i].marks <= HIGHEST_GRADE;
      if(!inRange)
        cout << "Enter a valid number." << endl;
    } while(!inRange);
    cout << endl;
  }
  return;
}

void grader(student s[], const int size)
{
  for(int i=0; i<size; i++)
  {
    if(s[i].marks <= HIGHEST_A && s[i].marks >= LOWEST_A)
      s[i].grade = 'A';
    else if(s[i].marks <= HIGHEST_B && s[i].marks >= LOWEST_B)
      s[i].grade = 'B';
    else if(s[i].marks <= HIGHEST_C && s[i].marks >= LOWEST_C)
      s[i].grade = 'C';
    else
      s[i].grade = 'F';
  }
  return;
}

void display(const student s[], const int size)
{
  for(int i=0; i<size; i++)
    cout << "Student Report || Name: " << s[i].name << ", Grade: " 
         << s[i].grade << endl;
  return;
}

void average(const student s[], const int size)
{
  int sum = 0;
  float avg;
  for(int i=0; i<size; i++)
    sum+=s[i].marks;
  avg = static_cast<float>(sum)/size;
  cout << "Class average is: " << avg << endl;
  return;
}











