//Programmer: David Gardiner               Date: 1/28/2017
//File: fishbomb.cpp                       Class: 1510 C
//Purpose: Help Bender figure out how many fish he will catch by throwing
//         sticks of dynamite in various locations.

#include <iostream>
using namespace std;

//------ CONSTANTS ------//
const int EXPLOSION_RADIUS = 5;        //Explosion radius of dynamite
const int NUM_DYNAMITE = 3;            //Number of dynamite sticks thrown

int main()
{
  //Declarations
  int num_tests;                     //Number of tests the user would like to do
  int num_caught;                    //Number of fish caught
  int height;                        //Height of the grid
  int width;                         //Width of the grid
  int **grid;                        //Dynamic 2D array representing the grid
  int expl_loc[NUM_DYNAMITE][2];     //Location of each explosion (row,col)

  cin >> num_tests;

  for(int i=0; i<num_tests; i++)
  {
    num_caught = 0;
    
    //Get height and weight
    cin >> height;
    cin >> width;

    //Allocate memory
    grid = new int*[height];
    for(int j=0; j<height; j++)
      grid[j] = new int[width];

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
    cout << "Test #" << i + 1 << ": Bender catches " << num_caught
         << " fish." << endl;
         //Deallocate memory

    for(int j=0; j<height; j++)
      delete[] grid[j];
    delete[] grid;
    grid = NULL;
  }

  return 0;
}
