#include <iostream>
using namespace std;
#include "myCstring.h"
void showResult(const char *lwd, const char *swd, const char *all) {
  cout << "The longest word: " << lwd << endl;//display longest word
  cout << "The shortest word: " << swd << endl; //display shortest word
  cout << "All words minus bad words: " << all<<endl; //display all words
}
int main()
{
const char* badAr[4] = {"funky", "idiot", "stinky", "stupid"};
        
char wd[10];
char all[111] = "";
char longestWd[10] = "";
char shortestWd[10] ="xxxxxxxxx";
int longest;
int shortest=10;
int len;
        
// loop to take input from user
 for(int i = 0; i < 10; i++) //while less than 10 inputs
  {
    cout << "Enter a word: "; //enter a word
    cin >> wd;
    
    // if bad word is found then skip the rest part
    if(binarySearch(badAr, 0, 3, wd) < 0)
      {               
	// if wd is not bad word
	// concatenate to the 'all' string
	myStrcat(all, wd);
	// also concatenate ',' follownig main string
	myStrcat(all, ",");
	
	len = myStrlen(wd); //get length of word
	if(len > longest) {//if word is more than the longest
	  longest=len; //make longest equal to inputed word
	  myStrcpy(longestWd, wd); //copy longest word to the cstring for the word
	}
	
	else if(len < shortest) { //if inputed word is shorter
	  shortest=len; //make shortest equal to inputed word
	  myStrcpy(shortestWd, wd); //copy inputed word to cstring shortest
	}
      }
  }
// showing result
 showResult(longestWd, shortestWd, all);
 
 return 0;
}
