/*
   COPYRIGHT (C) 2020 Joshua Brown (4323254) All rights reserved.
   CSII assignment E
   Author.  Joshua Brown
            jgb38@zips.uakron.edu
   Version. 1.01 02.24.2020
   Purpose: using linked lists
*/
#include "charList.hpp"
// Implementation file for the NumberList class

// Your coding required here
void CharList::appendNode(char letter){
    ListNode *newNode;
    newNode = new ListNode;
    ListNode *nodePtr;
    nodePtr = head;
    newNode->value = letter;
    newNode->next = nullptr;
    if(!head){
        head = newNode;
    }
    else{
        while(nodePtr->next){
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}
// insertNode(char);
// deleteNode(char);

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************

void CharList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->value << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}


// More of your coding required here


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************

CharList::~CharList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
