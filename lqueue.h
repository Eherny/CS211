#ifndef LQUEUE_H
#define LQUEUE_H
#include <string>
using namespace std;
typedef int el_t;

struct node{//struct node

  el_t elem; // includes an element el
  node* next;// includes a node next


};

class LQueue{
private:// private data members
node* front;
node* rear;
int count;
void queueError(string msg);
 void printAllReverse(node*);
public:// public  functions
LQueue();
~LQueue();
void addRear(el_t el);
el_t deleteFront();
bool isEmpty();
void displayAll();
void printAllReverse();

};

#endif
