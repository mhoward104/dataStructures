//Matthew Howard
//Cs 2315
//Lab 41

#include <iostream>
#include <cstdlib>
#include <string>
#include <d_stack.h>
using namespace std;

bool precedence(char stack, char next)
{
    if ( stack == '^' ) {
        return true;
    } else if ( next == '^' ) {
        return false;
    } else if ( stack == '*' || stack == '/' || stack == '%' ) {
        return true;
    } else if ( next == '*' || next == '/' || next == '%' ) {
        return false;
    }

    return true;
}

void infix2Postfix(string infix, ostream& out)
{
	miniStack<char> operators;
	for(uint i = 0; i < infix.length(); i++)
	{
		if(isspace(infix[i]))
		{
			//ignore
		}
		else if(infix[i] == '(' )
		{
			operators.push(infix[i]);
		}
		else if(isalnum(infix[i]))
		{
			out << infix[i] << ' ';
		}
		else if(infix[i] == '-' || infix[i] == '*' || infix[i] == '/' ||infix[i] == '+')
		{
			if(!operators.empty() && operators.top() != '(' && precedence(operators.top(), infix[i]))
			{
				out << operators.top() << ' ';
				operators.pop();
			}
			operators.push(infix[i]);
		}
		else
		{
			while(operators.top() != '(')
			{
				out << operators.top() << ' ';
				operators.pop();	
			}
			if(operators.empty())
			{
				out << "Error: Unbalanced Paranthesis";
			}
			else
			{
				operators.pop();
			}
			
		}
	}
	while(!operators.empty())
		{
			if(operators.top() == '(')
			{
				out << "Error: Unbalanced Paranthesis";
			}
			else
			{
				out << operators.top() << ' ';
			}
			operators.pop();
		}	
	
}
