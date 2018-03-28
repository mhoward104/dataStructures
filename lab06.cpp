// Matthew Howard
//CS 2315
// Lab 06
#include <lab06.h>



  IntegerSet IntegerSet::Union(const IntegerSet& otherSet) const
{
	IntegerSet u(*this);
	
	for (uint e = 0; e < N; e++)
		if (this->isMember(e) || otherSet.isMember(e))
			u.insertElement(e);
			
	return u;
}
  IntegerSet IntegerSet::intersection(const IntegerSet& otherSet) const
  {
	IntegerSet i(*this);
	
	for (uint e = 0; e < N; e++)
	{
		if (this->isMember(e) && otherSet.isMember(e))
		{
			i.insertElement(e);
		}
		else
		{
			i.deleteElement(e);
		}

	}

	return i;
  }
  
  
  IntegerSet IntegerSet::difference(const IntegerSet& otherSet) const
  {
	IntegerSet d(*this);
	
	for (uint e = 0; e < N; e++)
	{
		if (this->isMember(e) && !otherSet.isMember(e))
		{
			d.insertElement(e);
		}
		else
		{
			d.deleteElement(e);
		}

	}
	return d;
  
  }
  IntegerSet IntegerSet::symmetricDifference(const IntegerSet& otherSet) const
  {
	IntegerSet s(*this);
	
	for (uint e = 0; e < N; e++)
	{
		if ((this->isMember(e) || otherSet.isMember(e)) && !(this->isMember(e) && otherSet.isMember(e)))
		{
			s.insertElement(e);
		}
		else 
		{
			s.deleteElement(e);
		}
	}
	return s;
  }
  
