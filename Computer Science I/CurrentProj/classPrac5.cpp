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
	double paintHours = 5;
	double cleanFloors = 9;
	double cleanRest = 6;
	int volPaint = 0;
	int volFloor = 0;
	int volRest = 0;
	while(){
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

}
