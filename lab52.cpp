//Matthew Howard
//Cs 2315
//Lab 52

#include <d_node.h>
#include <linked-list.h>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
void linkedListReverse(node<T>*& front)
{
		
	node<T> *current = front;
	node<T> *prev = NULL;
	node<T> *next;
	
    while (current != NULL)
    {
       next = current->next;
	   current->next = prev;
	   prev = current;
	   current = next;
    }
	
	front = prev;
    

}
