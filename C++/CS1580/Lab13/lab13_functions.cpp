/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/16/16
File: lab13_functions.cpp
Description: Function definitions for lab13.h
*/

#include "lab13.h"
using namespace std;

//------Function Definitions------//
void getInput(int & h, int & w, int & l)
{
  cout << "Please enter the height of the box: ";
  cin >> h;
  cout << "Please enter the width of the box: ";
  cin >> w;
  cout << "Please enter the length of the box: ";
  cin >> l;
  return;
}


void menu(int & choice)
{
  do
  {
    cout << "What would you like to do?" << endl
         << "1. Compare 2 boxes" << endl
         << "2. Quit" << endl
         << "Select an option (1 or 2): ";
    cin >> choice;
    
    if(choice!=1 && choice !=2)
      cout << "Invalid option!" << endl;
  } while(choice!=1 && choice !=2);
  return;
}
