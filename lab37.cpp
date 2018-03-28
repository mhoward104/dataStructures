//Matthew Howard
//Cs 2315
//Lab 37
#include <iostream>
#include <d_matrix.h>
#include <lab37.h>
#include <string>
#include <iostream>  

using namespace std;

ostream& operator<<(ostream& out, const Sudoku& puzzle)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			out << puzzle.gameBoard[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Sudoku& puzzle)
{
	
	string rows;
	int c;
	
	for(int i = 0; i < 4; i++)
	{
		in >> rows;
		
		for(int j = 0; j < 4; j++)
		{
			c = rows[j] - 48;
			
			puzzle.gameBoard[i][j] = c; 
		}
		
	}
	return in;
}

Sudoku::Sudoku()
{
	gameBoard.resize(4, 4);
}

bool Sudoku::isValid() const
{
	vector<int> v;
	bool flag = true;
	int count = 0;
	// to inisualize the vector
	for(int i = 0; i < 4; i++)
	{
		v.push_back(0);
	}
	// to check the rows
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			v[j] = gameBoard[i][j];
		}
		sort(v.begin(), v.end());
		for(int k = 0; k < 4; k++)
		{
			if(v[k] != k + 1)
			{
				flag = false;
			}
		}
	}
	//check the columns
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			v[j] = gameBoard[j][i];
		}
		sort(v.begin(), v.end());
		for(int k = 0; k < 4; k++)
		{
			if(v[k] != k + 1)
			{
				flag = false;
			}
		}
	}
	//check quadrant 1
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			v[count] = gameBoard[i][j];
			count += 1;
		}
	}
	sort(v.begin(), v.end());
	for(int k = 0; k < 4; k++)
	{
		if(v[k] != k + 1)
		{
			flag = false;
		}
	}
	count = 0;
	
	//check quadrant 2
	for(int i = 0; i < 2; i++)
	{
		for(int j = 2; j < 4; j++)
		{
			v[count] = gameBoard[i][j];
			count += 1;
		}
	}
	sort(v.begin(), v.end());
	for(int k = 0; k < 4; k++)
	{
		if(v[k] != k + 1)
		{
			flag = false;
		}
	}
	count = 0;
	
	//check quadrant 3
	for(int i = 2; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			v[count] = gameBoard[i][j];
			count += 1;
		}
	}
	sort(v.begin(), v.end());
	for(int k = 0; k < 4; k++)
	{
		if(v[k] != k + 1)
		{
			flag = false;
		}
	}
	count = 0;
	
	//check quadrant 4
	for(int i = 2; i < 4; i++)
	{
		for(int j = 2; j < 4; j++)
		{
			v[count] = gameBoard[i][j];
			count += 1;
		}
	}
	sort(v.begin(), v.end());
	for(int k = 0; k < 4; k++)
	{
		if(v[k] != k + 1)
		{
			flag = false;
		}
	}
	count = 0;
		
	return flag;
}
