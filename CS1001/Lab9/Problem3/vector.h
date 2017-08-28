#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

using namespace std;

class Vector
{
public:
  // Constructor
  Vector();

  Vector(const Vector& v);
  // Destructor
  ~Vector();

  // Add elements to the vector
  void push_back(int v);

  // Read elements of the vector
  int& operator[](const int idx);

private:
  int sz;
  int max;
  int* array;
};

#endif //VECTOR_H
