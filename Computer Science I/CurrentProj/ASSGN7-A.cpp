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
	// Returns total unique items

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
	// After sort array, arraySize is unique.
	//Now both arrays are sorted.
	arraySize = sortArray(itemName, itemCountCost, arraySize);
	printArray(itemName, itemCountCost, arraySize);
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
	/*
	NOTE: This loop is fairly complicated, as i created it to not only sort the string array
	but also clear duplicates, while at the same time managing the doubble array that is
	parrallel to the string array.
	*/

	// Duplicates counter
	int dup = 0;
	bool sorted;
	// Sort loop
	do{
		sorted = true;
		for(int j = 0; j < size-1; j++){
			// Because its used twice, stored as var to save process power
			//Not sure why this threw error when i didnt have it convert to c_str,
			// but adding the function seems to of fixed the error
			int compare = strcmp(items[j].c_str(), items[j+1].c_str());

			/*
			This is the complicated part.
			The first statement sees if items[j] > items[j+1]
				AND
			that item[j+1] is not blank.
			This is required because if items[j] > items[j+1], and items[j+1]
			is blank, next loop will trigger the second statement, items[j] == "" and items[j+1] != ""

			The second statemt is needed because when items[j] =="", and items[j+1] != "", compare will be < 0.
			because we do not want blank space at the start of the array, we need to swap these cases aswell.
			*/
			if((compare > 0 && items[j+1] != "") || (items[j] == "" && items[j+1] != "")){
				// This if statement catches all 'out of order' array indexes.
				sorted = false;
				// This swaps values of the strings and their countCost parrallels
				swap(items[j], items[j+1]);
				swap(countCost[j][0], countCost[j+1][0]);
				swap(countCost[j][1], countCost[j+1][1]);
			} else if(compare == 0 && items[j] != ""){
				// this catches all duplicates and adds the duplicates
				// according countCost index values to the origionals value.
				sorted = false;
				dup++;
				items[j+1].clear();
				countCost[j][0] += countCost[j+1][0];
				countCost[j][1] += countCost[j+1][1];
			}
		}
	}while(!sorted);

	// This finds out how many unique entries there are
	int newSize = size;
	// If no duplicates, returns origional size.
	if(dup > 0){
		newSize = 0;
		for(int k = 0; k < size; k++){
			if(items[k] != ""){
				newSize++;
			} else break;
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
