//Matthew Howard
//CS 2315
//Lab34

//use push_back


template <typename T>
void miniVector<T>::insert(int i, const T& item)
//insert items at index i in the vector
//precondition vector is not empty and 0 <= 1<= vSize
//Postcondition the vector size increase by 1
{
	if(empty() && i != 0)
	{
		throw underflowError("miniVector insert(): vector empty");
	}
	
	if(i < 0 || i > vSize)
	{
		throw indexRangeError("miniVecotr insert(): index range error", i, vSize);
	}

		//callpush_back to add item to vArr
		this->push_back(item);
		
		//loop to clear a spot to insert item at index i
		for(int j = i; j < this->size(); j++)
		{
			this->vArr[i + 1]  = this->vArr[i];
		}
		//insert item at index i
		this->vArr[i] = item;
		
}

template <typename T>
void miniVector<T>::erase(int i)
//erase the item at index i in the vector
//Precondition vector is not empty and 0 <= 1 < vSize
//Postcondition the vector size decreases by 1

// do the checks at the top
{
	if(empty() && i != 0)
	{
		throw underflowError("miniVector insert(): vector empty");
	}
	
	if(i < 0 || i > vSize)
	{
		throw indexRangeError("miniVecotr insert(): index range error", i, vSize);
	}
	
	for(int j = i; j < this->size(); j++)
	{
		if(this->size() - 1 == j)
		{
			this->pop_back();
		}
		else
		{
		this->vArr[j] = this->vArr[j + 1];
		}
	}
}
