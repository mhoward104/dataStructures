//Matthew Howard
//CS 2315
//Lab 16
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


void printOctal(int num, ostream& os)
{		

	if(num < 0)
	{
		unsigned int x;
		x = num;
		
		printOctal(x / 8, os);
		os << x % 8;
	}
	else if(num > 0)
	{
		printOctal(num / 8, os);
		os << num % 8;
	}

}
