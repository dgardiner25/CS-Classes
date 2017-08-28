#ifndef DTOR_H
#define DTOR_H

class dtor
{
public:
  dtor() { ptr = new int; }

  ~dtor() { delete ptr; }

  int* ptr;
};

#endif // DTOR_H
