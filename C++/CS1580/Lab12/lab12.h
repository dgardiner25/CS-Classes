/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/09/16
File: lab12.h
Description: Constants and function prototypes to get the names and marks of 
             students and output them to a file.
*/

#ifndef LAB12_H
#define LAB12_H

#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;

//------Constants------//
const short NUM_TO_INCREMENT = 7;

//------Function Prototypes------//
//Description: The getInfo() function prompts the user to enter the names and
//             marks of each student.
//Pre: None.
//Post: The name and marks of each student are changed.
void getInfo(student & s1, student & s2, student & s3);

//Description: The incrementMarks() function increments the marks of each 
//             student by NUM_TO_INCREMENT.
//Pre: None.
//Post: The marks of each student are incremented.
void incrementMarks(student & s1, student & s2, student & s3);

//Description: The outputToFile() function outputs the name and marks of each
//             student.
//Pre: None.
//Post: The name and marks of each student are output to the output file.
void outputToFile(student s1, student s2, student s3);

#endif
