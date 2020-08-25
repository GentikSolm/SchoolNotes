/*
	COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
	CSI assignment 1 A
	Auther. Josh Brown
			jgb38@zips.uakron.edu
	Version 1.01 09.17.2019
	Purpose: Dealing with different types of data as input.
*/
// My Validation Program for input
#include <iostream> // for input-output stream operations
#include <iomanip> // for providing parametric manipulators operations
#include <limits> // for providing elements with the chracteristics of arithmetic types
using std::cout; // for using output to console
using std::cin; // for input to console
using std::endl; // for easier \n usage
int main(){	// Starting new block
	double organisms = 0.00; // To hold num of organisms

	//get the number of starting organisms

	bool loopFlag = true; // control flag for the loop

	do //post test loop
	{	// Starting new block
		cout << "Enter the starting number of organisms: "; // output stream message
		cin >> organisms; //input stream a variable
		//Do not accept a number less than 2 for the
		// starting size of the populations
		if((cin.fail()) || organisms < 2) // decision construct tests 2 conditions
		{	// Starting new block
			cout << "The starting number of organisms must be a valid number that is atleast 2.\n"; // more output to console
			cin.clear(); //Clears the error flags so i/o operations will work
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the input stream
		}	// ending block
		else
		{ 	// Starting new block
			loopFlag = false; // Change Boolean value to end this loop because of good input
		}	// ending block
	} while(loopFlag); // Loop control expression is a boolean value
	return 0; // ends program and returns a zero back to the os

// Research findings:
/*
Why use 'using std::...' instead of 'using namespace std;'?
	This is good practice because the program only imports the ... instead of the entire std namespace.

What is cin.fail()?
 	cin.fail() is a boolean that is either true of false,
	if it is true, that means that the input was invalid for the type of data
	it was trying to assing. By using this in the if statement, we can see if the user
	input a value that could go into the organism variable.

Short-circuit evaluation?
	This is how CPP does evauations of statements. In this case,
	it reads if cin.fail() is true, and because it is an || (or)
	statement, it will right away go into the block, without trying to determine
	if organisms < 2. This is good because if it tried to evaluate
	organisms < 2 even after getting a true value for cin.fail(), it would error
	because organisms was not properly assigned and is invalid.

Paramaters for ignore, numeric limits and stream size?:
	the paramaters for ignore tell the program to ignore everthing in the input stream
	up to the max streamszie, or '\n'.
	std::numeric_limits<std::streamsize>::max is another way of saying numerical value for the maximum
	stream size.
*/



}
