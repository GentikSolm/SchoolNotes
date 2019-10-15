/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN5-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 10.12.2019
  Purpose: Check for primes
*/
#include <iostream>
#include <limits>
#include <cmath>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int userInInt(string termin = "\n-> ");
	// Requests and int from the user and then verifies it is an int.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT

void checkForPositive(int &num);
	// Takes in a reference to a INT variable, and
	// comfirms that the number is positive. If it is not,
	// it will ask for a new positive number. It will also do
	// input verification using userInInt()

bool isPrime(int userInput);
	//precondition:: userInput must be positive number!
	//postcondition::  Checks if the given number is prime or not.
	// According to common mathmatics, 1 is not prime, and the program will return
	// that it is false if given 1.

int main(){
	// number to be checked
	int userInput;
	cout << "Enter a number to determine if it is prime, to exit, enter -1.\n-> ";
	userInput = userInInt();

	// Controls flow of program, if user enters 1, program stops
	while(userInput != -1){
		// Makes sure userInput is positive
		checkForPositive(userInput);
		// Prints if the number is prime
		if(isPrime(userInput)){
			cout << userInput << " Is prime!\n";
		}
		else {
			cout << userInput << " Is not prime!\n";
		}
		// Prints all primes under entered number
		cout << "Other primes are: \n";
		for(int i = 2; i < userInput;i++){
			if(isPrime(i)){
				cout << i << '\t';
			}
		}
		cout << "\nEnter the next number\n-> ";
		userInput = userInInt();
	}
	cout << "Goodbye!";
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

void checkForPositive(int &num){
	// Takes in a reference to a INT variable, and
	// comfirms that the number is positive. If it is not,
	// it will ask for a new positive number. It will also do
	// input verification using userInInt()
	while(num < -1){
		cout << "Please enter a positive number!\n-> ";
		num = userInInt();
	}

}

bool isPrime(int userInput){
	// Checks if the given number is prime or not.
	// According to common mathmatics, 1 is not prime, and the program will return
	// that it is false if given 1.
	int i = 2;
	if(userInput == 2 || userInput == 3 || userInput == 1) return true;
	while(sqrt(userInput) >= i){
		if(userInput % i ==0){
			return false;
		}
		i++;
	}
	return true;
}
