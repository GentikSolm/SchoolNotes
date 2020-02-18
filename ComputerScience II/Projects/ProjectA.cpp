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
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

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
int randNum();
bool mainMenu(Lab Labs[NUMLABS]);
void search(Lab Labs[NUMLABS]);
int intVeri(int min, int max);
void displayLab(Lab labs[NUMLABS]);
void startup();
void showMenu();


// MAIN ------------------------------------------------------------------
int main(){
    bool flag = true;
    Lab labs[NUMLABS];
    for(int i = 0; i < NUMLABS; i++){
        labs[i].initLab(LABSIZES[i]);
    }
    labs[0].initUser(18, 12345, 15, "Hose");
    startup();
    while(flag){
        showMenu();
        flag = mainMenu(labs);
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
int randNum(){
    int num;
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
bool mainMenu(Lab labs[NUMLABS]){
    int choice;
    cout << setw(35)  << "Your choice: ";
    choice = intVeri(1, 5);
    switch (choice) {
        case 1:
            // login(labs);
            break;
        case 2:
            // logoff(labs);
            break;
        case 3:
            search(labs);
            break;
        case 4:
            displayLab(labs);
            break;
        case 5:
            return false;
    }
    cin.get();
    cin.get();
    return true;
}
int intVeri(int min = -1, int max =-1){
    int input;
    cin >> input;
    while(cin.fail() || ((input < min || input > max) && !(min == -1 && max == -1)) ){
        cout << "Invalid entry, must be a number";
        if(!(min == -1 && max == -1)){
            cout << " greater than " << min << " and less than " << max;
        }
        cout << ":\n";
        cin.clear();
        cin.ignore();
        cin >> input;
    }
    return input;
}
void search(Lab labs[NUMLABS]){
    int searchNum, labNum, stationNum;
    double foundNum;
    cout << "Enter the 5 digit ID number of the user to find:\n";
    searchNum = intVeri(9999, 100000);
    foundNum = searchUser(searchNum, labs);
    labNum = foundNum;
    stationNum = (foundNum - labNum) * 100;
    cout << "User " << searchNum;
    if(foundNum == -1){
        cout << " was not found in any lab.\n";
    }
    else{
        cout << " is in lab " << labNum +1 << " at computer " << stationNum +1 << endl;
    }
}
void displayLab(Lab labs[NUMLABS]){
    cout << "Please enter the lab to display: ";
    int labNum;
    labNum = intVeri(1, NUMLABS) - 1;
    cout << "\nLAB STATUS\n";
    cout << "Lab #\t" << labNum + 1 << " for " << UNIVERSITYNAMES[labNum] << endl;
    cout << "Computer Stations\n";
    for(int i = 0; i < LABSIZES[labNum]; i++){
        cout << std::setw(2) << std::left << i + 1 << ": ";
        if(labs[labNum].rId(i) == -1) cout << "empty";
        else cout << labs[labNum].rId(i);
        if((i+1) % 5 == 0) cout << endl;
        else cout << "  " << setw(0) << std::right;
    }
    cout << endl;
}
void startup(){
    cout << "\tWelcome - here is our list of available labs\n";
    for(int i = 0; i < NUMLABS; i++){
        cout << "lab # " << i + 1 << " for " << UNIVERSITYNAMES[i] << endl;
    }
}
void showMenu(){
    cout << ' ' << setw(60) << std::setfill('_') << ' ' << endl;
    cout << '|' << setw(60) << std::setfill('-') << '|' << endl;
    cout << '|' << setw(41) << std::setfill(' ') << "Josh Brown Incorporated" << setw(19) << '|' << endl;
    cout << '|' << setw(39) << std::setfill(' ') << "Computer Lab System" << setw(21) << '|' << endl;
    cout << '|' << setw(60) << std::setfill('_') << '|' << endl;
    cout << '|' << setw(35) << std::setfill(' ') << "MAIN MENU" << setw(25) << '|' << endl;
    cout << '|' << setw(40) << std::setfill(' ') << "1) Simulate login" << setw(20) << '|' << endl;
    cout << '|' << setw(41) << std::setfill(' ') << "2) Simulate logoff" << setw(19) << '|' << endl;
    cout << '|' << setw(32) << std::setfill(' ') << "3) Search" << setw(28) << '|' << endl;
    cout << '|' << setw(38) << std::setfill(' ') << "4) Disply a lab" << setw(22) << '|' << endl;
    cout << '|' << setw(30) << std::setfill(' ') << "5) Quit" << setw(30) << '|' << endl;
    cout << '|' << setw(60) << std::setfill('_') << '|' << endl << endl;
    cout << std::setfill(' ');
}
