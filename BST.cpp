#include <iostream>
#include <cstdlib> //for rand()
#include <fstream>
using namespace std;

typedef int el_t;

class Node
{
  friend class BST;
private:
  el_t elem;
  Node* right;
  Node* left;
public:
  Node(el_t e){elem=e; right=NULL; left=NULL;}; //implement the constructor inside the class definition
};

class BST
{
private:
  Node* root;
  void destroy(Node* p);
  void insertNode(Node*&, el_t);
  void  inOrderPrint(Node* p);
  void  preOrderPrint(Node* p);
  void postOrderPrint(Node* p);
  int getNumNodes(Node* p);
  int getMaxLength(Node* p);
  bool searchRec(Node* p, el_t e);
  int getNumNodesBetween(Node* p,el_t min,el_t max);
 void printNodesBetween(Node* p,el_t min,el_t max);
public:
  BST();
  ~BST();
  void insertNode(el_t);
  bool search(el_t e);
  void  inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  int getNumNodes();
  bool searchRec(el_t e);
  int getMaxLength();
  int getNumNodesBetween(el_t min,el_t max);
  void printNodesBetween(el_t min, el_t max);
};

BST::BST()
{
  root = NULL;
}
BST::~BST()
{
  destroy(root);
  cout<<endl;
}
void BST::destroy(Node* p)
{
  if(p==NULL)
    return;
  destroy(p->left);
  destroy(p->right);
  //  cout<<p->elem<<"-->";
  delete p;
}
void BST::inOrderPrint()
{
  inOrderPrint(root);
}
void BST::inOrderPrint(Node* p)
{
  if(p==NULL)
    return;
  inOrderPrint(p->left);
  cout<<p->elem<<"-->";
  inOrderPrint(p->right);
}
void BST::preOrderPrint()
{
  preOrderPrint(root);
}
void BST::preOrderPrint(Node* p)
{
  if(p==NULL)
    return;
  cout<<p->elem<<"-->";
  preOrderPrint(p->left);
  preOrderPrint(p->right);
}
void BST::postOrderPrint()
{
  postOrderPrint(root);
    }
void BST::postOrderPrint(Node* p)
{
  if(p==NULL)
    return;
  postOrderPrint(p->left);
  postOrderPrint(p->right);
  cout<<p->elem<<"-->";
}
int BST::getNumNodes()
{
  return getNumNodes(root);
}
int BST::getNumNodes(Node* p)
{
  if(p=NULL)
    return 0;
  else
    return getNumNodes(p->left)+ getNumNodes(p->right)+1;
}
void BST::insertNode(el_t e)
{
  insertNode(root, e);
}
int BST::getMaxLength()
{
  return getMaxLength(root);
}
int BST::getMaxLength(Node* p)
{
  if(p==NULL)
    return 0;
  else
    {
      int num,num2;
      num=getMaxLength(p->left)+1;
      num2=getMaxLength(p->right)+1;
      if(num>=num2)
	return num;
      else if(num2>num)
	return num2;
    }
}
bool BST::searchRec(el_t e)
{
  return searchRec(root,e);
}
bool BST::searchRec(Node* p,el_t e)
{
  if(p==NULL)
    {
      return false;
    }
  else
    {
      if(p->elem==e)
	return true;
      else if(e<p->elem)
	searchRec(p->left,e);
      else if(e>p->elem)
	searchRec(p->right,e);
    }
}
void BST::insertNode(Node*& p, el_t e)
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}
void BST::printNodesBetween(el_t min,el_t max)
{
  return printNodesBetween(root,min,max);
} 
void BST::printNodesBetween(Node* p,el_t min,el_t max)
{
  if(p==NULL)
    return;
  printNodesBetween(p->left,min,max);
    if(p->elem>min&&p->elem<max)
      cout<<p->elem<<"-->";
  printNodesBetween(p->right,min,max);
}
int BST::getNumNodesBetween(el_t min,el_t max)
{
  return getNumNodesBetween(root,min,max);
}
int BST::getNumNodesBetween(Node* p,el_t min,el_t max)
{
  if(p==NULL)
    return 0;
  else if(p->elem>min&&p->elem<max)
    return 1+ getNumNodesBetween(p->left,min,max)+getNumNodesBetween(p->right,min,max);
  else
    return getNumNodesBetween(p->left,min,max)+getNumNodesBetween(p->right,min,max);
}
bool BST::search(el_t e)
{
  //Don't use recursion. Use a loop.
  //You want to know how many times it loops to find e.
  //declare a counter. 
  Node* temp=root;
  int count=0;
  while(temp!=NULL)
    {
      count++;
      if(temp->elem==e)
	{
	  cout<<count<<"Nodes checked\nfound"<<endl;
	  return true;
	}
      else if(e<temp->elem)
	temp=temp->left;
      else if(temp->elem<e)
	temp=temp->right;
    }
  cout<<count<<"nodes checked\nNot found"<<endl;
  return false;



  //display the counter
}

int main()
{
  BST b;
  ifstream fin;
  fin.open("bst.dat");
  int min,max,value;
  cout<<"Enter min: ";
  cin>>min;
  cout<<"Enter max: ";
  cin>>max;
  if(!fin)
    cout<<"file cannot be recognized"<<endl;
  else
    {
      fin>>value;
      while(fin)
	{
	  b.insertNode(value);
	  fin>>value;
	}
      cout<<"The number of nodes between " <<min<<"and" << "is"<<b.getNumNodesBetween(min,max)<<endl<<endl;
      b.printNodesBetween(min,max);
    }
  fin.close();



  /*
  srand(time(0)); //you need to include cstdlib
  BST b;
  b.insertNode(5);
 b.insertNode(8);
 b.insertNode(3);
 b.insertNode(9);
 b.insertNode(6);
 b.insertNode(1);
 b.insertNode(0);
 b.insertNode(4);
 b.insertNode(7);
 b.insertNode(20);
 b.insertNode(21);
 cout<<  b.getMaxLength()<<endl;
 cout<<  b.searchRec(6)<<endl;
 cout<<b.searchRec(69)<<endl;

 /*
    cout << "---- Print all elements using the in-order traversal -----" << endl;
    b.inOrderPrint();
    cout<<endl;
  cout << "---- Print all elements using the pre-order traversal -----" << endl;
    b.preOrderPrint();
    cout<<endl;
  cout << "---- Print all elements using the post-order traversal -----" << endl;
  b.postOrderPrint();
  cout<<endl;
  cout << "\n--- destructor gets called when b goes out of scope here ---" << endl;
  /////////////////////////////
  /*
 LL l;
 BST b;
  for(int i=0;i<10000;i++)
    {
int random=rand()%10000+1;
      b.insertNode(random);
      l.addRear(random);
    }

  int key;
  cout << "What number do you want to search for? ";
  cin >> key;
 

  cout << "BST *************************" << endl;
 
  b.search(key);

  cout << "LL************************" << endl;
  
  l.search(key);
  */

  return 0;
}
