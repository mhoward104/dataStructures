// Matthew Howard
// Cs 2315
// Lab 02

#include <lab02.h>
#include <cstdlib> // for absolute value


Rational::Rational()					// default constructor
{
	setNumerator(0);
	setDenominator(1);
}
//	r[0] = 0; ****this works, but we should minimize the # of functions
//	r[1] = 1; ****that directly manipulate the private data members




Rational::Rational(int num, int denom)        // additional constructor
{
		setNumerator(num);
		setDenominator(denom);
}

void Rational::setNumerator(int num)
{
	r[0] = num;                      // set numerator to num
}        

void Rational::setDenominator(int denom)      // set denominator to denom
{
	r[1] = denom != 0 ? denom : 1;
}

int Rational::getNumerator() const            // return numerator
{
	return r[0];
}

int Rational::getDenominator() const          // return denominator
{
	return r[1];
}

void Rational::reduce()                       // Reduce to lowest terms and normalize
{
	int great = gcd(getNumerator(), getDenominator());
	
	if (getDenominator() < 0)
		great = -great;
	
	setNumerator(getNumerator() / great);
	setDenominator(getDenominator() / great);
}

int Rational::gcd(int m, int n) const         // returns the gcd of m and n
{
	int great;
	
	if(m == 0)
		great = abs(n);
	else if(n == 0)
		great = abs(m);
	else
	{
		m = abs(m);
		n = abs(n);
		int rem = m % n;
		
		while (rem != 0)
		{
			m = n;
			n = rem;
			rem = m % n;
		}
		great = n;
	}
	
	return great;
}


