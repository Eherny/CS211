#ifndef LL_H
#define LL_H
#include <string>
using namespace std;
typedef string el_t;

struct node{//struct node

  el_t elem; // includes an element el
  node* next;// includes a node next


};

class LL{
private:// private data members
  node* front;
  node* rear;
  int count;
  void LLError(string msg);
  void printAllReverse(node*);
 public:// public  functions
  LL();
  ~LL();
  void addFront(el_t el);
  void addRear(el_t el);
  el_t deleteFront();
  el_t deleteRear();
  bool isEmpty()const;
  void displayAll()const;
  LL(const LL& source);
  void printAllReverse();
  void deleteNode(el_t);
  bool search(el_t e);
  void addInOrderAscend(el_t e);
  void deleteNodes(el_t);
  void addInOrderDescend(el_t e);    
};

#endif
