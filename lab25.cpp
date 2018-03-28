//Matthew Howard
//Lab 25
//CS 2315

#include <lab25.h>

  template<class T>  
  Accumulator<T>::Accumulator(const T& value)   // constructor
  {
	  total = value; 
  }
  
  //getTotal
  template<typename T> T Accumulator<T>::getTotal() const                   // return total
  {
	  return total;
  }
  
  template<typename T>
  void Accumulator<T>::addValue(const T& value)        // add (+) value to total
  {
	 total += value;
  }
