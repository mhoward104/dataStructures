#include <d_node.h>
#include <linked-list.h>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
uint linkedListSize(node<T> *front);

#include "lab50.cpp"

int main()
{
  int i;
  node<int> *front = NULL;

  cout << "Before insertions, list size = " << linkedListSize(front) << endl;

  while (cin >> i)
  {
    linkedListInsertUnordered(front, i);
    cout << "After inserting " << i << " in the list, the list consists"
         << " of " << linkedListSize(front) << " nodes" << endl;
  }

  cout << "Contents of list:" << endl;
  cout << front;

  linkedListDestroy(front);

  return EXIT_SUCCESS;
}
