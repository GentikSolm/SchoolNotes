/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  Personal
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 9.29.2019
  Purpose: Some simple functions that are used in general programs
*/
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <ctime>
using std::cin;
using std::cout;
using std::string;

// The following functions are for input verification.
int userInInt(string termin);
	// Requests and int from the user and then verifies it is an int.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT

double userInDouble(string termin);
	// Requests Double from the user and then verfies it is a double.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT

// Returns a random number between the given inputs, max and min
int randBetween(int max, bool noError);
	// Returns a number that is between the Max and 1. If Max <= 1,
		// this will cout error and return -1.
	// If the function should be used in a case where it is okay for Max <= 1, pass in noError = true
		// this will cause the program to not error and return a value that is in absoulute value of the range.

int userInInt(string termin = "\n-> "){
	int temp;
	cin >> temp;
	while(cin.fail()){
		cout << "That was not a number! Please enter a number" << termin;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> temp;
	}
	return temp;
}

double userInDouble(string termin = "\n-> "){
	double temp;
	cin >> temp;
	while(cin.fail()){
		cout << "That was not a number! Please enter a number" << termin;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> temp;
	}
	return temp;
}

int randBetween(int max = 10, bool noError = false){
	srand(time(0));
	int num = 0, min = 1;
	int randRange = max - min;
	if(randRange <=0 && !noError){
		cout << "\n\nERROR: Max must be more than 1! Returned -1.\n";
		return -1;
	}
	else num = rand() % abs(randRange) + min;
	return num;
}
