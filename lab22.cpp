//Matthew Howard
//Cs 2315
//Lab 22

// template function prototype
template<typename T>
const T *binarySearch(const T *first, const T *last, T itemToFind)
{
	
	int middle;
	
	if(first > last)
	{
		return NULL;
	}
	middle = (last - first) / 2;
	if(first[middle] == itemToFind)
	{
		return first + middle;
	}
	else if(first[middle] < itemToFind)
	{
		return binarySearch(first + (middle + 1) , last, itemToFind);
	}
	else
	{
		return binarySearch(first, first + (middle - 1), itemToFind);
	}
	
}
