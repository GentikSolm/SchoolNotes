/* Lab 1 : main.cpp
Author: Joshua Brown
jgb38@uakron.edu
Purpose: Demonstration of a simple program */
#include <iostream>
using namespace std;
int main()
{
  cout << "Calculated total pay and output";
  // variables for payrate and hours
  int payrate = 7;
  int hours = 40;
  int totalPay = payrate * hours;
  cout << "Total pay: $" << totalPay << ".00" << endl;
}
