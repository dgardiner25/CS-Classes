//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)          
//Date: 10/31/16
//Class: CS1570
//File: debate.cpp                    
//Purpose: Help Lisa get practice debating before her real debate.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "debate.h"
using namespace std;

int main()
{
  short question_length;    //Length of question asked
  short c1_score = 0;       //Total of candidate 1's score
  short c2_score = 0;       //Total of candidate 2's score
  
  //Seed the RNG
  srand(time(NULL));
  
  //Greet the user
  cout << "Welcome to this year's city office debate!" << endl
       << "I'm your host David Gardiner, here with Brandon Henry." << endl
       << "Let's get started with the questions:" << endl;
  
  for(int i=0; i<NUM_QUESTIONS; i++)
  { 
    //Ask candidate 1 a question
    question_length = askQuestion(1);                       
    //Generate candidate 1's answer
    c1_score += pickAnswer(question_length, CAND1_SENTENCE_FILE, 1);

    //Ask candidate 2 a question
    question_length = askQuestion(2);                       
    //Generate candidate 2's answer
    c2_score += pickAnswer(question_length, CAND2_SENTENCE_FILE, 2);    
  }  
  
  //Display the winner
  displayWinner(c1_score, c2_score);
  
  //Sign-off
  cout << "Well folks, that's all the time we have." << endl
       << "I hope you enjoyed it as much as we have!" << endl;

  return 0;
}
