/********************************************************
CS111 Lab on c-strings
Template prepared by Kazumi Slott
********************************************************/
#include <iostream>
using namespace std;
//prototype
void myStrcat(char dest[], const char source[]);

int main()
{
  char str2[80] = "Dave ";
   myStrcat(str2, "Smith");
  cout << str2 << endl; //Dave Smith

  return 0;
}

void myStrcat(char dest[], const char source[])
{

  int d;
  int i;
  //Move d to the end of dest ('\0')
  for(d=0;dest[d]!='\0';d++)
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
