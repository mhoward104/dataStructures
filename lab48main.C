#include <iostream>
#include <iomanip>
#include <d_random.h>
#include <queue>

using namespace std;

template<typename T>
void distribution(const priority_queue<T>& pq, ostream& os);

#include "lab48.cpp"

int main()
{
  priority_queue<int> pq1;
  priority_queue<char> pq2;
  priority_queue<double> pq3;
  randomNumber rnd;
  int i;

  cout << "Distribution of PQ1 with size() = " << pq1.size() << endl;
  distribution(pq1, cout);

  for (i = 0; i < 5; ++i)
  {
    pq1.push(rnd.random(5));
    cout << endl << "Distribution of PQ1 with size() = " << pq1.size()
         << endl;
    distribution(pq1, cout);
  }

  for (i = 0; i < 10000; ++i)
  {
    pq1.push(rnd.random(5));
    pq2.push(char(rnd.random(26) + 65));
    pq3.push(rnd.random(8) * 0.125);
  }

  cout << endl << "Distribution of PQ1" << endl;
  distribution(pq1, cout);
  cout << endl << "Distribution of PQ2" << endl;
  distribution(pq2, cout);
  cout << fixed << showpoint << setprecision(3);
  cout << endl << "Distribution of PQ3" << endl;
  distribution(pq3, cout);

  return 0;
}
