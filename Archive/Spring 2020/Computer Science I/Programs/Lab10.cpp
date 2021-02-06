// Program id: CSLab10.cpp
// This is our template for CS Lab 10
// ERROR HANDLING PRACTICE PROGRAM
//  This program is used for the University of Akron, Department of Computer Science Laboratories
//
// This program reads a file that contains salary amounts, applies a cost of living adjustment (RATE_INCREASE),
// and writes the updated amounts to a new salary file. Simple program and we will upgrade it to handle errors
// goal: put error handling into each function and write our own error handler function as well
//
// First -
// Go to the end of the program to find the errorHandler function. This function will process all errors
// if the status is one then the function should resume processing after displaying the message.
// if the status is two then the function should interrupt the program.
// Considerations for interrupting the program include closing the files properly, etc... look at the logic and
// think how to return back to main and let the program end there. Do not use EXIT.
//
// Second -
// Find the PLACE ERROR HANDLING HERE comments in each function and write the interface to the error handler.
// Format the data in error, the message, and the status code. You can pass these as literals in your function call.
// status code one - any invalid amounts (amounts of zero included) or mild file errors
//                   are reported exceptions. They are ignored (not written) as new output
// status code two - any severe file operation errors, such as opening, or severe conditions
//                   while reading and writing, should halt the program
// Notice the use of stringstream (we will cover this in class)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cerr;

const float RATE_INCREASE = .025;
// Function prototypes
void adjustSalary(ifstream &, ofstream &);
bool readFile(ifstream &);
bool writeFile(ofstream &, float &);
bool isValid(const string &);
void errorHandler(string, int, string);      // we can't pass by reference b/c we're using literals

int main()
{
  ifstream salaryFile;                       // create file input object
  ofstream newSalaryFile;                    // create file output object
  // notice we open the files and connect them to the names here, in the caller (main), as recommended
  salaryFile.open("salaries.txt");           // open the file and make the function's parameter an ifstream
  newSalaryFile.open("newsalaries.txt");     // open the file and make the function's parameter an ofstream
  try{
	  if(readFile(salaryFile))
	  {
	    adjustSalary(salaryFile, newSalaryFile); // adjust salary will process the entire salary file
	  }
	  else
	  {
	    errorHandler("salaries.txt", 2, "File Failed to open");
	  }
}
	catch(int num){}
	salaryFile.close();
	newSalaryFile.close();
	return 0;
}
//Precondition: valid open file with salary amount
//Postcondition: cost of living adjusted amount
//will be written to new salaries file
void adjustSalary(ifstream &salaryFile, ofstream &newSalaryFile)
{
  int validCount = 0;
  string stringAmount = " ";
  // notice that we are reading the file into a string, and not a float. You could read into a float, our variable amount.
  // the reason why we did this is because we can only see the invalid characters if it is a string, and we want them for
  // our error handling output (so the user knows what exactly was bad). ??? Ask about any of this anytime in class.
  while (!(salaryFile >> stringAmount).eof())        // avoids the isolated eof test from failure (as explained in our lectures)
  {
    float amount = 0.00;
    stringstream stringStreamAmount(stringAmount);  // The stringstream class: uses stream insertion operator
    stringStreamAmount >> amount;                   // stream string stream into the amount and convert the streamed string into a float

    if (!isValid(stringAmount))                     // is there an invalid value (non-numeric data) (status one)
    {
	    errorHandler(stringAmount, 1, "Invaild Number");
    }
    else if (salaryFile.fail() && !salaryFile.eof())
    {
      // if fail bit was triggered here it may be more severe than invalid data
      // so we check the bad bit. If on, it's not a data issue and the stream should be considered unusable.
      if (salaryFile.bad())
      {
        errorHandler("salaries.txt", 2, "File is currupt");
		return;
      }
      else
      {
        errorHandler("salaries.txt", 1, "Invailid Data");
        // handle the error, and need to clear the buffer and reset the flags (status ONE)
        salaryFile.clear();
        salaryFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
    else if (amount <= 0)                          // invalid amount error of zero or less (status ONE)
    {
      errorHandler(stringAmount, 1, "Invalid Number, too small");
    }
    else if (amount > 999999.99)                   // invalid amount error over a million (status ONE)
    {
     	errorHandler(stringAmount, 1, "Invalid Number, too big");
    }
    else                                           // trailing else ... everything was valid.
    {
      amount = amount + (amount * RATE_INCREASE);
      if (writeFile(newSalaryFile, amount))
      {
        cout << "New rate: " << std::right << std::setw(15) << std::fixed << std::setprecision(2) << amount << endl;
      }
      else  // write error to file (status TWO)
      {
         errorHandler("salaries.txt", 2, "Output to file failed");
		 return;
      }
      validCount++;
    }
  }
  cout << "The number of valid salary adjustments made was: " << validCount << endl;
}
//***************************************************
// the read file function                           *
//***************************************************
//Precondition: opened file object is passed into this function
//Postcondition: The status of the file's disposition will be returned
bool readFile(ifstream &salaryFile)
{
  if (!salaryFile.is_open())
  {
    return false;
  }
  return true;
}
//***************************************************
// the write file function                           *
//***************************************************
//Precondition: opened file object is passed into this function and written to
//Postcondition: The status of the file's disposition will be returned
bool writeFile(ofstream &newSalaryFile, float &newAmt)
{
  newSalaryFile << newAmt << endl;  // writing to the output file
  if (!newSalaryFile.is_open())
  {
    return false;
  }
  return true;
}
//***************************************************
// the is valid function                           *
//***************************************************
//Precondition: a float or double is passed and converted to a string value
//Postcondition: The status of the float or double will be returned
// as bool (true or false), is it a numeric item or not
// this reads the string as an array and looks at each character, one by one
bool isValid(const string &str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if(!isdigit(str[i]) && str[i] != '.')
     {
       return false;
     }
   }
   return true;
}
//***************************************************
// the error handler function                       *
//***************************************************
//Precondition: an error message and an error status code
//Postcondition: The message will display to standard error
// the status code will determine if the program ends or returns
// The parameters are:
// 1) dataInfo is the data that caused the problem
//       - for amounts, use the stringAmount variable
//       - for files, use the name of the file
// 2) status is 1 or 2
// 3) message is a formatted, informative message
void errorHandler(string dataInfo, int status, string message)
{
   if(status == 1){
	   cerr << message << " Caused by " << dataInfo << endl;
   }
   else if(status == 2){
	   cerr << message << " Caused by " << dataInfo << endl;
	   cerr << "Fatal!";
	   throw 1;
   }
}
