#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;
void myFunc(int* array);
int main(){
	int myArray[6] = {0,1,2,2,3,4};
	myFunc(myArray);
	unique_ptr<int>myNum(new int (101));
	//myNum = unique_ptr<int>(new int (101));
	cout << *myNum;
}
void myFunc(int &array){
	for(auto i : array){
		cout << i << endl;
	}
	// for(int i = 0; i < 6; i++){
	// 	cout << array[i] << endl;
	// }
}
