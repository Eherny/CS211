#include "lqueue.h"
#include <iostream>
#include <string>
using namespace std;

LQueue::LQueue(){ //default constructor
  front=NULL;  //front used for front of queue
  rear=NULL; //rear is to used for rear of queue
  count=0;
  //all are checks to see if queue is empty

}

LQueue::~LQueue(){ //destructor destroys when lqueue goes past scope

  while(!isEmpty()) //checks to see if queue is empty, if not deletes front obj
                    //until it is
    {

      deleteFront();
    }

}
/*//////////////////////////////////////////////////////
Add rear will take an element and add the it to the linked queue
is queue is empty it creates a new node and sets it as front
if it is not empty it creates a new node and sets it to rear 
/////////////////////////////////////////////////////*/
void LQueue::addRear(el_t el){  

  if(isEmpty()) //if queue is empty
    {

      front=rear=new node; // front=rear set to new node
      front->elem=el;     //front equals the element
    }
  else
    {
      rear->next=new node; //if atleast one element set rear to the next 
      rear=rear->next;   //make rear point to next node
      rear->elem=el;  //puts element into the rear
      rear->next=NULL;  //makes next = to NULL
    }
  count++; //increases count when object is added
}
/*/////////////////////////////////////////////
delete front takes deletes the front object of the queue and passes the deleted
object into the main.

////////////////////////////////////////////*/
el_t LQueue::deleteFront()
{
  if(isEmpty()) //checks to see if queue is empty
    {
      queueError("The queue is empty,cannot delete anything"); //passes queueError function
      return -1; //returns -1 since its an error    
    }
  else if(count==1)  //if element has exactly one element in it
    {
      el_t element= front->elem;  //sets element equal to the front object
      delete front;  //deletes the front node
      front=rear=NULL;  //sets front and rear equal to NULL
      count--;     // decrements the count
      return element; //returns the element to the main
    }
 else
   {   //if lq has more than one element
     node* next=front->next;   //creates a new node called next and points it
                               //to next
     el_t element=front->elem;   //sets element equal to the front element
     delete front;  //deletes front
     front=next;  //sets front = to next
     count--; //decrements count
     return element; //returns the element
  }



}
/*///////////////////////////////////////////////
bool isempty is a bool function that checks if the lqueue is empty

/////////////////////////////////////////////*/
bool LQueue::isEmpty()  
{
  if(front==NULL&&rear==NULL&&count==0)  //checks everythign to see if its empty
    {
      return true; //if all conditons met reutnr true
    }
  else 
    return false; //return false if not empty


}
/*///////////////////////////////////////////////////
displayAll will output the elements inside the lqueue
/////////////////////////////////////////*///////////
void LQueue::displayAll()
{

  if(isEmpty()) //checks to see if its empty
    {
      cout<<"empty"<<endl; //count the object is empty
    }
  else
    {
      node* p;  //creats a node object p
      p=front; //points p to front
      while(p!=NULL)  //when p element is not null
	{
	  cout << p->elem<<"";  //cout the element
	  p=p->next;  //point p to next element
	}
    }
  
}

void LQueue::printAllReverse()
{
  printAllReverse(front);      //prints front element calling printAllreverse
}
void LQueue::printAllReverse(node* p)  //prints lqueue elements in reverse
                                       //by using recursion
{
  if(p==NULL) //if p is NUll stop
    return;
  else
    {
      printAllReverse(p->next); //call function but switch it to next element
      cout<< p->elem;  //cout the element
    }

}

/*//////////////////////////////////////////////////
queue error gets called to display an error message
///////////////////////////////////////////////////*/
void LQueue::queueError(string msg)
{
  cout<< "msg"<<endl;
}
