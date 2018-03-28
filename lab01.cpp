#include <iostream>
#include <string>

using namespace std;

const string ID = "Matthew Howard - CS 2315 - Lab 01\n\n";
int counter = 0;
int next_num = 0;
unsigned int productOfDigits(unsigned int);


int main()
{

	unsigned int num;

	//output Id Line
	cout << ID;

	//read an unknown # of unsigned ints from standard input_iterations and output the number of times that it loops
	while (cin >> num)
	{
        cout << num;
		while (num > 9)
        {
        next_num = productOfDigits(num);
		cout << " -> " << next_num << " ";
		num = next_num;
		counter++;
        }
       cout << "persistence: " << counter << endl;
       counter = 0;
        //cout <<  " persistance: " ;
	}



return 0;
}


unsigned int productOfDigits(unsigned int num)
{

	unsigned int product, digit;

	if (num ==0)
    {
        product = 0;
    }
    else
    {
         product = 1;
    }


    while (num != 0)
	{

		//Step 1: extract the rightmost digit of num
		digit = num % 10;


		//step 1: incorporate digit into prodcut
		product *= digit;

		//step 3: eliminate the rigtmost digit from num
		num /= 10;

	}



	return product;


}

