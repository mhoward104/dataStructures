#include <iostream>
#include <string>

using namespace std;

// template function prototypes
template<typename T>
void mySwap(T& first, T& second);
template<typename T>
void bubbleSort(T *array, int n);

#include "lab20.cpp"

template<typename T>
void printArray(const T *array, int count)
{
  if (count > 0)
  {
    cout << *array << " ";
    printArray(array + 1, count - 1);
  }
  else
    cout << endl;
}

int main()
{
  const int aCount = 5, bCount = 7, cCount = 5, dCount = 8;
  int a[aCount] = {5, 4, 3, 2, 1};
  double b[bCount] = {7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};
  char c[cCount] = {'H', 'E', 'L', 'L', 'O'};
  string d[dCount] = {"Cadillac", "Oldsmobile", "Chevrolet",
                      "Toyota", "Lexus", "Dodge", "GMC", "BMW"};

  cout << "Array a contains:" << endl;
  printArray(a, aCount);      // integer print template function
  bubbleSort(a, aCount);      // integer sort template function
  printArray(a, aCount);      // integer print template function

  cout << "Array b contains:" << endl;
  printArray(b, bCount);      // double print template function
  bubbleSort(b, bCount);      // double sort template function
  printArray(b, bCount);      // double print template function

  cout << "Array c contains:" << endl;
  printArray(c, cCount);      // character print template function
  bubbleSort(c, cCount);      // character sort template function
  printArray(c, cCount);      // character print template function

  cout << "Array d contains:" << endl;
  printArray(d, dCount);      // string print template function
  bubbleSort(d, dCount);      // string sort template function
  printArray(d, dCount);      // string print template function

  return 0;
}
