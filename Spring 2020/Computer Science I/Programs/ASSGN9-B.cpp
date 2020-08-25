/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN9-B
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 11.11.2019
  Purpose: make arrays bigger
*/

#include <iostream>
#include <memory>
#include "ASSGN9-B_makeArr.hpp"
#include "ASSGN9-B_printArr.hpp"
int main(){
	const int SIZE = 5;
	int myNumbersB[SIZE] = {18, 27, 3, 14, 95};
	//Initialize the new array with one extra space
	std::unique_ptr<int[]> newCopy(new int[SIZE + 1]);
	std::cout << "Before makeArr is called: " << std::endl;
	//Prints current array
	printArr(myNumbersB, SIZE);
	// sets the newcopy unique smart pointer to a new array that is one larger
	// than myNumbersB.
	newCopy = makeArr(myNumbersB, SIZE);
	std::cout << "\nAfter makeArr is called: " << std::endl;
	//Prints the new array. must use .get to get the address. 
	printArr(newCopy.get(), SIZE+1);
	return 0;
}
