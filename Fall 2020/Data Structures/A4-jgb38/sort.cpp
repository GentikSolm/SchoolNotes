#include <iostream>
#include <utility>
#include "sort.h"
#include <vector>
using std::swap;
using std::vector;
using std::cout;

void bubbleSort(int *arr, int size){
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
void insertSort(int *arr, int size){
    int j, num;
    for(int i = 1; i < size; i++){
        num = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > num){
            swap(arr[j+1], arr[j]);
            j--;
        }
    }
}
void selSort(int *arr, int size){

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
}

void mergeSort(int *arr, int left, int right){
    if(left < right){
        int mid = (left + (right-1))/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        int size1, size2;
        size1 = mid - left +1;
        size2 = right - mid;

        vector<int> leftA (size1);
        vector<int> rightA (size2);
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
void quickSortF(int *arr, int start, int end){
    if(start < end){
        int part = partFirst(arr, start, end);
        quickSortF(arr, start, part-1);
        quickSortF(arr, part+1, end);
    }
}
int partFirst(int *arr, int start, int end){
    int pivot = arr[start];
    int iter = start;
    int temp;
    for(int i = start; i <= end; i++){
        if(arr[i] < pivot){
            iter++;
            temp = arr[i];
            arr[i] = arr[iter];
            arr[iter] = temp;
        }
    }
    temp = arr[start];
    arr[start] = arr[iter];
    arr[iter] = temp;
    return iter;
}
void quickSortM(int *arr, int start, int end) {
    int i = start, j = end;
    int tmp;
    int pivot = arr[(start + end) / 2];
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (start < j)
        quickSortM(arr, start, j);
    if (i < end)
        quickSortM(arr, i, end);
}
