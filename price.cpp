#include "price.h"
#include <iostream>
using namespace std;

//default constructor
Price ::Price()
{
  dollar=0;
  cent=0;
}

//Constructor with arguments
Price ::Price(int d, int c)
{
  this->dollar = d;
  this->cent = c;
}

//overloading plus operator '+'
//returns an object of type Price
Price Price::operator+(const Price& Px)
{
  int centSum = Px.cent + this->cent; //find the sum of cents
  int carry = centSum / 100;          //find the carry to bet generated
  int newCent = centSum % 100;        //find the value of cent that actually
  //create a new price object
  Price newObj;
  newObj.cent = newCent;                              //set the cent of it
  newObj.dollar = (this->dollar + carry + Px.dollar); //set the dollar

  return newObj; //return the newly created object
}

//overloading minus operator '-'
//returns an object of type Price
Price Price::operator-(const Price& Px)
{
  Price newObj;
  //subtract the dollar and cent
  newObj.cent = this->cent - Px.cent;
  newObj.dollar = this->dollar - Px.dollar;

  //If cent is negative adjust it by adding 100
  if (newObj.cent < 0)
    {
      newObj.cent = 100 + newObj.cent;
      newObj.dollar--;
    }
  //return the newly created object
  return newObj;
}


//overloading insertion operator <<
ostream&  operator<<(ostream& out,const Price& Px)
{
  //print the price
  out << Px.dollar << ".";
  if (Px.cent < 10)
    {
      out << "0";
    }
  out << Px.cent;
  return out;
}
