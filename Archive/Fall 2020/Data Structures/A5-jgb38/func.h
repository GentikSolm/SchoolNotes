#ifndef FUNC_H
#define FUNC_H
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>

// std::string FILENAME = "github-graph_V1.0.txt";
std::string FILENAME = "github-graph.csv";
//globals for filename to use

struct node{
    //this is for the adj list. Each node links to the next follower
    std::string user;
    node *next = nullptr;
};
struct folls{
    //this is for the sorted vector of users and their followers.
    std::string user;
    int follows = 0;
};

typedef std::map<std::string, node*> myMap;
typedef std::vector<folls> myVec;
//make big long deffs easier

int userInInt();
    //grabs a verified int in the range 1-5
myMap initMap(myMap, std::string fileName);
    //initializes map, returns pointer to map
myMap delMap(myMap);
    //deletes map, returns pointer to deleted map
void topTen(myVec);
    //prints out the first ten elements of the sorted vector myVec
void avgFolls(myVec);
    //prints the average followers of myvec.
void medFolls(myVec);
    //prints the median of the data set. must be sorted
void findPath(myMap list, std::string start, std::string end);
    //finds path between two nodes. if no path then it will print "no path"
void menu(myMap, myVec);
    //main menu driver
myVec findFolls(myMap);
    //this function creates the vector of folls, sorted.

#endif
