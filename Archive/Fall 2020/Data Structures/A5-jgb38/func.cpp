#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using std::cin;
using std::queue;
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

        //this next block inserts each item into the vector based on the follower count
        //this way calculating average, median, and top ten are extreemly easy.
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
        cout << i+1 << ". User "<< followCounts[i].user << " Has " << followCounts[i].follows << " followers." << endl;
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

void findPath(myMap list, string end, string start){
    //standard BFS
    queue<string> path;
    map<string, bool> marked;
    map<string, string> parent;
    string user;
    path.push(start);
    while(!path.empty()){
        user = path.front();
        path.pop();
        for(node* iter = list[user]; iter!=nullptr; iter = iter->next){
            if(!marked[iter->user]){
                parent[iter->user] = user;
                marked[iter->user] = true;
                path.push(iter->user);
            }
        }
    }

    //If the end is unmarked, then it was never seen, meaning there is no path.
    if(!marked[end]){
        cout << "No path was found!" << endl;
        return;
    }
    //If there is a path, then
    queue<string> pathResult;
    string index = end;
    //when each child node is added to the que, its parent is also marked in a map.
    //this while loop backtracks each parent from the end to the start.
    while(parent[index] != start){
        pathResult.push(parent[index]);
        index = parent[index];
    }
    // after the queue is full, it prints out
    cout << end << " -> ";
    while(!pathResult.empty()){
        cout << pathResult.front() << " -> ";
        pathResult.pop();
    }
    //start is not in the queue because of the nature of the while loop so we must print it after.
    cout << start;
}
void menu(myMap adjList, myVec followCounts){
    int choice;
    string start, end;
    do{
        cout << "Please enter a choice 1-5:" << endl;
        cout << "1. Display Top Ten most followed users\n";
        cout << "2. Display the median amount of followers\n";
        cout << "3. Display the average amount of followers\n";
        cout << "4. Search the path between two users\n";
        cout << "5. Exit program\n";
        ///////////////////////////////////////////////////
        cout << "-> ";
        choice = userInInt();
        switch (choice) {
            case 1:
                cout << endl;
                topTen(followCounts);
                cout << endl;
            break;
            case 2:
                cout << endl;
                medFolls(followCounts);
                cout << endl;
            break;
            case 3:
                cout << endl;
                avgFolls(followCounts);
                cout << endl;
            break;
            case 4:
                cout << endl;
                cout << "Enter two users to search seperated by a space.\n-> ";
                cin >> start >> end;
                findPath(adjList, start, end);
                cout << endl << endl;
            break;
            case 5:
                cout << "Goodbye!";

        }
    } while(choice != 5);
}
int userInInt(){
	int temp;
	cin >> temp;
	while(cin.fail() || temp <= 0 || temp >= 6){
		cout << "That was not a valid number! Please enter a number\n> ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> temp;
	}
	return temp;
}
