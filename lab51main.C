#include <d_except.h>
#include <d_node.h>
#include <linked-list.h>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
node<T> *linkedListMaxElement(node<T> *front);

#include "lab51.cpp"

int main()
{
  int i;
  node<int> *front = NULL, *largest;

  while (cin >> i)
  {
    linkedListInsertUnordered(front, i);
  }

  cout << "Contents of list:" << endl;
  cout << front;

  try
  {
    largest = linkedListMaxElement(front);
    cout << "Largest element = " << largest->nodeValue << endl;
  }
  catch (underflowError listException)
  {
    cout << listException.what() << endl;
    exit(EXIT_FAILURE);
  }

  linkedListDestroy(front);

  return EXIT_SUCCESS;
}
