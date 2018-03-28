#ifndef LAB53_H
#define LAB53_H

#include <d_node.h>
#include <linked-list.h>

using namespace std;

template <typename T>
class miniStack
{
 public:
  // Constructor.  Create an empty stack.
  miniStack();

  // Push (insert) item onto the stack.
  // Postcondition:  the stack has a new topmost element and the stack
  // size increases by 1
  void push(const T& item);

  // Remove the item from the top of the stack.
  // Precondition:  the stack is not empty.  If the stack is empty,
  // the function throws the underflowError exception.
  void pop();
     
  // Return a reference to the element on the top of the stack.
  // Precondition:  the stack is not empty.  If the stack is empty,
  // the function throws the underflowError exception.
  T& top();
  // Constant version of top()
  const T& top() const;

  // Determine whether the stack is empty.
  bool empty() const;

  // Return the number of elements in the stack.
  int size() const;

 private:
  node<T> *stackListPtr;    // a singly-linked list maintains the stack items
  uint stackSize;           // # of elements on the stack
};

#include "lab53.cpp"

#endif
