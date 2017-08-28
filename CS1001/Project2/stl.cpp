#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <string>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
  ifstream fin(argv[1]);           // Get the file with the words in it
  map<string, int> words;          // map to hold the words and # of it 
  char curr_char;		   // to hold current char
  string curr_word = "";           // to hold current word

  if(argc != 2) // incorrect number of arguments
  {
    cout << "Correct usage: ./[program] [filename]" << endl;
    exit(1);
  }
  while(fin.get(curr_char)) // while still data
  {
    if(isalpha(curr_char)) // make sure only letters are taken in
      curr_word += tolower(curr_char); // change all to lowercase
    else
    {
      if(words.find(curr_word) == words.end()) // If not found in map already
        words[curr_word] = 1;
      else // Already in map
      {
        auto pos = words.find(curr_word); 
        words[curr_word] = pos->second+1; // increase previous number
      }
      curr_word = ""; // reset word
    }
  }

  // output pretty table
  cout << setw(20) << "Word" << setw(20) << "# of Occurences" << endl;
  cout << "----------------------------------------" << endl;
  auto it = words.begin();
  it++; // To get rid of spaces
  for (it; it != words.end(); it++)
  {
    cout << setw(20) << it->first << setw(20) << it->second << endl;
  }

  fin.close();

  return 0;
}
