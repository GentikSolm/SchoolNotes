/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  CSI assignment 1 A
  Auther. Josh Brown
          jgb38@zips.uakron.edu
  Version 1.01 09.16.2019
  Purpose: Calculates grades of N classroom excercieses as a percentage
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int excercieses;
  cout << "How many excercieses to input? ";
  cin >> excercieses;

  //Defining variables
  int i = 0;
  double gotPoints;
  double totalPoints;
  double temp;
  double grade;
  string gradeLetter;

  // While loop that takes in N scores and totals
  while(excercieses > i){
    i++;
    cout << endl << "Score received for excerciese " << i << ": ";
    cin >> temp;
    gotPoints += temp;
    cout << "Total points possible for excerciese " << i << ": ";
    cin >> temp;
    totalPoints += temp;
  };

  //Determines percentage grade
  grade = gotPoints / totalPoints * 100;
  cout << "Your total is " << gotPoints << " out of " << totalPoints << ", or " << std::setprecision(2)<< std::fixed << grade << "%." << endl;

  // Determines the grade letter
  if(grade >= 93) gradeLetter = "A";
  else if(grade >= 90) gradeLetter = "A-";
  else if(grade >= 87) gradeLetter = "B+";
  else if(grade >= 83) gradeLetter = "B";
  else if(grade >= 80) gradeLetter = "B-";
  else if(grade >= 77) gradeLetter = "C+";
  else if(grade >= 73) gradeLetter = "C";
  else if(grade >= 70) gradeLetter = "C-";
  else if(grade >= 67) gradeLetter = "D+";
  else if(grade >= 63) gradeLetter = "D";
  else if(grade >= 60) gradeLetter = "D-";
  else gradeLetter = "F";

  cout << "Your letter grade is " << gradeLetter << '.';
}
