//Programmer: DAVID GARDINER              Date: 10/7/16
//File: vendingMachine_functions.cpp      Class: CS1570 A
//Purpose: Function definitions for the code for a vending machine that sells
//         supplies to help heal those at the Snax-A-Thon.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "vendingMachine.h"
using namespace std;

string getName()
{
  string name;
  cout << "What is your first name?     ";
  cin >> name;
  return name;  
}

void greeting(string name)
{
  cout << "\nHello " << name << ", please choose your preferred"
       << " homeopathic remedy/supplement." << endl;
  return;
}

void menu(short num1, short num2, short num3, short num4, short num5)
{
  cout << "\n" << VENDING_NAME 
       << "\n------------";
  cout << "\n1. " << OPTION_1 << " ($" << PRICE_1 << ")";
  if(!num1)
    cout << UNAVAILABLE;
  cout << "\n2. " << OPTION_2 << " ($" << PRICE_2 << ")";
  if(!num2)
    cout << UNAVAILABLE;
  cout << "\n3. " << OPTION_3 << " ($" << PRICE_3 << ")";
  if(!num3)
    cout << UNAVAILABLE;     
  cout << "\n4. " << OPTION_4 << " ($" << PRICE_4 << ")";
  if(!num4)
    cout << UNAVAILABLE;    
  cout << "\n5. " << OPTION_5 << " ($" << PRICE_5 << ")";
  if(!num5)
    cout << UNAVAILABLE;   
  cout << "\n6. Quit\n" << endl;
       
  cout << "Enter your selection (1-6):      ";
  return;
}

short getRand(const short min, const short max)
{
  short num = (rand() % max) + min;
  return num;
}

void outputRemark(const short userChoice, const short randChoice)
{
  if(userChoice == randChoice)
    cout << "\n" << SAME_CHOICE << endl;
  else
  {
    switch(randChoice)
    {
      case 1:
        cout << "\n" << getRandRemark() << returnChoice(randChoice) << endl;
        break;
      case 2:
        cout << "\n" << getRandRemark() << returnChoice(randChoice) << endl;
        break;
      case 3:
        cout << "\n" << getRandRemark() << returnChoice(randChoice) << endl;
        break;
      case 4:
        cout << "\n" << getRandRemark() << returnChoice(randChoice) << endl;
        break;
      case 5:
        cout << "\n" << getRandRemark() << returnChoice(randChoice) << endl;
        break;
      case 6:
        cout << "\n" << getRandRemark() << "to quit" << endl;
        break;
    }
  }
  return;
}

string getRandRemark()
{
  short num = getRand(MIN_REMARKS, MAX_REMARKS);
  string ret;
  switch(num)
  {
    case 1:
      ret = REMARK_1;
      break;
    case 2:
      ret = REMARK_2;
      break;
    case 3:
      ret = REMARK_3;
      break;
    case 4:
      ret = REMARK_4;
      break;
    case 5:
      ret = REMARK_5;
      break;
    case 6:
      ret = REMARK_6;
      break;
    case 7:
      ret = REMARK_7;
      break;
  }  
  return ret;
}

string returnChoice(const short randChoice)
{
  string ret;
  switch(randChoice)
  {
    case 1:
      ret = OPTION_1;
      break;
    case 2:
      ret = OPTION_2;
      break;
    case 3:
      ret = OPTION_3;
      break;
    case 4:
      ret = OPTION_4;
      break;
    case 5:
      ret = OPTION_5;
      break;
  }
  return ret;
}

short getNumOfOption(const short option)
{
  short num;
  cout << "\nHow many of item " << option << " would you like?     ";
  cin >> num;  
  return num;
} 

short getRandAmt(const short numRequested)
{
  return getRand(MIN_AMOUNT, MAX_AMOUNT_MULTIPLIER * numRequested);
}

void compareAmounts(const short userAmt, const short randAmt)
{
  if(userAmt > randAmt)
    cout << "\nThat's waayyy too much for you, you want " << randAmt << endl;
  else if(randAmt > userAmt)
    cout << "\nNaw naw naw, you need " << randAmt << endl;
  else
    cout << "\nI can do that ... " << endl;
  return;
}

short updateInventory(short & numLeft, const short numRequested)
{
  string areIs;
  short finalNum;
  if(numLeft-numRequested < 0)
  {
    areIs = numLeft == 1 ? " is " : " are ";
    cout << "Only " << numLeft << areIs << "available,"
         << " you will be charged accordingly." << endl;
    finalNum = numLeft;
    numLeft = 0;
  }
  else
  {
    finalNum = numRequested;
    numLeft-=numRequested;
  }
  return finalNum;
}

float calcSubtotal(const short numToBuy, const float priceOfOption)
{
  float sub = numToBuy * priceOfOption;
  return sub;
}

float calcTaxPercent(float sub)
{
  float taxPercent = SALES_TAX_PERCENT_LESS_100;
  if(sub >= 100 && sub <= 300)
    taxPercent = SALES_TAX_PERCENT_100_TO_300;
  else if(sub > 300)
    taxPercent = SALES_TAX_PERCENT_MORE_300;
  return taxPercent;
}

float calcTax(float sub, float taxPercent)
{
  float taxVal;
  taxVal = taxPercent * sub + .005;
  taxVal = static_cast<float>(static_cast<int>(taxVal*100))/100;
  return taxVal;
}

float calcTotal(float sub, float taxVal)
{
  float totalVal = sub + taxVal;
  return totalVal;
}

void outputBill(string name, float sub, float taxVal, float totalVal)
{
  cout << "\nHere is your bill, " << name << ":"
       << "\nSubtotal: $" << sub
       << "\nTax: $" << taxVal
       << "\nTotal: $" << totalVal;
  return;
}

float getPayment()
{
  float payment;
  cout << "\nEnter how much money you would like to pay with:     $";
  cin >> payment;
  return payment;
}

bool isEnough(float payment, float totalVal)
{
  bool retVal = true;
  if(payment < totalVal)
  {
    cout << "\nEnter a valid amount." << endl;
    retVal = false;
  }
  return retVal;  
}

void returnChange(float payment, float totalVal)
{
  cout << "\nYour change is $" << (payment - totalVal) << endl;
  return;
}

void signoff()
{
  cout << "\nThank you for choosing the " << VENDING_NAME 
       << " vending machine and supporting the cause!" << endl;
  return;
}














