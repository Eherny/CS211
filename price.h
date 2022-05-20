#ifndef PRICE_H
#define PRICE_H

#include <iostream>
using namespace std;

//Class Price
class Price
{
 private: //private data members
  friend ostream& operator<<(ostream& out,const Price& px);
  int dollar;
  int cent;

 public:
  //constructors
  Price();
  Price(int, int); 

  ///operator overloading functions
  Price operator+(const Price&);
  Price operator-( const Price&);
  
 
};

#endif
