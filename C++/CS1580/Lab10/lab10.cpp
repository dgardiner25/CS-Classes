/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/26/16
File: lab10.cpp
Description: Encrypt a given name using an NTCA. 
*/

#include <iostream>
#include "lab10.h"
using namespace std;

int main()
{
  char choice;  //The user's choice to continue or not
    
  //Initialize the character array that will hold user's name
  char name[DATA_SIZE];
  
  //Greet the user
  greeting();
  
  do
  {
    //Get input from user
    getInput(name);
  
    //Output the NTCA
    cout << "Your name is: ";  
    showOutput(name);
    
    //Encrypt the NTCA
    encrypt(name);
  
    //Output the encryped NTCA
    cout << "Your encrypted message is: "; 
    showOutput(name);
    
    cout << "Would you like to continue? (y/n) ";
    cin >> choice;
    
    //Clear the buffer
    cin.ignore(50, '\n');
    
  } while(choice != 'n' && choice!= 'N');
  
  //Output sign-off
  signoff();
  
  return 0;
}
