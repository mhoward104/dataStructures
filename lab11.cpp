// Matthew Howard
// CS 2315
// Lab 11

#include <lab11.h>

bool IntegerSet::operator==(const IntegerSet& rhs) const // Test for equality
{

	for (uint e = 0; e < N; e++)
	{
		if(this->isMember(e) == !rhs.isMember(e))
		{
			return false;
			break;
		}
	}
	return true;
}
bool IntegerSet::operator<=(const IntegerSet& rhs) const // Subset
{
	for (uint e = 0; e < N; e++)
	{
		if(this->isMember(e) == 1)
		{
			if(rhs.isMember(e) == 0)
			{
				return false;
				break;
			}
		}

	}
	return true;

}

bool IntegerSet::operator< (const IntegerSet& rhs) const // Proper Subset
{
	if(*this <= rhs)
	{
		for(uint e = 0; e < N; e++)
		{
			if(rhs.isMember(e) == 1)
			{
				if(this->isMember(e) == 0)
					return true;
					break;
			}
		}
	}

	return false;
}

