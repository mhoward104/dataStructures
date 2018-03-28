//Matthew Howard
//Cs 2315
//Lab 39

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <d_stack.h>

using namespace std;

bool isPalindrome(string s)
{
	miniStack<char> word, word2;
	
	
	for(unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
		word.push(s[i]);
		
	}
	
	for(int i = s.length() -1; i >= 0; i--)
	{
		word2.push(s[i]);
	}
	
	for(uint i = 0; i < s.length(); i++)
	{
		if(word.top() == word2.top())
		{
			word.pop();
			word2.pop();
		}
		else
		{
			return false;
			break;
		}
	}
	//cout << s <<  endl;
	return true;
	
}
