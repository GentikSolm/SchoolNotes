/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGNA
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 1.27.2020
  Purpose:
*/
#include <vector>
#include <iostream>

//These are used for input validation and setprecision.
#include <limits>
#include <iomanip>

using std::cout;
using std::cin;

struct taxPayer{
	float taxRate;
	float income;
	float totalTaxes;
};

//Size of vectors
const int SIZE = 2;

/*
Since taxPrint is only printing the contents of the array, using const to stop
	 any unwanted changes

Since both are taking in citizen, a vector, we must declare it as a vector and
	pass it by reference. This is required because we are creating the
	taxPayer structs inside the function to the vector, and these changes to
	save to the actual vector, not a copy.

*/
void taxPrint(const std::vector<taxPayer>&);
// Takes in a vector of taxPayer structs and outputs the totalTaxes variable

void taxTaker(std::vector<taxPayer>&);
//fills vector with taxPayer structs. uses global SIZE variable. fills income,
//	taxRate, and calculates totalTaxes

int main()
{
   std::vector<taxPayer> citizen;
   taxTaker(citizen);
   taxPrint(citizen);
   return 0;
}

void taxTaker(std::vector<taxPayer> &citizen){
	float temp;
	//used for input verification
	//IMPORTANT: when comparing temp with a number, make sure to lable it float,
	//	see (1)
	for(int i = 0; i < SIZE; i++){
		//need loop for each struct

		citizen.push_back(taxPayer());
		//use this to initialize a taxPayer struct inside citizen

		cout << "Enter this year's income for tax payer " << i + 1 << ": ";
		cin >> temp;
		while(cin.fail() || temp <= 0){
			//Standard input verification
			cout << "That was not a number greater than Zero! Please enter a number: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> temp;
		}
		citizen[i].income = temp;
		//fills income with the verified value in temp

		cout << "Enter the tax rate for tax payer # " << i + 1 << ": ";
		cin >> temp;
		while(cin.fail() || temp < .01f || temp > 9.9f){
			// (1) - This will not work if the f is not included.
			// Since floating point is not exact, need to set both numbers to floating point
			// will not accept .01 if the f is not included
			cout << "That was not a number between .01 and 9.9! Please enter a number: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> temp;
		}
		citizen[i].taxRate = temp;

		citizen[i].totalTaxes = citizen[i].income * (citizen[i].taxRate/100);
		//calculates totalTaxes from income and taxRate
		// MUST INCLUDE /100 TO CONVERT FROM PERCENTAGE TO DECIMAL
		cout << std::endl;
	}
}
void taxPrint(const std::vector<taxPayer> &citizen){
	//const so that the vector is untouched, uses reference for speed.
	cout << "Taxes due for this year:\n\n";
	cout << std::fixed << std::setprecision(2);
	//use setprecision for two decimal points after monetary value.
	for(int i = 0; i < SIZE; i++){
		cout << "Tax Payer # " << i + 1 << ": $ " <<  citizen[i].totalTaxes << '\n';
	}
}
