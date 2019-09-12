/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  class assignment 3
  Auther. Josh Brown
          jgb38@zips.uakron.edu
  Version 1.01 09.12.2019
*/

#include <iostream>
using namespace std;

int main(){
  int x=3,y(4)z;
  if(x == y){
    z=5;
  }
  else{
    z = 6;
  }
  //What are the values of x,y,z?
  //The above values of x, y, z are respectivly:
  //3, 4, 6
  //This is because == is a comparator, and returns True if they are the same.
  //Therefore, 3 != 4, and it will run the else statement, making z = 6


  if(x = y){
    z=15;
  }
  else{
    z=16;
  }
  //What are the values of x,y,z?
  //The above values of x, y, z are respectivly:
  //4, 4, 15
  //Here, it is setting x to y, y is 4, and therefore x is now 4.
  //The program will read anything greater than 0 to be true, and will therefore execute
  //the next statement, making z = 15


  y = 0;
  if(x = y){
    z = 25;
  }
  else{
    z = 26;
  }
  //What are the values of x,y,z?
  //The above values of x, y, z are respectivly:
  //0, 0, 26
  //Finally, using the same reasoning as before, because it sets x to y,
  //which is 0, this will read 0 as false.
  //This will case the else statement to run, changing z to 26.
}
