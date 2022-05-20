#include "LL.h"
#include <iostream>
#include <string>
using namespace std;

LL::LL(){ //default constructor
  front=NULL;  //front used for front of queue
  rear=NULL; //rear is to used for rear of queue
  count=0;
  //all are checks to see if queue is empty

}

LL::~LL(){ //destructor destroys when lqueue goes past scope

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
void LL::addRear(el_t el){  

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
void LL::addFront(el_t el)
{
  if(isEmpty())
    {
      front= rear=new node;
      rear->elem=el;
      rear->next=NULL;
    }
  else
    {
      node* p= new node;
      p->elem=el;
      p->next=front;
      front=p;
    }
  count++;


}
/*/////////////////////////////////////////////
delete front takes deletes the front object of the queue and passes the deleted
object into the main.

////////////////////////////////////////////*/
el_t LL::deleteFront()
{
  if(isEmpty()) //checks to see if queue is empty
    {
      LLError("The queue is empty,cannot delete anything"); //passes queueError function
       //returns -1 since its an error    
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
     node* newf=front->next;   //creates a new node called next and points it
                               //to next
     el_t element=front->elem;   //sets element equal to the front element
     delete front;  //deletes front
     front=newf;  //sets front = to next
     count--; //decrements count
     return element; //returns the element
  }



}
/*//////////////////////////////////
deleteRear is a linked list function that deletes the rear node of
the linked list and returns the value of the deleted linked list

/////////////////////////////////*/
el_t LL::deleteRear()
{
  if(isEmpty()) //if ll is empty and attempting to delete a list
    {
      LLError("Error list is empty"); //display LL
    }
  else if(count==1&&front==rear) //if count is atleast 1 and front and rear are qual
    {
      el_t old= rear->elem; //capture the rear element
      delete rear; //delete rear
      front=rear=NULL; //make front and rear= to null
      count--; //minus count
      return old; //return deleted element
    }
  else //of ll has more than 1 node
    {
      node* p=new node; //create a new node
      el_t old=rear->elem; //capture old element
      for(p=front;p->next !=rear;p=p->next);//search for the second toe last element
      delete rear; //delete the rear
      rear=p; //make rear point to the same number as p
      rear->next=NULL; //put next node = to NULL
      count--; //MINUS count
      return old; //return deleted element
    }
}
/*///////////////////////////////////////////////
bool isempty is a bool function that checks if the lqueue is empty

/////////////////////////////////////////////*/
bool LL::isEmpty()const  
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
void LL::displayAll()const
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
	  cout << p->elem<<" ";  //cout the element
	  p=p->next;  //point p to next element
	}
    }
  
}
/*//////////////////////////////////////////
LL is a copy function which takes in a LL it wants to copy and copys it into a 
new linked list
source is a linked list to be copied
///////////////////////////////////////////*/
LL::LL(const LL& source)
{
  front=this->rear=NULL;  //make front and rear = to null
  this->count=0; //make count = to 0
  node* p=source.front; //make a new node called p and make it equal to sources front elemnet
  while(p!=NULL) //while p is not NULL
    {
      this->addRear(p->elem); //add p to the rear of the new linked list
      p=p->next; //make p equal to next number
    }


}
void LL::printAllReverse()
{
  printAllReverse(front);      //prints front element calling printAllreverse
}
void LL::printAllReverse(node* p)  //prints lqueue elements in reverse
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

void LL::deleteNode(el_t e)
{
  node* pre;
  node* del;
  if(isEmpty())//if its empty do nothing
    return;
  else
    //filter through the linked list
    for(pre=front,del=front->next;del!=NULL && del->elem !=e; pre=del,del=del->next);
  //if the node is not NULL
  if(del!=NULL)
    {
      pre->next=pre->next->next;//advance the pre node over      
      delete del;//delete del
      del->next=del->next;//move the del over
      count--; //decriment the count
    }
  else if(pre==front||front->elem==e)//if the first node is the element
    { 
      deleteFront(); //delete the front

    }
  else
    {
      return;
    }



}
bool LL::search(el_t e)
{
  node* temp=front; //make a node = to the front
  while(temp!=NULL) //while the node is not NULL
    {
      if(temp->elem==e) //if the node is equal to the element return true
	return true;
      temp=temp->next; //advance the next node
    }
  return false;
    
}
void LL::addInOrderAscend(el_t e)
{
  node* p=front;
  if(front==NULL && rear ==NULL)
    {
      //if there are no nodes in the linked list add first object to the front
      addFront(e);
    }
  else
    {
      if(e<front->elem) //if the element is less than the front
	{
	  addFront(e); // add it to the front
     
  }
      else if(e>rear->elem)//if the element is greater than the rear
	{
	  addRear(e); //add it to the rear
	}
      else
	{//to sort it in the middle of the linked list
	  node* newNode=new node; //create a new node
	  newNode->elem=e;// put the element in the new node
	  while(p->next!=NULL&& p->next->elem<e)//search where it should fit
	    {
	      p=p->next;//advance to the next object
	    }
	  newNode->next=p->next;
	  p->next=newNode;
	  count++;//incriment the count
	}
    }

}
void LL::deleteNodes(el_t e)
{
  node* pre=NULL;
  node* del=front;
         
    
  while(del)
    {
      if(del->elem==e)
	{
	  node* temp=del->next;
	  if(pre)
	    {
	      pre->next=temp;
	    }
	  if(del==front)
	    {
	      front=temp;
	    }
	  if(del==rear)
	    rear=pre;
    
	  delete del;
	  del=temp;
	  count--;
	}
      else
	{
	pre=del;
      del=del->next;
	}
    }
  
  
  
}
void LL::addInOrderDescend(el_t e)
{
  node* p=front;
  if(front==NULL && rear ==NULL)
    {
      addFront(e);
      // front=rear=new node;
      //  front->elem=e;
    // count++;
    }
  else
    {
      if(e>front->elem)
        {
	  addFront( e);
	  //  node* newFront=new node;
	  //  newFront->elem=e;
	  // newFront->next=front;
	  //  front=newFront;
	  //   count++;
	}
      else if(e<rear->elem)
        {
	  addRear(e);
	  //          rear->next=new node;
	  // rear=rear->next;
	  //  rear->elem=e;
	  //  rear->next=NULL;
	  // count++;
        }
      else
        {
          node* newNode=new node;
          newNode->elem=e;
          while(p->next!=NULL&& p->next->elem>e)
            {
              p=p->next;
            }
          newNode->next=p->next;
          p->next=newNode;
	  count++;
        }
    }

}

/*//////////////////////////////////////////////////
//queue error gets called to display an error message
///////////////////////////////////////////////////*/
void LL::LLError(string msg)
{
  cout<< msg<<endl;
}
