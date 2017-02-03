/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/16/16
File: box.cpp
Description: Implementation of the box class.
*/

#include "box.h"
using namespace std;

box::box(const int h, const int w, const int l)
{
  setBox(h, w, l);
}

box::box(const box & source)
{
  height = source.height;
  width = source.width;
  length = source.length;
}

void box::setBox(const int h, const int w, const int l)
{
  if(h>0)
    height = h;
  else
  {
    cout << "Negative height not allowed!" << endl;
    exit(1);
  }
  if(w>0)
    width = w;
  else
  {
    cout << "Negative width not allowed!" << endl;
    exit(1);
  }
  if(l>0)
    length = l;
  else
  {
    cout << "Negative length not allowed!" << endl;
    exit(1);
  }
  return;
}

box operator+(const box & b1, const box & b2)
{
  box ret;
  ret.height = b1.height + b2.height;
  ret.width = b1.width + b2.width;
  ret.length = b1.length + b2.length;
  return ret;
}

bool operator>(const box & b1, const box & b2)
{
  bool isGreater = false;
  if(b1.height > b2.height && b1.width > b2.width && b1.length > b2.length)
    isGreater = true;
  return isGreater;
}

void box::print() const
{
  static int box_num = 1;
  cout << "Box " << box_num << ":"
       << "\tHeight: " << height << endl
       << "\tWidth:  " << width << endl
       << "\tLength: " << length << endl;
  box_num++;
  return;
}





