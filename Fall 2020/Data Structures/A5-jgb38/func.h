#ifndef FUNC_H
#define FUNC_H
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>

// std::string FILENAME = "github-graph_V1.0.txt";
std::string FILENAME = "github-graph.csv";

struct node{
    std::string user;
    node *next = nullptr;
};
struct folls{
    std::string user;
    int follows = 0;
};

typedef std::map<std::string, node*> myMap;
typedef std::vector<folls> myVec;

myMap initMap(myMap, std::string fileName);
myMap delMap(myMap);
void topTen(myVec);
void avgFolls(myVec);
void medFolls(myVec);
void findPath(myMap list, std::string start, std::string end);
bool findPath(myMap list, std::string start, std::string end, std::queue<std::string> path_, std::map<std::string, bool> marked_);
myVec findFolls(myMap);


#endif
