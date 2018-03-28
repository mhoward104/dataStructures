//Matthew Howard
//Cs 2315
//Lab 40

#include <iostream>
#include <cstdlib>
#include <string>
#include <d_stack.h>
using namespace std;

bool isNestedCorrectly(string s)
{
	bool check = false;
	miniStack<char> left;
	
	for(uint i = 0; i < s.length(); i++)
	{
		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			left.push(s[i]);
		}
		else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if(left.empty())
			{
				check = false;
				break;
			}
			else if((s[i] == ')' && left.top() == '(') || (s[i] == ']' && left.top() == '[') || (s[i] == '}' && left.top() == '{'))
			{
				check = true;
				left.pop();
			}
		}
	}
	if(!left.empty())
	{
		check = false;
	}	
	return check;
}
