#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using std::cin;
using std::cout;
using std::ifstream;
using std::string;
using std::map;
using std::vector;
using std::endl;

myMap initMap(myMap list, string fileName){
    ifstream data;
    data.open(fileName);
    string tUser; // follower
    string tFoll; // followed
    getline(data, tUser);
    while(!(data >> tUser).eof()){
        data >> tFoll;
        node* temp = new node;
        temp->user = tUser;
        temp->next = list[tFoll];
        list[tFoll] = temp;
    }
    return list;
}
myMap delMap(myMap list){
    node* temp;
    for(auto iter = list.begin(); iter != list.end(); iter++){
        while(iter->second != nullptr){
            temp = iter->second;
            iter->second = iter->second->next;
            delete temp;
        }
    }
    return list;
}
std::vector<folls> findFolls(myMap list){
    std::vector<folls> followCounts;
    folls temp;
    for(auto iter = list.begin(); iter != list.end(); iter++){
        temp.follows = 0;
        temp.user = iter->first;
        while(iter->second != nullptr){
            temp.follows++;
            iter->second = iter->second->next;
        }
        auto iter2 = followCounts.begin();
        while(iter2 != followCounts.end() && iter2->follows > temp.follows){
            iter2++;
        }
        followCounts.insert(iter2, temp);
    }
    return followCounts;
}
void topTen(std::vector<folls> followCounts){
    for(int i = 0; i < 10; i++){
        cout << followCounts[i].user << " -- " << followCounts[i].follows << endl;
    }
}
void avgFolls(myVec followCounts){
    int total = 0;
    int size = 0;
    for(auto iter = followCounts.begin(); iter != followCounts.end(); iter++){
        total += iter->follows;
        size++;
    }
    cout << "Average of " << total / size << " followers per user.\n";
}
void medFolls(myVec followCounts){
    cout << "Median ammount of followers: " << followCounts[followCounts.size()/2-1].follows << endl;
}
