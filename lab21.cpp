//Matthew Howard
//CS 2315
//Lab21


template<typename T>
const T *linearSearch(const T *array, int n, T itemToFind)
{
	
	if (n==0) 
	{
	return NULL; 
	}
	else if(array[n-1] == itemToFind) 
	{
	return &array[n-1];
	} 
	return linearSearch(array,n-1,itemToFind); 
	

}
