//Programmer: DAVID GARDINER (A) & BRANDON HENRY (B)          
//Date: 10/31/16
//Class: CS1570
//File: debate.cpp                    
//Purpose: Function definitions to help Lisa get 
//         practice debating before her real debate.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "debate.h"
using namespace std;

short getRand(const short min, const short max)
{
  return rand()%(max-min+1)+min;
}

short askQuestion(const short cand_num)
{
  char question[MAX_SENTENCE_LENGTH];
  short q_length;
  cout << "\nCandidate #" << cand_num << ": ";
  cin.getline(question, MAX_SENTENCE_LENGTH, '?');
  q_length = strlen(question);
  return q_length;
}

short pickAnswer(const short q_length, const char file_name[], 
                const short cand_num)
{ 
  ifstream fin(file_name);
  short num_lines;
  short rand_num;
  short num_sentences = getRand(MIN_SENTENCES, MAX_SENTENCES);
  short total_cnt;
  short cnt;
  short score;
  char answer[MAX_SENTENCE_LENGTH] = {'\0'};
  char prefix[MAX_SENTENCE_LENGTH] = {'\0'};
  char current_word[MAX_WORD_LENGTH] = {'\0'};
  string ans_arr[50];
  
  fin >> num_lines;
  fin.ignore();
  
  
  for(int i=0; i<num_lines; i++)
  {
    getline(fin, ans_arr[i]);
  }
  for(int i=0; i<num_sentences; i++)
  {
    rand_num = getRand(0, num_lines-1);
    total_cnt = (ans_arr[rand_num].length()/num_sentences)*(i);
    cnt = 0;
    if(i)
    {
      while(ans_arr[rand_num][total_cnt]!=' ')
      {
        total_cnt++;
      }
    }
    while(total_cnt < (ans_arr[rand_num].length() * (i+1))/num_sentences || 
          isalpha(ans_arr[rand_num][total_cnt]))  
    {
      current_word[cnt] = ans_arr[rand_num][total_cnt++];
      if(!isalpha(current_word[++cnt]))
      {
        current_word[cnt] = '\0';
        strcat(answer, current_word);
        cnt = 0;
      }
      else
        cnt++;
    }
    if(rand()%100<INTERJECTION_CHANCE && i!=num_sentences-1)
    {    
      pickInterjection(answer, cand_num);
    }
  }
  
  if(rand()%100<PREFIX_CHANCE)
  {
    pickPrefix(prefix, answer);
  }
  
  pickPunctuation(answer);
  
  score = calcScore(q_length, answer);
  
  cout << "Answer: " << answer << endl;
  cout << "Score : " << score << endl;

  fin.close();
  return score;
}

void pickInterjection(char answer[], const short cand_num)
{
  ifstream fin;
  short num_lines;
  short rand_num;
  char interjection[MAX_SENTENCE_LENGTH];
  
  if(cand_num==1)
    fin.open(CAND1_INTERJECTION_FILE);
  else
    fin.open(CAND2_INTERJECTION_FILE);
    
  fin >> num_lines;
  fin.ignore();  
  
  rand_num = getRand(0,num_lines-1);
    
  for(int i=0; i<num_lines-1;i++)
  {
    if(fin.getline(interjection, MAX_SENTENCE_LENGTH) && i==rand_num)
    {
      strcat(answer, interjection);
    }
  }
  fin.close();
  return;
}

void pickPrefix(char prefix[], char answer[])
{
  ifstream fin_prefix(PREFIX_FILE);
  short counter = 0;
  short rand;
  string prefix_arr[50];
  while(getline(fin_prefix, prefix_arr[counter]))
  {
    prefix_arr[counter] += " ";
    counter++;
  }
  rand = getRand(0,counter-1);
  for(int i=0; i<counter; i++)
  {
    if(i==rand)
    {
      strcpy(prefix, prefix_arr[i].c_str());
    }
  }
  strcat(prefix, answer);
  strcpy(answer, prefix);
  fin_prefix.close();
  return;
}

void pickPunctuation(char answer[])
{
  short rand_num = getRand(1,100);
  short ans_length = strlen(answer);
  char temp[MAX_SENTENCE_LENGTH] = {'\0'};
  strncpy(temp, answer, ans_length-1);
  if(rand_num <= PERIOD_CHANCE)
  {
    strcat(temp, ".\0");
  }
  else if(rand_num <= Q_MARK_CHANCE + PERIOD_CHANCE)
  {
    strcat(temp, "?\0");
  }
  else
  {
    strcat(temp, "!\0");
  }
  strcpy(answer, temp);
  return;
}

short calcScore(const short q_length, const char arr[])
{
  short word_score = 0;
  short total_score = 0;
  short count = 0;
  while(arr[count]!=0)
  {
    switch(tolower(arr[count]))
    {
      case 'e':
      case 'a':
      case 'i':
      case 'o':
      case 'n':
      case 'r':
      case 't':
      case 'l':
      case 's':
      case 'u':
        word_score+=(1*calcChance(CHAR_DBL_CHANCE, CHAR_TRPL_CHANCE)); 
        break;
      case 'd':
      case 'g':
        word_score+=(2*calcChance(CHAR_DBL_CHANCE, CHAR_TRPL_CHANCE));
        break;
      case 'b':
      case 'c':
      case 'm':
      case 'p':
        word_score+=(3*calcChance(CHAR_DBL_CHANCE, CHAR_TRPL_CHANCE));
        break;
      case 'f':
      case 'h':
      case 'v':
      case 'w':
      case 'y':
        word_score+=(4*calcChance(CHAR_DBL_CHANCE, CHAR_TRPL_CHANCE));
        break;
      case 'k':
        word_score+=(5*calcChance(CHAR_DBL_CHANCE, CHAR_TRPL_CHANCE));
        break;
      case 'j':
      case 'x':
        word_score+=(8*calcChance(CHAR_DBL_CHANCE, CHAR_TRPL_CHANCE));
        break;
      case 'q':
      case 'z':
        word_score+=(10*calcChance(CHAR_DBL_CHANCE, CHAR_TRPL_CHANCE));
        break; 
      default:
        word_score*=calcChance(WORD_DBL_CHANCE, WORD_TRPL_CHANCE);
        total_score+=word_score;
        word_score = 0;
    }
    count++;
  }
  return (total_score/q_length);
}

short calcChance(const short percent_dbl, const short percent_trpl)
{
  short ret = 1;
  if(rand()%100 < percent_trpl)
    ret = 3;
  else if(rand()%100 < percent_dbl)
    ret = 2;
  return ret;
}

void displayWinner(const short score1, const short score2)
{
  short win_score = score1;
  char win_name[15] = "Candidate 1";
  
  if(score2 < score1)
  {
    win_score = score2;
    strcpy(win_name, "Candidate 2\0");
  }
  if(score1 == score2)
    cout << "\nI can't believe it! The candidates tied with " << win_score 
         << " each!" << endl;
  else
    cout << "\nAnd the winner, with a score of " << win_score << " points... "
         << win_name << "!" << endl;
  return;
}















