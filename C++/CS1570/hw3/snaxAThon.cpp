//Programmer: David Gardiner          Date: 09/12/16
//File: snaxAThon.cpp                 Class: CS1570 A
//Purpose: Help create a song based off of the input
//         level of inspiration as well as determine the
//         amount of food each animal will get.

#include <iostream>
#include <string>
using namespace std;

//Number of playable notes
const short NUM_NOTES = 7;

//Range
const short LOWER_LIM = 10;
const short UPPER_LIM = 100;

//Inspiration level that ends the program
const short INSP_TERMINANT = 1;

//Next inspiration value calculations
const short EVEN_INSP_DIVISOR = 2;
const short ODD_INSP_ADDITION = 1;
const short ODD_INSP_MULTIPLIER = 3;

//Note values
const short VAL_A = 0;
const short VAL_B_FLAT = 1;
const short VAL_C_PLUS_PLUS = 2;
const short VAL_D_MINUS = 3;
const short VAL_E_SHARP = 4;
const short VAL_F_FLAT = 5;
const short VAL_H = 6;

//Note sounds
const string SOUND_A = "wah";
const string SOUND_B_FLAT = "bleep";
const string SOUND_C_PLUS_PLUS = "do-wah";
const string SOUND_D_MINUS = "ding";
const string SOUND_E_SHARP = "honk";
const string SOUND_F_FLAT = "wapp";
const string SOUND_H = "DOH!";

//Note-animal correspondance
const string ANIMAL_A = "El Chupacabra";
const string ANIMAL_B_FLAT = "BuckToothedSlug";
const string ANIMAL_C_PLUS_PLUS = "freaky fish";
const string ANIMAL_D_MINUS = "3-legged snakes";
const string ANIMAL_E_SHARP = "trash bears";
const string ANIMAL_F_FLAT = "Hans";
const string ANIMAL_H = "Cletus";


int main()
{
  //Input values
  short inspiration = 0;
  
  //Number of snacks each animal gets
  short numSnacksA = 0; 
  short numSnacksBb = 0;          
  short numSnacksCPP = 0;
  short numSnacksDMinus = 0;
  short numSnacksESharp = 0;
  short numSnacksFb = 0;
  short numSnacksH = 0;
  
  //Greeting
  cout << "Welcome to my Snax-a-Thon!" << endl;

  //Get input
  do 
  {
    cout << "\nWhat is your current inspiration on a " << LOWER_LIM
         << "-" << UPPER_LIM << " scale?        ";
    cin >> inspiration;

    //Range check    
    if(inspiration < LOWER_LIM)
      cout << "\nThat is too Ralph Wiggumian! Enter another number." << endl;
    else if(inspiration > UPPER_LIM)
      cout << "\nThat is too John Coltrainian! Enter another number." << endl;
  } while (inspiration < LOWER_LIM || inspiration > UPPER_LIM);
  
  cout << "\nThank you! Here is a song for you.\n" << endl; 

  //Play the next note of the tune and add to num times animal is fed and
  //repeat until the number to exit the inspiration calculater is hit 
  while(inspiration!=INSP_TERMINANT)
  {
    if(inspiration%NUM_NOTES==VAL_A)
    {
      cout << SOUND_A << " ";
      numSnacksA++;
    } 
    else if(inspiration%NUM_NOTES==VAL_B_FLAT)
    {
      cout << SOUND_B_FLAT << " ";
      numSnacksBb++;
    }
    else if(inspiration%NUM_NOTES==VAL_C_PLUS_PLUS)
    {
      cout << SOUND_C_PLUS_PLUS << " ";
      numSnacksCPP++;
    }
    else if(inspiration%NUM_NOTES==VAL_D_MINUS)
    {
      cout << SOUND_D_MINUS << " ";
      numSnacksDMinus++;
    }
    else if(inspiration%NUM_NOTES==VAL_E_SHARP)
    {
      cout << SOUND_E_SHARP << " ";
      numSnacksESharp++;
    }
    else if(inspiration%NUM_NOTES==VAL_F_FLAT)
    {
      cout << SOUND_F_FLAT << " ";
      numSnacksFb++;
    }
    else
    {
      cout << SOUND_H << " ";
      numSnacksH++;
    }

    
    //Determine next inspiration level
    //If insp is even, divide by EVEN_INSP_DIVISOR
    //If it is odd, multiply by ODD_INSP_MULTIPLIER 
    //  and then add ODD_INSP_ADDITION
    if(inspiration%2==0)                 
      inspiration/=EVEN_INSP_DIVISOR;
    else
      inspiration = (inspiration * ODD_INSP_MULTIPLIER) + ODD_INSP_ADDITION;
  }
  
  //Output
  cout << "\n\nNow for how much each animal gets to eat:\n" 
       << ANIMAL_A << " get(s) " << numSnacksA << " snacks.\n"
       << ANIMAL_B_FLAT << " get(s) " << numSnacksBb << " snacks.\n"
       << ANIMAL_C_PLUS_PLUS << " get(s) " << numSnacksCPP << " snacks.\n"
       << ANIMAL_D_MINUS << " get(s) " << numSnacksDMinus << " snacks.\n"
       << ANIMAL_E_SHARP << " get(s) " << numSnacksESharp << " snacks.\n"
       << ANIMAL_F_FLAT << " get(s) " << numSnacksFb << " snacks.\n"
       << ANIMAL_H << " get(s) " << numSnacksH << " snacks.\n"; 
 
  //Sign-off
  cout << "\nI hope you enjoyed the music and you enjoy your food "
       << "even more!" << endl; 
 
  return 0;
}
