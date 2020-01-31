#include <iostream>
#include <vector>
using std::vector;

int main(){
    int size, uniqueNums;
    std::cin >> size >> uniqueNums;
    vector<int>myArray(size);
    for(long int i = 0; i < size; i++){
        std::cin >> myArray[i];
    }
    int first = 0, last = 1, countUnique = 0;
    bool flag = true, flag2;
    for(int i = 0; i < size; i++){
        flag2 = true;
        while(flag && i < size-1){
            if(myArray[i] == myArray[i+1]){
                first++;
                i++;
            }
            else{
                flag = false;
            }
        }
        if(countUnique == uniqueNums){
            last = i;
            break;
        }
        for(int j = first; j < i; j++){
            if(myArray.size() > 99999) break;
            if(myArray[j] == myArray[i]){
                flag2 = false;
                break;
            }
        }
        if(flag2)countUnique++;
    }
    if(countUnique != uniqueNums){
        first = -2;
        last = -1;
    }
    std::cout << first + 1 << ' ' << last;
    return 0;
}
