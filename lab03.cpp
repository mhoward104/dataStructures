// Matthew Howard
// Cs 2315
// Lab 03

#include <lab03.h>
#include <cstdlib> // for abs

 



  Rational Rational::add(const Rational& addend) const     // Addition
{
	Rational sum;   // declare a local rational object
	int lcm = this->lcm(this->getDenominator(), addend.getDenominator());

	// manipulate the local rational object
	sum.setNumerator(lcm * this->getNumerator() / this->getDenominator() +
					 lcm * addend.getNumerator() / addend.getDenominator());
	sum.setDenominator(lcm);
	sum.reduce();

	return sum;  // return the local Rational object
}
  Rational Rational::additiveInverse() const               // Returns the additive inverse
  {
	return Rational(-1 * this->getNumerator(), this->getDenominator());
  }



  Rational Rational::subtract(const Rational& subtrahend) const // Subtraction
  {
	return this->add(subtrahend.additiveInverse());
  }



  Rational Rational::multiply(const Rational& multiplicand) const // Multiplication
  {
	  Rational product;					// declare a local rational object


	  product.setNumerator(this->getNumerator() * multiplicand.getNumerator());
	  product.setDenominator(this->getDenominator() * multiplicand.getDenominator());

	  product.reduce();
	  return product;

  }



 Rational Rational::multiplicativeInverse() const         // Returns the multiplicative inverse**** Dont think this one works
  {

	int d = this->getNumerator();
	int n = this->getDenominator();
	

	return Rational(n, d);
  }



  Rational Rational::divide(const Rational& divisor) const   // Division
  {
	Rational quot;
	return this->multiply(divisor.multiplicativeInverse());


  }

  ostream& Rational::print(ostream& os) const     // Print Rational to output stream
  {

   cout << getNumerator() << '/' << getDenominator();

	return os;
  }

  istream& Rational::read(istream& is)                    // Read Rational from input stream
  {
	int num, denom, x, y;
	
	is >> num >> denom >> x >> y;
	this->setNumerator(num);
	this->setDenominator(denom);
	return is;
  }
  int Rational::lcm(int m, int n) const                    // returns the least common multiple of m and n
  {
	if(m == 0 || n == 0)
		return 0;
	else
		return abs(m * n) / gcd(m, n);
  }
