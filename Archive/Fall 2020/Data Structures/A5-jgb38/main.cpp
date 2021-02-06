#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "func.cpp"
using std::cin;
using std::cout;
using std::ifstream;
using std::string;
using std::map;
using std::endl;

int main(){
    // adjecency list. Using map since the userid's are so large, this makes indexing very fast and easy
    map<string, node*> adjList;
    adjList = initMap(adjList, FILENAME);

    //this is a sorted vector of all the followers and their follower count. This makes top ten, average and median very
    //very fast.
    std::vector<folls> followCounts = findFolls(adjList);
    menu(adjList, followCounts);
    cout << followCounts.size();
    //deletes adj list.
    adjList = delMap(adjList);
    return 0;
}
