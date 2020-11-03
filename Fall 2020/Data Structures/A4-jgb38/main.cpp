#include <iostream>
#include "sort.cpp"
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::rand;

int userInInt();
int initArray(int **main, int **sort);
void resetArray(int *base, int *reset, int size);
void printArray(int *array, int size);

int main(){
    int* mainArray;
    int* sortArray;
    int size = initArray(&mainArray, &sortArray);

    printArray(sortArray, size);
    cout << "\nArray sorted:\n";
    mergeSort(sortArray, 0, size-1);
    printArray(sortArray, size);

    delete mainArray;
    delete sortArray;
    return 1;
}


int initArray(int **main, int **sort){
    srand(time(NULL));
    cout << "Please enter a data set size\n> ";
    // int size = userInInt();
    int size = 20;
    cout << "Initializing. . .\n";
    *main = new int[size];
    *sort = new int[size];
    for(int i = 0; i < size; i++){
        (*main)[i] = rand() % size;
        //This keeps the numbers in the array a similar range to the length of the array.
        //Larger arrays can have bigger numbers.
        (*sort)[i] = (*main)[i];
    }
    return size;
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
void resetArray(int *base, int *reset, int size){
    for(int i = 0; i < size; i++){
        reset[i] = base[i];
    }
}
void printArray(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << ' ';
    }
}
