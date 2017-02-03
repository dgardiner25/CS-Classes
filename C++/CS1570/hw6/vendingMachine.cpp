//Programmer: DAVID GARDINER          Date: 09/20/16
//File: vendingMachine.cpp            Class: CS1570 A
//Purpose: Write the code for a vending machine that sells
//         supplies to help heal those at the Snax-A-Thon.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "vendingMachine.h"
using namespace std;

int main()
{
  //For formating to 2 decimal places in case of 0 in dollar amount
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint); 
  cout.precision(2);
  
  //Input variables
  string firstName;           //Name of user
  short optionChoice;         //Value of what option user would like
  short randOption;           //Random computer-chosen value
  short numOfOptionRequested; //How many of the option they would like
  short randAmt;              //Random computer-chosen value
  short numOfOption;          //The actual number the user will receive
  float paymentAmount;        //Amount user is paying with
  bool quit = false;          //Check if program ends
  
  //Calculated variables
  string areIs;               //To determine if are or is will be used 
  float subtotal = 0;         //Total before tax
  float tax;                  //Amount of tax to be added onto subtotal
  float total;                //Total cost of purchases
  bool paymentReceived;       //To check if user has entered enough to pay with
  
  //For changing inventory
  short numOption1 = START_1;
  short numOption2 = START_2;
  short numOption3 = START_3;
  short numOption4 = START_4;
  short numOption5 = START_5;
  
  //Seed the RNG
  srand(time(NULL));
  
  //Get user's name
  firstName = getName();

  //Greeting
  greeting(firstName);
  
  
  //Give user menu options until they quit
  do
  {
    //Display menu
    menu(numOption1, numOption2, numOption3, numOption4, numOption5);
    
    //Input the choice the user requests
    cin >> optionChoice;
    
    //Choose a random option
    randOption = getRand(MIN_OPTIONS, MAX_OPTIONS);
    
    //Output remark
    outputRemark(optionChoice, randOption);
    
    //Check which option is selected, ensure item is available, add to subtotal
    //and update inventory
    switch(randOption)
    {
      case 1:
        if(numOption1 == 0)
        {
          cout << UNAVAILABLE_REMARK << endl;
        }
        else 
        {
          numOfOptionRequested = getNumOfOption(1);
          randAmt = getRandAmt(numOfOptionRequested);
          compareAmounts(numOfOptionRequested, randAmt);
          numOfOptionRequested = randAmt;
          numOfOption = updateInventory(numOption1, numOfOptionRequested);
          subtotal += calcSubtotal(numOfOption, PRICE_1);
        }
        break;
      case 2:
        if(numOption2 == 0)
        {
          cout << UNAVAILABLE_REMARK << endl;
        }
        else 
        {
          numOfOptionRequested = getNumOfOption(2);
          randAmt = getRandAmt(numOfOptionRequested);
          compareAmounts(numOfOptionRequested, randAmt);
          numOfOptionRequested = randAmt;
          numOfOption = updateInventory(numOption2, numOfOptionRequested);
          subtotal += calcSubtotal(numOfOption, PRICE_2);
        }
        break;
      case 3:
        if(numOption3 == 0)
        {
          cout << UNAVAILABLE_REMARK << endl;
        }
        else 
        {
          numOfOptionRequested = getNumOfOption(3);
          randAmt = getRandAmt(numOfOptionRequested);
          compareAmounts(numOfOptionRequested, randAmt);
          numOfOptionRequested = randAmt;
          numOfOption = updateInventory(numOption3, numOfOptionRequested);
          subtotal += calcSubtotal(numOfOption, PRICE_3);
        }
        break;
      case 4:
        if(numOption4 == 0)
        {
          cout << UNAVAILABLE_REMARK << endl;
        }
        else 
        {
          numOfOptionRequested = getNumOfOption(4);
          randAmt = getRandAmt(numOfOptionRequested);
          compareAmounts(numOfOptionRequested, randAmt);
          numOfOptionRequested = randAmt;
          numOfOption = updateInventory(numOption4, numOfOptionRequested);
          subtotal += calcSubtotal(numOfOption, PRICE_4);
        }
        break;
      case 5:
        if(numOption5 == 0)
        {
          cout << UNAVAILABLE_REMARK << endl;
        }
        else 
        {
          numOfOptionRequested = getNumOfOption(5);
          randAmt = getRandAmt(numOfOptionRequested);
          compareAmounts(numOfOptionRequested, randAmt);
          numOfOptionRequested = randAmt;
          numOfOption = updateInventory(numOption5, numOfOptionRequested);
          subtotal += calcSubtotal(numOfOption, PRICE_5);
        }
        break;
      case QUIT_OPTION:
        quit = true;
        break;
      default:
        cout << "\nEnter a valid option." << endl;
    }
} while(!quit);
  
  //Calculate sales tax and round to nearest penny
  tax = calcTax(subtotal, calcTaxPercent(subtotal));

  //Calculate total bill cost
  total = calcTotal(subtotal, tax);
  
  do
  {
    //Output bill
    outputBill(firstName, subtotal, tax, total);

    //Determine how much money user wants to pay with  
    paymentAmount = getPayment();
    
    //Check if amount entered is enough
    paymentReceived = isEnough(paymentAmount, total);
      
  } while(!paymentReceived); //Repeat until enough money is inserted
  
  //Output the user's change
  returnChange(paymentAmount, total);
  
  //Sign-off
  signoff();

  return 0;
}
