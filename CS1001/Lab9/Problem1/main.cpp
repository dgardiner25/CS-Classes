#include <iostream>

#include "list.h"

using namespace std;

int main()
{
  List nums(0);
  const int max_val = 5;

  // Add some numbers to the list
  for (unsigned int i = 1; i <= max_val; i++)
  {
    nums.append(i);
  }

  nums.print();

  cout << "Press enter to continue...";
  cin.get();

  // Double the list
  List* nums_copy = new List(nums);

  cout << "The list, doubled: " << endl;
  nums.extend(nums_copy);
  nums.print();

  delete nums_copy;

  return 0;
}
