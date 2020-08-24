#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
const int SIZE = 40;
int main(){
    cout << setw(SIZE) << std::setfill('|') << std::right << "Hello world!\n";
    cout << setw(SIZE) << std::setfill('-') << std::left << "Goodbye world!";
}
