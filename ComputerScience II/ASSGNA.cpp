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
unique_ptr<char[]> deleteRepeats(const char (&ogArray)[SIZE]);
	//Takes in a character array and returns a unique pointer to
	// an array containing only the unique values


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
	origionalArray[9] = 'd';
	unique_ptr<char[]>noRepeats;
	noRepeats = deleteRepeats(origionalArray);

	// for(int i = 0; i < SIZE; i++){
	//
	// }
}

unique_ptr<char[]> deleteRepeats(const char (&ogArray)[SIZE]){
	// Arrays decay when they are passed into functions
	// Therefore, it is not possible to use a range based loop on them
	// when passed. Because of the decay they lose the
	// size data origionally attached to them.
	char tempArray[SIZE] = {'\0'};
	// bool flag;
	int counter = 0;
	// for(int i = 0; i < SIZE; i++){
	// 	flag = false;
	// 	for(int j = 0; j < SIZE; j++){
	// 		if(ogArray[i] == tempArray[j])flag = true;
	// 	}
	// 	if(!flag){
	// 		tempArray[counter++] = ogArray[i];
	// 	}
	// }
	for(char item : ogArray){
		cout << counter++ << std::endl;
	}

	unique_ptr<char[]>newArray(new char[counter]);
	for(int i = 0; i < counter; i++){
		newArray[i] = tempArray[i];
	}
	return newArray;
}
