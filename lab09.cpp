// Matthew Howard
// Cs 2315
// lab 09

#include <lab09.h>

Rational& Rational::operator++()                         // preincrement
{
	Rational copy;
	copy.setNumerator(1);
	copy.setDenominator(1);
	*this = *this + copy;
	
	
	return *this;
}

Rational Rational::operator++(int)                       // postincrement
{
	Rational copy(*this);

	++*this;
	//this->operator++(); Also works
	
	return copy;
}
Rational& Rational::operator--()                         // predecrement
{
	Rational copy(*this);
	copy.setNumerator(1);
	copy.setDenominator(1);
	*this = *this - copy;
	
	return *this;
}
Rational Rational::operator--(int)                       // postdecrement
{
	Rational copy;
	
	--*this;
	
	return copy;
}

