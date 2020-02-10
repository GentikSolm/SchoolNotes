/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGNA
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 2.6.2020
  Purpose: demonstrate knowledge of classes
*/

#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <cstdlib>
#include <ctime>
using std::unique_ptr;
using std::cout;
using std::cin;
using std::endl;

// Global Constants
// Number of computer labs
const int NUMLABS = 8;
// Number of computers in each lab
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan",
"The University of Pittsburgh", "Stanford University", "Arizona State University",
"North Texas State University", "The University of Alabama, Huntsville",
"Princeton University", "Duquesne University"};
// Program----------------------------------------------

/*
To do:
    Make UI
    Make user deletion member function
    Make random ID verification
    General user input & verification
    function to print out each lab.
        use a lab member function for this
    initialization message


Done:
    General framework for date structure:
        Array of pointers to Labs Objects -> Each lab has Array of pointers to Users
    Search function for user id
    member function for initializing new user
    read functions for id, time, and name
    Destructors for both classes
    newId creator

*/
class User{
private:
    int time;
    std::string name;
    int id;
public:
    User();
    void initUser(const int, const int,const std::string);
    std::string outName();
    int outId();
    int outTime();
};
class Lab{
private:
    int numStations;
    User* stations = nullptr;
public:
    void initLab(const int numStations_);
    int rId(const int stationNum);
    int rTime(const int stationNum);
    std::string rName(const int stationNum);
    int nStations();
    void initUser(const int stationNum, const int id_, const int time_, const std::string name_);
    ~Lab();
};

double searchUser(const int id_, Lab Labs[NUMLABS]);
int newId();

int main(){
    Lab labs[NUMLABS];
    for(int i = 0; i < NUMLABS; i++){
        labs[i].initLab(LABSIZES[i]);
    }

}

/*
Lab Functions
*/
Lab::~Lab(){
    delete []stations;
}
void Lab::initLab(const int numStations_){
    numStations = numStations_;
    stations = new User[numStations];
}
int Lab::rId(const int stationNum){
    return stations[stationNum].outId();
}
int Lab::rTime(const int stationNum){
    return stations[stationNum].outTime();
}
std::string Lab::rName(const int stationNum){
    return stations[stationNum].outName();
}
int Lab::nStations(){
    return numStations;
}
void Lab::initUser(const int stationNum, const int id_, const int time_, const std::string name_){
    stations[stationNum].initUser(id_, time_, name_);
}

/*
User Functions
*/
void User::initUser(const int id_, const int time_, const std::string name_){
    id = id_;
    time = time_;
    name = name_;
}
User::User(){
    id = -1;
    time = 0;
    name = "";
}
std::string User::outName(){
    return name;
}
int User::outId(){
    return id;
}
int User::outTime(){
    return time;
}

/*
Other Functions
*/
int newId(){
	srand(time(0));
    num = (rand() % 10) + (rand() % 10) * 10 + (rand() % 10) * 100 + (rand() % 10) * 1000 + (rand() % 10) * 10000;
    return num;
}
double searchUser(const int id_, Lab labs[NUMLABS]){
    bool flag = false;
    for(int i = 0; i < NUMLABS; i++){
        for(int j = 0; j < labs[i].nStations(); j++){
            if(labs[i].rId(j) == id_){
                flag = true;
                return i + j*.01;
            }
        }
    }
    return -1;
}
