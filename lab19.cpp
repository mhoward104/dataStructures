//Matthew Howard
//CS 2315
//Lab 19


#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

// isPalindrome is a recursive function that returns true if string s
// is a palindrome and false otherwise
bool isPalindrome(string s)
{
	if(s.length() <= 1)
	{
		return true;
	}
	else if(toupper(s.at(0)) == toupper(s.at(s.length() - 1)))
	{
		
		return isPalindrome(s.substr(1,s.length() - 2));
	}
	else
	{
		return false;
	}
	
}
