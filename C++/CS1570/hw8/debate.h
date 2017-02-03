//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)          
//Date: 10/31/16
//Class: CS1570
//File: debate.cpp                    
//Purpose: Constants and function prototypes to help Lisa get 
//         practice debating before her real debate.

#ifndef DEBATE_H
#define DEBATE_H
using namespace std;

//------Constants------//
const short NUM_QUESTIONS = 4;
const short CHAR_DBL_CHANCE = 3;
const short CHAR_TRPL_CHANCE = 2;
const short WORD_DBL_CHANCE = 5;
const short WORD_TRPL_CHANCE = 2;
const short PREFIX_CHANCE = 50;
const short INTERJECTION_CHANCE = 25;
const short PERIOD_CHANCE = 40;
const short Q_MARK_CHANCE = 30;
const short E_POINT_CHANCE = 30;

const short MIN_SENTENCES = 2;
const short MAX_SENTENCES = 4;
const short MAX_SENTENCE_LENGTH = 1000;
const short MAX_WORD_LENGTH = 20;

const char CAND1_SENTENCE_FILE[50] = "candidate1_sentences.dat";
const char CAND2_SENTENCE_FILE[50] = "candidate2_sentences.dat";
const char CAND1_INTERJECTION_FILE[50] = "candidate1_interjections.dat";
const char CAND2_INTERJECTION_FILE[50] = "candidate2_interjections.dat";
const char PREFIX_FILE[50] = "prefix_expressions.dat";

//------Function Prototypes------//
//Description: The getRand() function generates a random integer value between
//             the min and max values passed to it.
//Pre: None.
//Post: A random number is returned.
short getRand(const short min, const short max);

//Description: The askQuestion() function prompts the user to ask a question
//             for a certain candidate and then calculates and returns the 
//             number of characters in the question.
//Pre: None.
//Post: A question is read in from the user and the number of characters in
//      said question is returned.
short askQuestion(const short cand_num);

//Description: The pickAnswer() function randomly combines anywhere from 2-4
//             sentences, has the chance to add in a prefix expression and
//             interjections between the sentence fragments, and outputs the
//             newly created phrase as an answer with its score.
//Pre: None.
//Post: An answer and a score is output to the screen, the score is returned.
short pickAnswer(const short q_length, const char file_name[], 
                const short cand_num);

//Description: The pickInterjection() function randomly picks an interjection
//             based on the candidate number passed.
//Pre: cand_num must be 1 or 2.
//Post: An interjection is added to the answer.
void pickInterjection(char answer[], const short cand_num);

//Description: The pickPrefix() function randomly picks a prefix.
//Pre: None.
//Post: A prefix is added to the beginning of the answer.
void pickPrefix(char prefix[], char answer[]);

//Description: The pickPunctuation() function randomly picks between a period,
//             question mark, or exclamation point to replace the very last
//             period of the answer with.
//Pre: None.
//Post: The ending punction stays the same or gets changed to a question mark
//      or exclamation point.
void pickPunctuation(char answer[]);

//Description: The calcScore() function calculates the score based on each
//             letter and word, each with a chance to be doubled or tripled
//             and the combined total of the words is divided by the number
//             of characters of the question asked.
//Pre: None.
//Post: A score is returned.
short calcScore(const short q_length, const char arr[]);

//Description: The calcChance() function returns either 1, 2, or 3 dependent on
//             the chance to double or triple the score.
//Pre: None.
//Post: 1, 2, or 3 is returned.
short calcChance(const short percent, const short multiplier);

//Description: The displayWinner() function determines and displays the winner.
//Pre: None.
//Post: A winner is output to the screen.
void displayWinner(const short score1, const short score2);

#endif
