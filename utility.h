#ifndef UTILITY_H
#define UTILITY_H
#include <string>
using namespace std;
/*//////////////////////////////////////////
this is a tool to see if a character in a string 
is a letter or not
////////////////////////////////////////*/
bool isLetter(char ch)
{
  if((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z'))
    return true;
  else
    return false;
}
/*//////////////////////////////////////////////
this is a tool in order to take a capital letter and 
turn it into a lowercase letter
//////////////////////////////////////////////*/
char myToLower(char ch)
{
  if(ch>='A'&& ch<='Z')
    ch=ch+('a'-'A');
  return ch;
}
/*////////////////////////////////////////////////////////////
this is a tool in order to take a string and make sure all letters
are lowercase and return back the string
///////////////////////////////////////////////////////////*/
string stripStr(string wd)
{
  string w;
  for(int i=0;i<wd.length();i++)
    {
      if(isLetter(wd[i]))
	w+=myToLower(wd[i]);
    }
  return w;
}
/*////////////////////////////////////////////////////////
This is a tool that takes a lowercase letter and turns it into
a capital letter
///////////////////////////////////////////////////////*/
char toMyUpper(char ch)
{
  if(ch>='a'&&ch<='z')
    ch=ch-('a'-'A');
  return ch;
}
#endif
