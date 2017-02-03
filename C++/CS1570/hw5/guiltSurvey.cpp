//Programmer: David Gardiner          Date: 10/05/16
//File: guiltSurvey.cpp               Class: CS1570 A
//Purpose: Survey users and calculate GUILT based off of their
//         amount of food wasted per day, number of public transportation
//         miles per day, relation to Mr. Burns, and amount of methane 
//         produced in the past week.

#include <iostream>
#include <string>
using namespace std;

//-------Constant Declarations-------//

//Min and max values for input
const short MIN_OPTION_1 = 0;
const short MAX_OPTION_1 = 100;
const short MIN_OPTION_2 = 1;
const short MAX_OPTION_2 = 250;
const short MIN_OPTION_3 = 1;
const short MAX_OPTION_3 = 120;
const short MIN_OPTION_4 = 0;
const short MAX_OPTION_4 = 3;

//For modifying values
const float OPTION_1_MULTIPLIER = 1.5;
const float OPTION_1_OFFSET = 6;
const float OPTION_2_MULTIPLIER = -2;
const float OPTION_2_OFFSET = 1;

//Only for Mr. Burns
const short BURNS_COEFFICIENT = 570;

//If option has already been completed
const string COMPLETED = "\nYou have already completed this option!";


//-------Function Protoypes-------//

//Description: The greeting() function displays a greeting. 
//Pre: None.
//Post: Message is output to screen.
void greeting();

//Description: The menu() function displays a menu and prompt for option 
//             choice.
//Pre: None.
//Post: Menu and prompt for choice is output to screen.
void menu();

//Description: The inputCheck() function prompts and gets input from user and 
//             checks if input is within range.
//Pre: minVal must be < maxVal.
//Post: Input within given range is returned.
float inputCheck(const string prompt, const float minVal, const float maxVal);

//Description: The yesNo() function prompts and gets input from user.
//Pre: None.
//Post: Return true or false.
bool yesNo(const string prompt);

//Description: The moidifer() function modifies values for use in GUILT 
//             calculation.
//Pre: None.
//Post: Value modified by multiplier and offset is returned.
float modifier(float val, const float multiplier, const float offset);

//Description: The foodWasted() function prompts and gets input from user for 
//             amount of food wasted within past week.
//Pre: None.
//Post: Amount of food wasted is returned.
float foodWasted();

//Description: The publicTrans() function prompts and gets input from user if 
//             they use public transportation, and if so, prompts and gets 
//             input for number of miles traveled by public transportation per 
//             day.
//Pre: None
//Post: If no public transportation is used, 0 is returned and if public 
//      transportation is used, the number of miles traveled per day is 
//      returned.
short publicTrans();

//Description: The burnsCheck() function prompts and gets input from user on 
//             if they are Mr. Burns, if not prompts and gets input on if they 
//             are related to Mr. Burns, otherwise, prompts for user's age.
//Pre: None
//Post: If user is Mr. Burns, the burns coefficient is returned, if user is
//      related to Mr. Burns, half of the burns coefficient is returned,
//      and otherwise, the user's age is returned.
short burnsCheck();

//Description: The methaneProduction() function prompts and gets input from 
//             user on how many whole pigs their father has eaten in the past 
//             week and calculates the amount of methane produced determined 
//             by input value.
//Pre: None
//Post: The calculated amount of methane produced is returned.
float methaneProduction(const float foodWaste);

//Description: The calcGuilt() function calculates GUILT value (sum of all 
//             other values). 
//Pre: None.
//Post: Calculated GUILT value is returned.
void calcGuilt(float foodWaste, float miles, const short valOption3, 
                const float methaneVal);
                
//Description: The outputGuilt() function displays a final GUILT value.
//Pre: None.
//Post: GUILT value is output to screen.
void outputGuilt(const float guiltVal);

//Description: The signOff() function displays a sign-off.
//Pre: None
//Post: Message is output to screen.
void signOff();

