#include <iostream>
#include "basicFuncHeader.h"
#include "basicFunctions.cpp"
using namespace std;

int main(){
	print("Please enter a number greater than 1: ");
	int num = userInInt(": ");
	while(randBetween(num) == -1){
		print("The number must be greater than 1!: ");
		num = userInInt(": ");
	}
	cout << endl << endl << randBetween(num);
	return 0;
}
