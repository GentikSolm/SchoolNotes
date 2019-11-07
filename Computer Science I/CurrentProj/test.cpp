#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;
int main(){
	float progress = 0.0;
	while (progress <= 1.0) {
	    int barWidth = 70;

	    std::cout << "[";
	    int pos = barWidth * progress;
	    for (int i = 0; i < barWidth; ++i) {
	        if (i < pos) std::cout << "=";
	        else if (i == pos) std::cout << ">";
	        else std::cout << " ";
	    }
	    std::cout << "] " << int(progress * 100.0) << " %\r";
	    std::cout.flush();

		this_thread::sleep_for(chrono::seconds(1));
	    progress += 0.16; // for demonstration only
		if(progress >= 1.0){
			cout << "[";
			for(int i = 0; i < 70; i++){
				cout << "=";
			}
			cout << "] 100 %";
			break;
		}
	}
	std::cout << std::endl;
}
