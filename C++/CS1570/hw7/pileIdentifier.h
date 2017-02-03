//Programmer: DAVID GARDINER          Date: 10/16/16
//File: pileIdentifier.h              Class: CS1570 A
//Purpose: Constants, type declarations, templates, and function
//         prototypes to help identify the various trash piles 
//         throughout the city of Springfield.

#ifndef PILEIDENTIFIER_H
#define PILEIDENTIFIER_H
using namespace std;

//------Constants------//
const short NUM_ENTRIES = 15;

//Mins and maxes
const short MIN_SECTORS = 1;
const short MAX_SECTORS = 7;
const short MIN_WEIGHT = 25;
const short MAX_WEIGHT = 500;
const short MIN_GUILT = 100;
const short MAX_GUILT = 10000;

//Offenders with the top _ percent to display
const float TOP_PERCENTAGE = .5;

//Names to choose from
const string NAMES[] = {"Homer", "Maggie", "Bart", "Moe", "Barney", "Marge",
                        "Cletus", "Snake", "Mr. Burns", "Dr. Nick", 
                        "Krusty the Clown", "Chief Wiggum", "Ralph Wiggum",
                        "Skinner", "Lenny"};
                                   
                                   
//------Type Declarations-------//
struct pile
{
  short sector;
  short weight;
};

struct offender
{
  string name;
  short guilt;
};

//------Templates------//
//Description: The sortArray() function sorts the given array in 
//             descending order.
//Pre: The < operator must be defined for type T.
//Post: The array is sorted.
template <typename T>
void sortArray(T arr[], const short data_size)
{
  T temp;
  for(int i = 0; i < data_size; i++)
    for(int j = 0; j < data_size - 1; j++)
      if(arr[j] < arr[i])
      {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
  return;
}

//------Function Prototypes------//
//Description: The greeting() function displays a greeting to the screen. 
//Pre: None.
//Post: A greeting is output to the screen.
void greeting();

//Description: The getRand() function generates a random number given a min 
//             and max value.
//Pre: None.
//Post: A random number is returned.
short getRand(const short min, const short max);

//Description: The assignPileVals() function assigns random values to all
//             elements within the data size of the array.  
//Pre: None.
//Post: The number of array elements within the data size are filled with 
//      random values. 
void assignPileVals(pile arr[], const short data_size);

//Description: The assignPileOffender() function assigns random names and 
//             values to all elements within the data size of the array.
//Pre: None.
//Post: The number of array elements within the data size are filled with 
//      random names and values. 
void assignOffenderVals(offender arr[], const short data_size);

//Description: The outputPiles() function displays the array elements to the 
//             screen.
//Pre: None.
//Post: The array elements are output to the screen.
void outputPiles(const pile arr[], const short data_size);

//Description: The outputPiles() function displays the array elements to the 
//             screen.
//Pre: None.
//Post: The array elements are output to the screen.
void outputOffenders(const offender arr[], const short data_size); 

//Description: The operator<() function overloads the < operator for the pile
//             object.
//Pre: None.
//Post: True is returned if p1 < p2 and false is returned otherwise.
bool operator<(const pile p1, const pile p2);

//Description: The operator<() function overloads the < operator for the 
//             offender object.
//Pre: None.
//Post: True is returned if o1 < o2 and false is returned otherwise.
bool operator<(const offender o1, const offender o2);

//Description: The outputTopTwo() function displays the two most guilty 
//             offender's names and guilt values.
//Pre: None.
//Post: Two names and guilt values are output to the screen.
void outputTopTwo(const offender arr[]);

//Description: The outputTopPercentage() function displays the offenders with
//             the combined weight of all piles less than the top percentage.
//Pre: None.
//Post: The names of offenders with the given top percentage of weight out of 
//      all piles are output to the screen.
void outputTopPercentage(const pile arr1[], const offender arr2[], 
                         const short data_size);

//Description: The sumAllWeights() function sums the weight of all trash piles.
//Pre: None.
//Post: The sum of all trash piles is returned.
int sumAllWeights(const pile arr[], const short data_size);

//Description: The outputSectorWeights() function outputs the weight of each
//             pile in each sector.
//Pre: None.
//Post: The weights of each sector are output.
void outputSectorWeights(const pile arr[], const short data_size);

//Description: The identifyPiles() function prompts the user and gets input
//             for which pile in which sector they would like identified until
//             the user wants to quit.
//Pre: None.
//Post: The offender of the pile selected is output to the screen.
void identifyPiles(const pile arr1[], const offender arr2[], 
                   const short data_size);

//Description: The outputPerp() function displays the passed perpertrator's
//             name.
//Pre: None.
//Post: The perpertrator's name is output to the screen.                   
void outputPerp(short weight, string name);

//Description: The calcNumPiles() function calculates the number of piles in 
//             the given sector.
//Pre: None.
//Post: The calculated number of piles is returned.
short calcNumPiles(const pile arr[], const short sec, const short data_size);

//Description: The getInput() function displays and prompt, gets input from
//             the user and checks to see if the input is within range.
//Pre: None.
//Post: Input is returned if it is within range.
short getInput(const string prompt, const short min, const short max);

//Description: The signoff() function displays a sign-off to the screen.
//Pre: None.
//Post: A sign-off is output to the screen.
void signoff();

#endif
