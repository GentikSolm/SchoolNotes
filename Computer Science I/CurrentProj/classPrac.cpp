#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
int main(){

	//Seed changes random output!
	srand(time(0));
	const int myCounter = 127;
	int varCtr;
	for(int varCtr = 0; varCtr <= myCounter; varCtr++){
		cout << 1+ rand()% 12 << endl;
	}
}
