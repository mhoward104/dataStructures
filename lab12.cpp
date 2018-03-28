//Matthew Howard
//Cs 2315
//Lab 12

#include <iostream>
#include <stdlib.h>

using namespace std;


void insertComma(unsigned long num, ostream& os)
{
	int i;
	if(num < 1000)
	{
		os << num;
	}
	else
	{
		i = num % 1000;
		num -= i;
		insertComma(num / 1000, os);
		if(i == 0)
		{
			os << "," << i << i << i;
		}
		else
		{
		os << "," << i; 
		}
	}
}
