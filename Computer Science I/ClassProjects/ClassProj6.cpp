#include <fstream>
#include <iostream>
#include "myLib.cpp"
#include <string>
using std::cin;
using std::cout;
using std::string;
using namespace cs1;

int main(){
	string userin;
	cin >> userin;
	fileCopy(userin, "text.exe");
	return 0;
}
