//Matthew Howard
//CS 2315
//Lab 43

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <vector>
#include <cmath>
#include <d_queue.h>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits)
{
	int count = 0;
	vector<miniQueue<int> > bucket(10, miniQueue<int>());
	int temp,temp2, mod = 10, div = 1;
	
	for(uint k = 0; k < numDigits; k++)
	{
		for(unsigned int i = 0; i < v.size(); i++)
		{
			temp2 = v[i] % mod;				
			temp = temp2 / div;
			bucket[temp].push(v[i]);
		}
	
		for(uint i = 0; i < 10; i++)
		{
			while(!bucket[i].empty())
			{
				v[count] = bucket[i].front();
				bucket[i].pop();
				count += 1;
			}
			
		}
		mod *= 10;
		div *= 10;
		count = 0;
		cout << v << endl;
	}
}
