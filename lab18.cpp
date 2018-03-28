//Matthew Howard
//CS 2315
//Lab 18

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void printBase32(int num, ostream& os)
{
		char base[] = {'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'};
	
		unsigned int x = num;
		int out = 0;
			
		if(x < 0)
	{
		x = num;
		
		printBase32(x / 32, os);
		out = x % 32;
		os << base[out];
		
		
	}
	else if(x > 0)
	{
		printBase32(x / 32, os);
		out = x % 32;
		os << base[out];

		
	}
}
