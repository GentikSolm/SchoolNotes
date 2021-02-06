#include <iostream>
#include <fstream>
#include <vector>
using std::ifstream;
using std::cin;
using std::cout;
using std::vector;
int main(){
	ifstream input;
	int temp;
	int total = 0;
	vector<int> numVector;
	input.open("nums.txt");
	for(int i = 0; !input.eof(); i++){
		input >> temp;
		if(input.fail()) break;
		numVector.push_back(temp);
	}
	cout << "Numbers in vector: ";
	for(int i = 0; i < numVector.size(); i++){
		cout << numVector[i] << ' ';
		total += numVector[i];
	}
	cout << std::endl << "There are " << numVector.size() << " Elements in the vector\n";
	cout << "There total of all the numbers in the vector is: " << total;
	input.close();
	return 0;
}
