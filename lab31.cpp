//Matthew Howard
//cs 2315
//Lab 31

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <iomanip>
using namespace std;


int main()
{
	//variables
	string name;
	unsigned int longest = 0, arraySize;
	vector<string> v;
	unsigned int columns, rows;
	

	//input for the .dat 
	 while (cin >> name)
	 {
		 if(name.length() > longest)
		 {
			 longest = name.length();
		 }
		v.push_back(name);
		
	 }
	 
	 //size of the array
	 arraySize = v.size();
	 //number of columns
	 columns = 62 / (longest + 2);
	 //number of rows
	 rows = (v.size() / columns);
	 if(v.size() % columns != 0)
	 {
		 rows += 1;
	 }
	

	 if (v.size() == 0)
	 {
		cout << "No data\n"; 
	 }
	 
	 sort(v.begin(), v.end());
	 
	//cout information and lines
	 cout << "Matthew Howard - CS 2315 - Lab 31" << endl;
	 cout << string(60, '-');
	 cout << endl;
	 //loops to print the correct number of rows and columns
	 for(unsigned int i = 0; i < rows; i++)
	 {
		 cout << left << setw(longest + 2) << v[i] << " ";
		
		for(unsigned int j = rows + i; j < arraySize; j += rows)
		{
			cout << left << setw(longest + 2) << v[j] << " ";
		}
		cout << endl;
	 }

	
	return EXIT_SUCCESS;
}
