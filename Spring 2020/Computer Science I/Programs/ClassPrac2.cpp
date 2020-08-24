#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;

double * getNumbers(int num);

int main(){
	double * dubArray;
	int num;
	cout << "How many numbers do you want to enter?\n-> ";
	cin >> num;
	cout << "Enter " << num << " Doubles:\n";
	dubArray = getNumbers(num);
	delete [] dubArray;
	return 0;

}
double * getNumbers(int num){
	double * dubArray = new double[num];
	for(int i = 0; i < num; i++){
		cout << i + 1 << ": ";
		cin >> dubArray[i];
	}
	return dubArray;
}
