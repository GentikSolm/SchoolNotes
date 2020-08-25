#ifndef	ASSGN9_B_PRINTARR
#define	ASSGN9_B_PRINTARR
#include <iostream>

void printArr(int *arr, int size){
	//Pre condition: array is good, and passed correctly
	//		Size is the size of the array
	//Prints out the contents of the array

	for(int i = 0; i < size; i++){
		// prints the value in the address of i + the address of the first
		// array item.
		std::cout << *(i + arr) << " ";
	}
	std::cout << std::endl;
}

#endif
