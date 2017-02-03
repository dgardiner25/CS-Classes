/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/19/16
File: lab9.h
Description: The constants, type declarations, and prototypes to create a   
             gradebook, calculate the letter grades of students, and
             calculate the class average.
*/

#ifndef LAB9_H
#define LAB9_H
using namespace std;

//------Constants------//
const int NUM_STUDENTS = 3;
const short LOWEST_GRADE = 0;
const short HIGHEST_GRADE = 100;
const short LOWEST_A = 90;
const short HIGHEST_A = 100;
const short LOWEST_B = 80;
const short HIGHEST_B = 89;
const short LOWEST_C = 70;
const short HIGHEST_C = 79;

//------Type Declarations------//
struct student
{
  string name;
  short marks;
  char grade;
};

//------Function Prototypes------//
//Description: Display a greeting to the user.
//Pre: None.
//Post: A message is output to the screen.
void greeting();

//Description: Prompt and get input from the user.
//Pre: None.
//Post: Input (if in range) is assigned to array elements.
void getInput(student s[], const int size);

//Description: Calculate the grade letter of the students.
//Pre: None.
//Post: Correct letter grades are assigned to each student element.
void grader(student s[], const int size);

//Description: The students name and grade letter is displayed.
//Pre: None.
//Post: The name and letter grade are output to the screen.
void display(const student s[], const int size);

//Description: Calculate the average of the entire class.
//Pre: None.
//Post: The class average is output to the screen.
void average(const student s[], const int size);

#endif
