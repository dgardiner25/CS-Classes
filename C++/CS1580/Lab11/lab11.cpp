/*
Programmer: David Gardiner, 12447993
Instructor: Rushiraj
Section: E
Date: 11/02/16
File: lab11.cpp
Description: Create Thanksgiving dinner invitations and calculate the number of
             turkeys required to feed all the guests.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

const string LAST_NAME_HOST = "Gardiner"; //Host's last name

int main()
{
  ifstream fin("Invitees.dat"); //Open the connection to invitees file
  ofstream fout1("Invitations.dat"); //Open the connection to invitations file
  ofstream fout2("Host.dat"); //Open the connection to host file
  short total_guests = 0; //Total guests used for num_turkeys calculation
  short num_turkeys; //Number of turkeys needed to feed guests
  short num_in_house; //Number of occupants in each household
  string relationship; //Relationship to host
  string name; //Name of guest
  
  fout1 << "---------------------------------------------------" << endl;
  while(getline(fin, relationship, ';')) //Loop while there is still data
  {
    relationship[0] = tolower(relationship[0]); //To improve looks
    getline(fin, name, ';');
    fin >> num_in_house;
    total_guests += num_in_house;
    
    fout1 << "###################################################" << endl
          << "\nTHANKSGIVING DINNER INVITATION" << endl
          << "\nDearest " << relationship << " " << name << ", we cordially "
          << "invite you and your family to the Thanksgiving Dinner on "
          << "November 22nd, hosted by the " << LAST_NAME_HOST << "s. We hope "
          << "to see you soon." << endl << endl
          << "---------------------------------------------------" << endl;
  
    fin.ignore(); //For some reason, there is a hidden new-line character
    fin.ignore(); //in my "Invitees.dat" file
  }
  
  num_turkeys = total_guests / 5;
  if(total_guests%5!=0)
    num_turkeys++;
  
  fout2 << "Dear Host, \n\nYou have invited " << total_guests << " number of "
        << "guests. Based on your assumption you will require " << num_turkeys
        << " number of turkeys to host the dinner successfully.\n\nHappy "
        << "Thanksgiving!" << endl;

  fin.close();
  fout1.close();
  fout2.close();
  return 0;
}
