/***************************************************************************
CS211
Template prepared by Kazumi Slott 
Your name:

Program description: program will take any number between a threshold,and a base between 2,8,16 and convert the number to a character and push it to a stack.Then calls a recursive way to convert

***************************************************************************/
#include <iostream>
using namespace std;
#include "stack.h"
#include "/cs/slott/cs211/checkInput.h"
int getBase();
char convertToChar(int n);
void convertRec(int n,int b);
void convertStack(int n,int b);

int main()
{
  int dec;
  int base;

  cout << "Enter a number in base 10: ";

  //get a decimal number by calling getData in checkInput.h. Accept a numer 
  //between 1 and 999999.
  dec=getData(1,999999,"Enter a number between 1 and 999999. Enter again:");

  //get a base (2, 8 or 16) by calling getBase
  cout<<"Enter a base you want to convert to"<<endl;
  base=getBase();

  cout << "----------- Using recursion ---------------" << endl;
  //call convertRec to show the number in the base number system of the user’s choice
  convertRec(dec,base);

  cout << endl;

  cout << "----------- Using a stack ---------------" << endl;
  //Call convertStack to show the number in the base number system of the user’s choice

  convertStack(dec,base);
  cout << endl;
  return 0;
}

/****************************************************************************
This function asks for a number system to which a decimal number is converted, either 2, 8 or 16.
It rejects bad inputs other than 2, 8 or 16.
It returns either 2, 8 or 16
****************************************************************************/
int getBase()
{
  int b=0;//initialize b for base
  cin>>b;//get user input for a bse
  if(b==2||b==8||b==16)//accept only 2,8,16
    {
      return b;//return it 
    }
  else
    {
      cout<<b<<" is invalid. Enter 2, 8 or 16 only"<<endl;//cout invalid
      return getBase();//try again to get base
    }
}
/****************************************************************************
This function receives an integer between 0 and 15 and returns the character.
If n = 0 .. 9, it returns '0' .. '9'
If n = 10 .. 15, returns 'A' .. 'F'

n is an integer between 0 and 15
****************************************************************************/
char convertToChar(int n)
{
  if(n>=0&&n<=9)//when n is zero to 9
    {
      return ((char)n+'0');//convert number to a character
    }
  
  else if(n>=10 &&n<=15)//when n is 10 through 15
    return ((n-10)+'A'); //cout number to A,B,C,D,E,F
}
/***************************************************************************
This is a <<recursive>> function to convert a decimal number to a different number system and print it.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
***************************************************************************/
void convertRec(int n, int b)
{
  if(n==0)//while n is zero end reccursion
    return;
  else
    {
      convertRec(n/b,b);//call recursion function
      cout<<convertToChar(n%b);//cout number % base
    }   
}

/**************************************************************************
This function uses a stack to convert a decimal number to a different number system and prints it.
This is not a recursive function.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
**************************************************************************/
void convertStack(int n, int b)
{
  Stack s;
  while(n!=0&&!s.isFull())//checks if number n is not zero and if stack is not full
    {
      s.push(convertToChar(n%b));//pushs the character conversion onto stack 
      n/=b;//divdes number by base
    }
  while(!s.isEmpty())//while stack is not empty
    {
      cout<<s.pop();//pop all the numbers to display
    }
  cout<<endl;//end line
}
