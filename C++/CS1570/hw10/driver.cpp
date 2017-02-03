//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)         Date: 12/4/16
//File: driver.cpp                                           Class: CS1570 
//Purpose: Driver for simulation.

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include "town.h"
#include "activist.h"
#include "polluter.h"
#include "root.h"
using namespace std;

//Description: The simulation() function simulates a day in which
//             an activist chases a polluter.
//Pre: None.
//Post: A day is run.
void simulation(const short size, const short roots, const short cops,
                const short days, const short d_wall, const short d_cop);  
                                                   
int main()
{
  //Simulation parameters
  short grid_size;       //Size of the town
  short num_roots;       //Number of roots in the town
  short num_cops;        //Number of cops in the town
  short num_days;        //Number of days to run the simulation
  short d_wall_loss;     //Loss of dignity for bumping into a wall
  short d_cop_loss;      //Loss of dignity for making an excuse to a cop
  
  
  //Connect to the config file
  ifstream fin("config.dat");

  //Seed the RNG
  srand(time(NULL));
  
  fin >> grid_size;
  fin >> num_roots;
  fin >> num_cops;
  fin >> num_days;
  fin >> d_wall_loss;
  fin >> d_cop_loss;  
  
  for(int i=0; i<num_days; i++)
    simulation(grid_size, num_roots, num_cops, num_days, d_wall_loss, 
               d_cop_loss);
  return 0;
}

void simulation(const short size, const short roots, const short cops,
                const short days, const short d_wall, const short d_cop)
{ 
  static bool first_time = true;            //For outputting only the first day
  static short day_counter = 1;             //Running count of days
  town springfield(size, cops);             //Create town
  activist lisa("Lisa", ACTIVIST_SPRITE);   //Create activist
  polluter homer("Homer", POLLUTER_SPRITE); //Create polluter
  root root_arr[MAX_ROOTS];
  
  //Place activist
  lisa.place_me(springfield);
  //Place polluter
  homer.place_me(springfield);
  
  //Place roots
  for(int i=0; i<roots; i++)
    root_arr[i].place_root(springfield);
  
  if(first_time)
    cout << springfield << endl; //Pre-sim town

  //Characters stepping
  do
  {
    lisa.walk(springfield, roots, root_arr, d_wall, d_cop, homer, day_counter,
              days);      
    homer.rand_walk(springfield);      
    if(first_time)
    {
      cout << springfield << endl;    
      usleep(500000);
    }
  } while(lisa.getActive() && day_counter<days);
  day_counter++;
  first_time = false;
  return;
}







                                                                                                                                           
