// Simple program that inputs a time and returns the distance
// and object would fall in that time.
#include <iostream>
using namespace std;
int main()
{
  double time;
  cout << "ASSIGN1-B\tPlease enter a number for freefall\n-> ";
  cin >> time;
  cout << "The object fell " << ((time * time) *32)/2 << " feet!";
  return 0;
}
