#include <iostream>
using namespace std;
double helloWorld(double x = 4){
	cout << "Hello world!\n";
	return x/10;

}
int main(){

	cout << helloWorld(10);


}
