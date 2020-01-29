/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGNA
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 1.27.2020
  Purpose:
*/
#include <iostream>
#include <string>
#include <sstream>
using std::cout;

class Complex{
private:
	double real, imaginary;
public:
	Complex(double real, double imaginary);
	std::string toString();

};

Complex::Complex(double r = 0, double i = 0){
	real = r;
	imaginary = i;
}
std::string Complex::toString(void){
	std::ostringstream output;
	output << real << " + " << imaginary << 'i';
	return output.str();
}

int main(){
	Complex num(5,2);
	cout << num.toString();
}
