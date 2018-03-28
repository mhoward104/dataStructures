//Matthew Howard
//CS 2315
//Lab 44

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <deque>


using namespace std;

bool isPalindrome(string s)
{
	deque<int> pal;
	
	for(unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
		pal.push_back(s[i]);
	}
	
	while(pal.size() > 1)
	{
		if(pal.front() == pal.back())
		{
			pal.pop_back();
			pal.pop_front();
		}
		else
		{
			return false;
			break;
		}
	}
	
	return true;
}
