#ifndef MYSTRINGMAP_H
#define MYSTRINGMAP_H

#include "abstractstringmap.h"

const int MAX_SIZE = 100;

template <typename T>
class Pair
{
  private:
    string key;       // Variable that holds the key
    T value;          // Holds the value associated with the key
  public:
    // Pair constructor
    Pair(){}

    // Paramaterized constructor
    Pair(string k, T v)
    {
      key = k;
      value = v;
    }

    // Returns the key of the pair
    string getKey() { return key; }

    // Sets the key
    void setKey(const string& k) { key = k; }

    // Returns the value
    T getVal() { return value; }

    // Sets the value
    void setVal(const T& v) { value = v; }
};

template <typename T>
class MyStringMap : public AbstractStringMap<T>
{
  private:
    int sz;         // Current size of the table
    int max_sz;     // Max size of the table
    Pair<T> *map;   // Array to hold the hash-table

    // Hash a string into an int to place object into hash-table
    int hash(const string &s) const;
  public:
    // Default constructor
    MyStringMap();

    // Destructor
    ~MyStringMap();

    // Returns the size of the map
    int size() const { return sz; }

    // Returns whether or not the map is empty
    bool isEmpty() const { return (sz ? false : true); }

    // Returns the value of the given key, if the key is not found
    // an Oops object is thrown
    const T& valueOf(const string& key) const throw ( Oops );

    // Clears the map
    void clear();

    // Insert a key-value pair
    void insert(const string & key, const T& val);

    // Remove a key-value pair
    void remove(const string& k);

    // Print the map
    void print() const;
};

#include "mystringmap.hpp"

#endif
