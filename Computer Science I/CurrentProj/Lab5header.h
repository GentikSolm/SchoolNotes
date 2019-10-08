#ifndef LAB5HEADER_H
#define LAB5HEADER_H
#include <string>
using std::string;
int userInInt(string termin = "\n-> ");
	// Requests and int from the user and then verifies it is an int.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT

double userInDouble(string termin = "\n-> ");
	// Requests Double from the user and then verfies it is a double.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT

double getPrice();
	// Requests a price from the user as a double.
	// Does input validation using userInDouble.
	// Returns price
int getNumber();
	// Requests a number  from the user as a int.
	// Does input validation using userInInt.
	// Returns number

char getSaleType();
	// Gets a char from the user that is either R or W or r or w.
	// Will do input validation.
	// returns user's choice.

double calcTotal(char saleType, double price, int number);
	// takes in sale type, price, and  number of items
	// First checks to see if retial or whole sale, then does needed calculations
	// to find the total cost. returns this cost as a double.

#endif
