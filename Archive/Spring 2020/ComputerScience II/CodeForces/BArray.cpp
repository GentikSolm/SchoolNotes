#include <iostream>
#include <vector>
#include <set>
using std::vector;
using std::cout;
using std::cin;

int main(){
    // Size is size of vector
    // uniqueNums is how many uniqueNums we are looking for
    // last is the last unique number to return
    int size, uniqueNums, last;

    // taking in vars
    cin >> size >> uniqueNums;

    // make int array
    vector<int>myArray(size);

    // making int set
    std::set<int> mySet;

    // taking in numbers and populating the vector
    for(int i = 0; i < size; i++){
        cin >> myArray[i];

        // At the same time, we are filling the int set
        mySet.insert(myArray[i]);

        // Here, if the size of the set is uniqueNums, then we have found all the nums we need
        // It will then set last to i, which is the last unique number we need.
        if(mySet.size() == uniqueNums){
            last = i;
            break;
        }
    }
    // If it did not break the previous for loop, then there are not enough unique numbers
    // therefore, out -1 -1
    if(mySet.size() < uniqueNums){
        cout << "-1 -1";
        return 0;
    }
    // new int set
    std::set<int> mySet2;
    // this for loop runs backwards from the last position found.
    // This is required by question #23
    for(int i = last; i >= 0; i--){
        mySet2.insert(myArray[i]);
        // If the size of set2 is the ammount of uniqueNums, we have found the lower bound
        // The first position will be i +1 and the last will be last +1.
        // +1 is needed for both because they are taken from the array positions,
        // which are 1 behind common counting.
        if(uniqueNums == mySet2.size()){
            cout << i+1 << ' ' << last+1;
            return 0;
        }
    }
}
