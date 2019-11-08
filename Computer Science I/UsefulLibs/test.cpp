#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Progress.cpp"
#include <chrono>
#include <thread>
using namespace std;
int main(){
	for(int i = 0; i < 200; i++){
		progBar(19);
		std::this_thread::sleep_for(chrono::milliseconds(70));
	}
}
