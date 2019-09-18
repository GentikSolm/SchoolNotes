/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
class prac 4
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 09.17.2019
  Purpose: Classroom practice 4
*/
#include <iostream>
#include <iomanip>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
int main(){
	//Sum of 5 inputs 0 to 10
	int i = 0;
	int temp = 0;
	int total = 0;
	cout << "Please enter 5 numbers 1 to 10." << endl;
	while(i < 5){
		cout << "-> ";
		cin >> temp;
		if((cin.fail()) || temp < 0 || temp > 10){
			cout << endl <<"Please enter a valid number 0 to 10" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else{
			total += temp;
			i++;
		}
	}
	cout << "The total is " << total;
}
