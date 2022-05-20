#include <iostream>
#include <fstream>
#include <string>
#include "LL.h"
#include "utility.h"
using namespace std;
//prototypes
void buildLL(LL& l);
void removeBadWords(LL& l);
void outputToFile(LL& l);
int main()
{
  LL li;//creating linked list
  
  buildLL(li); //adding words using a text file
  removeBadWords(li);//filtering out bad words using a text file
  outputToFile(li); //outputting the filtered text words into the directory
  return 0;
}
/*////////////////////////////////////////////////////////////
The purpose of this function is to open a text document and 
add every single word from it in aphabetical order

l a linked list is being passed into this function
/////////////////////////////////////////////////////////////*/
void buildLL(LL& l)
{
  ifstream fin; //ifstream objectto open a file
  fin.open("essay.txt"); //opening up a text document essay
  string word; //string object
  while(!fin.eof()) //while not the end of the file
    {
      fin>>word; //take in a word
      word=stripStr(word); //passing the word and making all the letters lowercase
      if(!l.search(word)) //search if the word is already in the file
	l.addInOrderAscend(word); //add the word to the document in ascending order
    }
  fin.close(); //close the file
}
/*////////////////////////////////////////////////////////////////////
remove bad words takes in a text object and takes those words that
are assumed bad and filters them out of the linked list.
a linked list is l is being passed into the function
///////////////////////////////////////////////////////////////////*/
void removeBadWords(LL& l)
{
  ifstream fin; //ifstream object
  fin.open("bad.txt"); //open up a file bad.txt
  string bad_word;//create a string titled bad_words
  while(!fin.eof()) //while not at the end of the file
    {
      fin>>bad_word; //take in a word from the file
      if(l.search(bad_word)) //search if the word is in the linked list
	l.deleteNode(bad_word); //if it is delete the node that has the word
    }
  fin.close(); //close the file
}
/*//////////////////////////////////////////////////////////////////
output to file get a linked list that has been assorted in ascending order
and puts each word into a file that starts with the first letter. once all
words starting with the letter are in, it closes the file and opens up the next
letters file and repearts the process
output to file takes in a linked list
/////////////////////////////////////////////////////////////////*/
void outputToFile(LL& l)
{
  ofstream fout; //ofstream object
  string s=l.deleteFront(); //getting the first word of Linked list
  string fileName="./dictionary/?.txt"; //creating a fileName
  fileName[13]=toMyUpper(s[0]); //puts the capital first letter into file to create a text file
  fout.open(fileName.c_str()); //open up a new file in the directory
  while(!l.isEmpty()) //repearting until linked list is empty
    {
      if(toMyUpper(s[0])==fileName[13]) //if a word starts with letter of file
	{
	  fout<<s<<endl; //put into the file
	}
	else
	  {
	    fileName[13]=toMyUpper(s[0]); //get a new file title 
	    fout.close();//close the file
	    fout.open(fileName.c_str()); //open up a new file with next letter
	    fout<<s<<endl;//output the word into the file
	  }
      s=l.deleteFront(); //get the next word
    }
  fout.close();//close file once everything is done
}
