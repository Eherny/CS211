#ifndef STUDENT_H
#define STUDENT_H
#include "price.h"
#include <string>
using namespace std;
const int MAX = 6; //max size for classes

class Student
{//private data functions
 private:
  string firstName;
  string lastName;
  char gender;
  int stuID;
  int numClasses;
  int classes[MAX];
  Price balance;
  //function data
 public:
  Student( string f, string l, char g,int id);
  Student();
  int addCourse(int crn);
  void viewAllCourses();
  bool dropCourse(int crn);
  string getFirstName()const;
  string getLastName()const;
  char getGender()const;
  int getNumClasses()const;
  int getStuID()const;
  int getClassOf(int i)const;
  Price getBalance()const;
  void addFee(int d,int c);
  void reduceFee(int d,int c);
};
#endif

