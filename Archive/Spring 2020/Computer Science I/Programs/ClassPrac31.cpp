/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  Class Practice on 10/31
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 10.31.2019
  Purpose: 2 functions for calculations on arrays
*/
#include <iostream>
#include <fstream>
using std::ifstream;
using std:: cin;
using std:: cout;
using std:: endl;


double calcSum(double arr[], int arraySize);
	// Takes a double array, and the number of items in that array
	// and returns the total sum of all the numbers.
	//Pre condition: array size must be < arraySize, and arraySize must be >= 0!

double calcAverage(double arr[], int totalNum);
	// Takes a double array, and the number of items in that array
	// and returns the average of all the numbers.
	//Pre condition: array size must be < arraySize, AND arraySize Must be > 0!
	// Note! Average function uses sum function.

int main(){
	int numRead = 0;
	double myArray[100] = {0};
	ifstream input;
	input.open("prac6_numbers.txt");
	for(int i = 0; i < 100;i++){
		if(!input.eof()){
			input >> myArray[i];
			if(input.fail()){
				break;
			}
			numRead++;
		}
		else{
			break;
		}
	}
	input.close();
	cout << "Total number read: " << numRead << endl;
	cout << "Total sum of numbers : ";
	cout << calcSum(myArray, numRead);
	cout << endl;
	cout << "Total average of numbers: ";
	cout << calcAverage(myArray, numRead) << endl;
}

double calcSum(double arr[], int arraySize){
	double totalSum = 0;
	for(int k = 0; k < arraySize; k++){
		totalSum += arr[k];
	}
	return totalSum;
}

double calcAverage(double arr[], int totalNum){
	return calcSum(arr, totalNum) / totalNum;
}
