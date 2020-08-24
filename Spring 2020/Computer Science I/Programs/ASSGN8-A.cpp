/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN8-A
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 11.11.2019
  Purpose: Pig latin!

  I put more comments in here than usual because of
  "Part of your grade is determined by how you come up with a process to write this program"
*/
#include <string>
#include <iostream>
#include <fstream>
using std::ifstream;
using std::cout;
using std::endl;
using std::string;

void pigLatinTranslator(ifstream&, string);
	// Takes in a input file, and the desired ending
	// Stream must be open, and ending must be atleast one character.
	// Prints words immediatly to output.

int main(){
	// Desired ending
	string ending = "AY";

	//File for inpit
	string fileName = "ASSGN8-A.TXT";
	ifstream wordFile;
	wordFile.open(fileName.c_str());
	// makes sure file is there.
	if(wordFile.fail()){
		cout << "File error";
		return 0;
	}
	//Output to console along with translation
	pigLatinTranslator(wordFile, ending);

	//All done, close file and return
	wordFile.close();
	return 0;
}

void pigLatinTranslator(ifstream &file, string ending){
	// char temp holder for 2 purposes, first for making sure the end of the current line has not been reached
	// And second, for getting the fisr character of each word.
	// Char can be used for both because in each instance it is re-written before it is used.
	char tempChar;

	// Used to store each word as it is input from the file
	string tempWord;

	//While not end of line:
	while(!file.eof()){
		// First instance of storing data into char temp, happens every while loop iteration:
		file.get(tempChar);
		// Makes sure that it is not a new line:
		// 		Must put back character if it is not the newline!
		if(tempChar != '\n') file.putback(tempChar);
		//If it is a newline, then cout a new line
		else cout << endl;
		//Translation happens here:
		// Read in word:
		file >> tempWord;
		//Verifies that the word read in correctly.
		if(file.fail()) break;
		// Take first character and over-write current variable in char temp
		tempChar = tempWord[0];
		//Stores everything after the first character origionally in tempWord into temp word;
		//		Essentially cutting out the first character.
		tempWord = tempWord.substr(1);
		//Finally, prints this word to standard output, concatinating
			// all but the first letter of tempword, the first character, and then the ending
			// that was handed to the function and then a space.
		cout << tempWord + tempChar + ending << ' ';
	}
}
