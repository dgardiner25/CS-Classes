//Programmer: DAVID GARDINER          Date: 11/14/16
//File: activist.cpp                  Class: CS1570 A
//Purpose: Implementation of the activist class.

#include "activist.h"
using namespace std;

activist::activist(const char spr, const string n)
{
  setToxicity(DEF_TOX);
  setDignity(DEF_DIG);
  xLocation = DEF_X_ACT;
  yLocation = DEF_Y_ACT;
  sprite = spr;
  state = DEF_STATE;
  name = n;
}

void activist::setToxicity(float f)
{
  if(f >= MIN_TOXICITY && f <= MAX_TOXICITY)
    toxicity = f;
  else
  {
    cout << "\nInvalid toxicity!" << endl;
    exit(1);
  }
  return;
}

void activist::setDignity(short s)
{
  if(s >= MIN_DIGNITY && s <= MAX_DIGNITY)
    dignity = s;
  else
  {
    cout << "\nInvalid dignity!" << endl;
    exit(1);
  }
  return;
}

void activist::place_me(town & t)
{
  xLocation = t.getSize() / 2;
  yLocation = t.getSize() / 2;
  t.setPoint(xLocation, yLocation, sprite);
  return;
}

void activist::rand_walk(town & t)
{
  short direction; //0=North,1=East,2=South,3=West
  short x_temp;
  short y_temp;
  t.setPoint(xLocation, yLocation, ' ');
  do
  {
    direction = rand()%4;
    x_temp = xLocation;
    y_temp = yLocation;
    if(direction == 0)
      y_temp++;
    else if(direction == 1)
      x_temp++;
    else if(direction == 2)
      y_temp--;
    else
      x_temp--;
  } while(t.getPoint(x_temp, y_temp)=='W' || t.getPoint(x_temp, y_temp)=='E' || 
          t.getPoint(x_temp, y_temp)==POLLUTER_SPRITE);
  xLocation = x_temp;
  yLocation = y_temp;
  t.setPoint(xLocation, yLocation, sprite);
  return;
}

ostream& operator<<(ostream & o, const activist & a)
{
  cout << "Name: " << a.name << endl
       << "Toxicity: " << a.toxicity << endl
       << "Dignity: " << a.dignity << endl
       << "Location: (" << a.xLocation << "," << a.yLocation << ")" << endl
       << "State: ";
  if(a.state==-1)
    cout << "Gone" << endl;
  else if(!a.state)
    cout << "Normal" << endl;
  else
    cout << "Cool" << endl;
  return o;
}




