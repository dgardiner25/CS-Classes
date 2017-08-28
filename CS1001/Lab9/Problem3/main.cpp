#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
  Vector* vect = new Vector;

  for (int i = 0; i < 10; i++)
  {
    vect->push_back(i);
  }

  Vector* copy = new Vector(*vect);

  for (int i = 0; i < 10; i++)
  {
    cout << (*copy)[i] << endl;
  }
  
  delete vect;
  delete copy;

  return 0;
}
