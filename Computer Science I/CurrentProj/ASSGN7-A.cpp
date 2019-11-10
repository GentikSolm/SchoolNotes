/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN7-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 11.9.2019
  Purpose: Output ammount of items and their total cost from market.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <utility>
#include <cstring>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::swap;
using std::strcmp;
using std::setw;

void makeHeader();
	// Header for console output.
int makeArrays(string[], double[][2], ifstream&);
	// Takes in a large string array, and a 2d int array, and a file
	// Sorts file and stores it in string, and in parrallel stores the total
	// Cost of items with the total count of items.
	// Returns the total size of the array, which is the same as the total
	// ammount of items in the file, NON UNIQUE

int sortArray(string[], double[][2], int);
	// Takes in two parrallel arrays and sorts them togeather
	// Also takes in int used size of array, NOT TOTAL SIZE
	// Returns total NON UNIQUE items

int squishArray(string[], double[][2], int);
	// Takes in two parrallel arrays and sees if the first is equal to
	// the next in a sorted list and then combines the second to the first.
	// Prereq: MUST BE SORTED
	// returns unique size


void printArray(string[], double[][2], int);
	// prints arrays as they should be formatted.

const int ARRAY_TOTAL_SIZE = 100;
// Size of arrays, must be large number to cath all items.

int main(){
	//to keep track of used array spaces
	//Creating 2 very large arrays to store all farm data
	string itemName[ARRAY_TOTAL_SIZE];
	double itemCountCost[ARRAY_TOTAL_SIZE][2]; //2D array, first item is ammount of that item, second is the total cost
	ifstream market;
	int arraySize;

	market.open("ASSGN6-B.txt");
	makeHeader();

	// Array size is non unique here.
	//This does not create the arays but merely fills them with unsorted values.
	arraySize = makeArrays(itemName, itemCountCost, market);

	arraySize = sortArray(itemName, itemCountCost, arraySize);
	//Now both arrays are sorted.
	arraySize = squishArray(itemName, itemCountCost, arraySize);
	//Now both are sorted and squished
	printArray(itemName, itemCountCost, arraySize);
	//Prints data
	return 0;
}

void makeHeader(){
	// Header for console
	cout << std::setw(50) << std::setfill('=') << '=';
	cout << "\n=	   FARMER'S MARKET INVENTORY		 =\n";
	cout << std::setw(50) << std::setfill('=') << '=';
	cout << endl << std::setfill(' ');
}

int makeArrays(string items[], double countCost[][2], ifstream &market){
	string trashCollection; // Used to store / disregard the item cost, as from assignment 6-B,
	// We calculated the cost for each item, thereofor no longer needed to know each farmers cost
	// Per item, only need total items and item total cost.
	int arraySize = 0;
	while(!market.eof()){
		// Disregard farm name, is not needed for assignment.
		getline(market, trashCollection, ',');
		market >> countCost[arraySize][0] >> items[arraySize] >> trashCollection >> countCost[arraySize][1];
		if(market.fail()){
			break;
		}
		++arraySize;
	}
	return arraySize;
}

int sortArray(string items[], double countCost[][2], int size){
	int small = 0, val;

	//increments non sorted sub array
	for(int i = 0; i < size; i++){
		small = i;
		//Searches for the smallest value
		for(int j = i+1; j < size; j++){
			if(strcmp(items[small].c_str(), items[j].c_str()) > 0) small = j;
		}
		//swaps the smallest value with the current value in the i slot
		swap(items[i], items[small]);
		swap(countCost[i][0], countCost[small][0]);
		swap(countCost[i][1], countCost[small][1]);
	}
	return size;
}
int squishArray(string items[], double countCost[][2], int size){

	int newSize = size;
	for(int i = 0; i < size; i++){
		//When a string next to another is equal, it will add the second to the first,
		//then swap the rest of the values to push out the empty string
		if(strcmp(items[i].c_str(), items[i+1].c_str()) ==0 && items[i] != ""){
			items[i+1].clear();
			countCost[i][1] += countCost[i+1][1];
			countCost[i][1] += countCost[i+1][1];
			newSize--;
			for(int j = i+1; j < size; j++){
				//swapping done here
				swap(items[j], items[j+1]);
				swap(countCost[j][0], countCost[j+1][0]);
				swap(countCost[j][1], countCost[j+1][1]);
			}
			i--;
		}
	}
	return newSize;
}
void printArray(string items[], double countCost[][2], int size){
	for(int i = 0; i < size; i++){
		cout << std::left << setw(25) << items[i] << countCost[i][0] << " items totaling $" << countCost[i][1] << endl;
	}
	cout << "\nThere were " << size << " items contributed to this week's event.";
}
