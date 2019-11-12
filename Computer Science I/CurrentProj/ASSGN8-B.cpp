/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN8-B
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 11.11.2019
  Purpose: Decode Messages
*/
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::cin;

string decode(char[], int, int);
	// Takes in a cstring array, the current key, and the total size of the cstring
	// Returns a string object that is the decodded message givevn a key.
	//key should be > 0, and size must match actual cstring size.


int main(){
	// Current try is printed out each iteration of the key loop
	string currentTry;
	char encoded[] = ":mmZ\\dxZmx]Zpgy";
	int strLen = 15;
	int maxKeys = 100;
	//Loop for each key
	for(int i = 1; i <= maxKeys; i++){
		//Used to wait for user input.
		string trashCollection;
		currentTry = decode(encoded, i, strLen);
		cout << "Key: " << i << " Decoded message: " << currentTry << endl;
		// So that there isnt too much console output at one time.
		if(i % 26 == 0){
			cout << "\nPress enter to continue. . .";
			std::getline(cin, trashCollection);
		}
	}

	// Its 88!
	return 0;
}


string decode(char coded[], int key, int size){
	string decoded = "";
	for(int j = 0; j < size; j++){
		//Reverse engineering the encryption process:
		if(coded[j] - key <= 126 && coded[j] - key >= 32){
			//Because decoded is a string, its easy to
			// just 'add' new characters.
			decoded += (coded[j] - key);
		} else {
			decoded += (((coded[j]-32) + 127) - key);
		}

	}
	return decoded;
}
