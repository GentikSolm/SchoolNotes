// This program demonstrates simple operations
// on a linked list.
#include <iostream>
#include "charList.cpp"

int main()
{
   // Define a NumberList object.
   CharList list;

   // Append some values to the list.
   list.appendNode('t');
   list.appendNode('s');
   list.appendNode('n');
   list.appendNode('m');
   list.appendNode('j');
   list.appendNode('f');
   list.appendNode('c');
   list.appendNode('a');
   // list.insertNode('y');
   // list.insertNode('0');
   // list.insertNode('9');
   // list.insertNode('o');
   // list.insertNode('p');
   // list.insertNode('@');
   // list.insertNode('Q');
   // list.deleteNode('t');
   list.displayList();
   return 0;
}
