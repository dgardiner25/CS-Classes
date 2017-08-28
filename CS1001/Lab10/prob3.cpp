#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char *buf = new char[100];
  unsigned int total = 0;
  unsigned int lines = 0;

  while (cin.getline(buf, 100))
  {
    lines++;
    total+=strlen(buf);
    buf = new char[100];
  }
  
  cout << total / lines << endl;

  return 0;
}
