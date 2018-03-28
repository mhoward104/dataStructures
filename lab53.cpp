//MAtthew Howard
//CS 2315
//Lab 53

#include <d_node.h>
#include <linked-list.h>
#include <lab53.h>
#include <d_except.h>

using namespace std;

  // Constructor.  Create an empty stack.
  template <typename T>
  miniStack<T>::miniStack()
  {
		stackListPtr = new node<T>;
		stackSize = 0;
  }
  
  // Push (insert) item onto the stack.
  // Postcondition:  the stack has a new topmost element and the stack
  // size increases by 1
  template <typename T>
  void miniStack<T>::push(const T& item)
  {
		node<T> *endNode;
		node<T> *temp = stackListPtr;
		endNode = new node<T>;
		endNode->nodeValue = item;
		endNode->next = NULL;
		
		stackSize += 1;
		
		if(stackListPtr == NULL)
		{
			temp = endNode;
			//stackListPtr->nodeValue = item;
		}
		else
		{
			while(temp != NULL)
			{
				if(temp->next == NULL)
				{
					temp->next = endNode;
					break;
				}
				temp = temp->next;
			}
		}
  }
  
  // Remove the item from the top of the stack.
  // Precondition:  the stack is not empty.  If the stack is empty,
  // the function throws the underflowError exception.
  template <typename T>
  void miniStack<T>::pop()
  {
	  node<T> *temp = stackListPtr;
	  node<T> *prev = stackListPtr;
	  
	if(stackSize == 0)
	{
		throw underflowError("list is empty");
	}
	else
	{
		stackSize -= 1;
		while(temp != NULL)
		{
			if(temp->next == NULL)
			{
				prev->next = NULL;
			}
			prev = temp;
			temp = temp->next;
		
		}
	}

	
	
 }
  
  // Return a reference to the element on the top of the stack.
  // Precondition:  the stack is not empty.  If the stack is empty,
  // the function throws the underflowError exception.
  template <typename T>
  T& miniStack<T>::top()
  {
	node<T> *temp;
	temp = new node<T>;
	temp = stackListPtr;
	
	if(stackSize == 0)
	{
		throw underflowError("list is empty");
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->next == NULL)
			{
				return temp->nodeValue;
				break;
			}
			temp = temp->next;
		}
	}
		
    
	
	return temp->nodeValue;

  }
  
  // Constant version of top()
  template <typename T>
  const T& miniStack<T>::top() const
  {
	  
	node<T> *temp;
	temp = new node<T>;
	temp = stackListPtr;
	
	if(stackSize == 0)
	{
		throw underflowError("list is empty");
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->next == NULL)
			{
				return temp->nodeValue;
				break;
			}
			temp = temp->next;
		}
	}
		
    
	
	return temp->nodeValue;
  }
  
  // Determine whether the stack is empty.
  template <typename T>
  bool miniStack<T>::empty() const
  {
	  if(stackSize == 0)
	  {
		  return true;
	  }
	  return false;
  }
  
  // Return the number of elements in the stack.
  template <typename T>
  int miniStack<T>::size() const
  {
	return stackSize;
  }
