//Programmer: DAVID GARDINER        Date: 10/7/16
//File: vendingMachine.h            Class: CS1570 A
//Purpose: Function prototypes for the code for a vending machine that sells
//         supplies to help heal those at the Snax-A-Thon.

#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

//Message for option being out
const string UNAVAILABLE = " *NO LONGER AVAILABLE*";

const string UNAVAILABLE_REMARK = "\nItem is unavailable, choose another and "
                                  "grab some more IQ points while you're at " 
                                  "it.";

//Min and max values
const short MIN_OPTIONS = 1;
const short MAX_OPTIONS = 7;
const short MIN_REMARKS = 1;
const short MAX_REMARKS = 6;
const short MIN_AMOUNT = 1;
const short MAX_AMOUNT_MULTIPLIER = 2;

//Snarky remarks
const string SAME_CHOICE = "Fine! ... But you're gonna be sorry.";
const string REMARK_1 = "No, you really want ";
const string REMARK_2 = "As my uncle Hal would say, \"I can't do that for "
                        "you Dave. You want ";
const string REMARK_3 = "Only a loooooser would want THAT. Try this instead: ";
const string REMARK_4 = "WRONG! I'm sure you meant to pick ";
const string REMARK_5 = "PPpfffffttt. I think you need ";
const string REMARK_6 = "Only idiots choose that. Better to have some ";
const string REMARK_7 = "Tss, you must be Homer! Only Homer would want that. "
                        "Lisa's preference is ";

//Prices of vending options
const float PRICE_1 = 4.50;
const float PRICE_2 = 1.23;
const float PRICE_3 = 2.39;
const float PRICE_4 = 99.98;
const float PRICE_5 = 0.78;

//Starting inventory of each option
const short START_1 = 5;
const short START_2 = 12;
const short START_3 = 12;
const short START_4 = 12;
const short START_5 = 12;

//Current sales tax percentage
const float SALES_TAX_PERCENT_LESS_100 = 0.50;
const float SALES_TAX_PERCENT_100_TO_300 = 0.27;
const float SALES_TAX_PERCENT_MORE_300 = 0.02;

//Description: The getName() function prompts the user for their first name.
//Pre: None.
//Post: Name is returned.
string getName();

//Description: The greeting() function displays a greeting to the user.
//Pre: None.
//Post: A message is output to the screen.
void greeting(const string name);

//Description: The menu() function displays a menu and the availability of
//             the choices.
//Pre: None.
//Post: A menu is output to the screen.
void menu(const short num1, const short num2, const short num3, 
          const short num4, const short num5);

//Description: The getRand() function picks a random number given a min and max
//             value.
//Pre: None.
//Post: A random number is returned.       
short getRand(const short min, const short max);

//Description: The outputRemark() function displays a random remark dependent
//             on the the userChoice and randChoice.
//Pre: None.
//Post: A message is output to the screen.
void outputRemark(const short userChoice, const short randChoice);

//Description: The getRandRemark() function picks a random remark and
//             returns it.
//Pre: None.
//Post: A remark is returned.
string getRandRemark();

//Description: The returnChoice() function returns the name of the option
//             chosen.
//Pre: None.
//Post: Option name is returned.
string returnChoice(const short randChoice);

//Description: The getNumOfOption() function prompts the user for the number of
//             the chosen option they would like.
//Pre: None.
//Post: User input number is returned;    
short getNumOfOption(const short option);

//Description: The getRandAmt() function returns a random number used for the
//             amount of option chosen.
//Pre: None.
//Post: Random amount is returned.
short getRandAmt(const short numRequested);

//Description: The compareAmounts() function compares the two parameters and
//             outputs a correct remark.
//Pre: None.
//Post: A message is output to the screen.
void compareAmounts(const short userAmt, const short randAmt);

//Description: The updateInventory() function updates the selected option's
//             inventory and is updated based on the amount sent.
//Pre: numLeft must be modifiable.
//Post: Inventory is updated and the number of items is returned.
short updateInventory(short & numLeft, const short numRequested);

//Description: The calcSubtotal() function calculates the subtotal give the
//             price of the item chosen and the number of that item.
//Pre: None.
//Post: Calculated subtotal is returned.
float calcSubtotal(const short numToBuy, const float priceOfOption);

//Description: The calcTaxPercent() functions determines the percent of tax to
//             be applied to the subtotal.
//Pre: None.
//Post: An appropriate tax percent is returned.
float calcTaxPercent(const float sub);

//Description: The calcTax() function calculates the tax the user owes based
//             on their subtotal and a tax percentage.
//Pre: None.
//Post: Calculated tax is returned.
float calcTax(const float sub, const float taxPercent);

//Description: The calcTotal() function calculates the user's total owed.
//Pre: None.
//Post: Calculated total is returned.
float calcTotal(const float sub, const float taxVal);

//Description: The outputBill() functions displays the user's bill.
//Pre: None.
//Post: The user's bill is output to the screen.
void outputBill(const string name, const float sub, const float taxVal,
                const float totalVal);

//Description: The getPayment() function prompts user for how much they would
//             like to pay with and returns that value.
//Pre: None.
//Post: User input value is returned.
float getPayment();

//Description: The isEnough() function checks if user entered enough change.
//Pre: None.
//Post: True returned if user enters enough, false if not.
bool isEnough(const float payment, const float totalVal);

//Description: The returnChange() function gives the user their change.
//Pre: None.
//Post: Change is output to the screen.
void returnChange(const float payment, const float totalVal);

//Description: The signoff() function displays a signoff to the user.
//Pre: None.
//Post: A message is output to the screen.
void signoff();

#endif
