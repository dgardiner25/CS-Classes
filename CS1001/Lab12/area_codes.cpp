#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  ifstream fin(argv[1]);  // Open an input file stream to the file in argv[1]
  set<int> areaCodes;  // Set holding unique area codes
  set<int> dontUse;    // Set holding already used area codes
  int code;  // Current area code
  string junk;  // Gets rid of stuff we don't want

  if(argc != 2) // Must be 2 arguments
  {
    cout << "Invalid number of arguments!" << endl;
    cout << "Proper use: ./[program] [file]" << endl;
  }
  else if(!fin.is_open()) // If invalid file name
    cout << "Error 404 - File not found" << endl;
  else
  {
    while(fin >> junk) // Get rid of the name
    {
      fin >> code;  // Input area code
      
      // Check if current code is already in the set
      if(areaCodes.find(code) != areaCodes.end()) {
        dontUse.insert(code);
        areaCodes.erase(code);
      }
      if(dontUse.find(code) == dontUse.end()) {
        areaCodes.insert(code);
      }
      fin >> junk; // Get rid of next three nums
      fin >> junk; // Get rid of last four nums
    }

    // Output all of the unique area codes
    for(auto i : areaCodes)
      cout << i << endl;
  }


  return 0;
}
