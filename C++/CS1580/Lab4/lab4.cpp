//Programmer: David Gardiner          Date: 09/14/16
//File: lab4.cpp                      Class: CS1580 E
//Instructor: Rushiraj                     
//Purpose: Convert weight on Earth to the weight on
//         another planet of choice.
           

#include <iostream>
using namespace std;

//Conversion factors for Earth to other planet weight
const float WEIGHT_CONVERSION_MARS = 0.39;
const float WEIGHT_CONVERSION_SATURN = 1.17;
const float WEIGHT_CONVERSION_NEPTUNE = 1.23;

//Integer values of planet choices
const short VAL_MARS = 1;
const short VAL_SATURN = 2;
const short VAL_NEPTUNE = 3;


int main()
{
  //Input variableds
  float earthWeight;          //Weight of the user on Earth
  short planetChoice;         //Integer choice of the planet to visit
  char cont;                  //To ask if the user wants to convert again
  
  //Calculated variables
  float planetWeight;         //User's weight on the selected planet

  //Greeting
  cout << "Welcome to the planetary weight calculator." << endl;
  
  do
  {
  //Get user input
  cout << "\nPlease enter your weight in pounds on Earth:       ";
  cin >> earthWeight;
  
  do
  {
  cout << "\nPlanets of known weight conversion:\n"
       << "1. Mars\n" << "2. Saturn\n" << "3. Neptune\n" << endl;
  cout << "Which planet would you like to visit?      ";
  cin >> planetChoice;
  } while(planetChoice<VAL_MARS||planetChoice>VAL_NEPTUNE);
  
  //Convert weight on Earth to the planet of choice
  if(planetChoice==VAL_MARS)
    planetWeight = earthWeight * WEIGHT_CONVERSION_MARS;
  else if(planetChoice==VAL_SATURN)
    planetWeight = earthWeight * WEIGHT_CONVERSION_SATURN;
  else
    planetWeight = earthWeight * WEIGHT_CONVERSION_NEPTUNE;
  
  //Output weight on planet of choice
  cout << "\nYour weight on the planet of choice is " << planetWeight 
       << " pounds." << endl;
  
  //Ask if the user would like to make another conversion
  cout << "\nWould you like to make another conversion? (y/n)       ";
  cin >> cont;
  
  } while(cont=='y' || cont=='Y');    //Check if user wants to continue
  
  //Sign-off
  cout << "\nGood luck!" << endl;
  
  return 0;
}
