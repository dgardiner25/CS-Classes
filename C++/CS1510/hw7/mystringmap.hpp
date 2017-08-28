template <typename T>
MyStringMap<T>::MyStringMap()
{
  sz = 0;
  max_sz = MAX_SIZE;
  map = new Pair<T>[max_sz];    // Allocate the memory for the map
}

template <typename T>
MyStringMap<T>::~MyStringMap()
{
  delete[] map;       // Deallocate the memory
}

template <typename T>
const T& MyStringMap<T>::valueOf(const string& key) const throw ( Oops )
{
  int count = 0;            // Used to see if whole map searched
  int pos = hash(key);      // Position the given key should be in
  static T val;             // To return the found value
  while(map[pos].getKey() != key && count != max_sz)
  {
    if(pos == max_sz-1)     // If searched whole map
      pos = 0;
    else
      pos++;
    count++;
  }
  if(count == max_sz)
    throw(Oops("Map doesn't contain the key!"));
  val = map[pos].getVal();
  return val;
}

template <typename T>
int MyStringMap<T>::hash(const string &s) const
{
  return s[2] % max_sz;       // Basic hash function
}

template <typename T>
void MyStringMap<T>::clear()
{
  for(int i=0; i<max_sz; i++)
    map[i].setKey("");        // "Clear" the map
  sz = 0;
}

template <typename T>
void MyStringMap<T>::remove(const string& k)
{
  int count = 1;
  int pos = hash(k);      // Get where the key should be
  while(map[pos].getKey() != k && count != max_sz)
  {
    if(pos == max_sz-1)
      pos = 0;
    else
      pos++;
    count++;
  }
  if(map[pos].getKey() == k)
  {
    map[pos].setKey("");    // Remove the current key
    sz--;
  }
}

template <typename T>
void MyStringMap<T>::insert(const string & key, const T& val)
{
  int pos = hash(key);      // Get where the pair should go
  bool newKey = true;       // Used to see if the key has been used before
  Pair<T> temp(key, val);
  if(sz == max_sz)
    cout << "Error - Hash Map full!" << endl;
  else
  {
    if(map[pos].getKey() == key)
      newKey = false;
    while(map[pos].getKey() != "" && map[pos].getKey() != key)
    {
      if(pos == max_sz-1)
        pos = 0;
      else
        pos++;
      if(map[pos].getKey() == key)
        newKey = false;
    }
    map[pos] = temp;
    if(newKey)
      sz++;
  }
}

template <typename T>
void MyStringMap<T>::print() const
{
  for(int i=0; i<max_sz; i++)
    if(map[i].getKey() != "")
    {
      cout << "< " << map[i].getKey() << ", " << map[i].getVal() << " >"
           << endl;
    }
}
