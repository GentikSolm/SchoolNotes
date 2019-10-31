/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN6-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 10.29.2019
  Purpose: Read file to screen.
*/

#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(){
	string fileName;
	ifstream input;
	cout << "Please enter the name of the file you want to open: ";
	cin >> fileName;
	cin.get(); // Clears the \n from cin >> entry
	input.open(fileName.c_str());

	// Makes sure file is open
	if(input.fail()){
		cout << "The file cannot be opened!";
		return 0;
	} else {
		string line;
		// Loops while end of file is not reached
		while(!input.eof()){
			//loops 24 lines, also keeps count
			for(int i = 1; i <= 24; i++){
				if(input.eof()){
					break;
				}
				getline(input, line);
				// prints each line
				cout << i << ": " << line << endl;
			}
			cout << endl << "Press enter to continue";
			cin.get();
		}
	}
	input.close();
}
