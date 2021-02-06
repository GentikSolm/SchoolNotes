#include <cmath>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void countDown(int num);

int main(){
	countDown(5);
}
void countDown(int num){
    if(num == 0){
        cout << "Runtime";
    }
    else{
        cout << num << "...\n";
        countDown(num-1);
    }
}
