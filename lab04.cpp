// Matthew Howard 
//CS 2315 
//Lab 04

#include <iostream>
#include <bits.h>
#include <lab04.h>

using namespace std;


IntegerSet::IntegerSet()                           // initializes the set to the empty set
{	// Allocate the elements for the bitVector
	this->allocateStorage();
	
	//Iterate through the universe and delete each element from the set
	for (uint e = 0; e < N; e++)
		this->deleteElement(e);
		
}	

IntegerSet::IntegerSet(const IntegerSet& otherSet) // copy constructor--- make similar to ^ make it an identical copy of otherset--- always 48 elements--- asking if e is a member of other set (if Statment)
{
	this->allocateStorage();

	
	for(int i = 0; i < 2; i++)
		this->bitVector[i] = otherSet.bitVector[i];
	

	
	
}
IntegerSet::~IntegerSet()                          // destructor
{
	delete [] this->bitVector;						// uses [] because its an array otherwise leave [] off
}

bool IntegerSet::isMember(uint e) const            // returns true if e is a member of the set and false otherwise
{
	//getBit: get value of bin n in word
	//unsigned int getBit (unsigned int word, int );  bit(e) will either be a 0 or 1 isValid checks to see if the e is within the set
	return this->isValid(e) && getBit(this->bitVector[this->word(e)], this->bit(e));
}

uint IntegerSet::cardinality() const               // cardinality of a set increment a counter for the members
{
	int bitCounter = 0;
	
	for(int i = 0; i < 2; i++)
			{
				for(int j = 0; j < 32; j++)
				{
					
					if(getBit(this->bitVector[i], j))
					{

					bitCounter++;
					}
				}
			}
	
	

	return bitCounter;
}
void IntegerSet::insertElement(uint e)             // if e is valid and not a member of the set, insert e into set
{
	//unsigned int setBit(unsigned in word, int n, unsigned int v);  //doesnt work need to figure out
	if(this->isValid(e) && !this->isMember(e))
	this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 1);
	

}

void IntegerSet::deleteElement(uint e)             // if e is valid and a member of the set, delete e from set
{
	if(this->isValid(e) && this->isMember(e))
	this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 0);

}
IntegerSet IntegerSet::complement() const           // complement of a Set
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
ostream& IntegerSet::print(ostream& os) const
{
	int numElements = N / (CHAR_BIT * sizeof(uint));
	if (N % (CHAR_BIT * sizeof(uint)) != 0)
    ++numElements;
	  
	if(this->cardinality() == 0)
		os << static_cast<char>(216) << endl;
		else
		{
			int counter = 0;
			int commaCounter = 0;
			os << "{";
			for(int i = 0; i < numElements; i++)
			{
				for(int j = 0; j < 32; j++)
				{
					
					if(getBit(this->bitVector[i], j))
					{
						if(commaCounter != 0)
						{os << ",";}	
						
						os << counter;
						commaCounter++;						
					}
					counter++;
				}
			}
			os << "}" << endl;
		}
		
		return os;
}

bool IntegerSet::isValid(uint e) const             // 0 <= e < N
{
	if (e < 48)
	
		return 1;
		
		else
		
			return 0;
		
	
}

