// Matthew Howard
// CS 2315
// Lab 05

#include <lab05.h>
#include <iostream>







bool Rational::isEqualTo(const Rational& other) const    // *this == other
{


	if((this->getNumerator() * other.getDenominator()) == (other.getNumerator() * this->getDenominator()))
	{
		return 1;
	}
	else
	{
		return 0;
	}
		
}

bool Rational::isNotEqualTo(const Rational& other) const // *this != other
{
	if(!isEqualTo(other))
		return 1;
	else
		return 0;
}

bool Rational::isLessThan(const Rational& other) const   // *this < other
{

	if((this->getNumerator() * other.getDenominator()) < (other.getNumerator() * this->getDenominator()))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

bool Rational::isLessThanOrEqualTo(const Rational& other) const // *this <= other
{
	if(isLessThan(other) || isEqualTo(other))
		return 1;
	else
		return 0;
}

bool Rational::isGreaterThan(const Rational& other) const // *this > other
{
	if(!isLessThan(other))
		return 1;
	else
		return 0;
}

bool Rational::isGreaterThanOrEqualTo(const Rational& other) const // *this >= other
{
	if(!isLessThan(other) || isEqualTo(other))
		return 1;
	else
		return 0;
}
