/* Program: Filter
 * Author: Jake the Dog
 * Purpose: For filtering commented lines from STDIN
 */
#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    // Make a buffer to store each line as we read them
    string buffer;

    // Read lines until we reach EOF
    while (getline(cin, buffer))
    {
      // Find the first non-whitespace char in the string
      int i = 0;
      while (i < buffer.length() && isspace(buffer[i]))
      {
        i++;
      }

      // Check the first non-whitespace char. It's not always 0!
      if (buffer[i] != argv[1])
      {
        // Print out the lines that **don't** start with the input ignore char
        cout << buffer << endl;
      }
    }
  }

  // All done
  return 0;
}
