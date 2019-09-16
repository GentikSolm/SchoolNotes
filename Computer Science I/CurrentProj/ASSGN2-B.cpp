/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  CSI assignment 1 A
  Auther. Josh Brown
          jgb38@zips.uakron.edu
  Version 1.01 09.16.2019
  Purpose: Take in 10 numbers and do some arithmatic
*/
#include <iostream>
using namespace std;
int main(){
	cout << "Please enter 10 numbers!\n";

	//Declaring needed variables
	int i = 0;
	int pos = 0;
	int neg = 0;
	int temp = 0;

	//WHile loop that takes in 10 numbers
	while(i < 10){
		cout << "\nNumber " << i + 1 << ": ";
		cin >> temp;
		if(temp > 0) pos += temp;
		else neg += temp;
		i++;
	};

	//Returns the final values of positive and negative
  cout << "Total Negative sum: " << neg << ".\n";
	cout << "Total Positive sum: " << pos << ".\n";
	cout << "Total sum of Positive and Negative: " << pos + neg << '.';
}
