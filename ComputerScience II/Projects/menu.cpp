#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
void showMenu();
int main(){
    showMenu();
}

void showMenu(){
    cout << ' ' << std::setw(60) << std::setfill('_') << ' ' << endl;
    cout << '|' << std::setw(60) << std::setfill('-') << '|' << endl;
    cout << '|' << std::setw(41) << std::setfill(' ') << "Josh Brown Incorporated" << setw(19) << '|' << endl;
    cout << '|' << std::setw(39) << std::setfill(' ') << "Computer Lab System" << setw(21) << '|' << endl;
    cout << '|' << std::setw(60) << std::setfill('_') << '|' << endl;
    cout << '|' << std::setw(35) << std::setfill(' ') << "MAIN MENU" << setw(25) << '|' << endl;
    cout << '|' << std::setw(40) << std::setfill(' ') << "1) Simulate login" << setw(20) << '|' << endl;
    cout << '|' << std::setw(41) << std::setfill(' ') << "2) Simulate logoff" << setw(19) << '|' << endl;
    cout << '|' << std::setw(32) << std::setfill(' ') << "3) Search" << setw(28) << '|' << endl;
    cout << '|' << std::setw(38) << std::setfill(' ') << "4) Disply a lab" << setw(22) << '|' << endl;
    cout << '|' << std::setw(30) << std::setfill(' ') << "5) Quit" << setw(30) << '|' << endl;
    cout << '|' << std::setw(60) << std::setfill('_') << '|' << endl;
}
