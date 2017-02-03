//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)         Date: 12/4/16
//File: activist.cpp                                         Class: CS1570
//Purpose: Implementation of the activist class.

#include "activist.h"
using namespace std;

activist::activist(const string n, const char spr)
{
  setToxicity(DEF_TOX);
  setDignity(DEF_DIG);
  xLocation = DEF_X_ACT;
  yLocation = DEF_Y_ACT;
  sprite = spr;
  state = DEF_STATE;
  active = true;
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

void activist::walk(town & t, const short roots, const root roots_arr[],
                         const short d_wall, const short d_cop, polluter & p,
                         const short d_counter, const short max_days)
{
  short x_temp;     //Temporary x variable
  short y_temp;     //Temporary y variable
  short direction;  //Random direction to walk in

  //Used if activist lands on cop
  static short prev_x = 0;
  static short prev_y = 0;
  static bool is_cop = false;

  //Stats
  static short exits = 0;
  static short wacked = 0;
  static short p_catch = 0;
  static short d_low = 0;
  static float total_t = 0.0;
  do
  {
    x_temp = xLocation;
    y_temp = yLocation;

    if(toxicity<=COOL_TOX) //Smart walk
    {
      if(yLocation==p.getY())
      {
        if(xLocation<p.getX())
          x_temp++;
        else
          x_temp--;
      }
      else if(xLocation==p.getX())
      {
        if(yLocation<p.getY())
          y_temp++;
        else
          y_temp--;
      }
      else
      {
        if(yLocation<p.getY())
          y_temp++;
        else
          y_temp--;
      }
    }
    else //Random walk
    {
      direction = rand() % 4;
      if(direction == RIGHT)
        y_temp++;
      else if(direction == LEFT)
        y_temp--;
      else if(direction == UP)
        x_temp++;
      else
        x_temp--;
    }

    //Update stats
    if(toxicity>=GONE_TOX) //Toxicity too high
    {
      active = false;
      wacked++;
    }
    else if(dignity<=MIN_DIGNITY) //Dignity too low
    {
      active = false;
      d_low++;
    }
    if(t.getPoint(x_temp, y_temp)==WALL_SPRITE) //Run into wall
      dignity -= d_wall;
    else if(t.getPoint(x_temp, y_temp)==EXIT_SPRITE) //Goes out exit
    {
      active = false;
      exits++;
    }
    else if(t.getPoint(x_temp, y_temp)==POLLUTER_SPRITE) //Catches polluter
    {
      active = false;
      p_catch++;
    }
    else if(t.getPoint(x_temp, y_temp)==ROOT_SPRITE) //Eats a root
      *this + roots_arr[roots];
    else if(t.getPoint(x_temp, y_temp)==COP_SPRITE) //Runs into a cop
    {
      is_cop = true;
      prev_x = x_temp;
      prev_y = y_temp;
      dignity -= d_cop;
    }
  } while(t.getPoint(x_temp, y_temp)==WALL_SPRITE);

  //If prev location was cop
  if(is_cop && (prev_x != x_temp || prev_y != y_temp))
  {
    t.setPoint(xLocation, yLocation, COP_SPRITE);
    is_cop = false;
  }
  else
    t.setPoint(xLocation, yLocation, ' ');

  //Update location
  xLocation = x_temp;
  yLocation = y_temp;
  t.setPoint(xLocation, yLocation, sprite);

  if(!active) //If inactive, add toxicity to total
    total_t += toxicity;
  if(d_counter == max_days) //If last day, output stats
    outputStats(max_days, exits, wacked, p_catch, d_low, total_t);
  return;
}

void activist::outputStats(const short days, const short exits,
                           const short wacked, const short p_catch,
                           const short d_low, const float total_t)
{
  cout << name << " exited " << (static_cast<float>(exits)/days)*100
       << "% of the time." << endl;
  cout << name << " got too high " << (static_cast<float>(wacked)/days)*100
       << "% of the time." << endl;
  cout << name << " caught the polluter "
       << (static_cast<float>(p_catch)/days)*100 << "% of the time." << endl;
  cout << name << "'s dignity was too low "
       << (static_cast<float>(d_low)/days)*100 << "% of the time." << endl;
  cout << name << "'s average toxicity at the end of each day was "
       << (total_t/days) << "." << endl;
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
