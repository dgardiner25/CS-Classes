//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)         Date: 12/4/16
//File: polluter.cpp                                         Class: CS1570 
//Purpose: Implementation of the polluter class.

#include "polluter.h"
using namespace std;

polluter::polluter(const string n, const char spr)
{
  name = n;
  sprite = spr;
  xLocation = DEF_X_POL;
  yLocation = DEF_Y_POL;
  caught = false;
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
  short x_temp;     //Temporary x variable
  short y_temp;     //Temporary y variable
  short direction;  //Random direction to walk in
  
  //Used if activist lands on root
  static short prev_x = 0;
  static short prev_y = 0;
  static bool is_root = false;
  
  if(t.getPoint(xLocation, yLocation)==ACTIVIST_SPRITE)
    caught = true;
  if(!caught)
  {
    x_temp = xLocation;
    y_temp = yLocation;
    direction = rand()%4;
    if(direction == RIGHT)
      y_temp++;
    else if(direction == LEFT)
      x_temp++;
    else if(direction == UP)
      y_temp--;
    else
      x_temp--;
    if(t.getPoint(x_temp, y_temp)==COP_SPRITE) //Runs into cop
    {
      t.setPoint(xLocation, yLocation, ' ');
      xLocation = x_temp;
      yLocation = y_temp;
      t.setPoint(xLocation, yLocation, sprite);
      caught = true;
    }
    else if(t.getPoint(x_temp, y_temp)==ROOT_SPRITE) //Lands on root
    {
      is_root = true;
      prev_x = x_temp;
      prev_y = y_temp;
    }
    if(t.getPoint(x_temp, y_temp)!=WALL_SPRITE && 
       t.getPoint(x_temp, y_temp)!=EXIT_SPRITE &&
       t.getPoint(x_temp, y_temp)!=ACTIVIST_SPRITE && !caught)
    {
      //If previous was root
      if(is_root && (prev_x != x_temp || prev_y != y_temp))
      {
        t.setPoint(xLocation, yLocation, ROOT_SPRITE);
        is_root = false;
      }
      else
        t.setPoint(xLocation, yLocation, ' ');
        
      //Update location
      xLocation = x_temp;
      yLocation = y_temp;
      t.setPoint(xLocation, yLocation, sprite);
    } 
  }

  return;
}
