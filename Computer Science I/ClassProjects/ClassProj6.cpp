#include <fstream>
#include <iostream>
using std::cin;
using std::cout;
const double QUTR = .25;
const double DIME = .1;
const double PENNY = .01
int main(){
	dobule total = 0;
	char temp;
	std::ifstream input;

	input.open("input.dat");
	if(input.fail()){
		cout << "Input file cannot be opened at this time,";
		return 0;
	while(!eof())
		while(input >> temp != '\n'){
			input.put(temp);

		}
	}

	input >> x >> y

	input.close()
	return 0;
}
