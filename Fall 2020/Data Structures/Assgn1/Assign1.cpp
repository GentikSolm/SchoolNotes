#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <limits>
#include <cmath>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//TODO:
/*
    Linked list implementation
    Timesl
    add quick notes
*/




//GLOBALS
const int DBSIZE = 1000; //CHANGE FOR LARGER DB FOR ARRAY

//CLASSES / STRUCTS
struct city{
    string city;
    float xcord;
    float ycord;
};

class CityArray{
private:
    city cityDb[DBSIZE];
    int size=0;
public:
    void addCity(const float  xcord, const float ycord, const string cName, const bool init);
        // Add city into db, true for success and false for city already present
    void deleteCityName(const string cName);
        //Delete city from db by name
    void deleteCityCoord(const float xcord, const float ycord);
        //Delete city from db by name
    void printNearby(const string cName, const float distance);
        //print nearby locations
    int searchDbName(const string cName);
        //search db by name
    int searchDbCoord(const float xcord, float ycord);
        //search db by location
    void printDb(const int location);
    void printDbFull();
};

// class cityLinked{
// private:
//
// public:
//     bool addCity(const float  xcord, const float ycord);
//         // Add city into db, true for success and false for city already present
//
// };
float dec_to_rad(float degree);
void printMenu();
float getx();
float gety();
string getName();
int userInInt();
float userInfloat();
    // Requests float from the user and then verfies it is a float.
    // The validated user input is then returned
    // Non-requred string termin, is what is displayed when asking for the variable.
    // termin is ONLY used if input is invalid
    // NOTE: NO OUTPUT TO USER UNLESS INVALID INPUT

int main()
{
    int choice;
    char letter;
    CityArray ArrayDb;
    float x,y;
    int location;
    string name;
    std::ifstream database;
    database.open("Database.txt");
    while(!database.eof()){
        database >> name >> x >> y;
        ArrayDb.addCity(x, y, name,1);
    }
    database.close();
    do{
        printMenu();
        cout << "Enter your implementation option: ";
        cin >> letter;
        while(letter != 'A' && letter != 'b'){
            cout << "That was not a valid letter! Please enter another letter: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> letter;
        }
        cout << "Enter your operation option: ";
        choice = userInInt();
        if(letter == 'A'){

            switch (choice) {
                case 1://Insert
                    name = getName();
                    x = getx();
                    y = gety();
                    ArrayDb.addCity(x, y, name,0);

                break;
                case 2://search name
                    name = getName();
                    location = ArrayDb.searchDbName(name);
                    ArrayDb.printDb(location);
                break;
                case 3://search coord
                    x = getx();
                    y = gety();
                    location = ArrayDb.searchDbCoord(x,y);
                    ArrayDb.printDb(location);
                break;
                case 4://delete name
                    name = getName();
                    ArrayDb.deleteCityName(name);
                break;
                case 5://delete coord
                    x = getx();
                    y = gety();
                    ArrayDb.deleteCityCoord(x,y);
                break;
                case 6://list all in area
                    name = getName();
                    cout << "Enter Distance: ";
                    y = userInfloat();
                    ArrayDb.printNearby(name, y);
                break;
                case 7://print entire db
                    ArrayDb.printDbFull();
                break;
            }
        }
        else if(letter == 'B'){
            switch (choice) {
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                break;
                case 6:
                break;
                case 7:
                break;
            }
        }
    }while(choice != 8);



    // std::chrono::time_point<std::chrono::system_clock> start, end;
    // start = std::chrono::system_clock::now();
    // end = std::chrono::system_clock::now();
    // std::chrono::duration<float> elapsed_seconds = end‐start;
    // std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    // std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";


}


