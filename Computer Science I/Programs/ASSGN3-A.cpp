/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN3-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 09.18.2019
  Purpose: Make rectangles!
*/
#include <iostream>
#include <iomanip>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
int main(){
	int legnth = 0, width = 0, i = 0, temp = 0, tempWidth;
	cout << "Please enter two numbers from 1 to 75 to make a rectangle, first width then legnth." << endl;
	while(i < 2){
		cout << "-> ";
		cin >> temp;
		if((cin.fail()) || temp < 0 || temp > 75){
			cout << endl <<"Please enter a valid number 1 to 75" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if(i == 0){
			width = temp;
			i++;
		}
		else{
			legnth = temp;
			i++;
		}
	}
	cout << "Making a rectangle with width: " << width << ", and legnth: " << legnth << endl;
	while(0 < legnth){
		tempWidth = width;
		while(0 < tempWidth){
			cout << "X";
			tempWidth -=1;
		}
		cout << endl;
		legnth -=1;
	}
}
