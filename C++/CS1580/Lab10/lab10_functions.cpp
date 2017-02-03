/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/26/16
File: lab10_functions.cpp
Description: Function defintions to encrypt a given name using an NTCA.
*/

#include <iostream>
#include <cctype>
#include "lab10.h"
using namespace std;

void greeting()
{
  cout << "Welcome to the Enigma Machine 2.0, now with less security!" << endl;
  return;
}

void getInput(char arr[])
{
  cout << "\n\nEnter your name: ";
  cin.getline(arr, DATA_SIZE-1);
  return;
} 

void encrypt(char arr[])
{
  bool nullFound = false;
  short i = 0;
  short ASCIIVal;
  while(!nullFound)
  {
    ASCIIVal = arr[i];
    if(arr[i] == 0)
      nullFound = true;
    else if(isalpha(arr[i]))
    {
      if(isupper(ASCIIVal) && ASCIIVal < 88)
        arr[i] = ASCIIVal + 3;
      else if(islower(ASCIIVal) && ASCIIVal < 120)
        arr[i] = ASCIIVal + 3;
      else
        arr[i] = ASCIIVal - 23;
    }
    i++;
  }
  return;  
}

void showOutput(char arr[])
{
  cout << arr << endl; 
  return;
}

void signoff()
{
  cout << "\n\nThank you for using the budget Enigma Machine!" << endl;
  return;
}



