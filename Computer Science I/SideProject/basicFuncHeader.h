#ifndef BASICFUNCHEADER_H
#define BASICFUNCHEADER_H

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <ctime>
using std::cin;
using std::cout;
using std::string;

namespace basic{
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

}
#endif /* BASICFUNCHEADER_H */
