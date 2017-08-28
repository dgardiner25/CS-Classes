//Programmer: DAVID GARDINER               Date: 3/8/2017
//File: astack.h                           Class: 1510 C
//Purpose: Implementation of the Abstract Stack class.

#include "abstractstack.h"

const int DEFAULT_SIZE = 30;

template <typename T>
class ArrayStack: public AbstractStack<T>
{
  private:
    int max;          // Max size of stack
    int topPos;       // Position of the top element
    T* array;         // Pointer to type T to hold array stack

  public:
    ArrayStack()
    {
      max = DEFAULT_SIZE;
      topPos = 0;
      array = new T[max];
    }

    ~ArrayStack()
    {
      delete[] array;
    }

    bool isEmpty() const
    {
      return (topPos ? false : true);
    }

    const T& top() const throw ( Oops )
    {
      try
      {
        if(!topPos)
          throw Oops("Stack is empty!");
        return array[topPos-1];
      }
      catch(const Oops& e)
      {
        cout << e.getMsg() << endl;
      }
      return array[topPos]; //?
    }

    void push(const T& x)
    {
      try
      {
        if(topPos == max)
          throw Oops("Stack is full!");
        array[topPos++] = x;
      }
      catch(const Oops& e)
      {
        cout << e.getMsg() << endl;
      }
    }

    void pop()
    {
      try
      {
        if(!topPos)
          throw Oops("Stack is empty!");
        topPos--;
      }
      catch(const Oops& e)
      {
        cout << e.getMsg() << endl;
      }
    }

    void clear()
    {
      topPos = 0;
    }



};
