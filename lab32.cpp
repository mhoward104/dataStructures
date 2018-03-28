//Matthew Howard
//Cs 2315
//Lab 32

using namespace std;

template <typename T>
void exchangeSort(vector<T>& v)
{
	//unsigned int length = v.size();
	typename vector<T>::iterator i, j;
	
	for(i = v.begin(); i < v.end() - 1; i++)
	{
		for(j = i + 1; j < v.end(); j++)
		{
			if(*i > *j)
			{
				swap(*i, *j);
			}
		}
	}
}
