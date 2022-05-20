#include <iostream>
#include <iomanip>
using namespace std;

bool isPrime(int numb)
{
  for(int n=2;n<= numb/2;n++)
    {
      if(numb % n==0)
	return false;
    }
  return true;
}


int main()
{

  int num = 0;

  for(int i =2; i<=1000;i++)
    {
      if(isPrime(i) == true)

	{
	  cout<<setw(5)<< i;  
	  num++;
	  if(num % 10 == 0)
	    cout << endl;

	}
    }
  cout << "\n\n There are " << num << " prime numbers between 2 and 1000" << endl;

return 0;



  }
