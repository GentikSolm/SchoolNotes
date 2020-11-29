#ifndef FUNC_H
#define FUNC_H
#include <string>
#include <map>
#include <iostream>
#include <vector>

std::string FILENAME = "github-graph_V1.0.txt";
//std::string FILENAME = "github-graph.csv";

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
myVec findFolls(myMap);


#endif
