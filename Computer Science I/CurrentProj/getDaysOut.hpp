#ifndef GETDAYSOUT_HPP
#define GETDAYSOUT_HPP

// ********************************************************
// The getDaysOut function accepts the number of employees*
// in the company as an argument. It asks the user to     *
// enter the number of days each employee missed during   *
// the past year, validates it, and returns the total.	 *
// precondition: valid integer number of employees        *
// postcondition: returns integer total days missed       *
// ********************************************************
int getDaysOut(int &employees)
{
  int daysOut;	// To hold the days missed
  int total = 0;	// To hold the running total

  // Get the number of days missed by each employee.
  for (int count = 1; count <= employees; count++)
  {
    // Validate the number of days missed.
    bool loopFlag = true;
    do
    {
      std::cout << "How many days did employee "
			          << count << " miss? ";
      std::cin >> daysOut;
      if ((std::cin.fail()) || (daysOut < 0))
      {
        std::cout << "The days missed must be at least 0.\n";
        std::cin.clear();
        std::cin.ignore();
      }
      else
      {
        loopFlag = false;
      }
    } while (loopFlag);

    // Increment the total.
    total += daysOut;
  }

  // Return the total days missed for all employees.
  return total;
}

#endif
