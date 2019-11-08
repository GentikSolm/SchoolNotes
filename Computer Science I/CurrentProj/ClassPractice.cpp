#include <iostream>

int binarySearch(int array[], int size, int value, int positionFlag);

int main(){
	int myar[] = {0,1,1,1,1,6,20,30};
	std::cout << binarySearch(myar, 8, 1,1);
}

int binarySearch(int array[], int size, int value, int positionFlag){
	int first = 0,
		last = size -1,
		middle,
		position = -1;
	bool found = false;
	// any
	if(positionFlag == 0){
		while(!found && first <= last){
			middle = (first + last)/2;
			if(array[middle] == value){
				found = true;
				position = middle;
			}
			else if(array[middle] > value){
				last = middle -1;
			} else {
				first = middle +1;
			}
		}
	}
	// right most
	else if(positionFlag == 1){
		while(!found && first <= last){
			middle = (first + last)/2;
			if(array[middle] == value){
				int i = 0;
				while(array[middle + i] == value && middle + i + 1 < size) i++;
				position = middle + i -1;
				found = true;
			}
			else if(array[middle] > value){
				last = middle -1;
			} else {
				first = middle +1;
			}
		}
	}

	//left most
	else if(positionFlag == -1){
		while(!found && first <= last){
			middle = (first + last)/2;
			if(array[middle] == value){
				int i = 0;
				while(array[middle + i] == value && middle + i - 1 >= 0) i--;
				position = middle + i + 1;
				found = true;
			}
			else if(array[middle] > value){
				last = middle -1;
			} else {
				first = middle +1;
			}
		}
	}
	return position;
}
