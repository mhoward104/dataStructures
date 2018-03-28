#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void sieveOfEratosthenes(vector<bool>& prime);
void printPrimes(const vector<bool>& prime, ostream& os);

int main()
{
  int n;
  vector<bool> prime;
   
  cin >> n;
   
  prime.resize(n+1, true);
  *prime.begin() = *(prime.begin() + 1) = false;

  sieveOfEratosthenes(prime);
  printPrimes(prime, cout);
   
  return EXIT_SUCCESS;
}
