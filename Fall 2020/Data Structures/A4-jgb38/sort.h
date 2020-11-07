#ifndef SORT_H
#define SORT_H
void bubbleSort(int *arr, int size);
    //Sorts the array of size using bubble sort. arr must
    //be an array with ints
void insertSort(int *arr, int size);
    //Sorts the array of size using insert sort. Arr must
    //be an array with ints.
void selSort(int *arr, int size);
    //Sorts the array of size using selection sort. Arr must
    //be an array with ints.
void mergeSort(int *arr, int left, int right);
    //Sorts the array of size using Merge sort. Arr must
    //be an array with ints.
void quickSortM(int *arr, int start, int end);
    //Sorts the array of size using Quicksort (Middle partition) sort. Arr must
    //be an array with ints.
void quickSortF(int *arr, int start, int end);
    //Sorts the array of size using Quicksort (First partition) sort. Arr must
    //be an array with ints.
int partFirst(int *arr, int start, int end);
    //Partitions the array at the first element. Array must be
    //indexible from start to end.
int partMiddle(int *arr, int start, int end);
    //Partitions the array at the middle element. Array must be
    //indexible from start to end.
#endif
