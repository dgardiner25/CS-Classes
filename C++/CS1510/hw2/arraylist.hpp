//Programmer: David Gardiner               Date: 1/28/2017
//File: arraylist.hpp                     Class: 1510 C
//Purpose: Implementation of the ArrayList class.

#include <iostream>
#include "arraylist.h"
using namespace std;

template <typename T>
void ArrayList<T>::grow()
{
  ArrayList<T> temp;
  temp = *this;
  clear();
  m_size = temp.size();
  if(temp.max() < 2)
    m_max = 2;
  else
    m_max = temp.max()*2;
  m_data = new T[m_max];
  for(int i=0; i<m_size; i++)
    m_data[i] = temp.m_data[i];
}

template <typename T>
void ArrayList<T>::shrink()
{
  ArrayList<T> temp;
  temp = *this;
  clear();
  m_size = temp.size();
  m_max = temp.max()/2;
  m_data = new T[m_max];
  for(int i=0; i<m_size; i++)
    m_data[i] = temp.m_data[i];
}

template <typename T>
ArrayList<T>::ArrayList(int s, const T& x)
{
  m_max = m_size = s;
  m_data = new T[m_size];
  for(int i=0; i<s; i++)
    m_data[i] = x;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
  delete[] m_data;
  m_data = NULL;
}


template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  clear();
  m_size = rhs.size();
  m_max = rhs.max();
  m_data = new T[m_max];
  for(int i=0; i<m_size; i++)
    m_data[i] = rhs.m_data[i];
  return *this;
}


template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_size = cpy.size();
  m_max = cpy.max();
  m_data = new T[m_max];
  for(int i=0; i<m_size; i++)
    m_data[i] = cpy.m_data[i];
}

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  if(!m_size)
  {
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.first() (List is empty)" << endl;
    return m_errobj;
  }
  return *m_data;
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  if(i >= m_size)
  {
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.[] (Index out of bounds)" << endl;
    return m_errobj;
  }
  return *(m_data+i);
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  if(i >= m_size)
  {
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.[] (Index out of bounds)" << endl;
    return m_errobj;
  }
  return *(m_data+i);
}

template <typename T>
int ArrayList<T>::find(const T& x) const
{
  int index_found = -1;        // If not found, -1 is returned
  int i=0;                     // Counter
  while(index_found == -1 && i < m_size)
  {
    if(m_data[i] == x)
      index_found = i;
    else
      i++;
  }
  return index_found;
}

template <typename T>
void ArrayList<T>::clear()
{
  delete[] m_data;
  m_data = NULL;
  m_max = m_size = 0;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  if(m_size == m_max)
    grow();
  m_data[m_size++] = x;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  if(i >= m_size || i < 0)
  {
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.insert() (Index out of bounds)"
         << endl;
  }
  else
  {
    if(m_size == m_max)
      grow();
    for(int k=m_size; k>i; k--)
      m_data[k] = m_data[k-1];
    m_data[i] = x;
    m_size++;
  }
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  if(i >= m_size || i < 0)
  {
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.remove() (Index out of bounds)"
         << endl;
  }
  else if(!m_size && i < m_size && i >= 0)
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.remove() (List is empty)" << endl;
  else
  {
    if(m_size < m_max/4)
      shrink();
    for(int k=i; k<m_size-1; k++)
      m_data[k] = m_data[k+1];
    m_size--;
  }
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if(i<0 || i>=m_size || k<0 || k>=m_size)
  {
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.swap() (Index out of bounds)"
         << endl;
  }
  else
  {
    T temp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = temp;
  }
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  if(m_size < alist.size()) // For safety
      grow();
  for(int i=0; i<alist.size(); i++)
    m_data[m_size+i] = alist[i];
  m_size += alist.size();
}

template <typename T>
void ArrayList<T>::reverse()
{
  ArrayList<T> temp;
  temp = *this;
  if(!m_size)
    cout << "!-- ERROR: PANIC in ARRAYLIST!!.reverse() (List is empty)" << endl;
  else
  {
    for(int i=0; i<size(); i++)
    {
      m_data[i] = temp[size()-1-i];
    }
  }
}
