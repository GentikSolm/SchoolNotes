/*
  COPYRIGHT (C) 2019 Joshua Brown (jgb38) All rights reserved.
  ASSGNG
  Auther. Josh Brown
		  jgb38@zips.uakron.edu
  Version 1.01 3.04.2020
  Purpose: Demonstrate templates
*/
#ifndef DYNSTACK_HPP_INCLUDED
#define DYNSTACK_HPP_INCLUDED

namespace CS2{

template <class T>
class DynStack {
private:
   // Structure for stack nodes
   struct StackNode
   {
      T value;        // Value in the node
      StackNode *next;  // Pointer to the next node
   };
   StackNode *top;      // Pointer to the stack top

public:
    DynStack()
      {  top = nullptr; }

    ~DynStack();

    void push(T);
    void pop(T &);
    bool isEmpty();
    T add();
    T sub();
    T mult();
    T div();
    T addAll();
    T multAll();

};
template <class T>
DynStack<T>::~DynStack()
{
   StackNode *nodePtr = nullptr, *nextNode = nullptr;

   // Position nodePtr at the top of the stack.
   nodePtr = top;

   // Traverse the list deleting each node.
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}
template <class T>
void DynStack<T>::push(T num)
{
   StackNode *newNode = nullptr; // Poer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   newNode->value = num;

   // If there are no nodes in the list
   // make newNode the first node.
   if (isEmpty())
   {
      top = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert NewNode before top.
   {
      newNode->next = top;
      top = newNode;
   }
}
template <class T>
void DynStack<T>::pop(T &num)
{
   StackNode *temp = nullptr; // Temporary poer

   if (isEmpty())
   {
      std::cout << "The stack is empty.\n";
   }
   else  // pop value off top of stack
   {
      num = top->value;
      temp = top->next;
      delete top;
      top = temp;
   }
}
template <class T>
bool DynStack<T>::isEmpty()
{
   bool status;

   if (!top)
      status = true;
   else
      status = false;
   return status;
}
template <class T>
T DynStack<T>::add(){
    T num1, num2, total;
    pop(num1);
    pop(num2);
    //Sets num1 and num2 to the most recent poped items
    // Then total is set to their total,
    total = num1+num2;
    //Then pushed
    push(total);
    //and returned
    return total;
}
template <class T>
T DynStack<T>::sub(){
    T num1, num2, total;
    pop(num1);
    pop(num2);
    //Sets num1 and num2 to the most recent poped items
    // Then total is set to their subtraction,
    total = num2-num1;
    //Then pushed
    push(total);
    //and returned
    return total;
}
template <class T>
T DynStack<T>::mult(){
    T num1, num2, total;
    pop(num1);
    pop(num2);
    //Sets num1 and num2 to the most recent poped items
    // Then total is set to their multiplication,
    total = num1*num2;
    //Then pushed
    push(total);
    //and returned
    return total;
}
template <class T>
T DynStack<T>::div(){
    T num1, num2, total;
    pop(num1);
    pop(num2);
    //Sets num1 and num2 to the most recent poped items
    // verifies that it is not dividing by zero
    while(num1 == 0){
        num1 = num2;
        pop(num2);
    }
    //sets total to their divisior
    total = num2/num1;
    //pushes total
    push(total);
    //returns total
    return total;
}
template <class T>
T DynStack<T>::addAll(){
    T num1, total = 0;
    //While stack is not empty, pops items
    while(!isEmpty()){
        pop(num1);
        //adds each one to the total
        total +=num1;
    }
    //push total
    push(total);
    //returns total
    return total;
}
template <class T>
T DynStack<T>::multAll(){
    T num1, total = 1;
    //While stack is not empty, pops items
    while(!isEmpty()){
        pop(num1);
        //multiplies each one to the last
        total *=num1;
    }
    //push total
    push(total);
    //return total
    return total;
}
} // namespace CS2

#endif // DYNSTACK_HPP_INCLUDED
