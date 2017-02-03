//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)       Date: 12/4/16
//File: activist.h                                         Class: CS1570
//Purpose: Definition of the activist class.

#ifndef ACTIVIST_H
#define ACTIVIST_H

#include <string>
#include "town.h"
#include "root.h"
#include "polluter.h"
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

const float COOL_TOX = 0.08;
const float GONE_TOX = 0.25;

class activist
{
  private:
    float toxicity;     //Holds the toxicity of the object
    short dignity;      //Holds the dignity of the object
    short xLocation;    //Current x-coordinate of the object
    short yLocation;    //Current y-coordinate of the object
    char sprite;        //The sprite to represent the object
    short state;        //-1 is normal, 0 is cool, 1 is gone
    bool active;        //If activist is active
    string name;        //Holds the name of the object
  public:
    //Description: Default constructor for the activist class.
    //Pre: None.
    //Post: toxicity has been set to DEF_TOX, dignity has been set to DEF_DIG,
    //      xLocation has been set to DEF_X_ACT, yLocation has been set to
    //      DEF_Y_ACT, sprite has been set to spr, and name has been set to n.
    activist(const string n, const char spr = ACTIVIST_SPRITE);
    //Description: The setToxicity() function sets toxicity to f.
    //Pre: f must be within MIN_TOXICITY and MAX_TOXICITY.
    //Post: toxicity is set to f or the program exits.
    void setToxicity(float f);
    //Description: The setDignity() function sets dignity to s.
    //Pre: s must be within MIN_DIGNITY and MAX_DIGNITY.
    //Post: dignity is set to s or the program exits.
    void setDignity(short s);
    //Description: The getActive() function returns the active state of the
    //             calling object.
    //Pre: None.
    //Post: The state of active is returned.
    bool getActive() {return active;}
    //Description: The place_me() function sets the location of and places the
    //             object in the middle of the town, based on the size of the
    //             town.
    //Pre: None.
    //Post: The location of the object is set to the middle of the town and the
    //      object is placed in the town.
    void place_me(town & t);
    //Description: The walk() function moves the activist, either randomly or
    //             follows the polluter and updates stats.
    //Pre: None.
    //Post: The object moves and stats are updated.
    void walk(town & t, const short roots, const root roots_arr[],
              const short d_wall, const short d_cop, polluter & p,
              const short d_counter, const short max_days);
    //Description: The outputStats() function displays the stats at the end of
    //             the simulation.
    //Pre: days must not equal 0.
    //Post: The stats of the simulation are output to the screen.
    void outputStats(const short days, const short exits,
                     const short wacked, const short p_catch,
                     const short d_low, const float total_t);
    //Description: The operator<<() function displays the object's name,
    //             toxicity, dignity, location, and state.
    //Pre: None.
    //Post: The object's name, toxicity, dignity, location, and state are
    //      output to the screen.
    friend ostream& operator<<(ostream & o, const activist & a);
    //Description: The operator+() function adds the effect of a root to
    //             the toxicity of the calling object.
    //Pre: None.
    //Post: The calling object's toxicity is changed.
    void operator+(root r) {toxicity += r.getEffect(); return;}
};

#endif
