//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)         Date: 12/4/16
//File: polluter.h                                           Class: CS1570 
//Purpose: Definition of the polluter class.

#ifndef POLLUTER_H
#define POLLUTER_H

#include <string>
#include "town.h"
using namespace std;

//Default values
const short DEF_X_POL = -1;
const short DEF_Y_POL = -1;

class polluter
{
  private:
    string name;      //Holds the name of the object
    short xLocation;  //Current x-coordinate of the object
    short yLocation;  //Current y-coordinate of the object
    char sprite;      //The sprite to represent the object
    bool caught;      //If polluter is caught by a cop
  public:
    //Description: The default constructor for the polluter class.
    //Pre: None.
    //Post: name has been set to n, sprite has been set to spr,
    //      xLocation has been set to DEF_X_POL, and yLocation has been set to
    //      DEF_Y_POL. 
    polluter(const string n, const char spr = POLLUTER_SPRITE);
    //Description: The place_me() function randomly sets the location of and 
    //places the object in the of the town, avoiding other objects and walls.
    //Pre: None.
    //Post: The object is set to a random location in the town.
    void place_me(town & t);
    //Description: The rand_move() function chooses a random direction to move
    //             in, freezes the object for the turn if it hits a wall, and
    //             freezes the object for the rest of the day if it runs into
    //             a cop.
    //Pre: None
    //Post: The object moves in a random direction, avoiding other entities.
    void rand_walk(town & t);
    //Description: The getX() function returns the x-location of the object.
    //Pre: None.
    //Post: The x-location of the calling object is returned.
    short getX() {return xLocation;}
    //Description: The getY() function returns the y-location of the object.
    //Pre: None.
    //Post: The y-location of the calling object is returned.
    short getY() {return yLocation;}
};

#endif
