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
    map<string, node*> adjList;
    adjList = initMap(adjList, FILENAME);
    std::vector<folls> followCounts = findFolls(adjList);
    //topTen(followCounts);
    // avgFolls(followCounts);
    // medFolls(followCounts);
    findPath(adjList,"1", "4");
    //deletes adj list.
    adjList = delMap(adjList);
}
