//Matthew Howard
//CS 2315
//Lab 15
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


void printQuaternary(int num, ostream& os)
{		

	if(num < 0)
	{
		unsigned int x;
		x = num;
		
		printQuaternary(x / 4, os);
		os << x % 4;
	}
	else if(num > 0)
	{
		printQuaternary(num / 4, os);
		os << num % 4;
	}

}
