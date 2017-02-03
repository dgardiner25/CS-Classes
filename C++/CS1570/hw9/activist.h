//Programmer: DAVID GARDINER          Date: 11/14/16
//File: activist.h                    Class: CS1570 A
//Purpose: Definition of the activist class.

#ifndef ACTIVIST_H
#define ACTIVIST_H

#include <string>
#include "town.h"
using namespace std;

//Min and max toxicity allowed
const float MIN_TOXICITY = 0.0;
const float MAX_TOXICITY = 3.0;

//Min and max dignity allowed
const short MIN_DIGNITY = 0;
const short MAX_DIGNITY = 100;

//Default values
const float DEF_TOX = 0.05;
const short DEF_DIG = 100;
const short DEF_X_ACT = -1;
const short DEF_Y_ACT = -1;
const short DEF_STATE = 0;

class activist
{
  private:
    float toxicity;     //Holds the toxicity of the object
    short dignity;      //Holds the dignity of the object
    short xLocation;    //Current x-coordinate of the object
    short yLocation;    //Current y-coordinate of the object
    char sprite;        //The sprite to represent the object
    short state;        //-1 is gone, 0 is normal, 1 is cool
    string name;        //Holds the name of the object
  public:
    //Description: Default constructor for the activist class.
    //Pre: None.
    //Post: toxicity has been set to DEF_TOX, dignity has been set to DEF_DIG,
    //      xLocation has been set to DEF_X_ACT, yLocation has been set to 
    //      DEF_Y_ACT, sprite has been set to spr, and name has been set to n.
    activist(const char spr, const string n);
    //Description: The setToxicity() function sets toxicity to f.
    //Pre: f must be within MIN_TOXICITY and MAX_TOXICITY.
    //Post: toxicity is set to f or the program exits.
    void setToxicity(float f);
    //Description: The setDignity() function sets dignity to s.
    //Pre: s must be within MIN_DIGNITY and MAX_DIGNITY.
    //Post: dignity is set to s or the program exits.
    void setDignity(short s);
    //Description: The place_me() function sets the location of and places the 
    //             object in the middle of the town, based on the size of the 
    //             town.
    //Pre: None.
    //Post: The location of the object is set to the middle of the town and the
    //      object is placed in the town.
    void place_me(town & t);
    //Description: The rand_move() function chooses a random direction to move
    //             in, avoids walls and other objects, and udpates the 
    //             location of the object.
    //Pre: None
    //Post: The object moves in a random direction, avoiding other entities.
    void rand_walk(town & t);
    //Description: The operator<<() function displays the object's name, 
    //             toxicity, dignity, location, and state.
    //Pre: None.
    //Post: The object's name, toxicity, dignity, location, and state are
    //      output to the screen.
    friend ostream& operator<<(ostream & o, const activist & a);
};

#endif
