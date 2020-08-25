// Program id: CSLab08.txt
// This is our template for CS Lab 08
// Efficiency practice program
// This document has three cases that represent portions of programs
// that need some help; they are inefficient.
// Study the code and rewrite or remove portions of the code
// to make it more efficient. Your goal should be to decrease the number
// of units (operations) by as much as possible.
// We will assume a fictional chip where everything takes one cycle.

// UNITS:

// Mathematics (1 cycle)
// Assignment (1 cycle)
// Logical operations such compare operations, etc… (1 cycle)
// Return (1 cycle)
//  Hint: simply update this code for your answer by removing
//  the operations (code) that you find to be inefficient (unnecessary)...
//
//
// CASE 1
// Assume all variables and constants were defined, etc.
// This should be an easy one (short and sweet too)
	double sqrtPiOvr2 = sqrt(PI/2);
    for (i = 0; i < max; i++)
      myArray[i] += sqrtPiOvr2;

//
//
// CASE 2
// A function that should make you wince

int findHighest(double s1,double s2,double s3,double s4,double s5)
 {
	// ~13 cycles
    double score;
	s1>=s2 ? score = s1 : score = s2;
	score>=s3 ? score = score : score = s3;
	score>=s4 ? score = score : score = s4;
	score>=s5 ? score = score : score = s5;
	return score;
 }

//
//
// CASE 3
// A naïve program (hint: is maybe k totally useless?)
//                        if so, all the instructions are too.
//                  look for similar useless code and counters...
do
{
   cout << "Would you like to:" << endl;
   cout << "1. Calculate the Area of a Circle 12 times" << endl;
   cout << "2. Calculate the Area of a Rectangle 10 times" << endl;
   cin >> selection;
   if (selection == 1){
      for (int i = 0; i < 12; i++){
        cout << "Enter another radius" << endl;
        cin >> radius;
        cout << "The area of your circle is " << 3.14159 * radius * radius << endl;
      }
	//Also not sure if this is really needed.
	//Pretty sure it displayed in the origional file. Not 100% needed though.
	cout << "The maximum was reached" << endl;
   }
   	else if (selection == 2){
      	for (int i = 0; i < 10; i++){
            cout << "Enter another length and width of your rectangle separated with a space" << endl;
            cin >> length >> width;
            cout << "The area of your rectangle is " << length * width << endl;
         }
      }
   }
   else if (selection > 2){
      cout << "This was not a valid selection" << endl;
   }
//Not sure if user == "Admin" is needed, Because loop is do-while, cannot check
//before loop starts.
} while ((selection >=1 && selection <= 2) && (user == "Admin");
