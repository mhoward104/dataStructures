//Matthew Howard
//Cs 2315
//Lab 45

#include <iostream>
#include <string>
#include <deque>
#include <lab45.h>
#include <cmath>

using namespace std;

bool BigInt::operator==(const BigInt& rhs) const // Equality
{
	return ((digits == rhs.digits) && (sign == rhs.sign));
}

bool BigInt::operator<(const BigInt& rhs) const // Less Than
{
	
	bool check;
	double num1 = 0, num2 = 0;
	for(int i = digits.size() -1; i >= 0; --i)
	{
		num1 = num1 + ((pow(10.0, (double)i)) * (digits[i] - 48)) ;
	}
	
	for(int i = rhs.digits.size() -1; i >= 0; --i)
	{
		num2 = num2 + ((pow(10.0, (double)i)) * (rhs.digits[i] - 48)) ;
	}
	
	if(sign == NEGATIVE)
	{
		num1 *= -1;
	}
	
	if(rhs.sign == NEGATIVE)
	{
		num2 *= -1;
	}
	
	return num1 < num2;
}

BigInt::BigInt()                                      // constructor; digits = 0
{
	sign = ZERO;
	digits.push_front('0');
}
	
BigInt::BigInt(int num)                             // constructor; digits = num
{
		if(num == 0)
		{
			sign = ZERO;
		}
		else if(num > 0)
		{
			sign = POSITIVE;
		}
		else if(num < 0)
		{
			sign = NEGATIVE;
		}
		
		num = abs(num);
		if(num == 0)
		{
			digits.push_front('0');
			
		}
		
		char c;
		while(num > 0)
		{
			c = num % 10;
			digits.push_back(c + 48);
			num = (num / 10);
		}
}
	
BigInt::BigInt(const string str)                    // constructor; digits = str
{
	string::iterator itr;
	//sign = ZERO;
	if(fsaForInt(str))
	{
		for (uint i = 0; i < str.length(); i++)
		{
			if(isdigit(str[i]))
			{
				digits.push_front(str[i]);
			}
			else if(str[i] == '+')
			{
				sign = POSITIVE;
			}
			else if(str[i] == '-')
			{
				sign = NEGATIVE;
			}
		}		
	}
	else
	{
		sign = ZERO;
		digits.push_front('0');
	}
	
	if(digits.back() == '0')
	{
		sign = ZERO;
	}
	
	
}
	
BigInt::BigInt(const BigInt& other)   
{
		sign = other.sign;
		digits = other.digits;
}
