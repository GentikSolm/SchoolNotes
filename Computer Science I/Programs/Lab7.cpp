/* Program id: CSLab04 Solution.cpp
 This is our solution for CS Lab 04, to be used for CS Lab 07 for debugging practice
 DEBUGGING practice program

  This program is used for the University of Akron, Department of Computer Science Laboratories

 Program based on Tony Gaddis, Starting Out with C++: From Control Structures through Objects,
  (8th Ed.), Addison-Wesley Longman Publishing Co., Inc. Boston, MA, USA �2015

 This program displays the following menu:
             Geometry Calculator
             1. Calculate the Area of a Circle
             2. Calculate the Area of a Rectangle
             3. Calculate the Area of a Triangle
             4. Quit
             Enter your choice (1-4):
 If the user enters 1, the program should ask for the radius of the circle and then display
 its area. Use the following formula: area pi * radius^2
 Use 3.14159 for pi and the radius of the circle for radius. If the user enters 2, the program
 should ask for the length and width of the rectangle and then display the rectangle�s
 area. Use the following formula: area = length * width
 If the user enters 3 the program should ask for the length of the triangle�s base and its
 height, and then display its area. Use the following formula: area = base * height * .5
 If the user enters 4, the program should end. */

#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Function prototypes
int geoMenu();
bool validateInput(int, int, int, string);
bool validateFloatInput(float, float, float, string);
float calculateCircle();
float calculateRectangle();
float calculateTriangle();

// Global constants (the only globals that we use)
const int CIRCLE_CHOICE		= 1;
const int RECTANGLE_CHOICE	= 2;
const int TRIANGLE_CHOICE	= 3;
const int QUIT_CHOICE		= 4;
// Global constant for pi
const double PI = 3.14159;

int main()
{
   float area = 0.0;	// Area of the selected shape
   while (true)
   {
      int choice = geoMenu();  // Get the user's shape choice
      // Decision construct (switch) to respond to the user's menu selection.
      switch (choice)
      {
         case CIRCLE_CHOICE:
            // CALL CIRCLE FUNCTION
            area = calculateCircle();
            break;

         case RECTANGLE_CHOICE:
            // CALL RECTANGLE FUNCTION
            area = calculateRectangle();
            break;

         case TRIANGLE_CHOICE:
            // CALL TRIANGLE FUNCTION
            area = calculateTriangle();
            break;

         case QUIT_CHOICE:
            cout << "Program ending.\n";
			return 0;
      }
      cout << endl << std::fixed << "The area from your choice is: " << area << endl;
      // setprecision if you wish to
	  cin.get();
   }
   return 0;
}
//**********************************************************************************
// Geo Menu is the menu for our program
// precondtion: call when geometric calculator menu is to be displaye
// postcondition: returns an int that is the user choice
//**********************************************************************************
int geoMenu()
{
   int choice;		                                   // User's shape choice
   bool loopFlag = true;                             // control for validation
   string msg("The valid choices are 1 through 4."); // invalid message
	cout << "Geometry Calculator\n\n";
	cout << "1. Calculate the area of a Circle\n";
	cout << "2. Calculate the area of a Rectangle\n";
	cout << "3. Calculate the area of a Triangle\n";
	cout << "4. Quit\n\n";
	do
   {
      cout << "Enter your choice (1-4): ";
      cin >> choice;
      loopFlag = validateInput(choice, 1, 4, msg);
   } while (loopFlag);
	return choice;
}
//**********************************************************************************
// Validate Input takes integer data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
//**********************************************************************************
bool validateInput(int userChoice, int range1, int range2, string message)
{
   bool goodOrNot = false;
   if ((cin.fail()) || ((userChoice < range1) || (userChoice > range2)))
   {
      cout << message << endl;
      goodOrNot = true;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   return goodOrNot;
}
//**********************************************************************************
// Calculate the circle
// calls validation for float input: takes float data and ensures it is correct.
// precondtion: called after valid user choice - no parms
// postcondition: returns the area of a geometric circle
//**********************************************************************************
float calculateCircle()
{
   float radius = 0;                                    // radius of the circle
   bool loopFlag = true;                                // control for validation
   string msg("The radius can not be less than zero."); // invalid message
   do
   {
      cout << "Enter the circle's radius: ";
      cin >> radius;
      loopFlag = validateFloatInput(radius, 1, 999999999.99, msg); // we put an upper limit here of 999M
   } while (loopFlag);
   return (PI * radius * radius);
}
//**********************************************************************************
// Calculate the rectangle
// calls validation for float input (length and width): takes float data and ensures it is correct.
// precondtion: called after valid user choice - no parms
// postcondition: returns the area of a geometric rectangle
//**********************************************************************************
float calculateRectangle()
{
   float length = 0;	                                    // Length of a rectangle
   float width = 0;	                                    // Width of a rectangle
   // start with inputting and validating the length
   bool loopFlag = true;                                 // control for validation
   string msg("The length can not be less than zero.");  // invalid message
   do
   {
      cout << "Enter the rectangle's length: ";
      cin >> length;
      loopFlag = validateFloatInput(length, 1, 999999999.99, msg); // we put an upper limit here of 999M
   } while (loopFlag);
   // next inputting and validating the width
   msg = "The width can not be less than zero.";        // invalid message
   do
   {
      cout << "Enter the rectangle's width: ";
      cin >> width;
      loopFlag = validateFloatInput(width, 1, 999999999.99, msg); // we put an upper limit here of 999M
   } while (loopFlag);
   return (length * width);
}
//**********************************************************************************
// Calculate the triangle
// calls validation for float input (base and height): takes float data and ensures it is correct.
// precondtion: called after valid user choice - no parms
// postcondition: returns the area of a geometric triangle
//**********************************************************************************
float calculateTriangle()
{
   float base = 0;	                                   // Base of a triangle
   float height = 0;	                                   // Height of a triangle
   bool loopFlag = true;                                // control for validation
   string msg("The base can not be less than zero.");   // invalid message
   // start with inputting and validating the base length entry
   do
   {
      cout << "Enter the length of the base: ";
      cin  >> base;
      loopFlag = validateFloatInput(base, 1, 999999999.99, msg); // we put an upper limit here of 999M
   } while (loopFlag);
   // next inputting and validating the height
   msg = "The height can not be less than zero.";        // invalid message
   do
   {
      cout << "Enter the triangle's height: ";
      cin  >> height;
      loopFlag = validateFloatInput(height, 1, 999999999.99, msg); // we put an upper limit here of 999M
   } while (loopFlag);
   return (base * height * 0.5f);
}
//**********************************************************************************
// Validate Float Input takes float data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
//**********************************************************************************
bool validateFloatInput(float userChoice, float range1, float range2, string message)
{
  bool goodOrNot = false;
  if ((cin.fail()) || ((userChoice < range1) || (userChoice > range2)))
  {
     cout << message << endl;
     goodOrNot = true;
  }
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return goodOrNot;
}
