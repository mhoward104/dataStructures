//Matthew Howard
//Cs 2315
//Lab 36

#include <iostream>
#include <d_matrix.h>
#include <lab36.h>
#include <string>
#include <iomanip>

using namespace std;

void Spiral::initialize(int n)
{
	data.resize(n,n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			data[i][j] = 0;
		}
	}
}

void  Spiral::build()
{
	int k = 0;
	int m = data.rows();
	int l = 0;
	int n = data.rows();
	int i, counter = 1;
	
	while(k < m && l < n)
	{
		for(i = l; i < n; ++i)
		{
			data[k][i] = counter;
			counter += 1;
		}
		k++;
		for( i = k; i < m; i++)
		{
			data[i][n-1] = counter;
			counter += 1;
		}
		n--;
		if(k < m)
		{
			for(i = n-1; i >= l; --i)
			{
				data[m-1][i] = counter;
				counter += 1;
			}
			m--;
		}
		if(l < n)
		{
			for(i = m-1; i >= k; --i)
			{
				data[i][l] = counter;
				counter += 1;
				
			}
			l++;
		}
	}
}

ostream&  operator<<(ostream& out, const Spiral& spiral)
{
	int size = spiral.data.rows();
	int l = 1;
	
	for(int i = 10; i <= size * size; i *= 10)
	{
		l += 1;
	}
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			out << right << setw(l) << spiral.data[i][j] << " ";
		}
		out << endl;
	}
	
	return out;
}
