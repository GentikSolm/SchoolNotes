/*
ACADEMIC INTEGRITY PLEDGE

- I have not used source code obtained from another
student nor any other unauthorized source, either
modified or unmodified.

- All source code and documentation used in my program
is either my original work or was derived by me from
the source code published in the textbook for this
course or presented in class.

- I have not discussed coding details about this project
with anyone other than my instructor. I understand
that I may discuss the concepts of this program with
other students and that another student may help me
debug my program so long as neither of us writes
anything during the discussion or modifies any
computer file during the discussion.

- I have violated neither the spirit nor letter of these
restrictions.

Signed: Joshua Brown Date: 10/22/2019
COPYRIGHT (C) 2016 (your name). All Rights Reserved.
7 Days toss up project
author: Joshua Brown
version 1.01.10.22
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;


int main(){
	// Seeding random
	srand(time(0));
	int playerScore = 0, compScore = 0, coin = 0;
	string userGuess;

	// Dialoug for start of game
	cout << "LET THE\n";
	cout << "FLIP OF THE COIN REWRITE HISTORY\n\n\n";
	cout << "/----------------------\\\n";
	cout << "| RETURN TO SEVEN DAYS |\n";
	cout << "\\----------------------/\n\n";
	cout << "It is July 1, 1862, the final day\n";
	cout << "of the Battle of Seven Days...\n\n\n";
	cout << "In this re-enactment of the second day\n";
	cout << "of battle, you are George B. McClellan in charge of the Unionists\n\n\n";
	cout << "We will flip a coin to determine the\n";
	cout << "outcome of the small battles for\n";
	cout << "territories within the Seven Days area\n\n\n";
	cout << "You have to predict whether the coin\n";
	cout << "will come up heads or tails...\n\n";
	cout << "Now General McClellan\n";
	cout << "Do you predict the coin will come out\n";
	cout << "heads (H) or tails (T)?\n";

	//Loop for the 9 battles
	for(int i = 1;i <= 9;i++){
		cout << "Battle " << i << "- ";
		// Switch case for battle names
		switch(i){
			case 1:
				cout << "Little Round Top\n";
				break;
			case 2:
				cout << "Cemetry Ridge\n";
				break;
			case 3:
				cout << "Devils Den\n";
				break;
			case 4:
				cout << "The Wheatfield\n";
				break;
			case 5:
				cout << "The Peach Orchard\n";
				break;
			case 6:
				cout << "Culps Hill\n";
				break;
			case 7:
				cout << "Zieglers Grove\n";
				break;
			case 8:
				cout << "Seminary Ridge\n";
				break;
			case 9:
				cout << "GettysBurg\n";
				break;
		}
		cout << "Choose H or T: ";
		cin >> userGuess;

		// Semi- input verification for user input
		// If user enters not h,H,t,T, default to Heads
		if(userGuess != "H" && userGuess != "h" && userGuess != "T" && userGuess != "t"){
			userGuess = "H";
			cout << "\n\nYou have chosen heads";
		} else {
			cout << "\n\nYou have chosen " << userGuess;
		}
		cout << "\nStand by to fight, General McClellan...\n";

		// Random number generator, generates number
		// between 0 and 1.
		coin = rand() % 2;
		if(coin == 0){
			cout << "\n\nThe result of the coin flip was heads \n";
		} else {
			cout << "\n\nThe result of the coin flip was tails\n";
		}

		// Case for if user guess right or wrong.
		if((coin == 0 && (userGuess == "H" || userGuess == "h")) || (coin == 1 && (userGuess == "T" || userGuess == "t"))){
			cout << "Well done, General McClellan...\n";
			cout << "You have defeated Lee";
			playerScore++;
		} else {
			cout << "I am sorry, General McClellan...\n";
			cout << "but the battle goes to Lee\n";
			compScore++;
		}

		// current score
		cout << "So far: McClellan " << playerScore << " victories, Lee " << compScore << endl;
	}

	// Final dialog
	cout << "\n\nThe results show that\n";
	if(playerScore > compScore){
		cout << "George B. McClellan won the majority of the battles\n";
	} else {
		cout << "Robert E Lee won the majority of the battles\n";
	}
	cout << "and is thus declared the victor\n";
	cout << "on July 2 1863\n";
	cout << "\nIn the actual Battle at Seven Days,\n";
	cout << "the Northern troops turned back Lee's final assaults at Malvern Hill (July 1)....\n\n\n";
	cout << "The Confederates lost about 16,000 men...\n\n";
	cout << "The Unionists lost about 20,000 men...\n\n";
	cout << "McClellan's failure to capture Richmond, and the subsequent withdrawal of the Union's Army from the Yorktown Peninsula, signified the end of the Peninsular Campaign.\n\n";
	return 0;
}
