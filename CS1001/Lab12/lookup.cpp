#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <tuple>
using namespace std;

// Prints out the passed string and tuple
void print(string name, tuple<int,int,int>);

int main(int argc, char* argv[])
{
  ifstream fin(argv[1]);  // Open an input file stream to the file in argv[1]
  map<string, tuple<int, int, int>> person;  // Map to hold each name and number
  string toFind;  // Optional name to look up in the phonebook
  string name;  // Name of current line
  int areaCode;   // Area code of current line
  int firstThree;  // First three numbers of the current line
  int lastFour;   // Last four numbers of the current line
  bool found = false;  // Used to see if optional person was found or not

  if(argc == 1 || argc > 3)  // Make sure corrent number of arguments
  {
    cout << "Invalid number of arguments!" << endl;
    cout << "Proper use: ./[program] [file] [name to find (optional)]" << endl;
  }
  else if(!fin.is_open())  // If file not found
    cout << "Error 404 - File not found" << endl;
  else
  {
    while(fin >> name) // While there is still data
    {
      fin >> areaCode;
      fin >> firstThree;
      fin >> lastFour;

      // Create entry for current person in map
      person[name] = make_tuple(areaCode, firstThree, lastFour);
    }
  }
  if(argc == 3) // If trying to find specific person
  {
    toFind = argv[2];
    // Loop through all of the map
    for (auto it = person.begin(); it != person.end(); it++)
      if(it->first == toFind) // If found person
      {
        found = true;
        print(it->first, it->second); // Just print person
      }
    if(!found) // Print all phonebook if not found
      for (auto it = person.begin(); it != person.end(); it++)
        print(it->first, it->second);
  }
  else // If not trying to find a person
  {
    // Print all the phonebook
    for (auto it = person.begin(); it != person.end(); it++)
      print(it->first, it->second);
  }
  return 0;
}


void print(string name, tuple<int, int, int> tup)
{
  // Prints the name and number of the person like 'name: (###) ###-####'
  cout << name << ": (" << get<0>(tup) << ") " << get<1>(tup) << "-";
  if(get<2>(tup) < 1000)
    cout << "0";
  cout << get<2>(tup) << endl;
}
