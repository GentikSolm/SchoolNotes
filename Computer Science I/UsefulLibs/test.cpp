#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Progress.cpp"
#include <chrono>
#include <thread>
using namespace std;
int main(){
	progBar(19);
	for(int i = 0; i < 19; i++){
		progBar();
		std::this_thread::sleep_for(chrono::milliseconds(70));
	}
	cout << endl;
	for(int i = 0; i < 19; i++){
		progIcon(19);
		std::this_thread::sleep_for(chrono::milliseconds(70));
	}
}
