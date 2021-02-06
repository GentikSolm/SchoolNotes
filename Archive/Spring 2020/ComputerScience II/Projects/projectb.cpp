/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  Project B
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 4.2.2020
  Purpose: Linked list project
*/

#include <iostream> //General cin/cout
#include <string> //std::string
#include <cstdlib> //rand
#include <ctime> //seeding rand with processer time
#include <iomanip> //setw and setfill
#include <cctype> //isalpha
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

// Global Constants
// Number of computer labs
const int NUMLABS = 8;
// Number of computers in each lab
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan",
"The University of Pittsburgh", "Stanford University", "Arizona State University",
"North Texas State University", "The University of Alabama, Huntsville",
"Princeton University", "Duquesne University"};

class Lab; //So user can have friend lab
class User{
private:
    int time, id, station;
    std::string name;
    User* next;
    //Added next and station.
    //Next taks care of next item in linked list
    //Because im not useing tombstones, station now holds station number instead
    // of being implied from sliceing number.
public:
    User();
    //Default constructor
    //Default values are:
        //Time 0
        //id: -1
        //name: ""
    void initUser(const int, const int,const std::string, const int stationNum_);
    //Constructor accessed by Lab
    //sets time, id, name to the parramaters passed. Does not
    //check for errors
    std::string outName();
    //returns name
    int outId();
    //returns id
    int outTime();
    //retuns time

    friend class Lab;
    //Easier for lab to manage station assignments
    friend double searchUser(const int id_, Lab labs[NUMLABS]);
    //easier for search user to look through contents of lab / data of user
};
class Lab{
    //INIT LAB MUST BE CALLED BEFORE
    //ANY OTHER FUNCTIONS THAT INTERACT
    //WITH LAB CLASS
private:
    int numStations;
    User* statHead = nullptr;
    //added statHead to hold the head of the linked list.
public:
    void initLab(const int numStations_);
    //Initialize lab to have one null node.
    // MUST ALWAYS HAVE ATLEAST ONE NODE, CODE SHOULD TAKE CARE OF THIS
    int rId(const int stationNum_);
    //return the id of the station number
    int rTime(const int stationNum_);
    //return the time of the station number
    std::string rName(const int stationNum_);
    //return the name of the station number
    int nStations();
    //returns the number of stations in the lab
    void initUser(const int stationNum_, const int id_, const int time_, const std::string name_);
    //Initialize's user at given station to given arguments
    void delUser(const int stationNum_);
    //Deletes user at selected station, maintaining linked list.
    ~Lab();
    //deconstructor for the linked list
    friend double searchUser(const int id_, Lab labs[NUMLABS]);
    //again friend so that search can be more effecient.
};

double searchUser(const int id_, Lab labs[NUMLABS]);
/* searchUser:
    searches the given linked list of labs for
    the id provided. If a station is found
    with that id, it will return a double
    where the non decimal value is the lab number
    and the decimal value is the station number.
    If no station found, will return -1

    Only works if there are less than 999 Universitys.
    to change, must also change math in:
        search()
        logoff()
    so that in conversion they change from *1000
        to desired ammount. i.e, if there is 4000
        Universitys, searchUser to j*.0001,
        and in search() and logoff, change
        conversion code to *10000.

    To find areas with the conversion math, search
    for "(001)" in the code base.
*/
int randNum();
// Generates a randum number up to 99999
bool mainMenu(Lab labs[NUMLABS]);
/* mainMenu
    Controls flow of program.
    asks user for an input, and then will call
    that function that the usere chooses based on
    number input. Does input verification using
    intVeri()
*/
void search(Lab labs[NUMLABS]);
/* search
    asks the user for an id to search for.
    Does all input verification using intVeri
    Converts double to two ints, and outputs
    the results to the user.
*/
int intVeri(int min, int max);
//Input verification for ints. Requires an input
// between a min and max, inclusive
// min must be less than max.
void displayLab(Lab labs[NUMLABS]);
//Displays the contents of a lab to user
void startup();
//Outputs a list of all University's and thier names
void showMenu();
//Shows menu. Should be used with and is built for
//mainMenu function.
void login(Lab labs[NUMLABS]);
/* login
    generates an unique new id for a new user
    and adds them to the desired station in
    the desired lab. Checks for full labs
    as well as already used stations.

    Name must be a only alpha string, with the
    exception of ' '
*/
void logoff(Lab labs[NUMLABS]);
//takes user id and finds & loggs off that user.
void lablog(char io, int id, string name, int userTime);
//Used for file I/O
void recover(Lab labs[NUMLABS]);
//Uses intveri for multiple num inputs.
//recover users from file


