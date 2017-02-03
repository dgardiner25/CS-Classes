/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/30/16
File: complex.hpp
Description: Implementation of the complex class.
*/

#include "complex.h"
using namespace std;

template <class T>
complex<T> complex<T>::operator+(const complex<T> & rhs) const
{
  complex<T> sum;
  sum.m_a = m_a + rhs.m_a;
  sum.m_b = m_b + rhs.m_b;
  return sum;
}

template <class T>
ostream& operator<<(ostream & out, const complex<T> & c)
{
  out << c.m_a << "+" << c.m_b << "i";
  return out;
}
