//Matthew Howard
//CS 2315
//Lab 17

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void printHexadecimal(int num, ostream& os)
{
	
	
		unsigned int x = num;
		if(x < 0)
	{
		x = num;
		
		printHexadecimal(x / 16, os);
		os << hex << x % 16 << dec;
	}
	else if(x > 0)
	{
		printHexadecimal(x / 16, os);
		os << hex << x % 16 << dec;
	}
}
