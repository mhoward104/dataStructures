//Matthew Howard
//Lab 27
//CS 2315

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;
template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v)
{
	pair<T, int> x;
	x.first = v[0];
	x.second = 0;

	T check;

	int countOne = 0;

	
	for(unsigned int i = 0; i < v.size(); i++)
	{
		check = v[i];
		
		for(unsigned int j = 0; j< v.size(); j++)
		{
			if(check == v[j])
			{
				countOne += 1;
			}
		}
		if(countOne > x.second)
		{
			x.first = check;
			x.second = countOne;
			
		}
		countOne = 0;
	}
	
		return x;
}

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v)
{
	pair<T, int> x;
	x.first = v[0];
	x.second = 0;
	T check;
	int countOne = 0;
	
	
typename vector<T>::const_iterator itr;
typename vector<T>::const_iterator itr2;
	
	
	for(itr = v.begin(); itr < v.end(); ++itr)
	{
		check = *itr;
		
		for(itr2 = v.begin(); itr2 < v.end(); ++itr2)
		{
			if(check == *itr2)
			{
				countOne += 1;
			}
		}
		if(countOne > x.second)
		{
			x.first = check;
			x.second = countOne;
			
		}
		countOne = 0;
	}
	
		return x;
}
