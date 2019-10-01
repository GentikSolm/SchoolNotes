/* Program id: CSLab04.cpp
 This is our template for CS Lab 04
 DECOMPOSITION PRACTICE PROGRAM
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
 If the user enters 4, the program should end.

 */

// Complete your decomposition outline first (right below here)
// Next build your functions for each area to calculate
// Use the switch statements to make your calls to those functions

/*

Functional decomposition:

Level 1:

1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Get various Area entries
5. Display

Level 2:

1. Calculate the Area of a Circle
	a) Get radius
	b) Validate radius
	c) Calculate Area using Pi(R^2)
	d) Return value
2. Calculate the Area of a Rectangle
	a) Get legnth and width
	b) Validate side measurements
	c) Calculate Area using legnth * width
	d) Return value
3. Calculate the Area of a Triangle
	a) Get base and height
	b) Validate measurements
	c) Calculate Area using .5 * base * height
	d) Return value
4. Get various Area entries
	a) Ask user for choice
	b) Make sure choice is in range & is a number
5. Display
	a) Return area of choice
	b) Continue going untill user asks to exit


*/
#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int geoMenu();
bool validateInput(int, int, int, string);
bool validateFloatInput(float, float, float, string message);
float calculateCircle();
float calculateRectangle();
float calculateTriangle();

// Global constants for all choices
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
     cout << endl << std::fixed << "The area from your choice is: " << area << endl;  // setprecision if you wish to
	 cout << "Press any key to continue\n";
	 cin.get();
   }
}

// Geo Menu is the menu for our program
// precondtion: call when geometric calculator menu is to be display
// postcondition: returns an int that is the user choice
// FYI later, when we learn about char functions, we would use a char for choice
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

// Validate Input takes integer data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
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

// Calculate the circle takes float data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
float calculateCircle()
{
  float radius = 0;                                    // radius of the circle
  bool loopFlag = true;                                // control for validation
  string msg("The radius was invalid.");               // invalid message
  do
  {
    cout << "Enter the circle's radius: ";
    cin >> radius;
    loopFlag = validateFloatInput(radius, 0, 999999999.99, msg); // we put an upper limit here of 999M
  } while (loopFlag);
  return (PI * radius * radius);
}

// Validate Float Input takes float data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
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



// Calculate the rectangle takes float data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
float calculateRectangle()
{
  float legnth = 0, width = 0;                  	   //  legnth and width of the rectangle
  bool loopFlag = true;                         	   // control for validation
  string msgL("The Legnth was invalid.");       	   // invalid message for legnth
  string msgW("The width was invalid.");   			   // invalid message for legnth
  do
  {
    cout << "Enter the Rectangle's Legnth: ";
    cin >> legnth;
    loopFlag = validateFloatInput(legnth, 0, 999999999.99, msgL); // we put an upper limit here of 999M
  } while (loopFlag);
  do
  {
	cout << "Enter the Rectangle's Width: ";
	cin >> width;
	loopFlag = validateFloatInput(width, 0, 999999999.99, msgW); // we put an upper limit here of 999M
  } while (loopFlag);
  return (legnth * width);
}


// Calculate the triangle takes float data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
float calculateTriangle()
{
  float base = 0, height = 0;                         // Base and height of the triangle
  bool loopFlag = true;                               // control for validation
  string msgB("The Base was invalid.");               // invalid message
  string msgH("The Height was invlaid");
  do
  {
    cout << "Enter the triangle's base: ";
    cin >> base;
    loopFlag = validateFloatInput(base, 0, 999999999.99, msgB); // we put an upper limit here of 999M
  } while (loopFlag);
  do
  {
    cout << "Enter the triangle's height: ";
    cin >> height;
    loopFlag = validateFloatInput(height, 0, 999999999.99, msgH); // we put an upper limit here of 999M
  } while (loopFlag);
  return (.5 * base * height);
}
