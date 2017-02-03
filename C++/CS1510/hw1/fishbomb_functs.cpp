//Programmer: David Gardiner               Date: 1/28/2017
//File: fishbomb_functs.cpp                Class: 1510 C
//Purpose: Definitions of fishbomb functions.

#include "fishbomb.h"
using namespace std;

//------ DEFINITIONS ------//
void runTest(const int current_test)
{
  //Declarations
  int num_caught = 0;                 //Number of fish caught
  int height;                         //Height of the grid
  int width;                          //Width of the grid
  int **grid;                         //Dynamic 2D array representing the grid
  int expl_loc[NUM_DYNAMITE][2];      //Location of each explosion (row,col)

  //Get height and weight
  cin >> height;
  cin >> width;

  //Allocate memory
  grid = allocateMem(height, width);

  //Get sonar data of fish
  for(int j=0; j<height; j++)
    for(int k=0; k<width; k++)
      cin >> grid[j][k];

  //Get dynamite locations
  for(int j=0; j<NUM_DYNAMITE; j++)
    for(int k=0; k<2; k++)
      cin >> expl_loc[j][k];

  //Tally up number of fish "caught"
  for(int b=0; b<NUM_DYNAMITE; b++)
    for(int j=0; j<EXPLOSION_RADIUS; j++)
      for(int k=0; k<EXPLOSION_RADIUS; k++)
      {
        num_caught += grid[expl_loc[b][0]-2+j][expl_loc[b][1]-2+k];
        grid[expl_loc[b][0]-2+j][expl_loc[b][1]-2+k] = 0;
      }

  //Output number of fish "caught"
  cout << "Test #" << current_test + 1 << ": Bender catches " << num_caught
       << " fish." << endl;

  //Deallocate memory
  deallocateMem(grid, height);
}

int **allocateMem(const int h, const int w)
{
  int **arr;
  arr = new int*[h];
  for(int j=0; j<h; j++)
    arr[j] = new int[w];
  return arr;
}

void deallocateMem(int **arr, const int h)
{
  for(int j=0; j<h; j++)
    delete[] arr[j];
  delete[] arr;
  arr = NULL;
}
