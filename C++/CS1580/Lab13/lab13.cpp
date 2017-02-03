/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/16/16
File: lab13.cpp
Description: Practice using constructors, friend functions, and operator
             overloading through the use of a box class.
*/

#include "box.h"
#include "lab13.h"
#include <iostream>
using namespace std;

int main()
{
  box box1, box2, box5, box6;
  int ht, wt, lngth; //Variables that hold the dimensions of a box object
  int choice;        //User's menu option choice

  //Display menu and get user's choice
  menu(choice);
  
  while(choice!=2)
  {
    //Get input for box 1 dimensions
    cout << "\nFor box 1:" << endl;
    getInput(ht, wt, lngth);
    box1.setBox(ht, wt, lngth);
    
    //Get input for box 2 dimensions
    cout << "\nFor box 2:" << endl;
    getInput(ht, wt, lngth);
    box2.setBox(ht, wt, lngth);
    
    box box3(4, 5, 6); //Declare and initiliaze using constructor
    box box4(box3);    //Declare and initiliaze using copy constructor
    
    box5 = box1 + box3;
    box6 = box2 + box4;
    
    //Output all boxes
    cout << endl;
    box1.print();
    cout << endl;
    box2.print();
    cout << endl;
    box3.print();
    cout << endl;
    box4.print();
    cout << endl;
    cout << "After adding, the boxes are of the size:" << endl;
    box5.print();
    cout << endl;
    box6.print();
    cout << endl;
    cout << "Is box 5 > box 6? (0 = false, 1 = true) ---> "
         << (box5>box6) << endl << endl;

    //Display menu and get user's choice
    menu(choice);
  }


  return 0;
}









