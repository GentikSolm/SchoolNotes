/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  Auther. Josh Brown
          jgb38@zips.uakron.edu
  Version 1.01 09.10.2019
  Purpose: Class Assignment
*/
#include <iostream>
using namespace std;
int main(){
  double d1, d2;
  int i1, i2;
  d1 = 1.6;
  d2 = 3.9;
  i1 = d1;
  i2 = d2;
  //This is the exact andswer, beacause both variables are double and therefore do not round.
  //This is exactly 3.9/1.6
  //outpust: 2.4375
  cout << "d2/d1: " << d2/d1 << endl;

  //When i1 and i2 are assigned, they are converted into ints because i1 and i2 were both defined as int.
  //This is actually 3/1
  //output: 3
  cout << "i2/i1: " << i2/i1 << endl;

  //This gives the same answer as the first cout, however the output is rounded to an int because of the static cast.
  //this is 3.9/1.6 rounded down.
  //output: 2
  cout << "Static cast to int: " << static_cast<int>(d2/d1);
  return 0;
}
