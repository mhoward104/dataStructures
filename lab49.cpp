//Matthew Howard
//Lab49
//Cs 2315

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <d_timer.h>
#include <d_random.h>
#include <queue>

using namespace std;

template <typename T>
void pqSort(vector<T>& v)
{
	priority_queue<T> pq1;
	int size = v.size();
	int j = size - 1;
	
	for(int i = 0; i < size; i++)
	{
		pq1.push(v[i]);
	}
	
	while(!pq1.empty())
	{
		v[j] = pq1.top();
		pq1.pop();
		j--;
	}
}
