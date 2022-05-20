#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;

const int MAX=30;
typedef char  el_t;
//Class stack
class Stack{

private://private data members
  el_t el[MAX];
  int top;
  void stackError(string errorMsg)const;

 public:

  Stack(); //constructors
  bool isEmpty()const;
  bool isFull()const;
  void push(el_t e);
  el_t pop();
  el_t topElem()const;
  void displayAll(el_t e)const;
  void clearit(el_t e);
  int getSize();

};



#endif