//Main function
int main(){
    bool flag = true;
    //Used for menu loop
    Lab labs[NUMLABS];
    for(int i = 0; i < NUMLABS; i++){
        labs[i].initLab(LABSIZES[i]);
        //Initializes labs to their desired size
    }
    startup();
    //onetime message of Universitys
    while(flag){
        //main program loop.
        showMenu();
        flag = mainMenu(labs);
    }
    return 0;
}

/*
Lab Functions
*/
Lab::~Lab(){
    //deletes linked list.
    User* itr;
    itr = statHead;
    //transverse the lab list.
    while(itr->next != nullptr){
        statHead = statHead->next;
        delete itr;
        itr = statHead;
    }
    delete itr;
}
void Lab::initLab(const int numStations_){
    //Using non tombstone approach
    numStations = numStations_;
    statHead = new User;
}
int Lab::rId(const int stationNum_){
    User* itr;
    itr = statHead;
    //transverse linked list. same exact structure used in rTime and rName
    while(1){
        if(itr->station == stationNum_) return itr->id;
        if(itr->next != nullptr) itr = itr->next;
        else break;
    }
    return -1;
}
int Lab::rTime(const int stationNum_){
    User* itr;
    itr = statHead;
    while(1){
        if(itr->station == stationNum_) return itr->time;
        if(itr->next != nullptr) itr = itr->next;
        else break;
    }
    return 0;
}
std::string Lab::rName(const int stationNum_){
    User* itr;
    itr = statHead;
    while(1){
        if(itr->station == stationNum_) return itr->name;
        if(itr->next != nullptr) itr = itr->next;
        else break;
    }
    return "";
}
int Lab::nStations(){
    return numStations;
}
void Lab::initUser(const int stationNum_, const int id_, const int time_, const std::string name_){
    //init user now inserts a new user at the head of the linked list, and takes
    //care of head pointer.
    User* newUser;
    if(statHead->id == -1){
        (*statHead).initUser(id_, time_, name_, stationNum_);
    }
    else{
        newUser = new User;
        newUser->next = statHead;
        statHead = newUser;
        (*statHead).initUser(id_, time_, name_, stationNum_);
    }
}
void Lab::delUser(const int stationNum_){

    User* itr, *last;
    itr = statHead;
    //if found node is head
    if(itr->station == stationNum_){
        if(statHead->next == nullptr)statHead = nullptr;
        else{
            statHead = statHead->next;
        }
    }
    //traverses list till station is found
    else{
        while(itr->next != nullptr) {
            last = itr;
            itr = itr->next;
            if(itr->station == stationNum_){
                last->next = itr->next;
                break;
            }
        }
    }
    //deletes whatever was found
    delete itr;
    //if the head was deleted, initiate a new head.
    if(statHead == nullptr){
        statHead = new User;
    }
}

