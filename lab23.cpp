//Matthew Howard
//Cs 2315
//Lab23

// template function prototype
template<typename T>
int numDistinct(const T *array, int n)
{
	int count = 0;

	if(n <= 0)
		return 0;
		
	
	for(int i = 0; i < n; ++i)
	{
		if(array[0] == array[i])
		{
			count += 1;
			
		}
		
		
	}
	if(count > 1)
	{

		return 0 + numDistinct(array + 1, n - 1);
		
	}
	else 
	{

		return 1 + numDistinct(array + 1, n - 1);
	}	
	
	
	
}
