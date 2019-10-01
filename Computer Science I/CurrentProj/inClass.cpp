#include <iostream>
#include "D:\SchoolNotes\Computer Science I\SideProject\basicFunctions.cpp"
using namespace std;
int factorialThis(int num);
	// Outputs the factorial of the given number
int main(){
	cout << "Please enter a number: ";
	int myNum = userInInt(": ");
	cout << factorialThis(myNum);
}
int factorialThis(int num){
	int total = 1;
	while(num > 0){
		total *= num;
		num--;
	}
	return total;
}
