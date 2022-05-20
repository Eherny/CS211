#include <iostream>
using namespace std;
int cstr_i(char* cstr);
int main()
{                  ///copied slot's main with modifications
  bool bad;
  int num;
  char choice[10];
  do
     {
       bad = false;
       cout << "Enter an integer number: ";
       cin >> choice; 

      try
        {
          num = cstr_i(choice); 
        }
      catch(string invalid_argument)
        {
          cout<<invalid_argument<<endl;
          bad = true;
        }
     }while(bad == true);


   cout << "After catch" << endl;
   cout << "num = " << num << endl;
  return 0;

}

int cstr_i(char* cstr)
{
  string invalid_argument="Not a integer";
  int num=0;
  
  for(int i=0;cstr[i]!='\0';i++) //goes through each character and sees if they are an integer
    {
      if(cstr[i]>='0'&&cstr[i]<='9') //checks if they are integers
      {
	num=num*10+((cstr[i])-'0'); //adds them to a number using math
      }
    else
      throw invalid_argument; //throws invalid argument
    }
  
  return num; //returns num

}
