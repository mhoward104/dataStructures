//MAtthew Howard
//CS 2315
//Lab 35

#include <iostream>
#include <d_matrix.h>
using namespace std;


bool isIdentityMatrix(const matrix<int>& mat)
{
	int size = mat.rows();
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if( i == j)
			{
				if(mat[i][j] != 1)
					return false;
					break;
			}
			else if(i != j)
			{
				if(mat[i][j] != 0)
					return false;
					break;
			}
			
		}
			
	}		

	
	return true;
	
	
}


