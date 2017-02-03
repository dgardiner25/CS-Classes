//Programmer: DAVID GARDINER          Date: 10/16/16
//File: pileIdentifier_functions.cpp  Class: CS1570 A
//Purpose: Funciton definitions to help identify the various 
//         trash piles throughout the city of Springfield.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "pileIdentifier.h"
using namespace std;

void greeting()
{
  cout << "Welcome to the trash pile identifier!\n" << endl;
  return;
}

short getRand(const short min, const short max)
{
  return rand() % (max - min + 1) + min;
}

void assignPileVals(pile arr[], const short data_size)
{
  for(int i = 0; i < data_size; i++)
  {
    arr[i].sector = getRand(MIN_SECTORS, MAX_SECTORS);
    arr[i].weight = getRand(MIN_WEIGHT, MAX_WEIGHT);
  }
  return;
} 

void assignOffenderVals(offender arr[], const short data_size)
{
  for(int i = 0; i < data_size; i++)
  {
    arr[i].name = NAMES[i];
    arr[i].guilt = getRand(MIN_GUILT, MAX_GUILT);
  }
  return;
}

void outputPiles(const pile arr[], const short data_size)
{
  for(int i = 0; i < data_size; i++)
    cout << "Sector " << arr[i].sector 
         << ": weight " << arr[i].weight << " lbs" << endl;
  return;
}

void outputOffenders(const offender arr[], const short data_size)
{
  for(int i = 0; i < data_size; i++)
    cout << arr[i].name << ", guilt = " << arr[i].guilt << endl;
  return;
}

bool operator<(const pile p1, const pile p2)
{
  return p1.weight < p2.weight;
}

bool operator<(const offender o1, const offender o2)
{
  return o1.guilt < o2.guilt;
}

void outputTopTwo(const offender arr[])
{
  cout << "Most guilty citizen: " << arr[0].name << ", guilt = " 
       << arr[0].guilt << endl;
  cout << "Second most guilty citizen: " << arr[1].name << ", guilt = " 
       << arr[1].guilt << endl;
  return;
}

void outputTopPercentage(const pile arr1[], const offender arr2[], 
                         const short data_size)
{
  int sumWeights = 0;
  int sumAll = sumAllWeights(arr1, data_size);
  short i = 0;
  cout << "The residents with the top " << TOP_PERCENTAGE * 100 << "% of the " 
       << "total weight of all trash piles:" << endl;
  while(static_cast<float>(sumWeights+arr1[i+1].weight)/sumAll<TOP_PERCENTAGE)
  {
    cout << arr2[i].name << endl;
    sumWeights += arr1[i].weight;
    i++; 
  }
  return;
}

int sumAllWeights(const pile arr[], const short data_size)
{
  int sum = 0;
  for(int i = 0; i < data_size; i++)
  {
    sum += arr[i].weight;
  }
  return sum;
}

void outputSectorWeights(const pile arr[], const short data_size)
{
  short p_count;
  short total;
  for(int i = 1; i <= MAX_SECTORS; i++)
  {
    p_count = 1;
    total = 0;
    cout << "Sector " << i << ":" << endl; 
    for(int j = 0; j < data_size; j++)
      if(arr[j].sector == i)
      {
        cout << "    Pile " << p_count << " weight = " << arr[j].weight 
             << " lbs" << endl;
        total += arr[j].weight;
        p_count++;
      }
    cout << "    Total weight of sector = " << total << " lbs" << endl;
  }
  return;
}

void identifyPiles(const pile arr1[], const offender arr2[], 
                   const short data_size)
{
  bool perpFound;
  short i;
  char choice;
  
  short weightChoice;
  
  do
  {
    i = 0;
    perpFound = false;
    weightChoice = getInput("Enter the weight of a pile to be identified", 
                            MIN_WEIGHT, MAX_WEIGHT);
    
    do
    {
      if(weightChoice >= arr1[0].weight)
      {
        outputPerp(weightChoice, arr2[0].name);
        perpFound = true;
      }
      else if(weightChoice <= arr1[data_size-1].weight)
      {
        outputPerp(weightChoice, arr2[data_size-1].name);
        perpFound = true;
      }
      else if(weightChoice == arr1[i].weight)
      {
        outputPerp(weightChoice, arr2[i].name);
        perpFound = true;
      }
      else if(weightChoice < arr1[i].weight && weightChoice > arr1[i+1].weight)
      {
        if(abs(weightChoice - arr1[i].weight)
           < (weightChoice - arr1[i+1].weight))
          outputPerp(weightChoice, arr2[i].name);
        else
          outputPerp(weightChoice, arr2[i+1].name);
        perpFound = true;
      }
      i++;    
    } while(!perpFound && i < data_size);
    
    cout << "\nWould you like to check another? (y/n)     ";
    cin >> choice;  
    
  } while(choice != 'n' && choice != 'N');
  return;
}

void outputPerp(short weight, string name)
{
  cout << "\nThe most likely perpetrator for the pile that weighs " << weight
       << " lbs is " << name << endl;
  return;
}

short calcNumPiles(const pile arr[], const short sec, const short data_size)
{
  short num = 0;
  for(int i = 0; i < data_size; i++)
      if(arr[i].sector == sec)
        num++;
  return num;
}

short getInput(const string prompt, const short min, const short max)
{
  short ret;
  bool inRange;
  do
  {
    if(max!=1)
    {
      cout << "\n" << prompt << " (" << min << "-" << max << ")     ";
      cin >> ret;
      inRange = ret >= min && ret <= max;
      if(!inRange)
        cout << "\nNumber out of range, try again." << endl;
    }
    else
      ret = 1;
  } while(!inRange);
  return ret;
}

void signoff()
{
  cout << "\nI hope you have all the evidence you need, bye!" << endl;
}











