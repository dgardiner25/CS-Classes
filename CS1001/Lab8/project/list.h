#include <cstddef>
#include <iostream>

using namespace std;

class List
{
public:
  // Constructor
  List(int v);

  // Copy Constructor
  List(const List &copy);

  // Destructor
  ~List();

  // Append a new node to the linked list
  void append(int v);

  // Append a linked list to the end of this list
  void extend(List *e);

  // Print out the list
  void print() const;

  // Sum the values in the list
  int sum() const;

  // Getters
  int value() const { return val; };
  List *next() const { return nxt; };

private:
  // Get the last item in the linked list
  List *last();

  int val;
  List *nxt;
};
