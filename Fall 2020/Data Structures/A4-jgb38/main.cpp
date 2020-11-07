#include <iostream>
#include "sort.cpp"
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <limits>
#include <chrono>
#include <ctime>
#include <iomanip>

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
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> BubbleTime;
    std::chrono::duration<double> InsertTime;
    std::chrono::duration<double> SelTime;
    std::chrono::duration<double> MergeTime;
    std::chrono::duration<double> QuickFTime;
    std::chrono::duration<double> QuickMTime;
    cout << std::fixed;

    int size = initArray(&mainArray, &sortArray);

    cout << "For O(N^2) Sorting:\n";
    start = std::chrono::system_clock::now();
    bubbleSort(sortArray, size);
    end = std::chrono::system_clock::now();
    BubbleTime = end-start;

    resetArray(mainArray, sortArray, size);

    start = std::chrono::system_clock::now();
    insertSort(sortArray, size);
    end = std::chrono::system_clock::now();
    InsertTime = end-start;

    resetArray(mainArray, sortArray, size);

    start = std::chrono::system_clock::now();
    selSort(sortArray, size);
    end = std::chrono::system_clock::now();
    SelTime = end-start;
    resetArray(mainArray, sortArray, size);

    if(BubbleTime <= InsertTime && BubbleTime <= SelTime){
        if(SelTime <= InsertTime){
            cout << "1st: Bubble sort @ " << BubbleTime.count() << 's' << endl;
            cout << "2nd: Selection sort @ " << SelTime.count() << 's' << endl;
            cout << "3rd: Insert sort @ " << InsertTime.count() << 's' << endl;
        }
        else{
            cout << "1st: Bubble sort @ " << BubbleTime.count() << 's' << endl;
            cout << "2nd: Insert sort @ " << InsertTime.count() << 's' << endl;
            cout << "3rd: Selection sort @ " << SelTime.count() << 's' << endl;
        }
    }
    else if(InsertTime <= BubbleTime && InsertTime <= SelTime){
        if(SelTime <= BubbleTime){
            cout << "1st: Insert sort @ " << InsertTime.count() << 's' << endl;
            cout << "2nd: Selection sort @ " << SelTime.count() << 's' << endl;
            cout << "3rd: Bubble sort @ " << BubbleTime.count() << 's' << endl;
        }
        else{
            cout << "1st: Insert sort @ " << InsertTime.count() << 's' << endl;
            cout << "2nd: Bubble sort @ " << BubbleTime.count() << 's' << endl;
            cout << "3rd: Selection sort @ " << SelTime.count() << 's' << endl;
        }
    }
    else{
        if(InsertTime <= BubbleTime){
            cout << "1st: Selection sort @ " << SelTime.count() << 's' << endl;
            cout << "2nd: Insert sort @ " << InsertTime.count() << 's' << endl;
            cout << "3rd: Bubble sort @ " << BubbleTime.count() << 's' << endl;
        }
        else{
            cout << "1st: Selection sort @ " << SelTime.count() << 's' << endl;
            cout << "2nd: Bubble sort @ " << BubbleTime.count() << 's' << endl;
            cout << "3rd: Insert sort @ " << InsertTime.count() << 's' << endl;
        }
    }


    cout << "nlogn Sort:\n";
    start = std::chrono::system_clock::now();
    mergeSort(sortArray, 0, size-1);
    end = std::chrono::system_clock::now();
    MergeTime = end-start;

    resetArray(mainArray, sortArray, size);

    start = std::chrono::system_clock::now();
    quickSortF(sortArray, 0, size-1);
    end = std::chrono::system_clock::now();
    QuickFTime = end-start;

    resetArray(mainArray, sortArray, size);

    start = std::chrono::system_clock::now();
    quickSortM(sortArray, 0, size-1);
    end = std::chrono::system_clock::now();
    QuickMTime = end-start;

    resetArray(mainArray, sortArray, size);
    if(MergeTime <= QuickFTime && MergeTime <= QuickMTime){
        if(QuickMTime <= QuickFTime){
            cout << "1st: Merge sort @ " << MergeTime.count() << 's' << endl;
            cout << "2nd: Quick sort (Middle) @ " << QuickMTime.count() << 's' << endl;
            cout << "3rd: Quick sort (Front) @ " << QuickFTime.count() << 's' << endl;
        }
        else{
            cout << "1st: Merge sort @ " << MergeTime.count() << 's' << endl;
            cout << "2nd: Quick sort (Front) @ " << QuickFTime.count() << 's' << endl;
            cout << "3rd: Quick sort (Middle) @ " << QuickMTime.count() << 's' << endl;
        }
    }
    else if(QuickFTime <= MergeTime && QuickFTime <= QuickMTime){
        if(QuickMTime <= MergeTime){
            cout << "1st: Quick sort (Front) @ " << QuickFTime.count() << 's' << endl;
            cout << "2nd: Quick sort (Middle) @ " << QuickMTime.count() << 's' << endl;
            cout << "3rd: Merge sort @ " << MergeTime.count() << 's' << endl;
        }
        else{
            cout << "1st: Quick sort (Front) @ " << QuickFTime.count() << 's' << endl;
            cout << "2nd: Merge sort @ " << MergeTime.count() << 's' << endl;
            cout << "3rd: Quick sort (Middle) @ " << QuickMTime.count() << 's' << endl;
        }
    }
    else{
        if(QuickFTime <= MergeTime){
            cout << "1st: Quick sort (Middle) @ " << QuickMTime.count() << 's' << endl;
            cout << "2nd: Quick sort (Front) @ " << QuickFTime.count() << 's' << endl;
            cout << "3rd: Merge sort @ " << MergeTime.count() << 's' << endl;
        }
        else{
            cout << "1st: Quick sort (Middle) @ " << QuickMTime.count() << 's' << endl;
            cout << "2nd: Merge sort @ " << MergeTime.count() << 's' << endl;
            cout << "3rd: Quick sort (Front) @ " << QuickFTime.count() << 's' << endl;
        }
    }

    delete mainArray;
    delete sortArray;
    return 1;
}


int initArray(int **main, int **sort){
    srand(time(NULL));
    cout << "Please enter a data set size\n> ";
    int size = userInInt();
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
    cout << endl;
}
