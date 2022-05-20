#include <iostream>
using namespace std;

void myStrcpy(char dest[],const char source[]);

int main()
{
  char str1[20]="Hello CS111";
  cout<<str1<<endl;
  myStrcpy(str1,"Oh PHYS302");
  cout<<str1<<endl;
  myStrcpy(str1,"What a great world");
  cout<<str1<<endl;
  return 0;
}
void myStrcpy(char dest[],const char source[])
{
  //intitilaizes a value length at 0 
  int length=0;
  //while the value of the source isnt '\0'
  while(source[length]!='\0')
    {
      //copy each value to the source
      dest[length]=source[length];
      //incriment to next index
      length++;
    }
}
