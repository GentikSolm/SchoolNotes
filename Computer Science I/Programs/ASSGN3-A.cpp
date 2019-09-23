/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN3-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.02 09.18.2019
  Purpose: Make rectangles!
*/
#include <iostream>
#include <iomanip>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
int main(){
	//Length and width input from the user, determines the box's sides.
	//temp is used to move variables into length / width
	//tempWidth is used to set a dynamic width value
	int legnth = 0, width = 0, i = 0, temp = 0, tempWidth;
	cout << "Please enter two numbers from 1 to 75 to make a rectangle, first width then legnth." << endl;
	//input verification, want 2 inputs
	while(i < 2){
		cout << "-> ";
		//stores variable and if it is non error forming, it is assigned to length / width
		cin >> temp;
		if((cin.fail()) || temp < 0 || temp > 75){
			cout << endl <<"Please enter a valid number 1 to 75" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if(i == 0){// 0 is for width
			width = temp;
			i++;
		}
		else{
			legnth = temp;  //1 is for length
			i++;
		}
	}
	cout << "Making a rectangle with width: " << width << ", and legnth: " << legnth << endl;
	//This while loop is for the length
	while(0 < legnth){
		tempWidth = width;
		//this is used for width
		//tempWidth is needed because it decreases with ever recursion of the while loop, but needs to come back to its
		//origional after every length loop 
		while(0 < tempWidth){
			cout << "X";
			tempWidth--;
		}
		cout << endl;
		legnth--;
	}
}