void CityArray::addCity(const float  xcord, const float ycord, const string cName, const bool init){
    // Add city into db, true for success and false for city already present
    if(CityArray::searchDbName(cName) != -1 && !init){
        cout << "No need to insert again, as this record exists in the existing data set.\n\n";
        return;
    }
    cityDb[size].city = cName;
    cityDb[size].xcord = xcord;
    cityDb[size].ycord = ycord;
    size++;
    if(!init) cout << "Record inserted successfully.\n\n";
    return;
}
void CityArray::deleteCityName(const string cName){
    //Delete city from db by name
    int location;
    location = searchDbName(cName);
    if(location == -1){
        cout << "No such record exists in the existing data set.\n\n";
        return;
    }
    for(int i = location; i < size; i++){
        cityDb[i].city = cityDb[i+1].city;
        cityDb[i].xcord = cityDb[i+1].xcord;
        cityDb[i].ycord = cityDb[i+1].ycord;
    }
    size--;
    cout << "Deleted successfully" << endl;
}
void CityArray::deleteCityCoord(const float xcord, const float ycord){
    //Delete city from db by name
    int location;
    location = searchDbCoord(xcord,ycord);
    if(location == -1){
        cout << "No such record exists in the existing data set.\n";
        return;
    }
    for(int i = location; i < size; i++){
        cityDb[i].city = cityDb[i+1].city;
        cityDb[i].xcord = cityDb[i+1].xcord;
        cityDb[i].ycord = cityDb[i+1].ycord;
    }
    size--;
    cout << "Deleted successfully" << endl;
}
void CityArray::printNearby(const string cName, const float distance){
    //print nearby locations
    int arrLoc = searchDbName(cName);
    if(arrLoc ==-1){
        cout << "No such record exists in the existing data set.\n";
        return;
    }
    float x,y,x1,y1, distanceBetween;
    x = dec_to_rad(cityDb[arrLoc].xcord);
    y = dec_to_rad(cityDb[arrLoc].ycord);
    cout << "Output:\n";
    for(int i = 0; i < size; i++){
        x1 = dec_to_rad(cityDb[i].xcord);
        y1 = dec_to_rad(cityDb[i].ycord);
        distanceBetween = 3963 * acos(sin(x)*sin(x1)+cos(x)*cos(x1)*cos(y1-y));
        if(distanceBetween <= distance){
            cout << cityDb[i].city << ", (" << cityDb[i].xcord << ", " << cityDb[i].ycord << ')' << endl;
        }
    }

}
int CityArray::searchDbName(const string cName){
    //search db by name
    for(int i = 0; i < size; i++){
        if(cityDb[i].city == cName) return i;
    }
    return -1;
}
int CityArray::searchDbCoord(const float xcord, float ycord){
    //search db by location
    for(int i = 0; i < size; i++){
        if(cityDb[i].xcord == xcord && cityDb[i].ycord == ycord) return i;
    }
    return -1;
}
void CityArray::printDb(const int location){
    cout << "Output:\n";
    cout << cityDb[location].city << ", (" << cityDb[location].xcord << ", " << cityDb[location].ycord << ')' << endl;
}
void CityArray::printDbFull(){
    cout << "Output:\n";
    for(int i = 0; i < size; i++){
        cout << cityDb[i].city << ", (" << cityDb[i].xcord << ", " << cityDb[i].ycord << ')'<< endl;
    }
}

float dec_to_rad(float degree){
    float M_PI = 3.1415926535;
    return degree * (M_PI/180.0);
}
float userInfloat(){
	float temp;
	cin >> temp;
	while(cin.fail()){
		cout << "That was not a number! Please enter a number\n::";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> temp;
	}
	return temp;
}
int userInInt(){
	int temp;
	cin >> temp;
	while(cin.fail() || temp < 1 || temp > 8){
		cout << "That was not a valid option! Please enter a number\n::";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> temp;
	}
	return temp;
}
void printMenu(){
    cout << "******************************************" << endl;
    cout << "Implementation Options:" << endl;
    cout << "A. Use an array-based list implementation\nB. Use a linked-list implementation" << endl;
    cout << endl;
    cout << "Operation Options:" << endl;
    cout << "1. Insert a record" << endl;
    cout << "2. Search for a record by name" << endl;
    cout << "3. Search for a record by Coordinate" << endl;
    cout << "4. Delete a record by name" << endl;
    cout << "5. Delete a record by coordinate" << endl;
    cout << "6. Print records within a given diestance of a specified location" << endl;
    cout << "7. Print all records" << endl;
    cout << "8. Exit" << endl;
    cout << endl;
}
float getx(){
    cout << "Enter the x coordinate of the city: ";
    return userInfloat();
}
float gety(){
    cout << "Enter the y coordinate of the city: ";
    return userInfloat();
}
string getName(){
    cout << "Enter name of the city: ";
    string temp;
    cin >>temp;
    return temp;
}
