//Programmer: DAVID GARDINER               Date: 3/8/2017
//File: braincalc.cpp                      Class: 1510 C
//Purpose: Brain expression calculator for the Earth Defence Forces

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include "astack.h"
using namespace std;

// Description: Converts an infix equation into postfix for easier computation.
// Pre: Operators and operands must be separated by white space.
// Post: The infix argument has been converted and returned as postfix.
string infixToPostfix(const string infix);

// Description: Evaluates a postfix expression.
// Pre: Operators and operands must be separated by white space.
// Post: The result of the expression is returned.
int calcPost(const string postfix);

// Description: Calculates the desired operation.
// Pre: None.
// Post: The result of the operation is returned.
int doOperation(const int op1, const int op2, const char operation);

// Description: Checks if c is an operator.
// Pre: None.
// Post: True is returned if c is an operator.
bool isOp(const char c);

// Description: Checks if c is an operator.
// Pre: The operator must be in position 0 of c.
// Post: True is returned if c is an operator.
bool isOp(const string c);

// Description: Checks if c is a left bracket or parenthases.
// Pre: None.
// Post: True is returned if c is a left bracket or parenthases.
bool isLeftBracket(const char c);

// Description: Checks if c is a right bracket or parenthases.
// Pre: None.
// Post: True is returned if c is a right bracket or parenthases.
bool isRightBracket(const char c);

// Description: CHecks to see if l is of higher precedence than r.
// Pre: l and r must be operators.
// Post: True is returned if l is of higher precedence than r.
bool higherPrec(const char l, const char r);

// Description: Gives a weight to the passed character to determine precedence.
// Pre: c must be an operator.
// Post: The weight of c is returned.
short getWeight(const char c);

int main()
{
  string infix;
  string postfix = "";
  short count = 1;
  getline(cin, infix);
  while(infix[0] != '.')
  {
    postfix = infixToPostfix(infix);
    cout << postfix << endl;
    if(postfix != "")
      cout << "#" << count++ << ": " << calcPost(postfix) << endl;
    else
      cout << "INVALID!" << endl;
    getline(cin, infix);
  }
  return 0;
}

string infixToPostfix(const string infix)
{
  ArrayStack<char> s;
  string postfix = "";
  for(unsigned int i=0; i<infix.length(); i++)
  {
    char c = infix[i];
    if(isOp(c)) // If c is an operator
    {
      if(!s.isEmpty() && !isLeftBracket(s.top()) && higherPrec(c,s.top()))
        postfix += c;
      else
      {
        while(!s.isEmpty() && !isLeftBracket(s.top()) && higherPrec(s.top(),c))
        {
          postfix += s.top();
          s.pop();
        }
      s.push(c);
      }
    }
    else if(isdigit(c)) // Add digit to postfix string
      postfix += c;
    else if(isLeftBracket(c)) // Put left bracket on stack
      s.push(c);
    else if(isRightBracket(c))
    {
      // While s.top() is not a left bracket
      while(!s.isEmpty() && !isLeftBracket(s.top()))
      {
        postfix += s.top(); // Add operator at top of stack to postfix
        s.pop();
        // If not matching brackets (invalid)
        if((c == ')' && s.top() != '(') || (c == ']' && s.top() != '[') ||
           (c == '}' && s.top() != '{'))
          return "";
      }
      if(s.isEmpty()) // If no matching left bracket
        return "";
      s.pop();
    }
    else if(c == ' ') // Add space to keep operators and operands separate
      postfix += c;
  }

  while(!s.isEmpty())
  {
    //If extra left bracket (not balanced)
    if(s.top() == '(' || s.top() == '[' || s.top() == '{')
      return "";
    postfix += " ";
    postfix += s.top(); // Pop the remaining operators
    s.pop();
  }

  return postfix;
}

int calcPost(const string postfix)
{
  ArrayStack<int> s;
  istringstream inputstr(postfix);
  int op1, op2;
  string s1;

  while(inputstr >> s1) // While there is still input
  {
    if(isOp(s1[0])) // If s1[0] is operator, perform operation and add to stack
    {
      op2 = s.top();
      s.pop();
      op1 = s.top();
      s.pop();
      s.push(doOperation(op1, op2, s1[0]));
    }
    else if(isdigit(s1[0]))
    {
      s.push(atoi(s1.c_str()));
    }
  }

  return s.top();
}

int doOperation(const int op1, const int op2, const char operation)
{
  if(operation == '+')
    return op1 + op2;
  else if(operation == '-')
    return op1 - op2;
  else if(operation == '*')
    return op1 * op2;
  else if(operation == '/')
    return op1 / op2;
  return op1 % op2;
}

bool isOp(const char c)
{
  if(c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
    return true;
  return false;
}

bool isLeftBracket(const char c)
{
  if(c == '(' || c == '[' || c == '{')
    return true;
  return false;
}

bool isRightBracket(const char c)
{
  if(c == ')' || c == ']' || c == '}')
    return true;
  return false;
}

bool higherPrec(const char l, const char r)
{
  if(getWeight(l) >= getWeight(r))
    return true;
  else
    return false;
}

short getWeight(const char c)
{
  short weight = 0;
  if(c == '+' || c == '-')
    weight = 1;
  else if(c == '*' || c == '/' || c == '%')
    weight = 2;
  return weight;
}
