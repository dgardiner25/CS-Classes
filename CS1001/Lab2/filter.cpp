#include <iostream>
using namespace std;

int main() {
  string line;
  string story = "";
  while(getline(cin, line) && line[0]!='E')
    if(line[0]!='#')
      story += (line+"\n");
  cout << story << endl;

  return 0;
}
