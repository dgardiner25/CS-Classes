/*
Programmer: David Gardiner
Instructor: Rushiraj
Section: E
Date: 09/21/16
Description: Play blackjack, high or low, or leave 
             given user input at a casino.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  //Input variables
  short gameChoice;           //What the user wants to do
  bool leave = false;         //For checking if user wants to leave
  
  //Blackjack variables
  short dCard1;               //Dealer's first card
  short dCard2;               //Dealer's second card
  short pCard1;               //Player's first card
  short pCard2;               //Player's second card
  short totalDealer;          //Total of dealer's cards
  short totalPlayer;          //Total of player's cards
  
  //High or Low variables
  short hLNum1;               //First random number
  short hLNum2;               //Second random number    
  char highLow;               //User's choice of high or low
  
  //Greeting
  cout << "Welcome to the Switch Casino!\n" << endl;

  //Seed the RNG
  srand(time(NULL));
  
  //Get input until user leaves
  do
  {
    //Present options
    cout << "1. Blackjack\n"
         << "2. High or Low\n"
         << "3. Leave the casino\n"
         << "What would you like to do? (1-3)     ";
    cin >> gameChoice;
    
    switch (gameChoice)
    {
      //Blackjack
      case 1:
        cout << "\n-----Welcome to the Blackjack table-----" << endl;
        
        //Generate random cards for dealer
        dCard1 = rand() % 10 + 1;
        dCard2 = rand() % 10 + 1;
        totalDealer = dCard1 + dCard2;
        cout << "Dealer's cards are: " << dCard1 << " and " << dCard2 << endl;
        
        //Generate random cards for player
        pCard1 = rand() % 10 + 1;
        pCard2 = rand() % 10 + 1;
        totalPlayer = pCard1 + pCard2;
        cout << "Your cards are: " << pCard1 << " and " << pCard2 << endl;
        
        //Determine if dealer wins, player wins, or there is a tie
        if(totalDealer > totalPlayer)
          cout << "Dealer wins, you lose!\n" << endl;
        else if(totalPlayer > totalDealer)
          cout << "You win, dealer loses!\n" << endl;
        else
          cout << "Tie, no one wins!\n" << endl;
        break;
      
      //High or low   
      case 2:
        cout << "\n-----Welcome to the High or Low table-----" << endl;
        
        //Generate random first number
        hLNum1 = rand() % 100 + 1;
        cout << "First number: " << hLNum1 << endl;
        
        //Ask if user wants to guess high or low for next number
        cout << "Will the next number be higher or lower? (h/l)     ";
        cin >> highLow;
        
        //Generate random second number
        hLNum2 = rand() % 100 + 1;
        cout << "Second number: " << hLNum2 << endl;
        
        //Check to see if user is correct
        if((highLow=='h' || highLow=='H') && (hLNum2 > hLNum1))
          cout << "Correct, you win!\n" << endl;
        else if((highLow=='l' || highLow=='L') && (hLNum2 < hLNum1))
          cout << "Correct, you win!\n" << endl;
        else
          cout << "Incorrect, you lose!\n" << endl;
        break;
         
        //Leave
        case 3:
          leave = true;
          
          //Sign-off
          cout << "Thanks for playing!" << endl;
          break;
          
        //Invalid input
        default:
          cout << "Please enter a valid option.\n" << endl;
    
    }
  } while(!leave);

  return 0;
}
