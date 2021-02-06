/*
   COPYRIGHT (C) 2020 Joshua Brown (4323254) All rights reserved.
   CSII assignment I
   Author.  Joshua Brown
            jgb38@zips.uakron.edu
   Version. 1.01 04.20.2020
   Purpose: recursion
*/

#include <iostream>
#include <limits>
using std::cout;
using std::cin;
using std::endl;

void asterisks(int n);
//outputs desired ammount of *
int power(int x, int y);
// recurses till y = 0, then multiplies all x.
double powerReverse(int x, int y);
// returns 1 / power(x, y)

bool mainMenu();
//menu selection and calls functions based on choice
void disMenu();
//displays menu
int main(){
    bool flag = true;
    while(flag){
        disMenu();
        flag = mainMenu();
    }
}

void disMenu(){
    cout << "-------------------------\n";
    cout << "\t0: Exit" << endl;
    cout << "\t1: Write asterisks" << endl;
    cout << "\t2: Positive Power" << endl;
    cout << "\t3: Negative Power" << endl;
}
bool mainMenu(){
    int choice;
    cout << "-> ";
    cin >> choice;
    while(cin.fail() || choice > 3 || choice < 0){
        cout << "\tPlease enter a valid choice.\n-> ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
        cin >> choice;
    }
    int num1, num2;
    switch (choice) {
        case 0:
            return false;
        break;
        case 1:
            cout << "Please enter an integer\n-> ";
            cin >> num1;
            while(cin.fail() || num1 < 0){
                cout << "\tPlease enter a valid integer.\n-> ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
                cin >> num1;
            }
            cout << '\t';
            asterisks(num1);
            return true;
        break;
        case 2:
            cout << "Please enter two integers\n-> ";
            cin >> num1 >> num2;
            while(cin.fail() || num2 < 0){
                cout << "\tPlease enter a valid integer.\n-> ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
                cin >> num1 >> num2;
            }
            cout << '\t' << power(num1, num2) << endl;
            return true;
        break;
        case 3:
            cout << "Please enter two integers\n-> ";
            cin >> num1 >> num2;
            while(cin.fail() || num2 > 0){
                cout << "\tPlease enter a valid integer.\n-> ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
                cin >> num1 >> num2;
            }
            cout << '\t' << powerReverse(num1,num2) << endl;
            return true;
        default:
        return true;
    }
}
void asterisks(int n){
    if(n > 0){
        cout << '*';
        asterisks(n-1);
    }
    else{
        cout << endl;
    }
}
int power(int x, int y){
    if(y > 0){
        return x * power(x,y-1);
    }
    else return 1;
}
double powerReverse(int x, int y){
    y *=-1;
    return 1.0/power(x,y);
}
