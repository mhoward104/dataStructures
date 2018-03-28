//matthew Howard
//CS 2315
//Lab 46

#include <iostream>
#include <string>
#include <deque>
#include <lab46.h>

using namespace std;

  BigInt  BigInt::operator+ ( const BigInt& rhs ) const // Addition
  {	  
    int a, b;
	int sum;
	int carry = 0;
	uint len = digits.size();
	BigInt result;
	result.digits.pop_back();
	
	if((rhs.sign == NEGATIVE && (sign == POSITIVE || sign == ZERO)) || (sign == NEGATIVE && (rhs.sign == POSITIVE || rhs.sign == ZERO)))
	{
		BigInt rhsSwitch(rhs);
		if(rhsSwitch.sign == NEGATIVE)
		{
			rhsSwitch.sign = POSITIVE;
	
		}
		else
		{
			rhsSwitch.sign = NEGATIVE;
		}
		
		return *this - rhsSwitch;
	}
	
	
	if(len < rhs.digits.size())
	{
		len = rhs.digits.size();
	}
	
	for(uint i = 0; i < len; i++)
	{
		if(i < digits.size())
		{
			a = (digits[i] - 48);
		}
		else
		{
			a = 0;
		}
		if(i < rhs.digits.size())
		{
			b = (rhs.digits[i] - 48);
		}
		else
		{
			b = 0;
		}
		
		sum = a + b + carry;
		
		
		carry = sum / 10;
		sum = sum % 10;
		
		
		result.digits.push_back(sum + 48);
	}
	
	if(carry != 0)
	{
		result.digits.push_back(carry + 48);
	}
	
	if(sign == NEGATIVE)
	{
		result.sign = NEGATIVE;
	}
	else
	{
		result.sign = POSITIVE;
	}
	
	return result;
	
  }
  BigInt  BigInt::operator- ( const BigInt& rhs ) const // Subtraction
  {
	int a, b;
	int diff;
	int borrow = 0;
	uint len = digits.size();
	
	BigInt result;
	result.digits.pop_back();
	//compares them to see if they are the same including the sign value and subtracts them
	if(*this == rhs)
	{
		result.digits.push_back(0 + 48);
		return result;
	}
	//Checks opposite signs, switches the sign and adds them
	if((rhs.sign == NEGATIVE && (sign == POSITIVE || sign == ZERO)) || (sign == NEGATIVE && (rhs.sign == POSITIVE || rhs.sign == ZERO)))
	{
		BigInt rhsSwitch(rhs);
		if(rhsSwitch.sign == NEGATIVE)
		{
			rhsSwitch.sign = POSITIVE;
	
		}
		else
		{
			rhsSwitch.sign = NEGATIVE;
		}
		return *this + rhsSwitch;
	}
	//get the length of the longer side
	if(len < rhs.digits.size())
	{
		len = rhs.digits.size();
	}
	
	//if signs are the same and the big number is on the right switch signs
	if((sign == POSITIVE || sign == ZERO) && (*this) < rhs)
	{
		BigInt rhsSwitch(rhs);
		rhsSwitch = rhs - *this;
		rhsSwitch.sign = NEGATIVE;
		
		return rhsSwitch;
	}
	
	if(sign == NEGATIVE && rhs < (*this))
	{
		BigInt rhsSwitch(rhs);
		rhsSwitch = rhs - *this;
		rhsSwitch.sign = POSITIVE;
		
		return rhsSwitch;
	}
	
		
	//if signs are the same and the big number is on the left
	for(uint i = 0; i < len; i++)
	{
		if(i < digits.size())
		{
			a = (digits[i] - 48);
		}
		else
		{
			a = 0;
		}
		if(i < rhs.digits.size())
		{
			b = (rhs.digits[i] - 48);
		}
		else
		{
			b = 0;
		}
		
		diff = a - b - borrow;
		borrow = 0;
		
		if(diff < 0)
		{
			diff = diff + 10;
			borrow = 1;
		}
		result.digits.push_back(diff + 48);
	
	}
	//gets rid of the leading ZEROS using + 48 instead of + '0'
	while(result.digits.back() == 0 + 48 && result.digits.size() > 1)
	{
		result.digits.pop_back();
	}
	
	if(sign == NEGATIVE)
	{
		result.sign = NEGATIVE;
	}
	else
	{
		result.sign = POSITIVE;
	}
	
	  return result;
  }
