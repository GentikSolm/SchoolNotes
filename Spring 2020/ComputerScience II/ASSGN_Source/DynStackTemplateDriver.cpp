// AssgnG driver file
// Dr. Dianne Foreback

#include <iostream>
#include "DynStackTemplate.hpp"


int main()
{
    CS2::DynStack<int> even;

    if (even.isEmpty())
        std::cout << "My even stack is empty.\n\n";
    else
        std::cout << "My even stack is NOT empty.\n\n";

    std::cout << "I am pushing the following elements onto my even stack.\n";
    for (int i = 2; i <= 12; i+=2)
    {
        even.push(i);
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;

    int x;
    std::cout << "Here are the elements I am popping from my even stack.\n";
    std::cout << "Notice, the last in element is the first out element (LIFO).\n";
    while (!even.isEmpty())
    {
        even.pop(x);
        std::cout << x << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "After popping all elements from my even stack, it should be empty.\n";
    if (even.isEmpty())
        std::cout << "My even stack is empty.\n";
    else
        std::cout << "My even stack is NOT empty.\n";


    std::cout << "\n**************************************\n";
    std::cout << "  Code to test stack of type int \n";
    std::cout << "***************************************\n";

    CS2::DynStack<int> ten;
    for (int i = 1; i <11; ++i)
        ten.push(i);

    std::cout << "add: " << ten.add() << std::endl;
    std::cout << "sub: " << ten.sub() << std::endl;
    std::cout << "mult: " << ten.mult() << std::endl;
    std::cout << "pushing 10 onto the stack\n";
    ten.push(10);
    std::cout << "div: " << ten.div() << std::endl;
    std::cout << "addAll: " << ten.addAll() << std::endl;

    ten.push(2);
    ten.push(3);
    std::cout << "multAll: " << ten.multAll() << std::endl;


    std::cout << "\n**************************************\n";
    std::cout << "  Code to test stack of type double \n";
    std::cout << "***************************************\n";

    CS2::DynStack<double> tenOfDoubles;
    for (int i = 1; i <11; ++i)
        tenOfDoubles.push(i + 0.5);

    std::cout << "add: " << tenOfDoubles.add() << std::endl;
    std::cout << "sub: " << tenOfDoubles.sub() << std::endl;
    std::cout << "mult: " << tenOfDoubles.mult() << std::endl;
    std::cout << "pushing 10.0 onto the stack\n";
    tenOfDoubles.push(10.0);
    std::cout << "div: " << tenOfDoubles.div() << std::endl;
    std::cout << "addAll: " << tenOfDoubles.addAll() << std::endl;

    tenOfDoubles.push(2.5);
    tenOfDoubles.push(3.5);
    std::cout << "multAll: " << tenOfDoubles.multAll() << std::endl;



}
