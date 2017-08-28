#include "list.h"

List::List(int v)
{
  val = v;
  nxt = NULL;
}

List::List(const List &copy)
{
  val = copy.value();
  nxt = NULL;

  List *copy_iter = copy.next();
  List *this_iter = this;

  while (copy_iter)
  {
    this_iter->nxt = new List(copy_iter->value());
    this_iter = this_iter->next();
    copy_iter = copy_iter->next();
  }
}

List::~List()
{
  if (nxt)
  {
    delete nxt;
  }
}

// Append a new node to the linked list
void List::append(int v)
{
  List *l = last();

  l->nxt = new List(v);  
}

// Append a linked list to the end of this list
void List::extend(List *e) { last()->nxt = e; }

// Print out the list
void List::print() const
{
  const List *iter = this;
  while (iter)
  {
    cout << iter->value() << endl;
    iter = iter->next();
  }
}

// Sum the values in the list
int List::sum() const
{
  int sum = 0;

  const List *iter = this;
  while (iter)
  {
    sum += iter->value();

    iter = iter->next();
  }

  return sum;
}

List *List::last()
{
  List *l = this;
  while (l->next() != NULL)
  {
    l = l->next();
  }

  return l;
}
