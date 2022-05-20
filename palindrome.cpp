#include "LL.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isLetter(char c);
char myToLower(char c);
bool palindrome(LL& l);
void createLL(LL& l,string s);
int main()
{
  ifstream fin; //asking for file input to test palindrome
  string filename;

  cout<<"Enter a filename of palindromes you want to test: ";
  cin>>filename;
  fin.open(filename.c_str()); //opening file using c string
  if(!fin) //if file doesnt exist print so
    {
      cout<<"File doesnt exist"<<endl;
    }
  else
    {
      LL l; //creating LL list
      string s; //string s
      while(!fin.eof()) //while not at the end of the file
	{
  	  getline(fin,s); //get input from file and put it to string
	  createLL(l,s); //creats a linked list using string input
	 	 
	  if( palindrome(l)) //if list is a palindrome print out is a palindrome
	    {
	      
	      cout<< s<<" is a palindrome"<<endl;
	    }
	  else //if not a plaindrome print out its not one
	    {
	      cout<< s<<" is not a palindrome"<<endl;
	    }
	}
      
    }
  fin.close(); //close file when done
  return 0;
}
/*////////////////////////////////////////////////////////
createLL takes in a string and creates a linked list using the string
It scans every character of the string, checks if the character is a letter
if its a letter it adds it to the front of the linked list 
s is a string that the user got from a file
l is a linked list to be created using the s string
///////////////////////////////////////////////////////*/
void createLL(LL& l,string s)
{
  while(!l.isEmpty()) //ran into an issue where linked lists werent being reset,and just stacking ontop of eachother.to fix delete front into list is empty
    {
      l.deleteFront();
    }
  for(int i=0;i<s.length();i++) //for the length of the string
    {
      if(isLetter(s[i])) //if index of the string is a letter
	{
	  char newC=myToLower(s[i]); //make it lowercase if not already
	  l.addFront(newC); //add it to the linked list
	}
    }
}
/*/////////////////////////////////////////////////
isLetter is taking in a character to test whether the character is a 
letter of the alphabet or not.Tests for both capital and lowercase letters


char is a character the user is checking to see if its a letter
///////////////////////////////////////////////////*/
bool isLetter(char ch)
{
  if((ch>= 'a'&&ch<='z')||(ch>='A'&&ch<='Z')) //if character is A-Z or a-z
    return true; //return true
  else 
    return false;//if not a letter return false
  
}

/*///////////////////////////////////////////////////////////////
myToLower takes in a character and checks if its a capital letter or not
if its a capital letter it converts it into the lowercase form and returns it.

c is a character the user is testing for lowercase and capital
//////////////////////////////////////////////////////////////*/
char myToLower(char c) 
{
  if(c >='A' && c <='Z') //if a character is an capital letter
    c=c +('a'-'A'); //convert it into a lowercase letter
  return c; //return the c
  
}
/*//////////////////////////////////////////////////////////////
palindroom takes in a linked list and tests if a the list its carrying 
is a palindrome or not

l is a linked list its taking in to test for a palindrome
////////////////////////////////////////////////////////////*/
bool palindrome(LL& l)
{
  while(!l.isEmpty()) //while the list is not empty
    {
      char front=l.deleteFront(); //set front = to the front of the list
      char rear=front; //set rear = to front so that if an odd number of letters, it will still pass
      if(!l.isEmpty()) //check if list is not empty
	{
	  rear=l.deleteRear(); //make rear equal to the rear of the list
	}
      if(front!=rear) //if front does not equal rear get out of while loop and return false
	return false;
    }
  return true; //if the while loop completes everything return true
}
