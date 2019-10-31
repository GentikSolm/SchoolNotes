/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN6-B
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 10.29.2019
  Purpose: Read farmers market stuff.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::setw;

void makeHeader();
	// No Prereqs
	// Sole purpose is to print out the header
	// for the report.

void fileExtract(ifstream &input, ofstream &output, int &totalAmmount, double &totalCost);
	//Files are guarented to be present, but this is still a prereq
	// Takes files and extracts all variables, then sending them to other functions.
	// Brings in totalammount and totalcost as reference to modify
	// them in main so that the final cout statement works
	// Also places new data in report.txt


int main(){
	makeHeader();
	ifstream input;
	ofstream output;
	int totalAmmount = 0;
	double totalCost = 0;
	input.open("ASSGN6-A.txt");
	output.open("Report.txt");
	// print all lines to console
	fileExtract(input, output, totalAmmount, totalCost);
	// grand total output
	cout << setw(26) <<  "\nGrand total:" << totalAmmount << " Items totaling $" << totalCost;
}
void makeHeader(){
	// Header for console
	cout << setw(50) << std::setfill('=') << '=';
	cout << "\n=	   FARMER'S MARKET INVENTORY		 =\n";
	cout << setw(50) << std::setfill('=') << '=';
	cout << endl << std::setfill(' ');
}

void fileExtract(ifstream &input, ofstream &output, int &totalAmmount, double &totalCost){
	while(!input.eof()){
		// temp variables for each line
		string tempName, tempFood;
		int tempAmmount;
		double tempCost;
		getline(input, tempName, ',');
		if(tempName == "\n") break;
		// Output to either console or new file report.txt
		input >> tempAmmount >> tempFood >> tempCost;
		totalAmmount += tempAmmount;
		totalCost += tempAmmount * tempCost;
		output << tempName << ", " << tempAmmount << ' ' << tempFood << ' ' << tempCost << ' ' << tempCost * tempAmmount;
		cout << std::left << setw(25) << tempName << ' ' << tempAmmount << ' ' << tempFood << " @ " << tempCost << " each totaling $" << tempAmmount * tempCost;
	}
}
