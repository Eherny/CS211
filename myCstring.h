#ifndef MYCSTRING_H
#define MYCSTRING_H
#include <iostream>
using namespace std;

int myStrcmp(const char* cstr1, const char* cstr2)
{
  for(int i = 0; cstr1[i] != '\0' || cstr2[i] != '\0'; i++)//while the words are not null
    {
      if(cstr1[i] != cstr2[i]) //first word does not equal second
	return cstr1[i] - cstr2[i]; //return first word minus second word
    }
  return 0;//if they both match return 0
}  

int myStrlen(const char* cstr)
{
  //Get the length of cstr
  int i; //i is used after the for loop
  for(i = 0; cstr[i] != '\0'; i++)//goes to the end of word
    ;
  return i;//enter the count
}
void myStrcat(char* dest, const char* source)
{

  int d;
  int i;
  //Move d to the end of dest ('\0')
  for(d=0;dest[d]!='\0';d++) //go to the end of the destingation
    {
    }
  //copy each character from source to dest
  for(i=0;source[i]!='\0';i++,d++)
    {
      dest[d]=source[i];
    }


  //place '\0' at the end of dest
  dest[d]='\0';
}

void myStrcpy(char* dest,const char* source)
{
  //intitilaizes a value length at 0
  int length=0;
  //while the value of the source isnt '\0'
  for(length=0;source[length]!='\0';length++)
    {
      dest[length]=source[length]; //copy each word
    }
  dest[length]='\0'; //place the null operator at end
}



int binarySearch(const char **badAr,int start, int end,char* s)
{
  int mid;
  while(start<=end)//while start does not equal end
    {
      mid=start+(end-start)+1/2; //mid is calculated
      if(myStrcmp(badAr[mid],s)==0)//compare key with bardar
	return mid;//return mid value
      if(myStrcmp(badAr[mid],s)<0){ //compare the two words
	start=mid+1; //change the start value
      }
      else
	{
	  end=mid-1; //change end value
	}
    }
  return -1; //if not return -1
} 
 
#endif
