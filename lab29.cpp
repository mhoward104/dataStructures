//Matthew Howard
//Lab 29
//Cs 2315

//built in alg. for reverse and swap
#include <lab29.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

template<typename T>
bool nextPermutation(vector<T>& v)
{
	
	bool flag = false;
	int k = -1;
	//swap(v[v.size() - 1], v[v.size() - 2]);
	
	vector<T> check(v);
	sort(check.begin(), check.end());
	reverse(check.begin(), check.end());
	
	for(unsigned int i = v.size() - 1; i > 0; i--)
	{
		if(v[i - 1] < v[i])
		{
			k = i - 1;
			flag = true;
			
			break;
		}
		
	}
	
	for(unsigned int j = v.size() - 1; j > 0; j--)
	{
		if(v[j] > v[k])
		{
			swap(v[j], v[k]);
			break;
			
		}
		
	}
	
	reverse(v.begin() + k + 1, v.end());
	
	if(flag == false)
	{
		sort(v.begin(), v.end());
		return false;
	}
	else
	{
		return true;
	}
	

}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		os << v[i];
	}
return os;
}
