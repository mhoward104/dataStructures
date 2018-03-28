//Matthew Howard
//cs 2315
//Lab 42

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <d_stack.h>
#include <d_queue.h>

using namespace std;

bool isPalindrome(string s)
{
	miniStack<char> word;
	miniQueue<char> word2;
	
	
	for(unsigned int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
		word.push(s[i]);
		word2.push(s[i]);
	}
	
	for(uint i = 0; i < s.length(); i++)
	{
		if(word.top() == word2.front())
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
