//Matthew Howard
//CS 2315
//Lab 38

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <vector>
#include <cmath>

using namespace std;


ostream& operator<<(ostream& os, const vector<uint>& v);


void bucketSort(vector<uint>& v, uint numDigits)
{
	int count = 0;
	vector<vector<int> > bucket(10, vector<int>());
	int temp,temp2, mod = 10, div = 1;
	
	for(uint k = 0; k < numDigits; k++)
	{
		for(unsigned int i = 0; i < v.size(); i++)
		{
			
			temp2 = v[i] % mod;				
			temp = temp2 / div;
			bucket[temp].push_back(v[i]);
		}
	
		for(uint i = 0; i < 10; i++)
		{
			for(uint j  = 0; j < bucket[i].size(); j++)
			{
				v[count] = bucket[i][j];
				count += 1;		
			}
			bucket[i].clear();
		}
		mod *= 10;
		div *= 10;
		count = 0;
		cout << v << endl;
	}
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
}
