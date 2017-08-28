//Programmer: DAVID GARDINER               Date: 2/20/2017
//File: linkedlist.hpp                     Class: 1510 C
//Purpose: Implementation of the ArrayList class.

using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
  m_head = m_back = new Node<T>;
  m_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  if(m_head != m_back)
    clear();
}

template <typename T>
LinkedList<T>* LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  const Node<T>* temp = rhs.getFirstPtr();
  Node<T>* copy;
  clear();
  m_head->m_next = new Node<T>(temp->m_data, m_head->m_next);
  copy = m_head->m_next;
  m_size = rhs.size();
  while(temp->m_next != NULL)
  {
    temp = temp->m_next;
    copy->m_next = new Node<T>(temp->m_data, copy->m_next);
    copy = copy->m_next;
  }
  return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  m_head = m_back = new Node<T>;
  *this = rhs;
}

template <typename T>
int LinkedList<T>::size() const
{
  return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if(!m_size)
    return true;
  return false;
}

template <typename T>
Node<T>* LinkedList<T>::getFirstPtr()
{
  if(!m_size)
    return NULL;
  return m_head->m_next;
}

template <typename T>
const Node<T>* LinkedList<T>::getFirstPtr() const
{
  if(!m_size)
    return NULL;
  return m_head->m_next;
}

template <typename T>
Node<T>* LinkedList<T>::getLastPtr()
{
  if(!m_size)
    return NULL;
  return m_back;
}

template <typename T>
Node<T>* LinkedList<T>::getAtPtr(int i)
{
  Node<T>* temp = m_head;
  short count = 0;
  if(i <= m_size)
  {
    while(count != i)
    {
      temp = temp->m_next;
      count++;
    }
  }
  else
    return NULL;
  return temp;
}

template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* temp;
  while(m_head != NULL)
  {
    temp = m_head;
    m_head = m_head->m_next;
    delete temp;
  }
  m_head = m_back = new Node<T>;
  m_size = 0;
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  m_head->m_next = new Node<T>(x, m_head->m_next);
  if(!m_size)
    m_back = m_head->m_next;
  m_size++;
}

template <typename T>
void LinkedList<T>::insert_back(const T& x)
{
  m_back->m_next = new Node<T>;
  m_back = m_back->m_next;
  m_back->m_data = x;
  m_size++;
}

template <typename T>
void LinkedList<T>::insert(const T& x, Node<T>* pos)
{
  Node<T>* temp = m_head;
  Node<T>* new_node;
  while(temp != pos)
    temp = temp->m_next;
  new_node = new Node<T>(x, temp->m_next);
  temp->m_next = new_node;
  m_size++;
}

template <typename T>
void LinkedList<T>::remove_front()
{
  Node<T>* temp = m_head->m_next;
  m_head = NULL;
  delete m_head;
  m_head = temp;
  m_size--;
}

template <typename T>
void LinkedList<T>::remove_back()
{
  Node<T>* temp = m_head;
  for(int i=0; i<m_size; i++)
    temp = temp->m_next;
  m_back = temp;
  m_size--;
}

template <typename T>
void LinkedList<T>::remove(Node<T>* pos)
{
  Node<T>* temp = m_head;
  if(m_size > 0)
  {
    while(temp != pos)
      temp = temp->m_next;
    temp->m_next = temp->m_next->m_next;
    pos = NULL;
    m_size--;
  }
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
  if(m_size && rhs.size())
  {
    Node<T>* temp1 = m_head->m_next;
    const Node<T>* temp2 = rhs.getFirstPtr();
    temp2 = temp2->m_next;
    short count = 0;
    if(m_size == rhs.size())
      while(count < m_size && temp1->m_data == temp2->m_data)
      {
        count++;
        if(count == m_size)
          return true;
        temp1 = temp1->m_next;
        temp2 = temp2->m_next;
      }
  }
  return false;
}

template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& list)
{
  const Node<T>* temp = list.getFirstPtr();
  for(int i=0; i<list.size(); i++)
  {
    out << temp->m_data;
    temp = temp->m_next;
  }
  return out;
}
