//Programmer: David Gardiner          Date: 09/20/16
//File: vendingMachine.cpp            Class: CS1570 A
//Purpose: Write the code for a vending machine that sells
//         supplies to help heal those at the Snax-A-Thon.

#include <iostream>
#include <string>
using namespace std;

//Name of vending machine
const string VENDING_NAME = "Roots 'n Stuff";

//Name of vending options
const string OPTION_1 = "Ginko Root";
const string OPTION_2 = "Mandrake Root";
const string OPTION_3 = "Ginseng Root";
const string OPTION_4 = "Square Root";
const string OPTION_5 = "Vitamin R Root";

//The menu option to leave the machine
const short QUIT_OPTION = 6;

//Prices of vending options
const float PRICE_1 = 4.50;
const float PRICE_2 = 1.23;
const float PRICE_3 = 2.39;
const float PRICE_4 = 99.98;
const float PRICE_5 = 0.78;

//Starting inventory of each option
const short START_1 = 5;
const short START_2 = 4;
const short START_3 = 9;
const short START_4 = 11;
const short START_5 = 8;

//Current sales tax percentage
const float SALES_TAX_PERCENT = 0.16;

int main()
{
  //For formating to 2 decimal places in case of 0 in dollar amount
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint); 
  cout.precision(2);
  
  //Input variables
  string firstName;           //Name of user
  short optionChoice;         //Value of what option user would like
  float numOfOption;          //How many of the option they would like
  float paymentAmount;        //Amount user is paying with
  bool quit = false;          //Check if program ends
  
  //Calculated variables
  string areIs;               //To determine if are or is will be used 
  float subtotal = 0;         //Total before tax
  float tax;                  //Amount of tax to be added onto subtotal
  float total;                //Total cost of purchases
  
  //For changing inventory
  short numOption1 = START_1;
  short numOption2 = START_2;
  short numOption3 = START_3;
  short numOption4 = START_4;
  short numOption5 = START_5;
  
  //Greeting
  cout << "Got an ailment? You've come to the right place!" << endl;
  
  
  //Get user input
  cout << "\nWhat is your first name?     ";
  cin >> firstName;

  cout << "\nHello " << firstName << ", please choose your preferred"
       << " homeopathic remedy/supplement." << endl;

  //Give user menu options until they quit
  do
  {
    cout << "\n" << VENDING_NAME 
         << "\n------------";
    cout << "\n1. " << OPTION_1 << " ($" << PRICE_1 << ")";
    if(!numOption1)
      cout << " *NO LONGER AVAILABLE*";
    cout << "\n2. " << OPTION_2 << " ($" << PRICE_2 << ")";
    if(!numOption2)
      cout << " *NO LONGER AVAILABLE*";
    cout << "\n3. " << OPTION_3 << " ($" << PRICE_3 << ")";
    if(!numOption3)
      cout << " *NO LONGER AVAILABLE*";     
    cout << "\n4. " << OPTION_4 << " ($" << PRICE_4 << ")";
    if(!numOption4)
      cout << " *NO LONGER AVAILABLE*";    
    cout << "\n5. " << OPTION_5 << " ($" << PRICE_5 << ")";
    if(!numOption5)
      cout << " *NO LONGER AVAILABLE*";   
    cout << "\n6. Quit\n" << endl;
       
    cout << "Enter your selection (1-6):      ";
    cin >> optionChoice;
    
    //Check which option is selected, ensure item is available, add to subtotal
    //and update inventory
    switch(optionChoice)
    {
      case 1:
        if(numOption1 == 0)
        {
          cout << "\nItem is unavailable, choose another and grab some more IQ"
               << " points while you're at it." << endl;
        }
        else 
        {
          cout << "\nHow many of item " << optionChoice 
               << " would you like?     ";
          cin >> numOfOption;
          if(numOfOption < 0)
            cout << "\nSorry, no givesies-backsies." << endl;
          else if(numOfOption==0)
          {
            cout << "\nWhy did you choose this option if you "
                 << "don't want any?" << endl; 
          }
          else if(numOption1-numOfOption < 0)
          {
            areIs = numOption1==1 ? " is " : " are ";
            cout << "Only " << numOption1 << areIs << "available,"
                 << " you will be charged accordingly." << endl;
            subtotal += PRICE_1 * numOption1;
            numOption1 = 0;
          }
          else
          {
            subtotal += PRICE_1 * numOfOption;
            numOption1-=numOfOption;
          }
        }
        break;
      case 2:
        if(numOption2 == 0)
        {
          cout << "\nItem is unavailable, choose another and grab some more IQ"
               << " points while you're at it." << endl;
        }
        else 
        {
          cout << "\nHow many of item " << optionChoice 
               << " would you like?     ";
          cin >> numOfOption;
          if(numOfOption < 0)
            cout << "\nSorry, no givesies-backsies." << endl;
          else if(numOfOption==0)
          {
            cout << "\nWhy did you choose this option if you "
                 << "don't want any?" << endl; 
          }
          else if(numOption2-numOfOption < 0)
          {
            areIs = numOption2==1 ? " is " : " are ";
            cout << "Only " << numOption2 << areIs << "available,"
                 << " you will be charged accordingly." << endl;
            subtotal += PRICE_2 * numOption2;
            numOption2 = 0;
          }
          else
          {
            subtotal += PRICE_2 * numOfOption;
            numOption2-=numOfOption;
          }
        }
        break;
      case 3:
        if(numOption3 == 0)
        {
          cout << "\nItem is unavailable, choose another and grab some more IQ"
               << " points while you're at it." << endl;
        }
        else 
        {
          cout << "\nHow many of item " << optionChoice 
               << " would you like?     ";
          cin >> numOfOption;
          if(numOfOption < 0)
            cout << "\nSorry, no givesies-backsies." << endl;
          else if(numOfOption==0)
          {
            cout << "\nWhy did you choose this option if you "
                 << "don't want any?" << endl; 
          }
          else if(numOption3-numOfOption < 0)
          {
            areIs = numOption3==1 ? " is " : " are ";
            cout << "Only " << numOption3 << areIs << "available,"
                 << " you will be charged accordingly." << endl;
            subtotal += PRICE_3 * numOption3;
            numOption3 = 0;
          }
          else
          {
            subtotal += PRICE_3 * numOfOption;
            numOption3-=numOfOption;
          }
        }
        break;
      case 4:
        if(numOption4 == 0)
        {
          cout << "\nItem is unavailable, choose another and grab some more IQ"
               << " points while you're at it." << endl;
        }
        else 
        {
          cout << "\nHow many of item " << optionChoice 
               << " would you like?     ";
          cin >> numOfOption;
          if(numOfOption < 0)
            cout << "\nSorry, no givesies-backsies." << endl;
          else if(numOfOption==0)
          {
            cout << "\nWhy did you choose this option if you "
                 << "don't want any?" << endl; 
          }
          else if(numOption4-numOfOption < 0)
          {
            areIs = numOption4==1 ? " is " : " are ";
            cout << "Only " << numOption4 << areIs << "available,"
                 << " you will be charged accordingly." << endl;
            subtotal += PRICE_4 * numOption4;
            numOption4 = 0;
          }
          else
          {
            subtotal += PRICE_4 * numOfOption;
            numOption4-=numOfOption;
          }
        }
        break;
      case 5:
        if(numOption5 == 0)
        {
          cout << "\nItem is unavailable, choose another and grab some more IQ"
               << " points while you're at it." << endl;
        }
        else 
        {
          cout << "\nHow many of item " << optionChoice 
               << " would you like?     ";
          cin >> numOfOption;
          if(numOfOption < 0)
            cout << "\nSorry, no givesies-backsies." << endl;
          else if(numOfOption==0)
          {
            cout << "\nWhy did you choose this option if you "
                 << "don't want any?" << endl; 
          }
          else if(numOption5-numOfOption < 0)
          {
            areIs = numOption5==1 ? " is " : " are ";
            cout << "Only " << numOption5 << areIs << "available,"
                 << " you will be charged accordingly." << endl;
            subtotal += PRICE_5 * numOption5;
            numOption5 = 0;
          }
          else
          {
            subtotal += PRICE_5 * numOfOption;
            numOption5-=numOfOption;
          }
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
  tax = SALES_TAX_PERCENT * subtotal + .005;
  tax = static_cast<float>(static_cast<int>(tax*100))/100;      //To chop

  //Calculate total bill cost
  total = tax + subtotal;
  
  cout << "\nHere is your bill, " << firstName << ":";
  
  do
  {
    //Output bill
    cout << "\nSubtotal: $" << subtotal
         << "\nTax: $" << tax
         << "\nTotal: $" << total;

    //Determine how much money user wants to pay with  
    cout << "\nEnter how much money you would like to pay with:     $";
    cin >> paymentAmount;
    
    //Check if amount entered is enough
    if(paymentAmount < total)
      cout << "\nEnter a valid amount." << endl;
      
  } while(paymentAmount < total); //Repeat until enough money is inserted
  
  //Output change returned
  cout << "\nYour change is $" << (paymentAmount - total) << endl;
  
  //Sign-off
  cout << "\nThank you for choosing the " << VENDING_NAME 
       << " vending machine and supporting the cause!" << endl;

  return 0;
}
