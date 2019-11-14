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
#include <limits>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

const int FLOOR_ARRAY_SIZE = 5;
const int ROOM_ARRAY_SIZE = 8;

//	Transfers are represented by a T.
//	The Check outs are represented by a C.
//	Nurse work stations are represented by a W.
//	Occupied rooms are represented by an asterisk O.
//	A vacant room is represented by a blank V.
//	The utility rooms are represented by an X.

const char VACANT = 'V';
const char CHECKOUT = 'C';
const char OCCUPIED = 'O';
const char NURSE_STATION = 'W';
const char TRANSFER = 'T';
const char UTILITY = 'X';
const char INVALID = '@';

// These functions will work in their current form. You must use them. You may add functions but
// don't remove them. Complete the pre and post condition comments.

/*
Pre: 	hospitalFloors is filled with correct chars
Post:	prints out the contents of hospitalFloors to cout
Prints the grid to the screen
*/
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
Pre:	hospitalFloors must be initialized and of correct size
			Beds.txt must be in same folder as program run
Post:	hospitalFloors will contain the correct character in each
			index given by the file Beds.txt

Reads in the initial grid from Beds.txt file
*/
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);


/*
Pre:	hospitalFloors has been filled with proper char's
Post:	Sets all checkout rooms to vacant
Perform the checkouts
*/
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);

/*
Pre:	Checkouts have been taken out, and vacant count has been initialized
Post:	Returns a pointer to an array of pointers of type char that are the addresses of
			available rooms for transfer.
			Also moves transfers to available rooms.
Perform the transfers and build the dynamic array of pointers.
this function also will compute the available number of rooms
*/
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &);

/*
Pre:	Must be some pointers left in arrOfRoomsLeft, and roomsLeft must be equal to that number
			newPatients must be less than roomsLeft
Post:	for each newPatient, the next last arrOfRoomsLeft contents pointer's value is set to
			OCCUPIED and then the pointer is set to nullptr.
			roomsLeft is also subtracted for each newPatients

Perform the new patient adds passing the new patient input from
the nurse station and passing the dynamic array of vacancies count for updating
*/
void newPatient(int, int &, char **);

/*
 Pre:	vacancies must be > 0, input stream must be clear
 Post:	returns a int between the givin minimum and 1 from the user.
 function for the input from the nurse's station. It returns
 the nurse station choice, passes the current vacancies.
*/
int newPatientInput(int);


int main(){
	char ** vacArr;
	char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE];
	int totalVacant = 0, userInput;
	readGrid(hospitalFloors);
	checkOuts(hospitalFloors);
	vacArr = tranfers(hospitalFloors, totalVacant);
	cout << " Checkouts and transfers completed\n";
	while(totalVacant != 0){
		printGrid(hospitalFloors);
		userInput = newPatientInput(totalVacant);
		if(userInput == -1) break;
		newPatient(userInput, totalVacant, vacArr);
	}
	printGrid(hospitalFloors);
	delete vacArr;
	if(totalVacant == 0){
		cout << "*** No more rooms are available today ***";
		return 4;
	}
	else{
		cout << "*** More rooms are available today ***";
		return 0;
	}
}


// FUNCTIONS GO HERE

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
Pre:	hospitalFloors has been filled with proper char's
Post:	Sets all checkout rooms to vacant
Perform the checkouts
*/
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]){
	for(int i = 0; i < FLOOR_ARRAY_SIZE; i++){
		for(int j = 0; j < ROOM_ARRAY_SIZE; j++){
			if(hospitalFloors[i][j] == CHECKOUT){
				hospitalFloors[i][j] = VACANT;
			}
		}
	}
}

/*
Pre:	Checkouts have been taken out, and vacant count has been initialized
Post:	Returns a pointer to an array of pointers of type char that are the addresses of
			available rooms for transfer.
			Also moves transfers to available rooms.
Perform the transfers and build the dynamic array of pointers.
this function also will compute the available number of rooms
*/
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &vacantCount){
	int vacArrCounter = 0;
	for(int i = 0; i < FLOOR_ARRAY_SIZE; i++){
		for(int j = 0; j < ROOM_ARRAY_SIZE; j++){
			if(hospitalFloors[i][j] == VACANT){
				vacantCount++;
			}
		}
	}
	char** vacArr = new char*[vacantCount];
	for(int i = 0; i < FLOOR_ARRAY_SIZE; i++){
		for(int j = 0; j < ROOM_ARRAY_SIZE; j++){
			if(hospitalFloors[i][j] == VACANT){
				vacArr[vacArrCounter] = &hospitalFloors[i][j];
				vacArrCounter++;
			}
		}
	}
	char* temp;
	for(int i = FLOOR_ARRAY_SIZE-1; i >= 0; i--){
		for(int j = ROOM_ARRAY_SIZE-1; j >= 0 ; j--){
			if(hospitalFloors[i][j] == TRANSFER){
				hospitalFloors[i][j] = OCCUPIED;
				vacArrCounter--;
				std::swap(*vacArr[vacArrCounter], hospitalFloors[i][j]);
				vacArr[vacArrCounter] = &hospitalFloors[i][j];
				//hospitalFloors[i][j] = OCCUPIED;
			}
		}
	}
	return vacArr;
}

/*
Pre:	Must be some pointers left in arrOfRoomsLeft, and roomsLeft must be equal to that number
			newPatients must be less than roomsLeft
Post:	for each newPatient, the next last arrOfRoomsLeft contents pointer's value is set to
			OCCUPIED and then the pointer is set to nullptr.
			roomsLeft is also subtracted for each newPatients

Perform the new patient adds passing the new patient input from
the nurse station and passing the dynamic array of vacancies count for updating
*/
void newPatient(int newPatients, int &roomsLeft, char **arrOfRoomsLeft){
	for(int i = 0; i < newPatients; i++){
		--roomsLeft;
		*arrOfRoomsLeft[roomsLeft] = OCCUPIED;
		arrOfRoomsLeft[roomsLeft] = nullptr;
	}
}

/*
 Pre:	vacancies must be > 0, input stream must be clear
 Post:	returns a int between the givin minimum and 1 from the user.
 function for the input from the nurse's station. It returns
 the nurse station choice, passes the current vacancies.
*/
int newPatientInput(int minimum){
	cout << "Please enter the number of new patients, from one up to " << minimum << ": ";
	int inputNum;
	cin >> inputNum;
	while(cin.fail() || inputNum > minimum || inputNum <= 0){
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if(inputNum == -1){
			break;
		}
		cout << "Invalid input, please enter a number between one and " << minimum << ":";
		cin >> inputNum;
	}
	return inputNum;
}
