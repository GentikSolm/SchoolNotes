#include <iostream>
#include <memory>
#include "basicFunctions.cpp"
using std::cout;
using std::cin;

int main(){
	int rows, coloums;
	int urow, ucol;
	cout << "Please enter the ammount of colums: ";
	coloums = userInInt();
	cout << "Please enter the ammount of rows: ";
	rows = userInInt();
	char **myArray = new char *[coloums];
	for(int i = 0; i < coloums; i++){
		myArray[i] = new char[rows];
	}
	cout << "Array Built\n";
	for(int i = 0; i < coloums; i++){
		for(int j = 0; j < rows; j++){
			myArray[i][j] = 'a' + (i+1);
		}
	}
	cout << "Array Initialized\n";
	do{
		cout << "\nWhat index do you want to see?: ";
		cin >> ucol >> urow;
		if(ucol == -1) break;
		cout << "The value in index " << ucol << ' '<< urow << " is " << myArray[ucol][urow];
	}while(true);
	return 0;
}
