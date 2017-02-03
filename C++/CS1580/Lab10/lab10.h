/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 10/26/16
File: lab10.h
Description: Function prototypes to encrypt a given name using an NTCA.
*/

#ifndef LAB10_H
#define LAB10_H

using namespace std;

//------Constants------//
const short DATA_SIZE = 50; //Max size of the array

//Description: The greeting() function displays a greeting to the user.
//Pre: None.
//Post: A greeting is output to the screen.
void greeting();

//Description: The getInput() function gets input from the user.
//Pre: None.
//Post: The user's input is put into a null-terminated character array.
void getInput(char arr[]);

//Description: The encrypt() function encrypts the passed NTCA.
//Pre: The passed array must contain the null character.
//Post: Each letter of the array will be shifted by 3 and if the letter is 
//      x, y, or z, it will be shifted back by 23. 
void encrypt(char arr[]);

//Description: The showOutput() function displays the passed NTCA.
//Pre: The passed array must contain the null character.
//Post: The array is output to the screen.
void showOutput(char arr[]);

//Description: The signoff() function displays a greeting to the user.
//Pre: None.
//Post: A sign-off is output to the screen.
void signoff();

#endif
