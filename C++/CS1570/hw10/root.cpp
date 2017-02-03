//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)         Date: 12/4/16
//File: root.cpp                                             Class: CS1570 
//Purpose: Implementation of the root class.

#include "root.h"
using namespace std;

root::root()
{
  if(rand()%2)
  {
    effect = (static_cast<float>(rand()) / RAND_MAX) * 
             (MAX_NEG_EFFECT - MIN_NEG_EFFECT) + MIN_NEG_EFFECT; 
    description = "Square";
  }
  else
  {
    effect = (static_cast<float>(rand()) / RAND_MAX) * 
             (MAX_POS_EFFECT - MIN_POS_EFFECT) + MIN_POS_EFFECT;
    description = "Truffle";
  }
  
} 

void root::place_root(town & t)
{
  float x = rand() % (t.getSize()-1);
  float y = rand() % (t.getSize()-1); 
  bool space_empty = false;
  
  do
  {
    if(t.getPoint(x,y)==' ')
    {
      t.setPoint(x,y,ROOT_SPRITE);
      space_empty = true;
    }
    else
    {
      x = rand() % (t.getSize()-1);
      y = rand() % (t.getSize()-1);
    }
  } while(!space_empty);
  return;
}

float root::getEffect()
{
  return effect;
}
