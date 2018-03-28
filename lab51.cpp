//MAtthew Howard
//CS 2315
//Lab 51

#include <d_except.h>
#include <d_node.h>
#include <linked-list.h>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
node<T> *linkedListMaxElement(node<T> *front)
{
	
	node<T> *largest;
	node<T> *copy;
	copy = front;
	largest = front;
	
	if(copy == NULL)
	{
		throw underflowError("linkedListMaxElement: list is empty");
	}
	
	while(front != NULL)
	{
		if(largest->nodeValue < front->nodeValue)
		{
			largest = front;
		}
		front = front->next;
	}
	
	return largest;
}
