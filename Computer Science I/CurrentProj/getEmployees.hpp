#ifndef GETEMPLOYEES_HPP
#define GETEMPLOYEES_HPP

// ********************************************************
// The getEmployees function asks the user for the number *
// of employees in the company, validates, and returns    *
// the value.                                             *
// precondition: no input                                 *
// postcondition: returns integer number of employees     *
// ********************************************************
int getEmployees()
{
  int employees;	// To hold the number of employees.
  bool loopFlag = true;
  // Get the number of employees in the company.
  do
  {
    std::cout << "How many employees are there in the company? ";
    std::cin >> employees;
    // Validate the number of employees.
    if ((std::cin.fail()) || (employees < 1))
    {
       std::cout << "The number of employees must be at least 1.\n";
       std::cin.clear();
       std::cin.ignore();
    }
    else
    {
       loopFlag = false;
    }
  } while (loopFlag);

  // Return the number of employees in the company.
  return employees;
}

#endif
