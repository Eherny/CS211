#include "lqueue.h"
#include <iostream>
#include <string>
using namespace std;
void createReverseLL(LQueue& ll,const string&s);
void addLLs(LQueue& lq,LQueue& lq2,LQueue& sum);
int main()
{
  string n1,n2; //declaring to strings
  cout<<"Enter a number: ";
  cin>>n1; //user input
  cout<<"Enter a second number: ";
  cin>>n2; //user input
  LQueue l1;  //creating 3 LQueue objects
  LQueue l2;
  LQueue total;
  createReverseLL(l1,n1); //turns user input string into a reverse linked queue
  createReverseLL(l2,n2);
  l1.displayAll(); //showing reverse addition
  cout<< "+";
  l2.displayAll();
  cout<<"=";
  addLLs(l1,l2,total);
  total.displayAll();  //displaying answer in reverse order
  cout<<endl;
  cout<<n1<<"+"<<n2<<"=";
  total.printAllReverse(); //showing answer in correct order
  cout<<endl;
    return 0;
}
/*/////////////////////////////////////
Turns a string into a and linked queue object in reverse order
LQ a linked queue object
s: is a string object

/////////////////////////////////////////*/
void createReverseLL(LQueue& lq,const string& s) 
{
  for(int i=s.size()-1;i>=0;i--)
    {
      int num = (int)s[i] - '0';
      lq.addRear(num);
    }

}
/*/////////////////////////////////////
addLLs function takes two linked queue objects and adds the elements they
contrain and adds them to a third linked queue object.
n1=number one
n2= number two
carry= is to carry the number to add to the sum when the previous sum is 
greater than 10
sum= is the sum of adding n1 and n2 and the carry
/////////////////////////////////////*/
void addLLs(LQueue& lq,LQueue& lq2,LQueue& total)
{//variables
  int n1; 
  int n2;
  int carry=0;
  int sum;

  while(!lq.isEmpty() || !lq2.isEmpty())//keeps adding until one queue is empty
   {
     if(lq.isEmpty()) //if first lq is empty turn n1 into 0
       {
	 n1=0;
       }
     else
       {
	 n1= lq.deleteFront(); //if not empty delete the front object of the lq
       }
     if(lq2.isEmpty()) //if second lq is empty turn n2 into 0
       {
	 n2=0;
       }
     else
	{
	  n2=lq2.deleteFront();  //if not empty delete front and pass it to n2
	}
     sum =  carry + n1+ n2;  //adds both numbers plus the carry over to sum
     
     if (sum>=10) //if sum is greater than or equal to 10
       {
	 sum= sum %10; // takes the remainer and and passes it to sum
	 carry=1;      //sets carry equal to 1
	 
       }
     else
       carry=0;   //if not greater than 10 carry remains 0
     
     total.addRear(sum);  //adds the sum to the rear of linked queue of total
     
   } //end of while loop
  //if carry at the end of the while loop is greater than 0 add the carry to total
 if(carry>0)    
   total.addRear(carry);
 
}
