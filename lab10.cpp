// Matthew Howard
// Cs 2315
// Lab 10

#include <lab10.h>
//use operator=() and other stuff from lab 08

IntegerSet IntegerSet::operator+(const IntegerSet& rhs) const // union
{
	IntegerSet u(*this);
	
	for (uint e = 0; e < N; e++)
		if (this->isMember(e) || rhs.isMember(e))
			u = u + e;
			
	return u;
}

IntegerSet IntegerSet::operator*(const IntegerSet& rhs) const // intersection
{
	IntegerSet i(*this);
	
	for (uint e = 0; e < N; e++)
	{
		if (this->isMember(e) && rhs.isMember(e))
		{
			i = i + e;
		}
		else
		{
			i = i - e;
		}

	}

	return i;
}

IntegerSet IntegerSet::operator-(const IntegerSet& rhs) const // difference
{
	IntegerSet d(*this);
	
	for (uint e = 0; e < N; e++)
	{
		if (this->isMember(e) && !rhs.isMember(e))
		{
			d = d + e;
		}
		else
		{
			d = d - e;
		}

	}
	return d;
}

IntegerSet IntegerSet::operator/(const IntegerSet& rhs) const // symmetric diff
{
	IntegerSet s(*this);
	
	for (uint e = 0; e < N; e++)
	{
		if ((this->isMember(e) || rhs.isMember(e)) && !(this->isMember(e) && rhs.isMember(e)))
		{
			s = s + e;
		}
		else 
		{
			s = s - e;
		}
	}
	return s;
}

