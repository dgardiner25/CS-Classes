//Programmer: DAVID GARDINER               Date: 4/2/2017
//File: heist.cpp                          Class: 1510 C
//Purpose: Help Bender find his way out of the heist.

#include <iostream>
#include <cstring>
using namespace std;

const short QUIT_VAL = 0;
const char PLAYER_CHAR = 'B';
const char EXIT_CHAR = 'E';
const char TRAP_CHAR = 'T';
const char WALL_CHAR = '#';
const char PATH_CHAR = '.';

// Description: Backtracking function to solve a maze;
// Pre: start_x and start_y must be within maze.
// Post: The maze is solved and the correct path is noted by '*'.
bool find_path(char **maze, short start_x, short start_y);

// Description: Print the map.
// Pre: maze must be of size_x and size_y or larger.
// Post: The map is output to the screen.
void print_map(char **maze, short size_x, short size_y);

int main()
{
  short map_x;                // # of map rows
  short map_y;                // # of map columns
  short bender_x;             // starting row of Bender
  short bender_y;             // starting column of Bender
  short map_count = 0;        // keeps track of # of maps for output

  char **map;                 // current map from input

  // Get map dimensions
  cin >> map_x >> map_y;
  cin.ignore();

  while(map_x != QUIT_VAL && map_y != QUIT_VAL)
  {
    // Allocate memory for map
    map = new char*[map_x];
    for(int i=0; i < map_x; i++){
      map[i] = new char[map_y];
    }

    // Read in the map
    char newline;
    for(int i=0; i < map_x; i++){
      for(int j=0; j < map_y; j++){
        cin.get(map[i][j]);
        if(map[i][j] == PLAYER_CHAR) // Figure out where Bender is
        {
          bender_x = i;
          bender_y = j;
        }
      }
      cin.get(newline) // To get rid of newlines
    }

    // If a path can be found
    if(find_path(map, bender_x, bender_y))
    {
      cout << "\nMap " << map_count << ":" << endl;
      print_map(map, map_x, map_y);
      cout << endl;
    }
    else
      cout << "No path to exit!" << endl;

    map_count++;

    // Deallocate memory
    for(int i=0; i < map_x; i++){
      delete[] map[i];
    }
    delete[] map;

    // Get next map dimensions
    cin >> map_x >> map_y;
    cin.ignore();

  }

  return 0;
}

bool find_path(char **maze, short start_x, short start_y)
{
  // N = 1, E = 2, S = 3, W = 4
  bool solved;
  short curr_x = start_x;
  short curr_y = start_y;
  short i = 0;
  // Loop through for all directions
  while(i<4)
  {
    switch(i)
    {
      case 0:
        curr_x--;
        break;
      case 1:
        curr_y++;
        break;
      case 2:
        curr_y--;
        break;
      case 3:
        curr_x++;
        break;
    }
    // If new pos is valid
    if(maze[curr_x][curr_y] == ' ' || maze[curr_x][curr_y] == EXIT_CHAR)
    {
      // If new pos is the exit
      if(maze[curr_x][curr_y] == EXIT_CHAR)
        return true;
      else
      {
        maze[curr_x][curr_y] = PATH_CHAR;
        // Backtracking
        solved = find_path(maze, curr_x, curr_y);
        if(solved)
        {
          if(maze[start_x][start_y] != PLAYER_CHAR)
            maze[start_x][start_y] = PATH_CHAR;
          return true;
        }
        else
        {
          maze[start_x][start_y] = ' ';
        }
      }
    }
    // Undo direction change
    else
    {
      curr_x = start_x;
      curr_y = start_y;
    }
    i++;
  }
  if(maze[curr_x][curr_y] == PATH_CHAR)
    maze[curr_x][curr_y] = ' ';
  return false;
}

void print_map(char **maze, short size_x, short size_y)
{
  for(int i=0; i < size_x; i++){
    for(int j=0; j < size_y; j++){
      cout << maze[i][j];
    }
    cout << endl;
  }
}
