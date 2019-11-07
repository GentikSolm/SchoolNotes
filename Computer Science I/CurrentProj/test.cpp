#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Progress.cpp"
#include <chrono>
using namespace std;
int main(){
	progIcon(99, true);
	for(int i = 0; i < 100; i++){
		progIcon(99);
		sleep_for(chrono::milliseconds(50));
	}
}
