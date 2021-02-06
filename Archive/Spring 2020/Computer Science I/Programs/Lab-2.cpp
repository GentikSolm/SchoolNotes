/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  CSI assignment 1 A
  Auther. Josh Brown
          jgb38@zips.uakron.edu
  Version 1.01 09.09.2019
  Purpose: Learning program Documentation and Standards.
*/
#include <iostream>
using namespace std;
int main()
{
  const double stateTax = .25;
  const double countyTax = .75;
  const doublle federalTax = 1.25;
  int statePopTotal;
  int countyPopTotal;
  int federalPopTotal;

  // Start of Psuedo code translation
  double price;
  double newPrice;
  double priceDisc = 0.00;
  double stateTax = 0.00;
  double countyTax = 0.00;
  double total = 0.00;
  double charity = 0.00;
  int counter = 0;

  counter += 1;
  countyTax = price *.05;
  stateTax = price * .03;
  newPrice = countyTax + stateTax + price;
  //If statements manipulating the price discount
  if((countyTax + stateTax) > 250.00)
  {
    priceDisc = newPrice *.01;
  };

  if(priceDisc > 15.00)
  {
    charity += priceDisc * .02;
    priceDisc -= charity;
  };

  newPrice -= priceDisc;
  total += newPrice;
  counter += 1;
  cout << total << endl;
  cout << charity;
}
