//Programmer: DAVID GARDINER          Class: CS1570 A    
//Original Creator: JENNIFER LEOPLD  Modified: 11/14/16 
//File: driver.cpp                    
//Purpose: Test drive the activist, polluter, and town classes.

#include <ctime>
#include "town.h"
#include "activist.h"
#include "polluter.h"
using namespace std;
                                                   
// # of random moves by the activist & polluter to test
const int NUM_RANDOM_MOVES = 4;
                                                  
// Town's grid size
const short TOWN_SIZE = 7;
                                                   
                             
int main()
{
  cout << "\nTesting will now begin...\n";
                                               
  // Seed the random number generator
  srand(time(NULL));
                                               
  //*** Test construction of Town
  town springfield(TOWN_SIZE);
  cout << "\nTown initially looks like this:\n";
  cout << springfield << endl;
                                                                
                                                               
  //*** Test construction and functionality of Activist & Town
  activist lisa(ACTIVIST_SPRITE, "Lisa");
  cout << "\nActivist initially looks like this:\n";
  cout << lisa << endl;
                                                                    
  lisa.place_me(springfield);
  cout << "\nAfter placing Activist in middle of town:\n";
  cout << springfield << endl;
                              
  cout << "Here are " << NUM_RANDOM_MOVES 
       << " moves by the Activist:\n";
  for (int i = 1; i <= NUM_RANDOM_MOVES; i++)
  {
    lisa.rand_walk(springfield);
    cout << springfield << endl;
  }
                                                                                        
  //*** Test construction and functionality of Polluter & Town
  polluter homer("Homer");
  homer.place_me(springfield);
  cout << "Town after randomly placing a Polluter:\n";
  cout << springfield << endl;
                                                                                                     
  cout << "Here are " << NUM_RANDOM_MOVES 
       << " moves by the Polluter:\n";
  for (int i = 1; i <= NUM_RANDOM_MOVES; i++)
  {
     homer.rand_walk(springfield);
     cout << springfield << endl;
  }
                                                                                                                              
  cout << "That concludes our tests.\n";
                                                                                                                                         
  return 0;
}                                                                                                                                           
