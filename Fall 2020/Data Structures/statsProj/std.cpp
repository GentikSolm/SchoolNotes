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
template <class typeName>
void mergeSort(typeName arr, int left, int right);

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
    mergeSort(sample, 0, n-1);
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
template <class typeName>
void mergeSort(typeName arr, int left, int right){
    if(left < right){
        int mid = (left + (right-1))/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        int size1, size2;
        size1 = mid - left +1;
        size2 = right - mid;

        vector<double> leftA (size1);
        vector<double> rightA (size2);
        for(int i = 0; i < size1; i++){
            leftA[i] = arr[left+i];
        }
        for(int j = 0; j< size2; j++){
            rightA[j] = arr[mid + 1 + j];
        }
        int i = 0, j = 0, k = left;

        while(i < size1 && j < size2){
            if(leftA[i] <= rightA[j]){
                arr[k] = leftA[i];
                i++;
            }
            else{
                arr[k] = rightA[j];
                j++;
            }
            k++;
        }
        while(i < size1){
            arr[k] = leftA[i];
            i++;
            k++;
        }
        while(j < size2){
            arr[k] = rightA[j];
            j++;
            k++;
        }
    }
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
