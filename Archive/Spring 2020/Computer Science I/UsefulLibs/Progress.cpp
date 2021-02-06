#include "Progress.h"
#include <string>
#include <iostream>
using std::cout;
using std::string;
using std::to_string;

void progIcon(double totalIter){
	static int i = 0;
	totalIter--;
	if(i > totalIter || i == -1){
		 i = 0;
		 return;
	 }
	 if(totalIter < 1){
		 cout << "\ntotalIter must be Greater or equal to 1!";
		 return;
	 }
	char sym[] = {'|','/','-','\\'};
	string progOut = "[";
	progOut += sym[i % 4];
	progOut += "] ";
	progOut += to_string(int(i / totalIter * 100)) + " %\r";
	cout << progOut;
	cout.flush();
	i++;
}

void progBar(double totalIter){
	static int i = 0;
	totalIter--;
	double progress = i / totalIter * 100;
	string buffer = "[";
	int sizeOfBuffer;
	if(progress > 100 || i == -1){
		i = 0;
		return;
	}
	if(totalIter < 1){
		cout << "\ntotalIter must be Greater or equal to 1!";
		return;
	}
	for(int j = 0; j < progress *.7 -1; j++) buffer += "=";
	buffer += ">";
	sizeOfBuffer = buffer.size();
	for(int k = 0; k <= (70 - sizeOfBuffer); k++) buffer += " ";
	buffer += "] " + to_string(int(progress)) + " %\r";
	cout << buffer;
	cout.flush();
	i++;

}
