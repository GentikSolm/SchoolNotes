// Program id: CSLab05.cpp
// This is our template for CS Lab 05
// REFACTORING PRACTICE PROGRAM
// This program is used for the University of Akron, Department of Computer Science Laboratories
// Goal: refactor main into functions
// examine each portion in main and analyze the code for refactoring
// Next build your function prototype
// Next build your function by copying and pasting the code from main, into your function
// repeat until complete

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
#include "Lab5header.h"
using namespace std; // forgive me for being lazy!
using std::string;
const double TAX_RATE = .05;

int main()
{
   char saleType;
   int number = 0;
   double price = 0, total = 0;

	price = getPrice();
    number = getNumber();
	saleType = getSaleType();
    total = calcTotal(saleType, price, number);

    cout << setprecision(2) << fixed << showpoint << number << " items at $" << price << endl;
    cout << "Total bill $" << total;
    if ((saleType == 'R') || (saleType == 'r')){
        cout << " includes sales tax.\n";
    }

    return 0;
}

int userInInt(string termin){
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

double userInDouble(string termin){
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

double getPrice(){
	// Requests a price from the user as a double.
	// Does input validation using userInDouble.
	// Returns price
	double price;
	cout << "Enter price $";
	price = userInDouble("$ ");
	return price;
}

int getNumber(){
	// Requests a number  from the user as a int.
	// Does input validation using userInInt.
	// Returns number
	int num;
	cout << "Enter number purchased: ";
	num = userInInt(": ");
	return num;
}

char getSaleType(){
	char userChoice;
	do{
		cout << "Type W if this is wholesale purchase. \n"
			 << "Type R if this is retail purchase. \n"
			 << "then press return... \n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.get(userChoice);
	}while(!((userChoice == 'R') || (userChoice == 'r') || (userChoice == 'W') || (userChoice == 'w')));

	return userChoice;
}

double calcTotal(char saleType, double price, int number){
	double total = 0;
	double subTotal = 0;
	if ((saleType == 'W') || (saleType == 'w'))
    {
        total = price * number;
    }
    else if ((saleType == 'R') || (saleType == 'r'))
    {
        subTotal = price * number;
        total = subTotal + subTotal * TAX_RATE;
    }
	return total;
}
