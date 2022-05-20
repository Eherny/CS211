
 /******************File Edit Options Buffers Tools C Help
/*****************************************************
File Edit Options Buffers Tools C Help
/*****************************************************
***********************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name:
*****************************************************/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
//       fill
template <class T>
void fill(T ar[], int n)
{
  for(int i =0;i < n; ++i)
    {
      cout << "Enter an item: ";
      cin >> ar[i];
    }
}




/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
       //         print

template <class T>

void print(const T ar[],int n)
{
  for(int i =0 ; i < n;i++)
    cout << ar[i] << " ";
}


/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
       //       getHighest
template <class T>
int getHighest(const T ar[],int  n){

  int hi= 0;

  for(int i=1; i<n;i++)
    {
      if(ar[i]>ar[hi])
	hi=i;
     
	}
  return hi;
}




/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
       //       getLowest
template <class T>

  int getLowest(const T ar[],int n)
  {
    int minIndx = 0;
    for(int i=1;i < n;i++)
      {
	if(ar[i] < ar[minIndx])
	  minIndx=i;
      }
    
    return minIndx;

  }




/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
       //       getAvg
template <class T>

double  getAvg( T ar[], int n){
  double  avg=0.0;
  double  sum = 0.0;
  for(int x=0; x< n;x++)
    {
      sum += ar[x];
      
 
   }
  avg=sum/n;
  return avg;
}
      
      


/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template <class T>
int unique( T ar[],T uniqAr[], int n){
  //initializing number of unique values found so far to 0
  int countUnique=0;
  //looping from 0 to n-1
  for(int i=0;i<n;i++){
    //fetching value at index i from ar
    int value=ar[i];
    //checking if this value exist on uniqArr
    bool found=false; //initially assuming value is not present
    //looping through uniqAr from index 0 to countUnique-1
    for(int j=0;j<countUnique;j++){
      if(uniqAr[j]==value){
	//found. setting found to true and exiting inner loop
	found=true; 
	break;
      }
    }
    //if found is false,
    if(!found){
      //then adding value to uniqAr at index = countUnique
      uniqAr[countUnique]=value;
      //and incrementng countUnique
      countUnique++;
    }
  }
  //finally returning number of values in uniqAr
  return countUnique;
}
   
//uniqAr in the caller will be filled with only unique numbers
  

  // *///



/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>

void sort(T array[], int N)
{
   int lrgIndx; //the index of the largest value                                                                                               
   T temp; //temporary variable that holds the largest value                                                                                  

   //last is the last index in unsorted portion                                                                                                 
     for(int last = N-1; last >= 1; last--)
     {
     lrgIndx = 0; //assume the first item is the largest                                                                                      
     //find the largest in unsorted portion ([0..last])                                                                                       
    for(int i = 1; i <= last; i++)
    {
             if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
		          lrgIndx = i;
    }

    //  swap the largest with the last item in the unsorted portion                                                                            
     temp = array[lrgIndx];
     array[lrgIndx] = array[last];
     array[last] = temp;
    }
    }
//////////////////////////////////////
//This is a bubble sort function,its purpose is to take any
//array a return it in descending order//
//////////////////////////////////////

template<class T>
// perform bubble sort
void bubbleSort(T ar[],int n)
{
  bool done=false;
  int i;

  while(!done)
    {
      done = true;     
      for(i=0; i<n-1;i++)// loop to see the array
	{
	  if(ar[i]<ar[i+1])// loop to compare two elements
	    { // sorts in descending order,would be ascending if < was >
	     T swap=ar[i]; //swap is a placeholder, use T to be able to find 
	     // correct return type.
	      ar[i]=ar[i+1]; // swaps if not in the correct order.
	      ar[i+1]=swap;
	      done=false;
	    }
	}
      n--;      
    }
}
template <class T1,class T2>
int find(const T1 array[] ,int size,const  T2& key){
  for(int i=0;i<size;i++){
    if(array[i]==key)
      return i;
    
  }
  return -1;
}

template <class T1,class T2>
bool remove(  T1 array[],int& size , T2 key ){
  int index=find(array,size,key);
  if(index==-1)
 return false;

  for(int i=index;i<size-1;i++){
    array[i]=array[i+1];
  }
  size--;
  return true;
}

#endif
