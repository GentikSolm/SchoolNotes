#include <vector>
#include <iostream>
using std::cin;
using std::cout;



int main(){
	float x;
	cin >> x;
   	if(x < .01){
		cout << "true";
   	}
   	else cout << x;
   	return 0;
}
