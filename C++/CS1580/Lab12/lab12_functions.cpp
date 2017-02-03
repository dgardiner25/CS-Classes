/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/09/16
File: lab12_functions.cpp
Description: Function definitions to get the names and marks of students and 
             output them to a file.
*/

#include "lab12.h"
using namespace std;

void getInfo(student & s1, student & s2, student & s3)
{
  string name;
  short marks;

  cout << "Enter the name of the 1st student: ";
  cin >> name;
  s1.setName(name);

  cout << "Enter the marks of the 1st student: ";
  cin >> marks;
  s1.setMarks(marks);  

  cout << "Enter the name of the 2nd student: ";
  cin >> name;
  s2.setName(name);

  cout << "Enter the marks of the 2nd student: ";
  cin >> marks;
  s2.setMarks(marks);
  
  cout << "Enter the name of the 3rd student: ";
  cin >> name;
  s3.setName(name);

  cout << "Enter the marks of the 3rd student: ";
  cin >> marks;
  s3.setMarks(marks);
  return;
}

void incrementMarks(student & s1, student & s2, student & s3)
{
  s1.increment(NUM_TO_INCREMENT);
  s2.increment(NUM_TO_INCREMENT);
  s3.increment(NUM_TO_INCREMENT);
  return;
}

void outputToFile(student s1, student s2, student s3)
{
  ofstream fout("student.dat");
  fout << "-----------STUDENT REPORT-----------" << endl
       << s1.getName() << " || " << s1.getMarks() << endl
       << s2.getName() << " || " << s2.getMarks() << endl
       << s3.getName() << " || " << s3.getMarks() << endl
       << "----------------END-----------------" << endl;
  fout.close();
  return;  
}







