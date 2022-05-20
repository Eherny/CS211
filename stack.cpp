#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
//makes default empty stack
Stack::Stack()
{

  top=-1;

}
//checks a function is empty 
bool Stack::isEmpty()const
{
  return (top==-1)?true:false;
}
//checks the function is full
bool Stack::isFull()const
{
  return (top==MAX-1)?true:false;

}
//adds a character to the stack
void Stack::push(el_t e)
{
  if(isFull())
    stackError("stack overflow");
  else
    {
     el[++top]=e;
    }

}
//returns the top element and deincraments the array
el_t Stack::pop()
{
  if(isEmpty())
    stackError("stack underflow");

  else 
    return el[top--];


}
//function takes the top element and displays it
el_t Stack::topElem()const
{
  if (isEmpty())
    {
      stackError("Empty");
    }
  else
    {
      return el[top];
    }



}
//displays the whole stack starting from the top to bottom
void Stack::displayAll(el_t e)const
{
  if(isEmpty())
    {
      stackError("empty");
    }
  else{
    for(int i=top; i>=0;i--)
      {
	cout <<el[i]<<endl;
      }
  }
}
// stack error message
void Stack::stackError(string msg)const
{
  cout << msg<<endl;
  exit(1);
  
}
//clears the stack
void  Stack::clearit(el_t e)
{
  top=-1;


}
//gets the size of the stack
int Stack::getSize()
{
  return top+1;
}
