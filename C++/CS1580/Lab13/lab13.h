/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/16/16
File: lab13.h
Description: Function declarations. 
*/

#ifndef LAB13_H
#define LAB13_H

#include <iostream>
using namespace std;

//------Declarations------//
//Description: The getInput() function gets input from the user for the
//             height, width, and length.
//Pre: h, w, and l must be modifiable.
//Post: h, w, and have been modified.
void getInput(int & h, int & w, int & l);

//Description: The menu() function displays a menu and gets the user's choice.
//Pre: choice must be modifiable.
//Post: A menu is output to the screen and choice is modified.
void menu(int & choice);

#endif
