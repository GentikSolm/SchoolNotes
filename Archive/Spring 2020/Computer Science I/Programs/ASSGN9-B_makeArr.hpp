#ifndef	ASSGN9_B_MAKEARR
#define	ASSGN9_B_MAKEARR
#include <iostream>

std::unique_ptr<int[]> makeArr(int *arr, int size){
	// Pre condition: int array must be made, and given with its size.
	// Post: returns the pointer to the new array that is a copy of the old one,
	// shifted by one unit.

	//New size of the array
	size += 1;
	//Create the new dynamic memory space for the new array with the larger size
	std::unique_ptr<int[]> newArr(new int[size]);
	//For each item in the origional array, i=1 because we want to set the new
	// first value at index 0 to 0.
	for(int i = 1; i < size; i++){
		// each element is the dereferenced equivilant in
		// the origional array.
		newArr[i] = *(arr + (i-1));
	}
	newArr[0] = 0;
	return newArr;
}

#endif
