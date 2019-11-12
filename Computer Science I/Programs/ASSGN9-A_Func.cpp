#include <string>
#include <cstring>
void reverse(char word[]){
	//Pre condtion: word is a cstring with some value.
	//Post conditon: word is reversed

	// array length
	int length = strlen(word)-1;
	//pointers for start and end
	char *front, *rear;
	// loop that goes through each item untill half the size
	// of length, so that it is not reversed twice.
	for(int i = 0; i <= length/2; i++){
		// i incriments, as does length -i
		front = &word[i]; rear = &word[length-i];
		// This is handy because when i = length -i, aka odd words, it
		// swaps in place, making no need to check for even or odd.
		std::swap(*front, *rear);
	}

}
