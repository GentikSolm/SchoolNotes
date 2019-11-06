#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
	int first = 5, last = 15;
	int *squares = new int[last-first+1];
	for(int i = 0; i <= last -first; i++){
		squares[i] = (first + i) * (first + i);
	}
	for(int i = 0; i <= 10; i++){
		cout << squares[i] << "\n";
	}

}
