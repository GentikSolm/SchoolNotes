/*
   COPYRIGHT (C) 2020 Joshua Brown (4323254) All rights reserved.
   CSII assignment 1
   Author.  Joshua Brown
            jgb38@zips.uakron.edu
   Version. 1.01 01.29.2020
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream class

// build your class and member functions here
class Complex{
private:
	double real, imaginary;
public:
	Complex(double r, double i);
	std::string toString(void);
	Complex add(Complex);
	Complex subtract(Complex);
	Complex multiply(Complex);
	void setComplexNumber(int r,int i);

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
Complex Complex::add(Complex num){
	Complex newNum(num.real + real, num.imaginary + imaginary);
	return newNum;
}
Complex Complex::subtract(Complex num){
	Complex newNum(real - num.real, imaginary - num.imaginary);
	return newNum;
}
Complex Complex::multiply(Complex num){
	double newReal = 0, newImaginary = 0;
	newReal = num.real * real - (num.imaginary * imaginary);
	newImaginary = num.real * imaginary + num.imaginary * real;
	Complex newNum(newReal, newImaginary);
	return newNum;
}
void Complex::setComplexNumber(int r, int i){
	Complex(r,i);
}

int main()
{
	for (double i = 1; i < 100; ++i){
		Complex a{i * 2, i + 2};
		Complex b{i * 3, i + 3};

		Complex c = a.add(b); // invoke add function and assign to object c
		std::cout << "Test case for Complex: add " << std::endl;
		std::cout << a.toString() << " + " << b.toString() << " = " << c.toString() << std::endl;
		std::cout << std::endl;

		a.setComplexNumber(i * 2, i + 2); // reset realPart and
		b.setComplexNumber(i * 3, i + 3); // and imaginaryPart

		std::cout << "Test case for Complex: subtract " << std::endl;
		c = a.subtract(b); // invoke subtract function and assign to object c
		std::cout << a.toString() << " - " << b.toString() << " = " << c.toString() << std::endl;
		std::cout << std::endl;

		a.setComplexNumber(i * 2, i + 2); // reset realPart and
		b.setComplexNumber(i * 3, i + 3); // and imaginaryPart

		std::cout << "Test case for Complex: multiply " << std::endl;
		c = a.multiply(b); // invoke multiply function and assign to object c
		std::cout << a.toString() << " * " << b.toString() << " = " << c.toString() << std::endl;
		std::cout << std::endl;
		std::cout << "-----------------------\n\n";
   	}

}
