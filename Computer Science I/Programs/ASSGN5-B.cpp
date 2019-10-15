/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGN5-B
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 10.15.2019
  Purpose: Calculate scores of dodgeball players
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

void shoot(bool &targetAlive, double accuracy);
	//simulates shooting the target with the given accuracy.
	// generates a random number between 0 and 1, if
	// num is less than the accuracy, then the target
	// dies and targetAlive is set to false.
int startDuel();
	// simulates a duel between all players.
	// returns a number based on who won the duel
	// 1 is aaron
	// 2 is bob
	// 3 is charlie

// acc consts for players
const float AARONACCURACY	= 1.0/3;
const float BOBACCURACY		= .5;
const float CHARLIEACCURACY = 1.0;
const int NUMDUELS 			= 1000;
int main(){
	// seeds rand func
	std::srand(std::time(0));
	//win counts for players
	float aaronWon		= 0;
	float bobWon		= 0;
	float charlieWon	= 0;

	// loop for NUMDUELS and tracks num of wins for players
	for(int i = 0;i < NUMDUELS;i++){
		switch(startDuel()){
			case 1:
				aaronWon++;
				break;
			case 2:
				bobWon++;
				break;
			case 3:
				charlieWon++;
				break;
		}
	}
	cout << "Using the strategy of shooting at the best shooter alive, " << endl;
	cout << "AAron win %:	" << aaronWon / NUMDUELS << endl;
	cout << "Bob win %: 	" << bobWon / NUMDUELS << endl;
	cout << "Charlie win %:	" << charlieWon / NUMDUELS << endl;


}
void shoot(bool &targetAlive, double accuracy){
	//simulates shooting the target with the given accuracy.
	// generates a random number between 0 and 1, if
	// num is less than the accuracy, then the target
	// dies and targetAlive is set to false.
	if(accuracy > (std::rand() % 100)/100.0) targetAlive = false;
}
int startDuel(){
	// simulates a duel between all players.
	// returns a number based on who won the duel
	// 1 is aaron
	// 2 is bob
	// 3 is charlie
	bool aaronAlive = true;
	bool bobAlive = true;
	bool charlieAlive = true;
	while(true){
		if(aaronAlive && charlieAlive) shoot(charlieAlive, AARONACCURACY);
		else if(aaronAlive && bobAlive) shoot(bobAlive, AARONACCURACY);
		else if (aaronAlive) return 1;
		if(bobAlive && charlieAlive) shoot(charlieAlive, BOBACCURACY);
		else if(bobAlive && aaronAlive) shoot(aaronAlive, BOBACCURACY);
		else if(bobAlive) return 2;
		if(charlieAlive && bobAlive) shoot(bobAlive, CHARLIEACCURACY);
		else if(charlieAlive && aaronAlive) shoot(aaronAlive, CHARLIEACCURACY);
		else if(charlieAlive) return 3;
	}
}
