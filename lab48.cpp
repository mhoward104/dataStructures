//Matthew Howard
//CS 2315
//Lab 48

#include <iostream>
#include <iomanip>
#include <d_random.h>
#include <queue>

using namespace std;

template<typename T>
void distribution(priority_queue<T>& pq, ostream& os)
{	
	
	//int count = 0; 
	priority_queue<T> pq1 = pq;
	
	while(!pq1.empty())
	{
		T top = pq1.top();
		int count = 1;
		pq1.pop();
		
		while(pq1.top() == top && !pq1.empty())
		{
			count++;
			pq1.pop();
		}
		os << top;
		os << '(' << count << ')' << endl;
	}
	
}
