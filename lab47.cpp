//MAtthew Howard
//CS 2315
//Lab 47


#include <iostream>
#include <string>
#include <deque>
#include <lab47.h>

using namespace std;

BigInt  BigInt::operator*(const BigInt& rhs) const // Multiplication
{
	BigInt sum, base(*this);
	int rhsLength = rhs.digits.size();
	
	for(int i = 0; i < rhsLength; i++)
	{
		sum = sum + (base * rhs.digits[i]);
		base.digits.push_front('0'); //check later
	}
	if(sign == ZERO || rhs.sign == ZERO)
	{
		sum.sign = ZERO;
	}
	else if((rhs.sign == NEGATIVE && (sign == POSITIVE || sign == ZERO)) || (sign == NEGATIVE && (rhs.sign == POSITIVE || rhs.sign == ZERO)))
	{
		
		sum.sign = NEGATIVE;
	}
	else
	{
		sum.sign = POSITIVE;
	}
	
	return sum;
}

BigInt  BigInt::operator* ( char digit ) const
{
	BigInt result2;
	result2.digits.pop_back();
	int thisLength = digits.size(), carry = 0, product;
	int a = digit - 48, b, c;
	
	if(digit == '0')
	{
		result2.digits.push_back('0');
		return result2;
	}
	if(digit == '1')
	{
		
		return *this;
	}
	
	for(int i = 0; i < thisLength; i++)
	{
		b = digits[i] - 48;
		product = a * b + carry;
			
		carry = product / 10;
		product = product % 10;
			
		result2.digits.push_back(product + '0');
	}
	
	while(carry != 0)
	{
		c = carry % 10;
		result2.digits.push_back(c + 48);
		carry = carry / 10;
	}
	
	result2.sign = POSITIVE;
	
	return result2;
}

