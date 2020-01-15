#include <iostream>
using std::unique_ptr;
using std::cout;
unique_ptr<char[]> deleteRepeats(char*);

int const SIZE = 10;
int main(){
	char origionalArray[SIZE];
	origionalArray[0] = 'a';
	origionalArray[1] = 'b';
	origionalArray[2] = 'b';
	origionalArray[3] = 'c';
	origionalArray[4] = 'a';
	origionalArray[5] = 'c';
	origionalArray[6] = 'a';
	origionalArray[7] = 'c';
	origionalArray[8] = 'b';
	origionalArray[9] = 'd';
	unique_ptr<char[]>noRepeats;
	noRepeats = deleteRepeats(origionalArray);

	for(char& letter : noRepeats){
		cout << letter << std::endl;
	}
}

unique_ptr<char[]> deleteRepeats(char* ogArray){
	char tempArray[SIZE] = {'\0'};
	bool flag;
	int counter = 0;
	for(int i = 0; i < SIZE; i++){
		flag = false;
		for(int j = 0; j < SIZE; j++){
			if(ogArray[i] == tempArray[j])flag = true;
		}
		if(!flag){
			tempArray[counter++] = ogArray[i];
		}
	}

	unique_ptr<char[]>newArray(new char[counter]);
	for(int i = 0; i < counter; i++){
		newArray[i] = tempArray[i];
	}
	return newArray;
}
