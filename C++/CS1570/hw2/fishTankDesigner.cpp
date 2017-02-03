//Programmer: David Gardiner          Date: 09/04/16
//File: fishTankDesigner.cpp          Class: CS1570 A
//Purpose: Determine the dimensions of a fish tank, the volume of the
//         tank and the volume of water that can go in said tank, the number 
//         of fish that can go in the tank, and the mass of nuclear waste to 
//         add to the tank to keep the fish alive given the length of the tank.

#include <iostream>
using namespace std;

const float GAL_PER_CUBIC_FOOT = 7.48;	//Gallons of water per cubic foot
const float HEIGHT_MODIFIER = 2.0/3;    //For converting length to height

const short WIDTH_MODIFIER = 4;   //For converting length to width
const short FISH_BY_VOL = 25;    //To determine number of fish in tank
const short FEET_TO_INCH = 12;    //To change from feet to inches
const short LIFE_FACTOR = 11;		//Amount of nuclear waste needed
const short GAL_FOOD_FOR_FISH = 2;	//Gallons of food if freak fish present

int main()
{
  //User inputted values
  short length;
  bool freakFishPresent;
	
  //Calculated values
  short width, height, numFish;
  float volTank, volWater, wasteNeeded;
	
  //Greeting
  cout << "Welcome to the Fish Tank Designer 3000!" << endl;
	
  //Get user input
  cout << "\nEnter the length of the tank (to the nearest foot):        ";
  cin >> length;
	
  cout << "Will there be freak fish present in the tank? " 
       << "(0 for no, 1 for yes):       ";
  cin >> freakFishPresent;
	
  //Calculations 
  //Dimensions of the tank
  width = length / WIDTH_MODIFIER;
  height = length * HEIGHT_MODIFIER;
  volTank = length * width * height * GAL_PER_CUBIC_FOOT;
	
  //Amount of water to go in the tank
  volWater = volTank - (GAL_FOOD_FOR_FISH * freakFishPresent);
	
  //Number of fish that can go in the tank
  numFish = volWater / FISH_BY_VOL;
	
  //Amount of radioactive waste needed to keep the fish alive
  wasteNeeded = static_cast<float>(LIFE_FACTOR) / (height * FEET_TO_INCH);
	
	
  //Output of values
  cout << "\nThe values of your tank are:"
  << "\nLength: " << length << " ft"
  << "\nWidth: " << width << " ft"
  << "\nHeight: " << height << " ft"
  << "\nVolume of tank: " << volTank << " gallons"
  << "\nAmount of water to go in tank: " << volWater << " gallons"
  << "\nWaste needed: " << wasteNeeded << " rads"
  << "\nNumber of fish the tank can hold: " << numFish << " fish\n\n";
	
  //Sign-off
  cout << "Enjoy your new pets!" << endl;
	
  return 0;
}

	
