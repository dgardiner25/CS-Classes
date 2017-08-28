#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
  LinkedList<int> l;
  l.insert_front(1);
  l.insert_back(2);
  l.insert_back(3);
  l.insert_back(4);
  l.insert_back(5);
  l.insert_back(6);

  cout << l << endl;

  l.remove_back();
  //l.insert_back(7);
  cout << l << endl;

  return 0;
}
