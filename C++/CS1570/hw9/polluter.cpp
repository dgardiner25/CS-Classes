//Programmer: DAVID GARDINER          Date: 11/14/16
//File: polluter.cpp                  Class: CS1570 A
//Purpose: Implementation of the polluter class.

#include "polluter.h"
using namespace std;

polluter::polluter(const string n)
{
  name = n;
  sprite = POLLUTER_SPRITE;
  xLocation = DEF_X_POL;
  yLocation = DEF_Y_POL;
}

void polluter::place_me(town & t)
{
  short rand_x;
  short rand_y;
  do
  {
    rand_x = rand()%t.getSize()-1;
    rand_y = rand()%t.getSize()-1;
  } while(!(t.getPoint(rand_x, rand_y)==' '));
  xLocation = rand_x;
  yLocation = rand_y;
  t.setPoint(xLocation, yLocation, sprite);
  return;
}

void polluter::rand_walk(town & t)
{
  short direction; //0=North,1=East,2=South,3=West
  short x_temp;
  short y_temp;
  t.setPoint(xLocation, yLocation, ' ');
  do
  {
    direction = rand()%4;
    x_temp = xLocation;
    y_temp = yLocation;
    if(direction == 0)
      y_temp++;
    else if(direction == 1)
      x_temp++;
    else if(direction == 2)
      y_temp--;
    else
      x_temp--;
  } while(t.getPoint(x_temp, y_temp)=='W' || t.getPoint(x_temp, y_temp)=='E' || 
          t.getPoint(x_temp, y_temp)==ACTIVIST_SPRITE);
  xLocation = x_temp;
  yLocation = y_temp;
  t.setPoint(xLocation, yLocation, sprite);
  return;
}
