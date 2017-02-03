/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/05/16
File: lab7.h
Description: Function prototypes used to swap two values given by the user.
*/

#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <string>
using namespace std;

//Description: The greeting() function displays a greeting.
//Pre: None.
//Post: A greeting is output to the screen
void greeting();

//Description: The getVal() function gets input from the user
//Pre: None.
//Post: Input value is returned.
short getVal();

//Description: The swapVals() function swaps the value of the two parameters
//             through pass by reference.
//Pre: None.
//Post: The values of the pass by reference variables are swapped.
void swapVals(short & val1, short & val2);

//Description: The outputVals() function outputs the entered values and
//             specifies if before or after swapping.
//Pre: beforeAfter must either be "before" or "after".
//Post: The values are output to the screen with the appropriate before/after.
void outputVals(const string beforeAfter, const short val1, const short val2);

//Description: The signoff() function displays a sign-off.
//Pre: None.
//Post: A sign-off is output to the screen.
void signoff();

#endif
