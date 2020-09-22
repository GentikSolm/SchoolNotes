#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <limits>
#include <cmath>
#include <fstream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//TODO:
/*
    Times
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
struct cityLinked{
    string city;
    float xcord;
    float ycord;
    cityLinked* next = nullptr;
};
class CityLinkedList{
private:
    cityLinked* head = nullptr;
public:
    void addCity(const float  xcord, const float ycord, const string cName, const bool init);
        // Add city into db, true for success and false for city already present
    void deleteCityName(const string cName);
        //Delete city from db by name
    void deleteCityCoord(const float xcord, const float ycord);
        //Delete city from db by name
    void printNearby(const string cName, const float distance);
        //print nearby locations
    void printDb(const cityLinked* location);
    void printDbFull();

    cityLinked* searchDbName(const string cName);
        //search db by name
    cityLinked* searchDbCoord(const float xcord, float ycord);
        //search db by location
    ~CityLinkedList();
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
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<float> elapsed_seconds;
    std::cout << std::fixed;
    std::cout << std::setprecision(7);
    int choice;
    char letter;
    CityArray ArrayDb;
    CityLinkedList LinkedDb;
    float x,y;
    int location;
    cityLinked* linkedLocation;
    string name;
    std::ifstream database;
    database.open("Database.txt");
    while(!database.eof()){
        database >> name >> x >> y;
        ArrayDb.addCity(x, y, name,1);
        LinkedDb.addCity(x, y, name,1);
    }
    database.close();
    do{
        printMenu();
        cout << "Enter your implementation option: ";
        cin >> letter;
        while(letter != 'A' && letter != 'B' && letter != 'a' && letter != 'b'){
            cout << "That was not a valid letter! Please enter another letter: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> letter;
        }
        cout << "Enter your operation option: ";
        choice = userInInt();
        if(letter == 'A' || letter == 'a'){
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
        else if(letter == 'B' || letter == 'b'){
            switch (choice) {
                case 1://Insert
                    name = getName();
                    x = getx();
                    y = gety();
                    
                    LinkedDb.addCity(x, y, name,0);
                break;
                case 2://search name
                    name = getName();
                    linkedLocation = LinkedDb.searchDbName(name);
                    LinkedDb.printDb(linkedLocation);
                break;
                case 3://search coord
                    x = getx();
                    y = gety();
                    linkedLocation = LinkedDb.searchDbCoord(x,y);
                    LinkedDb.printDb(linkedLocation);
                break;
                case 4://delete name
                    name = getName();
                    LinkedDb.deleteCityName(name);
                break;
                case 5://delete coord
                    x = getx();
                    y = gety();
                    LinkedDb.deleteCityCoord(x,y);
                break;
                case 6://list all in area
                    name = getName();
                    cout << "Enter Distance: ";
                    y = userInfloat();
                    LinkedDb.printNearby(name, y);
                break;
                case 7://print entire db
                    LinkedDb.printDbFull();
                break;
            }
        }
    }while(choice != 8);
}

//Array functions
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
        if(cityDb[i].city == cName) continue; //skips self
        x1 = dec_to_rad(cityDb[i].xcord);
        y1 = dec_to_rad(cityDb[i].ycord);
        distanceBetween = 3963 * acos(sin(x)*sin(x1)+cos(x)*cos(x1)*cos(y1-y));
        if(distanceBetween <= distance){
            cout << cityDb[i].city << ", (" << cityDb[i].xcord << ", " << cityDb[i].ycord << ')' << endl;
        }
    }

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

//Linked list functions
void CityLinkedList::addCity(const float  xcord, const float ycord, const string cName, const bool init){
    if(CityLinkedList::searchDbName(cName) == nullptr){
        cityLinked* temp;
        temp = head;
        head = new cityLinked;
        head->next = temp;
        head->city = cName;
        head->xcord = xcord;
        head->ycord = ycord;
        if(!init){
            cout << "Record inserted successfully.\n\n";
        }
    } else if(!init){
        cout << "No need to insert again, as this record exists in the existing data set.\n\n";
    }
}
void CityLinkedList::deleteCityName(const string cName){
    cityLinked* temp = head;
    cityLinked* temp1;
    if(temp == nullptr){
        cout << "No such record exists in the existing data set.\n\n";
    } else if(temp->city == cName) {
        head = temp->next;
        delete temp;
        temp = nullptr;
        return;
    }
    while(temp->next!=nullptr){
        if(temp->next->city == cName){
            temp1 = temp->next;
            temp->next = temp->next->next;
            delete temp1;
            cout << "Deleted successfully" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "No such record exists in the existing data set.\n\n";
}
void CityLinkedList::deleteCityCoord(const float xcord, const float ycord){
    cityLinked* temp = head;
    cityLinked* temp1;
    if(temp == nullptr){
        cout << "No such record exists in the existing data set.\n\n";
    } else if(temp->xcord == xcord && temp->ycord == ycord) {
        head = temp->next;
        delete temp;
        temp = nullptr;
        return;
    }
    while(temp->next!=nullptr){
        if(temp->next->xcord == xcord && temp->next->ycord == ycord){
            temp1 = temp->next;
            temp->next = temp->next->next;
            delete temp1;
            cout << "Deleted successfully" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "No such record exists in the existing data set.\n\n";
}
void CityLinkedList::printNearby(const string cName, const float distance){
    cityLinked* linkedLoc = CityLinkedList::searchDbName(cName);
    cityLinked* temp = head;
    if(linkedLoc == nullptr){
        cout << "No such record exists in the existing data set.\n";
        return;
    }
    float x,y,x1,y1, distanceBetween;
    x = dec_to_rad(linkedLoc->xcord);
    y = dec_to_rad(linkedLoc->ycord);
    cout << "Output:\n";
    while(temp!=nullptr ){
        if(temp->city == cName){
            temp = temp->next;
            continue;
        } //skips self
        x1 = dec_to_rad(temp->xcord);
        y1 = dec_to_rad(temp->ycord);
        distanceBetween = 3963 * acos(sin(x)*sin(x1)+cos(x)*cos(x1)*cos(y1-y));
        if(distanceBetween <= distance){
            cout << temp->city << ", (" << temp->xcord << ", " << temp->ycord << ')' << endl;
        }

        temp = temp->next;
    }
}
cityLinked* CityLinkedList::searchDbName(const string cName){
    cityLinked* temp = head;
    while(temp!=nullptr){
        if(temp->city == cName){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
cityLinked* CityLinkedList::searchDbCoord(const float xcord, float ycord){
    cityLinked* temp = head;
    while(temp!=nullptr){
        if(temp->xcord == xcord && temp->ycord == ycord){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
void CityLinkedList::printDb(const cityLinked* location){
    cout << "Output:\n";
    cout << location->city << ", (" << location->xcord << ", " << location->ycord << ')' << endl;
}
void CityLinkedList::printDbFull(){
    cityLinked* temp = head;
    cout << "Output:\n";
    while(temp!=nullptr){
        cout << temp->city << ", (" << temp->xcord << ", " << temp->ycord << ')' << endl;
        temp = temp->next;
    }

}
CityLinkedList::~CityLinkedList(){
    cityLinked* temp = head;
    while(temp->next!=nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
    delete temp;
}



//General Functions
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
		cout << "That was not a valid option! Please enter a number: ";
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
