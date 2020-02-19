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
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

// Global Constants
// Number of computer labs
const int NUMLABS = 9;
// Number of computers in each lab
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37, 1};
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan",
"The University of Pittsburgh", "Stanford University", "Arizona State University",
"North Texas State University", "The University of Alabama, Huntsville",
"Princeton University", "Duquesne University", "Bruh uni"};

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

double searchUser(const int id_, Lab labs[NUMLABS]);
int randNum();
bool mainMenu(Lab labs[NUMLABS]);
void search(Lab labs[NUMLABS]);
int intVeri(int min, int max);
void displayLab(Lab labs[NUMLABS]);
void startup();
void showMenu();
void login(Lab labs[NUMLABS]);
void logoff(Lab labs[NUMLABS]);

int main(){
    bool flag = true;
    Lab labs[NUMLABS];
    for(int i = 0; i < NUMLABS; i++){
        labs[i].initLab(LABSIZES[i]);
    }
    startup();
    while(flag){
        showMenu();
        flag = mainMenu(labs);
    }
    return 0;
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
    num = rand() % 99999;
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
            login(labs);
            break;
        case 2:
            logoff(labs);
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
        cin.ignore(256, '\n');
        cin >> input;
    }
    return input;
}
void search(Lab labs[NUMLABS]){
    int searchNum, labNum, stationNum;
    double foundNum;
    cout << "Enter the 5 digit ID number of the user to find:\n";
    searchNum = intVeri(1,99999);
    foundNum = searchUser(searchNum, labs);
    labNum = foundNum;
    stationNum = (foundNum - labNum) * 100;
    cout << "User " << setw(5) << std::setfill('0') << searchNum;
    cout << setw(0) << std::setfill(' ');
    if(foundNum == -1){
        cout << " is not logged on.\n";
    }
    else{
        cout << " is in lab " << labNum +1 << " at computer " << stationNum +1 << endl;
        cout << "Name: " << labs[labNum].rName(stationNum) << '\t' << "Time using station: " << labs[labNum].rTime(stationNum) << endl;
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
        cout << std::right;
        if(labs[labNum].rId(i) == -1) cout << "empty";
        else {
            cout << setw(5) << std::setfill('0') << labs[labNum].rId(i);
            cout << setw(0) << std::setfill(' ');
        }
        if((i+1) % 5 == 0) cout << endl;
        else cout << "  " << setw(0) << std::right;
    }
    cout << endl << std::right;
}
void startup(){
    cout << "\n\tWelcome - here is our list of available labs\n";
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
void login(Lab labs[NUMLABS]){
    int labChoice, statChoice, id, time;
    string name;
    bool flag = true;
    cout << "Enter the lab number the user is loggin in from (1 - " << NUMLABS << "): ";
    labChoice = intVeri(1,NUMLABS);
    for(int i = 0; i < LABSIZES[labChoice-1]; i++){
        if(labs[labChoice-1].rId(i) != -1){
            flag = false;
        }
        else{
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << "Lab " << labChoice << ", " << UNIVERSITYNAMES[labChoice-1] << ", is at full capacity.\n"
            << "Please try your request again later...\n";
        return;
    }
    cout << "Enter the computer station number the user is logging in to (1 - " << LABSIZES[labChoice-1] << "): ";
    statChoice = intVeri(1, LABSIZES[labChoice-1]);
    if(labs[labChoice-1].rId(statChoice-1) != -1){
        cout << "Sorry, that work station is already taken!\n";
        return;
    }
    cout << endl;
    id = randNum();
    while(id < 1 || searchUser(id, labs) != -1) id = randNum();
    cout << "User id: " << setw(5) << std::setfill('0') << id;
    cout << setw(0) << std::setfill(' ');
    cin.ignore(256, '\n');
    flag = true;
    int countLetters = 0;
    do{
        cout << endl << "Please enter the name of the user:\n";
        getline(cin, name);
        if(name.length() > 35 || name.empty()){
            cout << "Name must be at least 1 character and at most 35";
            flag = false;
        }
        for(int i = 0; i < name.length(); i++){
            if(isalpha(name[i])) countLetters++;
            if(i == name.length()-1 && countLetters ==0){
                cout << "Name cannot be blank.";
                flag = false;
                break;
            }
            if(!(isalpha(name[i]) || name[i] == ' ')){
                cout << "Invalid name! Must contain only letters and spaces.";
                flag = false;
                break;
            }
            flag = true;
        }
    }while(!flag);
    cout << "Please enter the minutes of use for the workstation (15/30/45/60):\n";
    time = intVeri(15,60);
    while(time != 15 && time != 30 && time != 45 && time != 60){
        cout << "Invalid time, Enter (15/30/45/60):\n";
        time = intVeri(15,60);
    }
    labs[labChoice-1].initUser(statChoice-1, id, time, name);
    cout << "User succesfully logged in.\n";
}
void logoff(Lab labs[NUMLABS]){
    int id, labNum, stationNum;
    double location;
    cout << "Please enter User id to be logged off:\n";
    id = intVeri(1,99999);
    location = searchUser(id, labs);
    if(location == -1){
        cout << "User not currently logged in!\n";
        return;
    }
    labNum = location;
    stationNum = (location - labNum) * 100;
    labs[labNum].initUser(stationNum, -1, 0, "");
    cout << "User " << setw(5) << std::setfill('0') << id;
    cout << setw(0) << std::setfill(' ');
    cout << " was succesfully logged off.\n";
}
