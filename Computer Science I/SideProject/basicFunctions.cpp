/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  Personal
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 9.29.2019
  Purpose: Some simple functions that are used in general programs
*/

int userInInt(string termin = "\n-> "){
	// Requests and int from the user and then verifies it is an int.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT
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
	// Requests Double from the user and then verfies it is a double.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT
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
	// Returns a number that is between the Max and 1. If Max <= 1,
		// this will cout error and return -1.
	// If the function should be used in a case where it is okay for Max <= 1, pass in noError = true
		// this will cause the program to not error and return a value that is in absoulute value of the range.

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

// All of these functions will cout the given variable or string.
//{
void print(int aNum){
	cout << aNum;
}
void print(double aDouble){
	cout << aDouble;
}
void print(string aString){
	cout << aString;
}
void print(char aChar){
	cout << aChar;
}
//}
