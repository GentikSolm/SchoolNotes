/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGNA
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 1.16.2020
  Purpose: Delete repeats in an array
*/


#include <iostream>
using std::unique_ptr;
using std::cout;
const int SIZE = 10;
unique_ptr<char[]> deleteRepeats(char[]);
	//Takes in a character array and returns a unique pointer to
	// an array containing only the unique values
	// The new array is ended with a null terminator '\0'


int main(){
	char origionalArray[SIZE];
	origionalArray[0] = 'a';
	origionalArray[1] = 'b';
	origionalArray[2] = 'b';
	origionalArray[3] = 'c';
	origionalArray[4] = 'a';
	origionalArray[5] = 'c';
	origionalArray[6] = 'a';
	origionalArray[7] = 'c';
	origionalArray[8] = 'b';
	origionalArray[9] = 'c';
	unique_ptr<char[]>noRepeats;
	noRepeats = deleteRepeats(origionalArray);
	cout << "New Array:\n";
	for(int i = 0;; i++){
		// Missing forloop if statement because the loop
		// is broken when the null terminator is found, because the
		// size of the array is unknown.
		cout << noRepeats[i] << std::endl;
		if(noRepeats[i]== '\0'){
			// Displays last information as this means the last character has been reached.
			cout << "Ammout of items deleted:\n";
			cout << SIZE - i;
			break;
		}
	}
}

unique_ptr<char[]> deleteRepeats(char ogArray[]){
	char tempArray[SIZE] = {'\0'};
	// Creates a new, empty array that is guarenteed to be able to hold
	// all the unique characers from ogArray
	bool flag;
	// Used to see if a character is already in tempArray
	int counter = 0;
	// Used to count how many unique numbers there are
	for(int i = 0; i < SIZE; i++){
		flag = false;
		// Sets flag to false each iteration to indicate its a new character
		for(int j = 0; j < SIZE; j++){
			if(ogArray[i] == tempArray[j])flag = true;
			// nested loops checks to see if the new character is already is in the tempArray,
			// If it is, set flag to true so that the next if statement will not activate
		}
		if(!flag){
			tempArray[counter++] = ogArray[i];
			// If flag never changes from false, then it is a new character
			// and will be added to tempArray
		}
	}

	unique_ptr<char[]>newArray(new char[++counter]);
	//declaration of new array
	for(int i = 0; i < counter; i++){
		newArray[i] = tempArray[i];
		// Copys each element in tempArray to newArray
		// using the counter from previous for loop
	}
	newArray[counter-1] = '\0';
	// sets last char to null terminator
	return newArray;
}
