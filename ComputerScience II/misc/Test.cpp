#include <iostream>
#include <memory>

int main(){
    long int size, uniqueNums;
    std::cin >> size >> uniqueNums;
    std::unique_ptr<long int[]> myArray(new long int[size]);
    for(long int i = 0; i < size; i++){
        std::cin >> myArray[i];
    }
    long int first = 1, last = 1, countUnique = 1;
    bool flag = true;
    for(long int i = 0; i < size; i++){
        if(i == size-1 && flag == true)break;
        if(countUnique == uniqueNums){
            if(i == 0)i++;
            last = i;
            break;
        }
        if(flag && myArray[i] == myArray[i+1]){
            first++;
        }
        else{
            bool newflag = true;
            if(!i)newflag = false;
            for(long int j = 0; j < i; j++){
                if(myArray[j] == myArray[i]){
                    newflag = false;
                    break;
                }
            }
            if(newflag)countUnique++;
            flag = false;

        }
    }
    if(countUnique != uniqueNums){
        first = -1;
        last = -1;
    }
    std::cout << first << ' ' << last;
    return 0;
}
