#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <d_timer.h>
#include <d_random.h>

using namespace std;

template <typename T>
void exchangeSort(vector<T>& v);

#include <lab32.cpp>

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
    exchangeSort(w);
    t.stop();
    cout << "Exchange Sort: " << t.time() << endl;
    if (x != w)
      cout << "Sort didn't work correctly" << endl;
    cout << endl;
  }
  return EXIT_SUCCESS;
}
