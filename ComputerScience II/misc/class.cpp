#include <iostream>
#include <ios>
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::endl;

class Complex{
private:
    double real, imag;
public:
    Complex();
    Complex(double r, double i);
    Complex(const Complex &org);
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);
    Complex operator+ (Complex const &);
	friend Complex operator- (Complex const &, Complex const &);
	friend Complex operator* (Complex const &, Complex const &);
    friend bool operator== (Complex const &, Complex const &);
    friend bool operator!= (Complex const &, Complex const &);
    Complex& operator=(const Complex &);
};
Complex::Complex(){
    real = 0;
    imag = 0;
}
Complex::Complex(double r, double i){
    real = r;
    imag = i;
}
Complex::Complex(const Complex &org){
    real = org.real;
    imag = org.imag;
}
Complex& Complex::operator=(const Complex &org){
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
Complex operator- (Complex const &num1, Complex const &num2){
	Complex newNum(num1.real - num2.real, num1.imag - num2.imag);
	return newNum;
}
Complex operator* (Complex const &num1, Complex const &num2){
	double newReal = 0, newImaginary = 0;
	newReal = num1.real * num2.real - (num1.imag * num2.imag);
	newImaginary = num1.real * num2.imag + num1.imag * num2.real;
	Complex newNum(newReal, newImaginary);
	return newNum;
}
bool operator== (Complex const &num1, Complex const &num2){
    return num1.real == num2.real && num1.imag == num2.imag;
}
bool operator!= (Complex const &num1, Complex const &num2){
    return num1.real != num2.real && num1.imag != num2.imag;
}
ostream& operator<< (ostream& out, const Complex& num){
    out << num.real << " + " << num.imag << 'i';
    return out;
}
istream& operator>> (istream& in, Complex& num){
    char temp1, temp2, temp3;
    double tempReal, tempImag;
    if(!(in >> temp1 >> tempReal >> temp2 >> tempImag >> temp3
    && temp1 == '(' && temp2 == ',' && temp3 == ')')){
        in.setstate(std::ios::failbit);
        cout << "Fail!\n";
    }
    else{
        num.real = tempReal;
        num.imag = tempImag;
    }
    return in;
}

int main(){
    Complex a, b(1,4);
    cout << a + b + b;
    return 0;
}
