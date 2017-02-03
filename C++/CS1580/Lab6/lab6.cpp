/*
Programmer: David Gardiner
Instructor: Rushiraj
Section: E
Date: 09/28/16
Description: Calculate area of a circle
*/

#define _USE_MATH_DEFINES       //To use pi from cmath
#include <iostream>
#include <cmath>
using namespace std;

//--------Function Prototypes---------

//Description: Greeting message is output to the screen
//Pre: None
//Post: Greeting message is output to the screen void 
void greeting();

//Description: Read a user input for radius and make sure it is positive.
//             If it is negative, keep asking until it is positive
//Pre: None
//Post: A non-negative radius is returned float
float getRadius(); 

//Description: Calculate and return the area of the circle
//Pre: the parameter radius must be positive 
//Post: Area of the circle is returned. 
float calcArea(float rad); 

//Description: The radius and the area are output on the screen
//Pre: None
//Post: The radius and the area are output on the screen 
void printResult(float rad, float area); 

//Description: A signoff message is output on the screen
//Pre: None
//Post: A signoff message is output on the screen 
void signoff(); 

int main()
{
  //User input
  float radius;
  
  //Calculated
  float area;
  
  //Greet user
  greeting();
  
  //Get radius of circle from user
  radius = getRadius();
  
  //Calculate area
  area = calcArea(radius);
  
  //Output result
  printResult(radius, area);
  
  //Signoff
  signoff();

  return 0;
}

void greeting()
{
  cout << "Welcome to the area of a circle calculator" << endl;
  return;
}

float getRadius()
{
  float rad;
  do
  {
    cout << "\nEnter a positive radius: ";
    cin >> rad;
  }while(rad<=0);
  return rad;
}

float calcArea(float rad)
{
  float area = M_PI * rad * rad;
  return area;
}

void printResult(float rad, float area)
{
  cout << "\nThe area of a circle with radius " << rad
       << " is " << area << endl;
}

void signoff()
{
  cout << "Thank you for using the calculator, have a good day!" << endl;
}













