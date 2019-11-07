#include "Progress.h"
#include <string>
#include <iostream>
using std::cout;
using std::string;
using std::to_string;

void progIcon(int totalIter, bool newIter = false){
	char sym[] = {'-','\\','|','/'};
	string progOut = "[";
	if(newIter){
		 static int i = 0;
	 }
	 i++;
	 progOut += sym[i % 4] + "] ";
	 progOut += to_string(int(i / totalIter)) + " %\r";
	 cout << progOut;
}

void progBar(int totalIter, bool newIter = false){

}
