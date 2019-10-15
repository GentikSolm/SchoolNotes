// Program id: CSLab06.cpp
// This is our template for CS Lab 06
// UNIT TESTING PRACTICE PROGRAM
// This program is used for the University of Akron, Department of Computer Science Laboratories
// Program based on Tony Gaddis, Starting Out with C++: From Control Structures through Objects,
//  (8th Ed.), Addison-Wesley Longman Publishing Co., Inc. Boston, MA, USA �2015
//
// Goal: test all four functions
// First test: use assertions in each function to validate, such as assert(length > 0 && "length must
// be greater than 0.00") // before return length in the getLength function, etc...
// Make sure you put the additional messages in each assert.
// Second test: replace the getArea function with a stub, returning values of your choice.
// You can use a message indicating that the
// function was called with a value of x for the length and y for the width. Example:
// The getArea function was called with the following arguments:
// length: 7.3
// width: 2.2
// Third test: place the logic into main to make it a driver program, and test it accordingly
// Example line in your driver would be: area = getArea(9.2, 6.3)


#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

// Function prototypes
void getLength(double &);
void getWidth(double &);
double getArea(double, double);
void displayData(double, double, double);

int main()
{
  double length;  // To hold the rectangle's length
  double width;	// To hold the rectangle's width
  double area;	// To hold the rectangle's area

  // Get the rectangle's length.
  getLength(length);

  // Get the rectangle's width.
  getWidth(width);

  // Get the rectangle's area.
  area = getArea(length, width);

  // Display the rectangle's data.
  displayData(length, width, area);

  return 0;
}

//***************************************************
// getLength function                               *
//***************************************************
//Precondition: nothing is passed into this function
//Postcondition: The value of length, a positive number of the type double
//will be returned
void getLength(double &length)
{
  // Get the length.
  cout << "Enter the length: ";
  cin >> length;
}

//***************************************************
// getWidth function                                *
//***************************************************
//Precondition: nothing is passed into this function
//Postcondition: The value of width, a positive number of the type double
//will be returned
void getWidth(double &width)
{
  // Get the width.
  cout << "Enter the width: ";
  cin >> width;
}

//***************************************************
// getArea function                                 *
//***************************************************
//Precondition: length and width must be valid numbers, greater than 0.00
//Postcondition: The value of the area, a positive number of the type double
//will be returned
double getArea(double length, double width)
{
   cout << "getArea function called using values:\n";
   cout << "length: " << length;
   cout << "\nwidth: " << width;
   cout << "\nReturning 100.";
   return 100; //Not
}

//***************************************************
// displayData function                             *
//***************************************************
//Precondition: length, width, and area must be valid numbers, greater than 0.00
//Postcondition: The display of the values of the length, width, and the area as output
void displayData(double length, double width, double area)
{
   cout << "\nRectangle Data\n"
        << "--------------\n"
	<< "Length: " << length << endl
	<< "Width:  " << width << endl
	<< "Area:   " << area << endl;
}
