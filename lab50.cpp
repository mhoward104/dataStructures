//Matthew Howard
//CS 2315
//Lab 50

#include <d_node.h>
#include <linked-list.h>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
uint linkedListSize(node<T> *front)
{
	uint count = 0;
	node<T> *curr;

	
	while(front != NULL)
	{
		count++;
		curr = front;
	    front = front->next;

	}
	
	return count;
}
