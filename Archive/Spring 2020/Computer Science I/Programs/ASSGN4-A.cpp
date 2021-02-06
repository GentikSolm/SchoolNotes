/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN4-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 10.2.2019
  Purpose: compute future bank account balances
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;
using std::string;

double newBalance(double initialBalance, double interestRate);
	// This first version of the new balance function computes the
	// final account balance that will be reached by starting with
	// an initial balance and adding one year's interest at a given
	// interest rate (such as 0.05 for 5%). The function works
	// correctly for any non-negative arguments.

double newBalance(double initialBalance, double interestRate, int n);
	// This second version of the new balance function computes the
	// final account balance that will be reached by starting with
	// an initial balance and adding some n number of years of interest
	// at a given interest rate (such as 0.05 for 5%). The interest is added
	// once per year and it is applied to the entire balance.
	// For example, new_balance(100.00, 0.10, 2) is 121.00 since
	// the first year received 10.00 interest (10% of 100) and the
	// second year received 11.00 interest (10% of the 110, which
	// was the second year's starting balance). The function works
	// correctly for any non-negative arguments.
	// Notice n is not an appropriate variable name, but will not be
	// deducted for this program.

int yearsNeeded(double initialBalance, double interestRate, double goal);
   // The years needed function computes the number of years needed for
   // a given starting balance to reach a given goal at a certain rate
   // of compound interest. The function works correctly for any
   // positive arguments

double userInDouble(string termin = ": ");
	// Requests Double from the user and then verfies it is a double.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT

int main(){
	cout << "Please enter your starting ammount: ";
	double startingAmmount = userInDouble();
	while((startingAmmount <= 0)){
		//makes sure startingAmmount is at least 0
		cout << "Starting ammount must be more greater than or equal to 0!: ";
		startingAmmount = userInDouble();
	}
	cout << "Please enter the interest rate: ";
	double interestRate = userInDouble();
	while(interestRate <= 0.0){
	//makes sure interestRate is at least 0
		cout << "interest rate must be more greater than or equal to 0!: ";
		interestRate = userInDouble();
	}

	cout.precision(2);
	cout.setf(std::ios::fixed, std::ios::floatfield);
	//returns of all the different balances and years needed.
	cout << "Your balance is $"<< newBalance(startingAmmount, interestRate);
	cout << " after one year.\n";
	cout << "After ten years, your balance is $";
	cout << newBalance(startingAmmount, interestRate, 10);
	cout << std::endl << "In order to reach a million dollars, it will ";
	cout << "take " << yearsNeeded(startingAmmount, interestRate, 1000000000) << " years.";
}



double newBalance(double initialBalance, double interestRate){
	// This first version of the new balance function computes the
	// final account balance that will be reached by starting with
	// an initial balance and adding one year's interest at a given
	// interest rate (such as 0.05 for 5%). The function works
	// correctly for any non-negative arguments.
	return initialBalance * (1 + interestRate);
}

double newBalance(double initialBalance, double interestRate, int n){
	// This second version of the new balance function computes the
	// final account balance that will be reached by starting with
	// an initial balance and adding some n number of years of interest
	// at a given interest rate (such as 0.05 for 5%). The interest is added
	// once per year and it is applied to the entire balance.
	// For example, new_balance(100.00, 0.10, 2) is 121.00 since
	// the first year received 10.00 interest (10% of 100) and the
	// second year received 11.00 interest (10% of the 110, which
	// was the second year's starting balance). The function works
	// correctly for any non-negative arguments.
	// Notice n is not an appropriate variable name, but will not be
	// deducted for this program.
	return initialBalance * pow((1 + interestRate),n);
}

int yearsNeeded(double initialBalance, double interestRate, double goal){
   // The years needed function computes the number of years needed for
   // a given starting balance to reach a given goal at a certain rate
   // of compound interest. The function works correctly for any
   // positive arguments
   double balance = initialBalance;
   int years = 0;
   while(balance < goal){
	   //repeats untill the balance has reached the goal
	   balance *= (1 + interestRate);
	   years++;
   }
   return years;
}

double userInDouble(string termin){
	// Requests Double from the user and then verfies it is a double.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT
	double num;
	cin >> num;
	while(cin.fail()){
		cout << "That was not a number! Please enter a number" << termin;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> num;
	}
	return num;
}
