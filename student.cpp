#include "student.h"
#include "array.h"
//default student constructor
Student::Student( string f, string l, char g,int id)
{
  firstName=f;
  lastName=l;
  gender=g;
  numClasses=0;
  classes[MAX];
  stuID=id;
}
//default onstructor with default perameters
Student::Student()
{
  firstName="unknown";
  lastName= "unknown";
  gender= 'x';
  stuID=-1;
}
//adds course to student
int Student::addCourse(int crn)
{
  int index=find(classes,numClasses,crn);//checks to see if class is in index
  if(index!=-1){ //if it returns 0 classes was already registered
return 0;
 }
  else  if(numClasses==MAX){ //if classes are full  return -1
return -1;
 }
  classes[numClasses++]=crn; // successfully added class 
 return 1;
}
void Student::viewAllCourses(){

  print(classes,numClasses); //prints students courses
  

}

bool Student::dropCourse(int crn){

  return remove(classes,numClasses,crn); //drops courses


}

string Student::getFirstName()const
{
  return firstName;//gets first name
}

string Student::getLastName()const
{
  return lastName;//gets last name
}
char Student::getGender()const
{
  return gender; //gets gender
}
int Student::getNumClasses()const
{
  return numClasses; //gets numclasses
}
int Student::getStuID()const
{
  return stuID; //gets student id
}

int Student::getClassOf(int i)const
{
  find(classes,MAX,i); //finds the class
  return classes[i];  //returns the class
}
Price Student::getBalance()const
{
  return balance; //returns the balance
}
void Student::addFee(int d,int c)
{
  const  Price p(d,c); //gets the price 
  balance=balance+p; //adds it to balance

}
void Student::reduceFee(int d,int c)
{
  Price p(d,c); //gets price
  balance=balance-p; //adds it to the balance
}
