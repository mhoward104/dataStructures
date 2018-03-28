#include <d_node.h>
#include <linked-list.h>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
void linkedListReverse(node<T>*& front);

#include "lab52.cpp"

int main()
{
  int i;
  node<int> *front = NULL;

  cout << "Enter a collection of integers.  Use ^d to quit" << endl;
  while (cin >> i)
    linkedListInsertOrdered(front, i);

  cout << "Original Order:" << endl;
  operator<<(cout, front);
  linkedListReverse(front);
  cout << "Reversed Order:" << endl;
  operator<<(cout, front);

  linkedListDestroy(front);

  return EXIT_SUCCESS;
}
