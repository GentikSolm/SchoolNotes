#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){

	//Seed changes random output!
	srand(293);
	const int myCounter = 127;
	int varCtr;
	for(int varCtr = 0; varCtr <= myCounter; varCtr++){
		cout << 1+ rand()% 12 << endl;
	}
}