int main()
{
  //User input
  bool done = false;      //To exit menu loop when survey is complete
  short option;           //Menu option chosen
  short publicMiles;      //Miles of public transportation used
  short burnsOrAge;       //Returns burns value or age
  float waste;            //Amount of food wasted
  float amtMethane;       //Amount of methane produced in the past week
  
  //For checking if options have been completed already
  bool oneComplete = false;
  bool twoComplete = false;
  bool threeComplete = false;
  bool fourComplete = false;
  
  //Output greeting
  greeting();
  
  //Display menu until all options have been completed
  while(!done)
  {
    menu();
    cin >> option;
    
    switch (option)
    {
      //Amount of food wasted
      case 1:
        if(!oneComplete)
        {
          waste = foodWasted();
          oneComplete = true;
        } 
        else
          cout << COMPLETED << endl; 
        break;
        
      //How much public transportation is used
      case 2:
        if(!twoComplete)
        {
          publicMiles = publicTrans();
          twoComplete = true;
        } 
        else
          cout << COMPLETED << endl; 
        break;
        
      //Related to Mr. Burns or not
      case 3:
        if(!threeComplete)
        {
          burnsOrAge = burnsCheck();
          threeComplete = true;
        } 
        else
          cout << COMPLETED << endl; 
        break;
        
      //Amount of methane produced
      case 4:
        if(!fourComplete)
        {
          if(oneComplete)      //Option 1 must be complete first
          {
            amtMethane = methaneProduction(waste);
            fourComplete = true;
          }
          else
            cout << "\nYou must complete option 1 first!" << endl;
        } 
        else
          cout << COMPLETED << endl; 
        break;
        
      //Calculate GUILT once all others have been completed
      case 5:
        if(oneComplete && twoComplete && threeComplete && fourComplete)
        {
          calcGuilt(waste, publicMiles, burnsOrAge, amtMethane);
          done = true;
        }
        else
          cout << "\nYou must complete all other options first!" << endl;
        break;
        
      //Invalid choice
      default:
        cout << "\nEnter a valid option!" << endl;
    }
  }

  //Output sign-off
  signOff();

  return 0;
}

void greeting()
{
  cout << "Welcome to my carbon footprint survey!" << endl;
  return;
}

void menu()
{
  cout << "\nCarbon Footprint Survey"
       << "\n-----------------------"
       << "\n1. Wasteful (Food) Consumption"
       << "\n2. Public Transit Usage"
       << "\n3. Industrial Complicity"
       << "\n4. Farm-Related Methane Production"
       << "\n5. Compute GUILT value"
       << "\n\nPlease enter your choice (1-5):      ";
  return;
}

float inputCheck(const string prompt, const float minVal, const float maxVal)
{
  float num;
  bool outOfRange;
  
  do
  {
    cout << "\n" << prompt << " (" << minVal << "-" << maxVal << ")     ";
    cin >> num;
    outOfRange = (num < minVal) || (num > maxVal);
    if(outOfRange)
      cout << "\nEnter a number from " << minVal << "-" << maxVal << ".\n";
  } while(outOfRange);
  
  return num;
}

bool yesNo(const string prompt)
{
  bool ans;
  cout << "\n" << prompt << " (0 for no, 1 for yes)     ";
  cin >> ans;
  return ans;
}

float modifier(float val, float multiplier, float offset)
{
  float newVal = val * multiplier + offset;
  return newVal;
}

float foodWasted()
{
  float food;
  string prompt = "How many pounds of food per day do you waste?";
  food = inputCheck(prompt, MIN_OPTION_1, MAX_OPTION_1);
  return food;
}

short publicTrans()
{
  short miles;
  bool publicUsed;
  publicUsed = yesNo("Do you use public transportation?");
  if(!publicUsed)
    miles = 0;
  else
  {
    miles = inputCheck("How many miles per day?", MIN_OPTION_2, MAX_OPTION_2);
  }
  return miles;
}

short burnsCheck()
{
  short val;  
  if(yesNo("Are you Mr. Burns?"))
    val = BURNS_COEFFICIENT;
  else if(yesNo("Are you related to Mr. Burns?"))
    val = (BURNS_COEFFICIENT / 2);
  else
  {
    val = inputCheck("What is your age in years?", MIN_OPTION_3, MAX_OPTION_3);
  }
  return val;
}

float methaneProduction(const float foodWaste)
{
  string prompt = "How many whole pigs did your father eat this week?";
  short numPigs = inputCheck(prompt, MIN_OPTION_4, MAX_OPTION_4);
  float methaneVal = (foodWaste * (numPigs * numPigs)) + (3 * numPigs) + 5;
  return methaneVal;
}

void calcGuilt(float foodWaste, float miles, const short valOption3, 
                const float methaneVal)
{
  float newWaste = modifier(foodWaste, OPTION_1_MULTIPLIER, OPTION_1_OFFSET);
  float newMiles = modifier(miles, OPTION_2_MULTIPLIER, OPTION_2_OFFSET);
  float guiltVal = newWaste + newMiles + valOption3 + methaneVal; 
  outputGuilt(guiltVal);
  return;
}

void outputGuilt(const float guiltVal)
{
  cout << "\nYour GUILT value is " << guiltVal << endl;
  return;
}

void signOff()
{
  cout << "\nThank you for participating in my survey!" << endl;
  return;
}
