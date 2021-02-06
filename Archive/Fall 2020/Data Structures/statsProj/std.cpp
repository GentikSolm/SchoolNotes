#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using std::vector;
using std::cout;
using std::cin;
using std::sqrt;
using std::endl;
using std::swap;
using std::ifstream;
using std::ofstream;
int userInInt();
vector<double> selSort(vector<double> arr, int size);

int main(){
    int n, choice2;
    vector<double> sample;
    double mean, stdv, range, total, median, max, min, cOfv;
    mean = 0;
    stdv = 0;
    range = 0;
    total = 0;
    median = 0;
    max = 0;
    min = 0;
    cOfv = 0;
    ifstream data;
    data.open("data.txt");
    double temp;
    while(!(data >> temp).eof()){
        sample.push_back(temp);
        total += temp;
    }
    data.close();
    n = sample.size();
    sample = selSort(sample, n);
    range = std::abs(sample[0] - sample[n-1]);
    mean = total/n;
    if(n%2 == 0){
        median = (sample[n/2]+sample[(n/2)-1])/2;
    }
    else{
        median = sample[((n+1)/2)-1];
    }
    double totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += (sample[i] - mean)*(sample[i] - mean);
    }
    totalSum = totalSum/(n-1);
    stdv = sqrt(totalSum);
    min = sample[0];
    max = sample[n-1];
    cOfv = stdv / mean;
    cout <<"Results:\n";
    cout << "Data points:\n";
    for(int i = 0; i < sample.size(); i++){
        cout << sample[i] << ' ';
    }
    cout << endl;
    cout << "Sample Size: " << n << endl;
    cout << "Summation: " << total << endl;
    cout << "Mean:   " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Range:  " << range << endl;
    cout << "Stdv:   " << stdv << endl;
    cout << "Max:    " << max << endl;
    cout << "Min:    " << min << endl;
    cout << "Coefficient of Variation: " << cOfv << endl;
}
vector<double> selSort(vector<double> arr, int size){

    for(int j = 0; j < size; j++){
        int small = arr[j];
        int loc = j;
        for(int i = j; i < size; i++){
            if(small > arr[i]){
                small = arr[i];
                loc = i;
            }
        }
        swap(arr[loc], arr[j]);
    }
    return arr;
}

int userInInt(){
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
