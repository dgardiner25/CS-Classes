/*
Programmer: David Gardiner
Instructor: Rushiraj
Section: E
Date: 09/07/16
Description: Calculate BMI given height and weight
*/

#include <iostream>
using namespace std;

const short CONVERSION_FACTOR = 703;    //For BMI conversion

int main() 
{
  //User input
  short height, mass;
  
  //Calculated value
  float bmi;

  //Greeting
  cout << "This is the BMI calculator." << endl;
  
  //Get input
  cout << "Enter your weight to the nearest pound:    ";
  cin >> mass;
  
  cout << "Enter your height to the nearest inch:    ";
  cin >> height;
  
  //BMI calculation
  bmi = static_cast<float>(mass * CONVERSION_FACTOR) / (height * height);
  
  //Output
  cout << "Your BMI given a weight of " << mass << " pounds and a height of "
       << height << " inches is " << bmi << "." << endl;
  
  return 0;
}
