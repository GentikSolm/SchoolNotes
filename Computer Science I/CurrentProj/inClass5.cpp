#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int sum(int x, int y);

int main(){
	int a=2,b=10;
	int r = sum(a,b);
	cout << "result is: " << r;
	return 0;
}

int sum(int x, int y){
	return x + y;
}
