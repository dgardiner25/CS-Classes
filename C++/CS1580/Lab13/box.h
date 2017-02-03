/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/16/16
File: box.h
Description: Definition of the box class.
*/

#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <cstdlib>
using namespace std;

class box
{
  private:
    int height;
    int width;
    int length;
  public:
    //Description: Default constructor for the box class.
    //Pre: None.
    //Post: All members are set to 1.
    box(): height(1), width(1), length(1) {}
    //Description: Constructor that assigns height to h, width to w, and length 
    //             to l.
    //Pre: h, w, l must be positive.
    //Post: height has been assigned to h, width to w, and length to l.
    box(const int h, const int w, const int l);
    //Description: Copy constructor that copies the members of source to those
    //             of the calling object.
    //Pre: None.
    //Post: Source has been copied to the calling object.
    box(const box & source);
    //Description: The setBox() function assigns height to h, width to w, and 
    //             length to l. If h, w, or l are not positive, program exits.
    //Pre: None.
    //Post: If h, w, and l are positive, height has been assigned to h, width 
    //      to w, and length to l, otherwise, the program exits.
    void setBox(const int h, const int w, const int l);
    //Description: The operator+() function adds all members of b1 and b2.
    //Pre: None.
    //Post: A box with the members of b1 and b2 added together is output.
    friend box operator+(const box & b1, const box & b2);
    //Description: The operator>() function compares all members of b1 and 
    //             b2.
    //Pre: None.
    //Post: If all members of b1 are greater than b2, true is returned.
    //      Otherwise, false is returned.
    friend bool operator>(const box & b1, const box & b2);
    //Description: The print() function displays the members of the calling
    //             object.
    //Pre: None.
    //Post: The members of the calling object have been output to the screen.
    void print() const;
};












#endif
