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
    ListNode *nodePtr;
    newNode = new ListNode;
    nodePtr = head;
    newNode->value = letter;
    newNode->next = nullptr;
    //If the head is null, make into the head
    if(!head){
        head = newNode;
    }
    else{
        //While there is a next value, move forward
        while(nodePtr->next){
            nodePtr = nodePtr->next;
        }
        //finally, set last value to the new node.
        nodePtr->next = newNode;
    }
}

void CharList::deleteNode(char letter){
    ListNode *nodePtr, *nodePtr2;
    nodePtr = head;
    //If the head is not null, set nodePtr2 to next
    if(head) nodePtr2 = head->next;
    //If it is null, the list is empty
    else{
        std::cout << "List is empty!\n";
        return;
    }
    //If head is the value to delete:
    if(head->value == letter){
        //Delete head and set nodeptr2 as new head
        head = nodePtr2;
        delete nodePtr;
        return;
    }
    //While nodeptr2 is not null
    while(nodePtr2 != nullptr){
        //If nodeptr2 has the char value we want to delete
        if(nodePtr2->value == letter){
            //Set nodeptr to the next value after nodePtr2,
            nodePtr->next = nodePtr2->next;
            //and delete nodeptr2
            delete nodePtr2;
            return;
        }
        //If the last if statement didnt get hit, then move nodeptr and nodePtr2 forward
        nodePtr = nodePtr2;
        nodePtr2 = nodePtr2->next;
    }
    std::cout << "No char of that value found.\n";
}

void CharList::insertNode(char letter){
    ListNode *nodePtr;
    ListNode *newNode;
    newNode = new ListNode;
    nodePtr = head;
    //If there is no head, or the letter is bigger than the head:
    if(!head || letter >= head->value){
        //Insert new node as new head.
        newNode->next = head->next;
        newNode->value = head->value;
        head->next = newNode;
        head->value = letter;

    }
    else{
        //While there is a next
        while(nodePtr->next!=nullptr){
            //Move forward
            nodePtr = nodePtr->next;
            //If current is smaller than letter
            if(letter >= nodePtr->value){
                //copy origional into the newNode,
                //then set origional next to the new node, and change
                //the origional to new value
                newNode->value = nodePtr->value;
                newNode->next = nodePtr->next;
                nodePtr->next = newNode;
                nodePtr->value = letter;
                return;
            }
        }
        //If its the last letter, essentially append
        nodePtr->next = newNode;
        newNode->value = letter;
        newNode->next = nullptr;
    }
}

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
