//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)         Date: 12/4/16
//File: root.h                                               Class: CS1570 
//Purpose: Definition of the root class.

#ifndef ROOT_H
#define ROOT_H

#include <string>
#include <cstdlib>
#include <ctime>
#include "town.h"
using namespace std;

const float MIN_NEG_EFFECT = -.01;
const float MAX_NEG_EFFECT = -.001;
const float MIN_POS_EFFECT = .05;
const float MAX_POS_EFFECT = .1;

const short MAX_ROOTS = 20;

class root
{
  private:
    string description;  //Name of root
    float effect;        //Negative is square, positive is truffle
  public:
    //Description: Default constructor for the root class;
    //Pre: None.
    //Post: A randomly chosen effect is assigned to the object.
    root();
    //Description: The place_root() function places the calling object in the
    //             town.
    //Pre: None.
    //Post: The calling object is placed in the town.
    void place_root(town & t);
    //Description: The getEffect() function returns the effect of the object.
    //Pre: None.
    //Post: The effect of the calling object is returned.
    float getEffect();
};

#endif
