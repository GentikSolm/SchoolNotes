/*
   COPYRIGHT (C) 2020 Joshua Brown (4323254) All rights reserved.
   CSII assignment D
   Author.  Joshua Brown
            jgb38@zips.uakron.edu
   Version. 1.01 02.03.2020
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream class
#include <ios> //for setting failbit on istream
using std::cin;
using std::cout;
using std::ostream;
using std::endl;
using std::istream;
// build your class and member functions here
class Complex{
private:
	double real, imag;
public:
    //Constructors and copy
    Complex();
    Complex(double r, double i);
    Complex(const Complex &org);

    //Classis .functions
	std::string toString(void);
    Complex add(Complex);
    Complex subtract(Complex);
    Complex multiply(Complex);
    void setComplexNumber(int r,int i);

    //Overload operators
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);
    Complex operator+ (Complex const &);
    Complex operator- (Complex const &);
    Complex operator* (Complex const &);
    bool operator== (Complex const &);
    bool operator!= (Complex const &);
    Complex& operator=(const Complex &);
    //Destructor class not required because no dynamic variables
    // were created.

};
std::string Complex::toString(void){
	std::ostringstream output;
	output << real << " + " << imag << 'i';
	return output.str();
}
Complex Complex::add(Complex num){
	Complex newNum(num.real + real, num.imag + imag);
	return newNum;
}
Complex Complex::subtract(Complex num){
	Complex newNum(real - num.real, imag - num.imag);
	return newNum;
}
Complex Complex::multiply(Complex num){
	double newReal = 0, newimag = 0;
	newReal = num.real * real - (num.imag * imag);
	newimag = num.real * imag + num.imag * real;
	Complex newNum(newReal, newimag);
	return newNum;
}
void Complex::setComplexNumber(int r, int i){
	Complex(r,i);
}

//New func
// Default Constructor
Complex::Complex(){
    real = 0;
    imag = 0;
}
Complex::Complex(double r, double i){
    real = r;
    imag = i;
}

// copy function
Complex::Complex(const Complex &org){
    real = org.real;
    imag = org.imag;
}
Complex& Complex::operator= (Complex const &org){
    //Safe guarding self assignment
    if(this != &org){
        real = org.real;
        imag = org.imag;
    }
    return *this;
}
Complex Complex::operator+ (Complex const &num){
	Complex newNum(real + num.real, imag + num.imag);
	return newNum;
}
Complex Complex::operator- (Complex const &num){
	Complex newNum(real - num.real, imag - num.imag);
	return newNum;
}
Complex Complex::operator* (Complex const &num){
	double newReal = 0, newImaginary = 0;
	newReal = real * num.real - (imag * num.imag);
	newImaginary = real * num.imag + imag * num.real;
	Complex newNum(newReal, newImaginary);
	return newNum;
}
bool Complex::operator== (Complex const &num){
    return real == num.real && imag == num.imag;
}
bool Complex::operator!= (Complex const &num){
    return real != num.real && imag != num.imag;
}
ostream& operator<< (ostream& out, const Complex& num){
    //Didnt use sstream, just used a refernce ostream
    out << num.real << " + " << num.imag << 'i';
    return out;
}
istream& operator>> (istream& in, Complex& num){
    // because of format requirement, need temp char variables to hold
    // chars: '(', ',', ')'
    // First line inputs nums into tempReal and tempImag, so that
    // if fail, the class data is not affected.
    // Fail is check if input into the different vars fail, or
    // if temp1, temp2 or temp3 are not the correct characters.
    char temp1, temp2, temp3;
    double tempReal, tempImag;
    if(!(in >> temp1 >> tempReal >> temp2 >> tempImag >> temp3
    && temp1 == '(' && temp2 == ',' && temp3 == ')')){
        //sets failbit for istream
        // DOES NOT VALIDATE INPUT
        in.setstate(std::ios::failbit);
        cout << "Fail!\n";
    }
    //if it passes, then tempReal and tempImag will
    // be passed and set as the class's variables
    else{
        num.real = tempReal;
        num.imag = tempImag;
    }
    return in;
}


int main()
{
   for (double i = 1; i < 100; ++ i)
   {
     Complex a{i * 2, i + 2};
     Complex b{i * 3, i + 3};

     Complex c = a.add(b); // invoke add function and assign to object c
     std::cout << "Test case for Complex: add " << std::endl;
     std::cout << a.toString() << " + " << b.toString() << " = " << c.toString() << std::endl;

     a.setComplexNumber(i * 2, i + 2); // reset realPart and
     b.setComplexNumber(i * 3, i + 3); // and imagPart

     std::cout << "Test case for Complex: subtract " << std::endl;
     c = a.subtract(b); // invoke subtract function and assign to object c
     std::cout << a.toString() << " - " << b.toString() << " = " << c.toString() << std::endl;
     std::cout << std::endl;

     a.setComplexNumber(i * 2, i + 2); // reset realPart and
     b.setComplexNumber(i * 3, i + 3); // and imagPart

     std::cout << "Test case for Complex: multiply " << std::endl;
     c = a.multiply(b); // invoke multiply function and assign to object c
     std::cout << a.toString() << " * " << b.toString() << " = " << c.toString() << std::endl;
     std::cout << std::endl;
   }

//  THE FOLLOWING CODE FOR TESTING YOUR OVERLOADING ...

   for (double i = 1; i < 10; ++ i)
   {
     Complex y{i * 2.7, i + 3.2};
     Complex z{i * 6, i + 8.3};

     Complex x;
     Complex k;

     std::cout << "Enter a complex number in the form: (a, b)\n? ";
     std::cin >> k; // demonstrating overloaded >>
     std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
               << k << '\n'; // demonstrating overloaded <<
     x = y + z; // demonstrating overloaded + and =
     std::cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
     x = y - z; // demonstrating overloaded - and =
     std::cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
     x = y * z; // demonstrating overloaded * and =
     std::cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

     if (x != k) { // demonstrating overloaded !=
        std::cout << x << " != " << k << '\n';
     }

     std::cout << '\n';
     x = k;

     if (x == k) { // demonstrating overloaded ==
        std::cout << x << " == " << k << '\n';
     }
       std::cout << std::endl;
     }

return 0;

}
