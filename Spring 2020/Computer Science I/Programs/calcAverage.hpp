#ifndef CALCAVERAGE_HPP
#define CALCAVERAGE_HPP

// ********************************************************
// The calcAverage function takes the number of employees *
// in the company and the total number of days absent for *
// all employees during the year as arguments.            *
// precondition: valid integers days absent and employees *
// postcondition: returns average number as double        *
// ********************************************************
double calcAverage(int &employees, int &daysOut)
{
  // Return the average number of days missed.
  return (static_cast<double>(daysOut) / employees);
}


#endif
