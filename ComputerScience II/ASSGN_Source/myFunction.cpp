#include "myFunction.hpp"
#include <iostream>
using std::cout;
void myNamespace1::myFunction(char myArray[SIZE]){
    for(int i = SIZE-1; i >= 0; i--){
        cout << myArray[i] << ' ';
    }
    cout << '\n';
}
void myNamespace1::myGreeting(){
    cout << "\nHello from namespace 1!\n";
}
void myNamespace2::myFunction(char myArray[SIZE]){
    for(int i = 0; i < SIZE; i++){
        cout << myArray[i] << ' ';
    }
    cout << '\n';
}
void myNamespace2::myGreeting(){
    cout << "\nHello from namespace 2!\n";
}
