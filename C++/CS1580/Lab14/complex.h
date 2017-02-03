/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/30/16
File: complex.h
Description: Declaration of the complex class.
*/

#include <iostream>
using namespace std;

template <class T>
class complex
{
  private:
    T m_a; //a component of a+bi
    T m_b; //b component of a+bi
  public:
    //Description: The default constructor for the complex class.
    //Pre: None.
    //Post: The member vaiables of complex have been assigned.
    complex(const T a=0, const T b=0): m_a(a), m_b(b) {}
    //Description: The operator+() function overloads the + operator to be able
    //             to add two complex numbers together, with a complex number
    //             of the sum being returned.
    //Pre: None.
    //Post: The sum of the calling object and rhs is returned.
    complex operator+(const complex<T> & rhs) const;
    //Description: The operator<<() function overloads the << operator and
    //             prints out the complex number in a+bi format.
    //Pre: None.
    //Post: A complex number is output to the screen.
    template <class U>
    friend ostream& operator<<(ostream & out, const complex<U> & c);
};


