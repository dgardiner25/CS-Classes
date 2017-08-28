#include "vector.h"

// Constructor
Vector::Vector()
{
  sz = 4;
  max = 0;
  array = new int[4];
}

// Copy Constructor
Vector::Vector(const Vector& v)
{
  sz = v.sz;
  max = v.max;
  array = v.array;
}

// Destructor
Vector::~Vector() { delete[] array; }

// Add elements to the vector
void Vector::push_back(int v)
{
  // Expand vector if needed
  if (max == sz)
  {
    sz = sz * 2;
    int* new_array = new int[sz];
    for (int i = 0; i < max; i++)
    {
      new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
  }

  array[max] = v;
  max++;
}

// Read elements of the vector
int& Vector::operator[](const int idx)
{
  if (idx < 0 || idx >= max)
  {
    throw invalid_argument("Index out of range");
  }

  return array[idx];
}
