/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/09/16
File: student.h
Description: Declaration of the student class.
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Min and max values for the marks
const short MIN_MARKS = 0;
const short MAX_MARKS = 90;

class student
{
  public:
    //Description: The getName() function returns the name of the calling
    //             object.
    //Pre: None.
    //Post: The name of the calling object is returned.
    string getName() const;
    
    //Description: The setName() function sets the name of the calling object.
    //Pre: None.
    //Post: The name of the calling object is changed.
    void setName(string s);
    
    //Description: The getMarks() function returns the marks of the calling
    //             object.
    //Pre: None.
    //Post: The marks of the calling object is returned.
    short getMarks() const;
    
    //Description: The setMarks() function sets the name of the calling
    //             objects if n is between MIN_MARKS and MAX_MARKS, otherwise
    //             the program exits.
    //Pre: None.
    //Post: The marks of the calling object is changed.
    void setMarks(short n);
    
    //Description: The increment() function adds n to the marks of the calling
    //             object.
    //Pre: None. 
    //Post: The marks of the calling object is incremented.
    void increment(short n);
  private:
    short marks;  //Holds the marks for the calling object
    string name;  //Holds the name for the calling object
};

#endif
