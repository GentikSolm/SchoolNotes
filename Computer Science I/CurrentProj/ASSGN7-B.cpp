/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN7-B
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 11.10.2019
  Purpose: Show total loads of items.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

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

int makeArrays(string[], ifstream&);
	// Takes in a large string array
	// Sorts file and stores it in string
	// Returns the size of the array, which is the same as the total
	// ammount of items in the file, NON UNIQUE, NOT FULL ARRAY SIZE

void sortArray(string items[], int size);
	// uses bubble sort to sort the given string array.
	// Does not return anything.
	// Size does not have to be the actual size of the array, just the size of how many strings there are.
void printArray(string[], int);
	// prints arrays as they should be formatted.

const int ARRAY_TOTAL_SIZE = 100;

int main(){
	//to keep track of used array spaces
	//Creating a very large array to store all farm data
	string itemName[ARRAY_TOTAL_SIZE];
	ifstream market;
	int arraySize;

	market.open("ASSGN6-B.txt");
	makeHeader();
	arraySize = makeArrays(itemName, market);
	sortArray(itemName, arraySize);
	printArray(itemName, arraySize);

}


void makeHeader(){
	// Header for console
	cout << std::setw(50) << std::setfill('=') << '=';
	cout << "\n=	   FARMER'S MARKET INVENTORY		 =\n";
	cout << std::setw(50) << std::setfill('=') << '=';
	cout << endl << std::setfill(' ');
}

int makeArrays(string items[], ifstream &market){
	string trashCollection; // Used to store / disregard the item cost, as from assignment 6-B,
	// We calculated the cost for each item, thereofor no longer needed to know each farmers cost
	// Per item, only need total items and item total cost.
	int arraySize = 0;
	while(!market.eof()){
		// Disregard farm name, is not needed for assignment.
		getline(market, trashCollection, ',');
		market >> trashCollection >> items[arraySize] >> trashCollection >> trashCollection;
		if(market.fail()){
			break;
		}
		++arraySize;
	}
	return arraySize;
}

void sortArray(string items[], int size){
	bool sorted;
	// Sort loop
	do{
		sorted = true;
		for(int j = 0; j < size-1; j++){
			//Not sure why this threw error when i didnt have it convert to c_str,
			// but adding the function seems to of fixed the error
			int compare = strcmp(items[j].c_str(), items[j+1].c_str());
			if(compare > 0){
				// This if statement catches all 'out of order' array indexes.
				sorted = false;
				// This swaps values of the strings and their countCost parrallels
				swap(items[j], items[j+1]);
			}
		}
	}while(!sorted);
}


void printArray(string items[], int size){
	int loads = 1, totalItems = 0;
	for(int i = 0; i < size; i++){
		//This statement is very useful Because
		// This passes the cout statement if the next item is of the same load.
		// then adding one to the loads of that item.
		if(items[i] == items[i+1]){
			loads++;
			continue;
		}
		totalItems++;
		cout << loads << " loads of " << items[i] << " were delivered"<< endl;
		loads = 1;
	}
	cout << "\nThere were " << totalItems << " items contributed to this week's event.";
}
