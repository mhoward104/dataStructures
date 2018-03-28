// Matthew Howard
//Cs 2315
//lab 20

// template function prototypes
template<typename T>
void mySwap(T& first, T& second)
{
	T temp = first;
	first = second;
	second = temp;
}



template<typename T>
void bubbleSort(T *array, int n)
{
	bool check = false;
	for(int i = 0; i < n - 1; i++)
	{
		if(array[i] > array[i+1])
		{
			mySwap(array[i+1] ,array[i]);
			check = true;
		}	
	}
	
	if(check == true)
	{
		bubbleSort(array, n);	
	}
	
	
	
	return;
	
}
