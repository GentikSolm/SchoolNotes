#ifndef SORT_H
#define SORT_H
void bubbleSort(int *arr, int size);
void insertSort(int *arr, int size);
void selSort(int *arr, int size);

void mergeSort(int *arr, int left, int right);
void quickSortM(int *arr, int start, int end);
void quickSortF(int *arr, int start, int end);
int partFirst(int *arr, int start, int end);
int partMiddle(int *arr, int start, int end);

#endif
