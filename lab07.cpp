// Matthew Howard
// CS 2315
// Lab 07

#include <lab07.h>
#include <stdlib.h>


  // overloaded input operator initializes Rational rat from input stream in
  //to istream& operator>>(istream in, rational rat)
  //istream Rational::read

  // overloaded output operator prints Rational rat to output stream out
ostream& operator<<(ostream& out, const Rational& rat)
{
   out << rat.getNumerator() << '/' << rat.getDenominator();

	return out;
}

  
istream& operator>>(istream& in, Rational& rat)                    // Read Rational from input stream
{
	int num, denom;
	
	in >> num >> denom;
	rat.setNumerator(num);
	rat.setDenominator(denom);
	
	return in;
  }
  
 Rational& Rational::operator=(const Rational& rhs)      						 // *this = rhs;
 {
	if(this != &rhs)
	{
		this->setNumerator(rhs.getNumerator());
		this->setDenominator(rhs.getDenominator());
	}

	
	return *this;
 }
 
 
  Rational Rational::operator+(const Rational& addend) const					// returns *this + addend
  {
	Rational sum; 	// declare a local rational object
	int lcm = this->lcm(this->getDenominator(),  addend.getDenominator());
	
	sum.setNumerator(lcm * this->getNumerator() / this->getDenominator() +
					 lcm * addend.getNumerator() / addend.getDenominator());  
	sum.setDenominator(lcm);
	sum.reduce();
	
	return sum;
						
  }
  
  
  
  Rational Rational::operator-() const                    					 // returns -(*this)
  {
	return Rational(-1 * this->getNumerator(), this->getDenominator());
  }
  
  
  
  Rational Rational::operator-(const Rational& subtrahend) const					 // returns *this - subtrahend
  {
	//return this->add(subtrahend.additiveInverse());
	//return this->operator+(subtrahend.operator-()); // works
	return *this + -subtrahend;
	
  }
  
  Rational Rational::operator*(const Rational& multiplicand) const				 // returns *this * multiplicand
  {
	  Rational product;					// declare a local rational object


	  product.setNumerator(this->getNumerator() * multiplicand.getNumerator());
	  product.setDenominator(this->getDenominator() * multiplicand.getDenominator());

	  product.reduce();
	  return product;
  }
  
  Rational Rational::operator/(const Rational& divisor) const // returns *this 
  {

	return this->operator*(divisor.multiplicativeInverse());
  }  
  
  bool Rational::operator==(const Rational& rhs) const     // *this == rhs
  {
	return (*this - rhs).getNumerator() == 0;
  }
  
  
  bool Rational::operator!=(const Rational& rhs) const     // *this != rhs
  {
	return !(*this == rhs);
	return *this != rhs;
  }
  
  bool Rational::operator< (const Rational& rhs) const     // *this <  rhs
  {
	if((this->getNumerator() * rhs.getDenominator()) < (rhs.getNumerator() * this->getDenominator()))
	{
		return 1;
	}
	else
	{
		return 0;
	}
  }
  
  
  bool Rational::operator<=(const Rational& rhs) const     // *this <= rhs
  {
	return (*this < rhs || *this == rhs);
  }
  
  bool Rational::operator>(const Rational& rhs) const     // *this >  rhs 
  {
	
	return !(*this < rhs);
  }
  bool Rational::operator>=(const Rational& rhs) const     // *this >= rhs
  {
	return (!(*this < rhs) || *this == rhs);
	  
  }
