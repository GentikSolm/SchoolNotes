/*
   COPYRIGHT (C) 2020 Joshua Brown (4323254) All rights reserved.
   CSII assignment E
   Author.  Joshua Brown
            jgb38@zips.uakron.edu
   Version. 1.01 02.24.2020
   Purpose: Use Namespaces
*/
// Place your name and description of this program at the top of this file in a comment.
// Give preconditions and post conditions for all functions.
// Make certain to follow the programming rubric and the specifications for this assignment.

#include <iostream>
#include "myFunction.cpp"
using std::cout;

void theFunction(char[]);

void theGreeting();

int main()
{
    char myArray[SIZE];
    for (int i = 0; i < SIZE; ++i)
        myArray[i] = 'a' + (i % 10);

    // call your global namespace greeting function
    theGreeting();
    // call your function using only the array
    // to demonstrate the SIZE is sharable (external)
    theFunction(myArray);
    // call your second namespace greeting function
    {
        using namespace myNamespace2;
        myGreeting();
        myFunction(myArray);
    }
    // call your first namespace greeting function
    {
        using namespace myNamespace1;
        myGreeting();
        myFunction(myArray);
    }


    return 0;
}

void theFunction(char myArray[SIZE]){
    for(int i = 0; i < SIZE; i++){
        cout << myArray[i];
    }
    cout << '\n';
}

void theGreeting(){
    cout << "Hello there, this is the global namespace.\nmyFunction prints the array without spaces.\n";
}