/*
User Functions
*/
void User::initUser(const int id_, const int time_, const std::string name_, const int stationNum_){
    id = id_;
    time = time_;
    name = name_;
    station = stationNum_;
}
User::User(){
    id = -1;
    time = 0;
    name = "";
    next = nullptr;
    station = -1;
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
    //Neseted for loop that goes through every station
    // in every Lab
    User* itr;
    for(int i = 0; i < NUMLABS; i++){
        itr = labs[i].statHead;
        if(itr == nullptr) break;
        while(1){

            //i is the lab and station is the station
            if(itr->id == id_) return i + itr->station*.001;
            if(itr->next != nullptr){
                itr = itr->next;
            }
            else break;
        }
    }
    return -1;
}
bool mainMenu(Lab labs[NUMLABS]){
    int choice;
    cout << setw(35)  << "Your choice: ";
    choice = intVeri(1, 6);
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
            recover(labs);
            break;
        case 6:
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
    //Math for conversion-----
    searchNum = intVeri(1,99999);
    foundNum = searchUser(searchNum, labs);
    labNum = foundNum;
    stationNum = (foundNum - labNum) * 1000;
    //end Math for conversion-
    //(001)
    cout << "User " << setw(5) << std::setfill('0') << searchNum;
    cout << setw(0) << std::setfill(' ');
    if(foundNum == -1){
        cout << " is not logged on.\n";
    }
    else{
        cout << ", "<< labs[labNum].rName(stationNum) << ", is in lab " << labNum +1
            << " at computer " << stationNum +1 << endl;
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
    cout << '|' << setw(39) << std::setfill(' ') << "5) Recover Login" << setw(21) << '|' << endl;
    cout << '|' << setw(30) << std::setfill(' ') << "6) Quit" << setw(30) << '|' << endl;
    cout << '|' << setw(60) << std::setfill('_') << '|' << endl << endl;
    cout << std::setfill(' ');
}
void login(Lab labs[NUMLABS]){
    int labChoice, statChoice, id, time;
    string name;
    bool flag = true;
    cout << "Enter the lab number the user is loggin in from (1 - " << NUMLABS << "): ";
    labChoice = intVeri(1,NUMLABS);

    //Checks if the lab is full
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

    //Checks if station is used
    if(labs[labChoice-1].rId(statChoice-1) != -1){
        cout << "Sorry, that work station is already taken!\n";
        return;
    }
    cout << endl;

    //Generates random number for id,
    // and verifies that it is unique
    id = randNum();
    while(id < 1 || searchUser(id, labs) != -1) id = randNum();
    cout << "User id: " << setw(5) << std::setfill('0') << id;
    cout << setw(0) << std::setfill(' ');
    cin.ignore(256, '\n');
    flag = true;
    int countLetters = 0;

    //Verification for user's name
    do{
        cout << endl << "Please enter the name of the user:\n";
        getline(cin, name);
        for(int i = 0; i < name.length() || name.empty(); i++){
            if(name.length() > 35 || name.empty()){
                cout << "Name must be at least 1 character and at most 35\n";
                flag = false;
                break;
            }
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

    //time input
    cout << "Please enter the minutes of use for the workstation (15/30/45/60):\n";
    time = intVeri(15,60);
    //time verification
    while(time != 15 && time != 30 && time != 45 && time != 60){
        cout << "Invalid time, Enter (15/30/45/60):\n";
        time = intVeri(15,60);
    }
    labs[labChoice-1].initUser(statChoice-1, id, time, name);
    cout << "User succesfully logged in.\n";
    lablog('I', id, name, time);
}
void logoff(Lab labs[NUMLABS]){
    int id, labNum, stationNum;
    double location;
    cout << "Please enter User id to be logged off:\n";
    id = intVeri(1,99999);
    location = searchUser(id, labs);
    //Checks that user is logged in.
    if(location == -1){
        cout << "User not currently logged in!\n";
        return;
    }
    //Math for conversion---------
    labNum = location;
    stationNum = (location - labNum) * 1000;
    //end Math for conversion-----
    //(001)
    string name = labs[labNum].rName(stationNum);
    int time = labs[labNum].rTime(stationNum);
    labs[labNum].delUser(stationNum);
    cout << "User " << setw(5) << std::setfill('0') << id;
    cout << setw(0) << std::setfill(' ');
    cout << " was succesfully logged off.\n";
    lablog('O', id, name, time);
}
void lablog(char io, int id, string name, int userTime){
    //time
    time_t now = time(0);
    char* timeIn = ctime(&now);
    timeIn[20] = '\0';
    ofstream file;
    file.open("lablog.txt", std::ios_base::app);
    //Fairly self explanitory.
    file << timeIn << ' ' << io << ' ' << id << ' ' << name << ' ' << userTime << " min"<< endl;
    file.close();
}
void recover(Lab labs[NUMLABS]){
    int labChoice, stat, id = -1, selId, time, tempNum;
    string name, temp;
    //station is the first available station, labNum is the lab #
    bool flag = true;
    cout << "Enter the lab number you would like to fill:\n";
    labChoice = intVeri(1,8);
    //check for full labs.
    for(int i = 0; i < LABSIZES[labChoice-1]; i++){
        if(labs[labChoice-1].rId(i) != -1){
            flag = false;
        }
        else{
            flag = true;
            stat = i;
            break;
        }
    }
    if(!flag){
        cout << "Lab " << labChoice << ", " << UNIVERSITYNAMES[labChoice-1] << ", is at full capacity.\n"
            << "Please try your request again later...\n";
        return;
    }
    cout << "What id would you like to search records for:\n";
    selId = intVeri(1,99999);
    tempNum = searchUser(selId,labs);
    //Checks if searched user is already logged in to avoid id conflict.
    if(tempNum != -1){
        cout << "That user is already logged in!\n";
        return;
    }
    ifstream file;
    file.open("lablog.txt");
    while(!file.eof()){
        //Search for id in file
        //      weekday month   date    time    i/o
        file >> temp >> temp >> temp >> temp >> temp >> id >> name >> time >> temp;
        if(id == selId) break;
    }
    file.close();
    //Confirm that id is searched id, if not, throw errer and return
    if(id != selId){
        cout << "ID was not found in logs.\n";
        return;
    }
    cout << "User " << id << " found! \nName: " << name << "\t\tTime: " << time << " min" << endl;
    labs[labChoice-1].initUser(stat, id, time, name);
    //Log new login
    lablog('I', id, name, time);
}
