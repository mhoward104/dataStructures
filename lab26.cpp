//Matthew Howard
//Cs 2315
//Lab 26

#include <vector>
#include <cmath>
#include <math.h>

//include cmath for "round" function
using namespace std;

int meanUsingIndexing(const vector<int>& v)
{
	vector<int>::size_type i;
	double sum = 0;
	
	for(i = 0; i < v.size(); ++i)
	{
		sum = sum + v[i];
	}
	sum =  round(sum / v.size());
	
	return (int) sum;
}
int meanUsingIterators(const vector<int>& v)
{
	vector<int>::const_iterator itr;
	double sum = 0;
	
	for(itr = v.begin(); itr < v.end(); ++itr)
	{
		sum += *itr;
	}
	sum = round(sum / v.size());
	
	return (int)(sum);
}
