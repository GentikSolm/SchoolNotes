#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::sqrt;
using std::endl;
using std::swap;
int userInInt();
void bubbleSort(double*, int);

int main(){
    char choice = 'y';
    int n;
    double *sSpace;
    double mean, stdv, range, total, median, max, min;
    while(choice == 'y'){
        mean = 0;
        stdv = 0;
        range = 0;
        total = 0;
        median = 0;
        max = 0;
        min = 0;
        cout << "What is the sample size?\n> ";
        n = userInInt();
        cout << "Please enter each number seperated by a space\n";
        sSpace = new double[n];
        for(int i = 0; i < n; i++){
            cin >> sSpace[i];
            total += sSpace[i];
        }
        bubbleSort(sSpace, n);
        range = std::abs(sSpace[0] - sSpace[n-1]);
        mean = total/n;
        if(n%2 == 0){
            median = (sSpace[n/2]+sSpace[(n/2)-1])/2;
        }
        else{
            median = sSpace[((n+1)/2)-1];
        }
        total = 0;
        for(int i = 0; i < n; i++){
            total += (sSpace[i] - mean)*(sSpace[i] - mean);
        }
        total = total/(n-1);
        stdv = sqrt(total);
        min = sSpace[0];
        max = sSpace[n-1];
        cout <<"Results:\n";
        cout << "Mean:   " << mean << endl;
        cout << "Median: " << median << endl;
        cout << "Range:  " << range << endl;
        cout << "Stdv:   " << stdv << endl;
        cout << "Max:    " << max << endl;
        cout << "Min:    " << min << endl;
        cout << "Do you want to continue? (y/n)\n> ";
        delete sSpace;
    }
}
void bubbleSort(double *arr, int size){
    bool flag = 0;
    while(!flag){
        flag = 1;
        for(int i = 0; i < size-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                flag = 0;
            }
        }
    }
}

int userInInt(){
	// Requests and int from the user and then verifies it is an int.
	// The validated user input is then returned
	// Non-requred string termin, is what is displayed when asking for the variable.
	// termin is ONLY used if input is invalid
	// NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT
	int temp;
	cin >> temp;
	while(cin.fail()){
		cout << "That was not a number! Please enter a number\n> ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> temp;
	}
	return temp;
}
