//Matthew Howard
//Cs 2315
//Lab 30

#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;


void sieveOfEratosthenes(vector<bool>& prime)
{
	unsigned int size = prime.size() -1;
	for (unsigned int p = 2; p * p <= size; ++p)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (unsigned int i = p * p; i <= size; i += p)
					prime[i] = false;
        }
    }
 
}
void printPrimes(const vector<bool>& prime, ostream& os)
{
	unsigned int size = prime.size() -1;
	for (unsigned int p = 2; p <= size; p++)
       if (prime[p])
          os << p << " ";
}
