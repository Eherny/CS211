#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;

template <class T>
class myVector{
 private:
  T* ar;
  int num;
 public:
  myVector();
  ~myVector();
  void push_back(const T& e);
  int size()const;
  T& operator[](int index)const;
  void erase(int index);
  void insert(int index,const T& e);
  
};
//default vector constructior
template <class T>
myVector<T>::myVector()
{
  ar = NULL;
  num = 0;
}
//default construcor, gets called everytime ar is null
template <class T>
myVector <T>::~myVector()
{

  if(ar != NULL)
    delete [] ar;
}
template <class T>
//creats an array thats a and adds it to the end of the vecor
void myVector <T>::push_back(const T& e)
{
  //initialized a dynamic array with 1 more slot
  T* array = new T[num+1];
  //goes through loop
  for(int i=0;i<num;i++)
    {

      *(array+i)= *(ar+i); //copies the array into another array
    }
  *(array+num)=e;//adds e to the end of the array
  if(ar!=NULL)//if array is not null
    {
      delete []ar; //delete array
    }
  ar=array;//points ar to array
  num++;//
}
template <class T>
int myVector<T>::size()const
{
  return num;
}

template <class T>
T& myVector <T>::operator[](int index) const
{
  if(index<num)
    {
      return *(ar+index);
    }
  else
    cout<< "invalid"<<endl;

}
template <class T>
void myVector<T>::erase(int index)
{
  if(index>(num-1))
    {
      cout<<"illegal index"<<endl;
    }
  else
    {
      T* ar2= new T[num];
      for (int i=0;i<index;i++)
	{
	  *(ar2+i)= *(ar+i);
	}
      for(int i=index; i<(num+1);i++)
	{
	  *(ar2+i)= *(ar+(i+1));
	}
      if(ar !=NULL)
	{
	  delete []ar;
	  ar=ar2;
	  num--;
	}
    }

}
template <class T>
void myVector<T>::insert(int index,const T& e)
{
  if (index<0 || index>num)
    {
      cout<<"illegal index"<<endl;
    }
  else
    {
      T* ar2= new T[num+1];
      for (int i=0;i<num;i++)
        {
          *(ar2+i)=*(ar+i);
        }
      num++;
      T temp1=*(ar2+index);
      for(int i=index;i<num;i++)
        {
          T temp2= *(ar2+(i+1));
          *(ar2+(i+1))=temp1;
          temp1=temp2;
        }
      *(ar2 + index)=e;
      if(ar!=NULL)
        {
          delete []ar;
          ar=ar2;
        }
    }
}
#endif
