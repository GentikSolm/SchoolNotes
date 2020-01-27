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
#include <limits>
#include <iomanip>
using std::cout;
using std::cin;
struct taxPayer{
	float taxRate;
	float income;
	float totalTaxes;
};

const int SIZE = 2;
void taxPrint(const std::vector<taxPayer>&);
void taxTaker(std::vector<taxPayer>&);

//Need to ask, should each function loopfor the vector, or should
// main loop.
int main()
{
   std::vector<taxPayer> citizen;
   taxTaker(citizen);
   taxPrint(citizen);
   return 0;
}
void taxTaker(std::vector<taxPayer> &citizen){
	float temp;
	for(int i = 0; i < SIZE; i++){
		citizen.push_back(taxPayer());
		cout << "Enter this year's income for tax payer " << i + 1 << ": ";
		cin >> temp;
		while(cin.fail() || temp <= 0){
			cout << "That was not a number greater than Zero! Please enter a number: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> temp;
		}
		citizen[i].income = temp;
		cout << "Enter the tax rate for tax payer # " << i + 1 << ": ";
		cin >> temp;
		while(cin.fail() || temp < .01 || temp > 9.9){
			cout << "That was not a number between .01 and 9.9! Please enter a number: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> temp;
		}
		citizen[i].taxRate = temp;

		citizen[i].totalTaxes = citizen[i].income * citizen[i].taxRate;
	}
}
void taxPrint(const std::vector<taxPayer> &citizen){
	cout << "Taxes due for this year:\n\n";
	cout << std::fixed << std::setprecision(2);
	for(int i = 0; i < SIZE; i++){
		cout << "Tax Payer # " << i + 1 << ": $ " <<  citizen[i].totalTaxes << '\n';
	}
}
