//Matthew Howard
//CS 2315
//Lab 14
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


void printBinary(int num, ostream& os)
{		

	if(num < 0)
	{
		unsigned int x;
		x = num;
		
		printBinary(x / 2, os);
		os << x % 2;
	}
	else if(num > 0)
	{
		printBinary(num / 2, os);
		os << num % 2;
	}

}
