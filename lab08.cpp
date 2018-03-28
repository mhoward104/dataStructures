// Matthew Howard
// CS 2315
// lab 08

#include <lab08.h>

// overloaded output operator for printing IntegerSet set to
// output stream out
ostream& operator<<(ostream& out, const IntegerSet& set)
{
	int numElements = N / (CHAR_BIT * sizeof(uint));
	if (N % (CHAR_BIT * sizeof(uint)) != 0)
    ++numElements;
	  
	if(set.cardinality() == 0)
		out << static_cast<char>(216) << endl;
		else
		{
			int counter = 0;
			int commaCounter = 0;
			out << "{";
			for(int i = 0; i < numElements; i++)
			{
				for(int j = 0; j < 32; j++)
				{
					
					if(getBit(set.bitVector[i], j))
					{
						if(commaCounter != 0)
						{out << ",";}	
						
						out << counter;
						commaCounter++;						
					}
					counter++;
				}
			}
			out << "}" << endl;
		}
		
		return out;
}

IntegerSet IntegerSet::operator+(uint e) const     // if e is valid and not a member of the set, insert e into set

{			
	IntegerSet temp(*this);
	//setBit: return value with bit n set to v (0 or 1)
	//unsigned int setBit(unsigned in word, int n, unsigned int v); 
	if(this->isValid(e) && !this->isMember(e))
		temp.bitVector[this->word(e)] = setBit(temp.bitVector[this->word(e)], this->bit(e), 1);

	return temp;		

	
}
IntegerSet IntegerSet::operator-(uint e) const     // if e is valid and a member of the set, delete e from set
{
	IntegerSet temp(*this);
	//setBit: return value with bit n set to v (0 or 1)
	//unsigned int setBit(unsigned in word, int n, unsigned int v); 
	if(this->isValid(e) && this->isMember(e))
		temp.bitVector[this->word(e)] = setBit(temp.bitVector[this->word(e)], this->bit(e), 0);

	return temp;
}

  IntegerSet IntegerSet::operator-() const           // complement of a Set
{
	IntegerSet comp;  // declare a local object
	
	int counter = 0;
	
	for(int i = 0; i < 2; i++)
		comp.bitVector[i] = this->bitVector[i];
	
	
		
		for(int j = 0; j < 2; j++)
		{


			for(int k = 0; k < 32; k++)
			{

				if(getBit(this->bitVector[j], k) && counter < 48)
				{
					comp.bitVector[j] = setBit(comp.bitVector[j], k, 0);
				}	
				else if(!getBit(this->bitVector[j], k) && counter < 48)
				{
					comp.bitVector[j] = setBit(comp.bitVector[j], k, 1);	
				}
				counter++;
				
			}

		}
	return comp; // return the local object
}



IntegerSet& IntegerSet::operator=(const IntegerSet& rhs) // *this = rhs; doing in class Friday
{
	if(this != &rhs)
	{
		for(uint e = 0; e < N; e++)
			if(rhs.isMember(e))
			/*the following two statements are equivalent, but the problem is that they both are attempting to use operator= (which we are defining*/
				//*this = *this + e;
				//this->operator=(this->operator+(e));
				this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 1);
			else	
				this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 0);
	}
	return *this;
}
