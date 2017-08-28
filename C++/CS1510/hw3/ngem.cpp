//Programmer: DAVID GARDINER               Date: 2/27/2017
//File: ngem.cpp                           Class: 1510 C
//Purpose: Neptunian Genetic Management (NGeM) system code.

#include <iostream>
#include <cstring>
#include "LinkedList.h"
using namespace std;

const short NUM_SEQUENCES = 5;

int main()
{
  string g_code[NUM_SEQUENCES];
  LinkedList<char> lists[NUM_SEQUENCES];
  string function;
  string sequence;
  short id1;
  short id2;
  short start1;
  short start2;
  short stop;

  for(int i=0; i<NUM_SEQUENCES; i++)
  {
    getline(cin, g_code[i]);
    for(int k=0; k<g_code[i].length(); k++)
      lists[i].insert_back(g_code[i][k]);
  }
  while(cin >> function)
  {
    if(function == "append")
    {
      bool error = false;
      cin >> id1;
      cin >> sequence;
      if(id1 < 0 || id1 >= NUM_SEQUENCES)
      {
        error = true;
        cout << "ERROR! append: invalid parameters" << endl;
      }
      if(!error)
      {
        for(int i=0; i<sequence.length(); i++)
        {
          if(sequence[i]!='B'&&sequence[i]!='P'&&sequence[i]!='O'
           &&sequence[i]!='Y'&&sequence[i]!='T'&&sequence[i]!='K'
           &&sequence[i]!='M')
            error = true;
        }
        if(error)
          cout << "ERROR! append: invalid parameters" << endl;
      }
      if(!error)
      {
        for(int i=0; i<sequence.length(); i++)
          lists[id1].insert_back(sequence[i]);
      }
    }
    else if(function == "trim")
    {
      cin >> id1;
      cin >> start1;
      short size = lists[id1].size();
      if(id1 < 0 || id1 >= NUM_SEQUENCES || start1 < 0 || start1 >= size)
        cout << "ERROR! trim: invalid parameters" << endl;
      else
      {
        while(start1 < size)
        {
          lists[id1].remove_back();
          start1++;
        }
      }
    }
    else if(function == "clip")
    {
      cin >> id1;
      cin >> start1;
      cin >> stop;
      short size = lists[id1].size();
      if(id1 < 0 || id1 >= NUM_SEQUENCES || start1 < 0 || start1 >= size
      || stop < start1 || stop >= size)
        cout << "ERROR! clip: invalid parameters" << endl;
      else
      {
        short count = start1;
        while(count <= stop)
        {
          lists[id1].remove(lists[id1].getAtPtr(start1));
          count++;
        }
      }
    }
    else if(function == "slice")
    {
      cin >> id1;
      cin >> start1;
      cin >> stop;
      stop+=2;
      short count = 0;
      short size = lists[id1].size();
      if(id1 < 0 || id1 >= NUM_SEQUENCES || start1 < 0 || start1 >= size
      || stop < start1 || stop >= size)
        cout << "ERROR! slice: invalid parameters" << endl;
      else
      {
        while(count < start1)
        {
          lists[id1].remove_front();
          count++;
        }
        while(stop <= size)
        {
          lists[id1].remove_back();
          stop++;
        }
      }
    }
    else if(function == "copy")
    {
      cin >> id1;
      cin >> id2;
      lists[id2] = lists[id1];
    }
    else if(function == "swap")
    {
      cin >> id1;
      cin >> start1;
      cin >> id2;
      cin >> start2;
      string copy1 = "";
      string copy2 = "";
      Node<char>* temp1 = lists[id1].getAtPtr(start1+1);
      Node<char>* temp2 = lists[id2].getAtPtr(start2+1);
      for(int i=start1;i<lists[id1].size();i++)
      {
        copy1 += temp1->m_data;
        temp1 = temp1->m_next;
      }
      while(start1 != lists[id1].size())
        lists[id1].remove_back();
      for(int i=start2;i<lists[id2].size();i++)
      {
        copy2 += temp2->m_data;
        temp2 = temp2->m_next;
      }
      while(start2 != lists[id2].size())
        lists[id2].remove_back();
      for(int i=0; i<=copy2.length(); i++)
        lists[id1].insert_back(copy2[i]);
      for(int i=0; i<=copy1.length(); i++)
        lists[id2].insert_back(copy1[i]);
      lists[id1].remove(lists[id1].getAtPtr(start1));
      lists[id2].remove(lists[id2].getAtPtr(start2));
    }
    else if(function == "transcribe")
    {
      cin >> id1;
      char curr;
      char new_c;
      for(int i=0; i<lists[id1].size(); i++)
      {
        Node<char>* temp = lists[id1].getAtPtr(i+1);
        curr = temp->m_data;
        if(curr == 'P')
          new_c = 'Y';
        else if(curr == 'O')
          new_c = 'T';
        else if(curr == 'K')
          new_c = 'M';
        else if(curr == 'Y')
          new_c = 'P';
        else if(curr == 'T')
          new_c = 'O';
        else if(curr == 'M')
          new_c = 'K';
        else if(curr == 'B')
          new_c = 'B';
        lists[id1].remove(lists[id1].getAtPtr(i));
        lists[id1].insert_front(new_c);
      }
    }
    else if(function == "print")
    {
      for(int i=0; i<NUM_SEQUENCES; i++)
      {
        cout << "#" << i << ", " << lists[i].size() << ": " << lists[i]
             << endl;
      }
      cout << endl;
    }
  }

  return 0;
}
