//Programmer: David Gardiner               Date: 1/28/2017
//File: fishbomb.h                         Class: 1510 C
//Purpose: Declarations of fishbomb functions.

#ifndef FISHBOMB_H
#define FISHBOMB_H

#include <iostream>
using namespace std;

//------ CONSTANTS ------//
const int EXPLOSION_RADIUS = 5;        //Explosion radius of dynamite
const int NUM_DYNAMITE = 3;            //Number of dynamite sticks thrown

//------ DECLARATIONS ------//
//Description: The runTest() function gets input from the user for how big
//             the grid of fish will be, allocates memory, gets the
//             of where to throw the dynamite, calculates # of fish
//             caught, outputs # caught, and deallocates memory.
//Pre: None.
//Post: The number of fish caught by Bender is output.
void runTest(const int current_test);

//Description: The allocateMem() function allocates the amount of memory
//             required for the grid.
//Pre: None.
//Post: The double 2D-array of correct size is returned.
int **allocateMem(const int h, const int w);

//Description: The deallocateMem() function deallocates the memory stored
//             in the passed 2D-array.
//Pre: None.
//Post: The memory is deallocated.
void deallocateMem(int **arr, const int h);

#endif
