//Matthew howard
//cs 2315
//lab33

using namespace std;

template <typename T>
void shellSort(vector<T>& v)
{
	int n = v.size();
	vector<int> gaps;
	vector<int> sub;
	int var = 0;
	
	//fills the gaps vecotor
	for (int k = 1; k <= n / 9; k = 3 * k + 1)
	{
		gaps.push_back(k);
	}
	
	for(int i = gaps.size() - 1; i >= 0; i--)
	{
		for(int j = 0; j < gaps[i]; j++)
		{
			for(int x = j; x < n; x += gaps[i])
			{
				
				sub.push_back(v[x]);	
			}
			
			insertionSort(sub);
			
			for(int y = j; y < n; y += gaps[i])
			{
				v[y] = sub[var];
				var += 1;
			}
				sub.clear();
				var = 0;

		}
	}

	
}
