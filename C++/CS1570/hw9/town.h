//Programmer: DAVID GARDINER          Date: 11/14/16
//File: town.h                        Class: CS1570 A
//Purpose: Definition of the town class.

#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <cstdlib>
using namespace std;

//Max town size allowed
const short MIN_TOWN_SIZE = 5;
const short MAX_TOWN_SIZE = 25;

//Sprites to represent the objects
const char ACTIVIST_SPRITE = 'A';
const char POLLUTER_SPRITE = 'P';

class town
{
  private:
    char grid[MAX_TOWN_SIZE][MAX_TOWN_SIZE]; //Holds the town
    short actual_size;                       //The size of the town
    //Description: The clear() function clears grid.
    //Pre: None.
    //Post: The elements are set to spaces.
    void clear();
    //Description: The build() function creates the walls of the town with
    //             exits in the middle of each.
    //Pre: None.
    //Post: Walls and exits are created within the town.
    void build();         
  public:
    //Description: The default constructor for the town class.
    //Pre: None.
    //Post: actual_size is set to size and clear() and build() are called.
    town(const short size);
    //Description: The getSize() function returns the size of the town.
    //Pre: None.
    //Post: The size of the town is returned.
    short getSize() const;
    //Description: The setSize() function sets actual_size to size.
    //Pre: size must be within MAX_TOWN_SIZE.
    //Post: The actual_size of the town is set to size or the program ends.
    void setSize(const short size);
    //Description: The getPoint() function returns the character at the
    //             given location.
    //Pre: None.
    //Post: The character at the given location is returned.
    char getPoint(const short row, const short col) const;
    //Description: The setPoint() function sets the point at the given
    //             location to the passed character.
    //Pre: None.
    //Post: The point at location (x,y) is changed.
    void setPoint(const short x, const short y, const char c);
    //Description: The operator<<() function displays the walls of the town
    //             and the objects inside.
    //Pre: None.
    //Post: The town is output to the screen.
    friend ostream& operator<<(ostream & o, const town & t);
};

#endif
