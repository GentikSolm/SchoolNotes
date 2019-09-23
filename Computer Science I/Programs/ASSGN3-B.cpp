/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN3-B
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.02 09.18.2019
  Purpose: Mad libs!
*/
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(){
	//Variables for mad libs words
	int number;
	string name, noun, bodyPart, verb;
	cout << "Welcome to Madlibs!" << endl;
	cout << "Please enter the word types into the prompt one by one." << endl;
	//Inputs for all the variables
	cout << "Name: ";
	cin >> name;
	cout <<"Noun: ";
	cin >> noun;
	cout <<"Number: ";
	cin >> number;
	cout <<"BodyPart: ";
	cin >> bodyPart;
	cout <<"Verb: ";
	cin >> verb;
	//actual madlibs output
	cout << "Thanks! Let me put that togeather. . .\n\n";
	cout << "The famous explorer " << name << " had nearly given up a life-long quest ";
	cout << "to find the lost city of " << noun << " when one day the " << noun << " found the explorer.\n\n";
	cout << "Surrounded by " << number << ' ' << noun << ", a tear came to " << name << "'s " << bodyPart;
	cout << ". After all this time, the quest was finally over. And then, the " << noun << " promply devoured " << name;
	cout << ".\n\nThe moral of the story? Be careful what you " << verb << " for.";
}
