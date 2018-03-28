#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <d_timer.h>
#include <d_random.h>

using namespace std;

template <typename T>
void insertionSort(vector<T>& v)
{
  typename vector<T>::iterator i, j, n = v.end(), start = v.begin();
  T target;

  // place v[i] into the sublist
  //   v[0] ... v[i-1], 1 <= i < n,
  // so it is in the correct position
  for (i = v.begin() + 1; i < n; i++)
  {
    // index j scans down list from v[i] looking for
    // correct position to locate target. assigns it to
    // v[j]
    j = i;
    target = *i;
    // locate insertion point by scanning downward as long
    // as target < v[j-1] and we have not encountered the
    // beginning of the list
    while (j > start && target < *(j-1))
    {
      // shift elements up list to make room for insertion
      *j = *(j-1);
      j--;
    }
    // the location is found; insert target
    *j = target;
  }
}

template <typename T>
void shellSort(vector<T>& v);

#include <lab33.cpp>

const int N = 10000;
enum TEST_TYPE {RANDOM, ASCENDING, DESCENDING};

int main()
{
  vector<int> v, w, x;
  randomNumber rnd;
  TEST_TYPE testType;
  int i;
  timer t;

  for (testType = RANDOM;
       testType <= DESCENDING;
       testType = static_cast<TEST_TYPE>(testType + 1))
  {
    if (!v.empty())
      v.clear();
    switch (testType)
    {
      case RANDOM:
        for (i = 0; i < N; ++i)
          v.push_back(rnd.random(1000000));
        cout << "Random Data:" << endl;
        break;
      case ASCENDING:
        for (i = 0; i < N; ++i)
          v.push_back(i);
        cout << "Ascending Data:" << endl;
        break;
      case DESCENDING:
        for (i = 0; i < N; ++i)
          v.push_back(N - i);
        cout << "Descending Data:" << endl;
        break;
    }
    x = v;
    sort(x.begin(), x.end());

    w = v;
    t.start();
    shellSort(w);
    t.stop();
    cout << "Shell Sort: " << t.time() << endl;
    if (x != w)
      cout << "Sort didn't work correctly" << endl;
    cout << endl;
  }
	
  return EXIT_SUCCESS;
}
