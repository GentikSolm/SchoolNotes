/*
   COPYRIGHT (C) 2019 Josh Brown. All rights reserved.
   CSI project 2
   Author.  josh Brown, 4323254.
   Version. 1.01 11.12.2019.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

const int FLOOR_ARRAY_SIZE = 5;
const int ROOM_ARRAY_SIZE = 8;

//	Transfers are represented by a �T�.
//	The Check outs are represented by a �C�.
//	Nurse work stations are represented by a �W�.
//	Occupied rooms are represented by an asterisk �O�.
//	A vacant room is represented by a blank �V�.
//	The utility rooms are represented by an �X�.

const char VACANT = 'V';
const char CHECKOUT = 'C';
const char OCCUPIED = 'O';
const char NURSE_STATION = 'W';
const char TRANSFER = 'T';
const char UTILITY = 'X';
const char INVALID = '@';

// These functions will work in their current form. You must use them. You may add functions but
// don't remove them. Complete the pre and post condition comments.

//Function prototypes
/*
Pre and Post condition comments go here ... Prints the grid to the screen
*/
//DONE
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
Pre and Post condition comments go here ... Reads in the initial grid from Beds.txt file
*/
//DONE
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);


/*
Pre and Post condition comments go here ... Perform the checkouts
*/
//DONE
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
Pre and Post condition comments go here ...Perform the transfers and build the dynamic array of pointers.
this function also will compute the available number of rooms
*/
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &);

/*
Pre and Post condition comments go here ...Perform the new patient adds passing the new patient input from
the nurse station and passing the dynamic array of vacancies count for updating
*/
void newPatient(int, int &, char **);

/*
 Pre and Post condition comments go here ... function for the input from the nurse's station. It returns
 the nurse station choice, passes the current vacancies.
*/
int newPatientInput(int);


int main()
{
	char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE];

	readGrid(hospitalFloors);
	checkOuts(hospitalFloors);

	cout << " Checkouts and transfers completed\n";
	printGrid(hospitalFloors);
    // CODE HERE and FUNCTIONS GO AFTER MAIN
    // THIS SHOULD BE PRIMARILY FUNCTION CALLS

    return 0;
}

// FUNCTIONS GO HERE

/*
Pre:	hospitalFloors must be initialized and of correct size
			Beds.txt must be in same folder as program run
Post:	hospitalFloors will contain the correct character in each
			index given by the file Beds.txt

Reads in the initial grid from Beds.txt file
*/
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]){
	ifstream bedFile;
	int inputNum;
	char whatIcon[7] = {VACANT, CHECKOUT, OCCUPIED, NURSE_STATION, TRANSFER, UTILITY, INVALID};
	bedFile.open("Beds.txt");
	if(bedFile.fail()){
		cout << "File failed!";
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < FLOOR_ARRAY_SIZE; i++){
		for(int j = 0; j < ROOM_ARRAY_SIZE; j++){
			bedFile >> inputNum;
			if(inputNum >= 7 || inputNum < 0) hospitalFloors[i][j] = whatIcon[7];
			else{
				hospitalFloors[i][j] = whatIcon[inputNum];
			}
		}
	}
	bedFile.close();
	printGrid(hospitalFloors);
	cout << " Grid Loaded\n\n";
}

/*
Pre: 	hospitalFloors is filled with correct chars
Post:	prints out the contents of hospitalFloors to cout
Prints the grid to the screen
*/
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]){
	cout << ' ' << std::setfill('-') << std::setw(22) << '-' << endl;
	for(int i = 0; i < FLOOR_ARRAY_SIZE; i++){
		for(int j = 0; j < ROOM_ARRAY_SIZE; j++){
			cout << ' ' << hospitalFloors[i][j] << ' ';
		}
		cout << endl;
	}
	cout << ' ' << std::setfill('-') << std::setw(22) << '-' << endl;
}

/*
Pre and Post condition comments go here ...Perform the transfers and build the dynamic array of pointers.
this function also will compute the available number of rooms
*/
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &totalTrans){
	int vacantCount = 0;
	for(int i = 0; i < FLOOR_ARRAY_SIZE; i++){
		for(int j = 0; j < ROOM_ARRAY_SIZE; j++){
			if(hospitalFloors[i][j] == 'V'){
				vacantCount++;
			}
		}
	}
	char** vacArr = new char*[vacantCount];
	int vacArrCounter = 0;
	for(int i = FLOOR_ARRAY_SIZE-1; i >= 0; i--){
		for(int j = FLOOR_ARRAY_SIZE-1; j >= 0; j--){
			if(hospitalFloors[i][j] == 'V'){
				vacArr[vacArrCounter++] = *(hospitalFloors[i][j]);
			}
		}
	}
	for(int i = FLOOR_ARRAY_SIZE-1; i >= 0; i--){
		for(int j = FLOOR_ARRAY_SIZE-1; j >= 0; j--){
			if(hospitalFloors[i][j] == 'T'){
				hospitalFloors[i][j] = 'V';
				std::swap(*hospitalFloors[i][j], *vacArr[vacArrCounter--]);

				//NOT DONE HERE
			}
		}
	}


}

/*
Pre:	hospitalFloors has been filled with proper char's
Post:	Sets all checkout rooms to vacant
Perform the checkouts
*/
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]){
	for(int i = 0; i < FLOOR_ARRAY_SIZE; i++){
		for(int j = 0; j < ROOM_ARRAY_SIZE; j++){
			if(hospitalFloors[i][j] == 'C'){
				hospitalFloors[i][j] = VACANT;
			}
		}
	}
}
