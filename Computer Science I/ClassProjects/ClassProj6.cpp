#include <fstream>
#include <iostream>
using std::cin;
using std::cout;
int main(){
	std::ifstream input;
	std::ofstream output;
	int x = 0, y = 1;

	input.open("input.dat");
	if(input.fail()){
		cout << "Input file cannot be opened at this time,";
		return 0;
	}
	output.open("output.dat");
	if(output.fail()){
		cout << "Output file failed.";
		return 0;
	}

	input >> x >> y;
	output << "Hello!";

	input.close();
	output.close();
	cout << x << ' ' << y;
	return 0;
}
