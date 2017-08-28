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
  List *nums_copy = new List(nums);

  nums.extend(nums_copy);
  nums.print();

  // Sum up some stuff
  cout << "List sum: " << nums.sum() << endl;
  cout << "Should be " << max_val *(max_val + 1) << endl;

  return 0;
}
