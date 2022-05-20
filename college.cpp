#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
#include <fstream>
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "student.h"
#include "price.h"
#include "array.h"


const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;
//Prototypes
int showMenu();
int showAdmMenu();
int showStuMenu();
void addStu(Student ar[],int& curID,int& count);
void showStuInfo(const Student& s);
void allStuInfo(const Student ar[],const int c);
void  removeStu(Student ar[],int& c);
bool operator==(const Student& s, int id);
void  showStuInfo( const Student& s );
void addStuFromFile(Student ar[],int& c,int &curID);
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student& s);
int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  Student stuAR[SIZE];//creating an object array for students class and setting the array size to SIZE
  int index = 0;//this wil hold the index of the student we want to find
  int choice;//this will hold the choice of what we want to check either admin or the student or end the program
  int password;//this will hold the password answer which should be 123 but the user eneters what they think it is
  int findId;//this variable will be used to find the student ID
  
  do{//this do while loop will keep going until choice is 3
    choice = showMenu();//this will show the menu and choice will hold the value of showmenu choicse
    if(choice == 1)//if choice is 1
      {
	cout << "Enter your password: ";
	cin>>password;//ask user to enter the admin password which is 123
	
	if(password == 123)//if they enter the correct passwor which is 123
	  {
	    
	    int adminC;//admins choice		\
	    
	    while(adminC != 6)//keep showing the admin menu until we click quit which is 6
	      {
		adminC = showAdmMenu();//storing the choice of show menu into adminc or admin choice
		//this switch statement is used to call seperate functions from the showAdmMenu()
		switch(adminC)
		  {
		  case 1:
		    addStu(stuAR,curID,count);//adding a student to class
		    break;
		  case 2:
		    addStuFromFile(stuAR,count,curID);//adding the students from the file college.dat
		    break;
		  case 3:
		    removeStu(stuAR,count);//removing a student from the class
		    break;
		  case 4:
		    cout << "Enter the student ID: ";
		    cin >> index;
		    findId = find(stuAR,count,index);//finding the student with that ID in the stuAR
		    if(findId == -1)
		      cout << "The student ID doesn't exist" << endl << endl;
		    else
		      showStuInfo(stuAR[findId]);//this function will show the specific students info that the id is ass
		      break;
		  case 5:
		    allStuInfo(stuAR,count);//displaying all of the students that are in the array
		    break;
		  default:
		    cout << endl;
		  }
	      }
	  }
	else
	  {
	    cout << "Wrong password. " << endl << endl;//display message if the password was incorrect
	  }
	
      }
    else if(choice == 2)//IF choice is 2
      {
	int studentID;//this variable will hold the students ID
	int password2;//this is holding the password for the student
	int studentC;//choice for the student
	int student_ID;
	cout << "Enter the student id: ";
	cin >> studentID;
	int found = find(stuAR,count,studentID);
	if(found == -1)
	  cout << "The student ID doesnt exist. " << endl << endl;
	else
	  {
	    cout << "Enter the password: ";
	    cin >> password2;//asking user to enter the password for   

	  }
	studentID = studentID % (PRIME1*PRIME2);
	if(password2 != studentID)
	  cout << "The password is wrong. " << endl << endl;
	
	else
	  {
	    int crn;//the crn that we wan to add
	    int crnD;//the crn that we wanna drop
	    cout << "Welcome " << stuAR[found].getFirstName() << endl;
	    
	    while(studentC != 5)
	      {
		studentC = showStuMenu();
		switch(studentC)
		  {
		  case 1:
		    addCourse(stuAR[found]);//this function will add a course to the student
		    break;
		  case 2:
		    dropCourse(stuAR[found]);
		    break;
		  case 3:
		    makePayment(stuAR[found]);
		    break;
		  case 4:
		    showStuInfo(stuAR[found]);
		    break;
		  }	
	      }
	  }	  
      }
  }while(choice != 3);
  
  
  
  
  
  
  return 0;
}



// ************************  PHASE 1  ****************************
/********************************************
addStu passes student array ID and a count
c=count or counter,ID= id number.
initizlized first and last name and gender
takes user input from user and creats a student object and adds it
to the array
*********************************************/
void addStu(Student ar[],int& ID,int& c)
{
  string first,last;
  char gend;
  if(c==SIZE)//error case for when c becomes the max size
    cout <<"Max number of students reached"<<endl;
else
//case 1 of admission
//user inputs for first name last name and gender
  cout<< "Enter first name: ";
  cin>>first;
  cout << "Enter last name: ";
  cin>>last;
  cout<<"Enter gender: ";
  cin>>gend;

  //create a student object. The first student created is given a stu id, 100000 (coming from const START).
  Student s(first,last,gend,ID);
  //The second student gets 100001, the third student gets 100002, etc (notice curID in main).

  //copy the info from the stu obj into the array at the appropriate slot
  ar[c]=s; 
  c++; //incriments the counter
  ID++;//incriments the student id number
}
/********************************************
showStuInfo takes a student object and shows the information of them
using functions in order to get private data functions
*********************************************/
                                                              
void  showStuInfo( const Student& s )                                                                                       
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 

//users price functions to get private deta members
  cout << "--------------------" << endl;                                                         
                                                                                                                                             
  cout << "first name: " <<  s.getFirstName()  << endl;                                                                                                 
 
  cout << "last name: " << s.getLastName()  << endl;                                                                                                  
 
  cout << "gender: " << s.getGender() << endl;                                                                                                      
 
  cout << "stu id: " << s.getStuID() << endl;                                                                                                      
 
  cout << "num classes: " << s.getNumClasses()  << endl;                                                                                                  
 
                                                                                                                                            
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < s.getNumClasses() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i)  << " ";                                                                                                                 
 
                                                                                                                                              
  cout << "\nAmount owed $" << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                               
 
  }

/********************************************
allStuInfo takes in an student array and a constant counter
c=counter
This goes through all the student array and prints out all the students according to the counter.
*********************************************/
void allStuInfo(const Student ar[],const int c)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  for(int i=0;i<c;i++)//for loop to show each student
    {
      showStuInfo(ar[i]);
    }
}
/********************************************
bool operator== checks to see if an id is the same as the id of the perapator.
s is a student object
id is the id of the object
*********************************************/
bool  operator==(const Student& s, int id) 
{
  if(s.getStuID()==id)
    return true;
  else
    return false;
}
/********************************************
removeStu takes an student array and the count of the arrau
asks user for what student they want to deletes them, 
ar=array counter
c=count
*********************************************/

void  removeStu(Student ar[],int& c)
{
//Case 3 of Admission
  int id; //intilizes id
  int index;//intizlizes index
//2 different messages
  cout<<"Enter the studentid:"; 
  cin>>id; //user input to ask for stu id
  index=find(ar,c,id);//checks to see if the student id is there
  if(index==-1)
    cout<<"student with id " << id << " doesn't exist" << endl;
  else
    {//if it finds the student deletes the student
      cout<< ar[index].getFirstName() << " " << ar[index].getLastName() << " has been removed." << endl;
      remove(ar,c,id); //removes if found
    }
}
/********************************************
addStufromFile takes a student array a counter and an id 
ar=student array
c=count
ID= student id number
opens a file of choice and creates a student object with the file and adds the
information to the student array

*********************************************/

void addStuFromFile(Student ar[],int& c,int &ID)
{
//Case 2 of admission
  ifstream fin;
  string fileName;
  string fN;
  string lN;
  char gender;

  cout<<"Enter file name"<<endl; //takes user input
  cin>>fileName;
  fin.open(fileName.c_str());//opens file with c string
  if(!fin)//if file doesnt open print out cannout open
    {
      cout<<"file cannot be found"<<endl;
    }
  else
    {
      fin>>fN;//take in fn
      fin>>lN;//take in lastname
      fin>>gender; //take in gender
      {
	while(fin)
	  {
	    if(c==SIZE)//if counter is equal to aize say array is full
	      {
		cout<< "Array is Full "<<endl;
	      }
	    else
	      {
		Student s(fN,lN,gender,ID);//creats student object
		ar[c]=s; //adds array student object to array
		c++;//incriments count
		ID++;//incriments ID
		fin>>fN; //takes in fn
		fin>>lN; //tales in ln
		fin>>gender; //takes in gender
	      }
	  }
      }
      fin.close(); //closes file
    }
}







//*******************  PHASE 2 ****************************
/*///////////////////////////////////////////////////////////////////
addCourse is gonna take in a student object
addcourses is gonna ask the student which courses they want to enroll in
if they arent taking it and their class scheduele isnt full it will add it
and add fees to their owed balance, if it cant add it will prompt the
appropriate error message

///////////////////////////////////////////////////////////////////*/

void  addCourse(Student& s )
{
//case 1 of student
//FYI, I am passing one student to this function not the array. 
  int crn;
  cout<< "Enter a crn to add"<<endl;
  cin>>crn;
  int addc=s.addCourse(crn);

//3 different messages to show
  if(addc==1)
    {
      cout<<crn<< " has been added successfully" << endl;
     s.addFee(50,14);
    }
  else if(addc==0)
    {
      cout << crn <<  " was not added because you have " << crn << " already." <<  endl;
    }
  else
    {
      cout<<crn<< " was not added because your schedule is full." <<  endl;
    }

}

/*/////////////////////////////////////////////////////////////////////
Drop courses is gonna take in a student object 
its gonna ask the student what course he wants to drop and if he is
actually taking the course it will remove it and reduce their fees
if he isnt enrolled it will prompt the failure of the drop

/////////////////////////////////////////////////////////////////////*/
void dropCourse(Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  int crn;
  cout<<"Enter a course you want to drop"<<endl;
  cin>> crn;
  bool remove= s.dropCourse(crn);
//2 different messages
  if (remove==false)
    {
      cout<<crn<< " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
    }
else
  {
    cout<<crn<< " has been dropped successfully." << endl;
    s.reduceFee(50,14);
  }

}

/*//////////////////////////////////////////////////////////////////
make payment is gonna take in a student object
make payment is gonna ask the user if he wants to make a payment and for how much
once entering the amount the user wants to pay the fees will be deducted
//////////////////////////////////////////////////////////////////*/
void  makePayment( Student& s)
{
//case 3 of student
//FYI, I am passing one student to this function not the array.
  int d;
  int c;
  cout<<"You owe $" <<s.getBalance()<<endl;
  cout<<"Enter the amount you would like to pay"<<endl;
  cin>>d>>c;
  s.reduceFee(d,c);  
}






//******************** PHASE 3 ****************************
/*
bool checkPassword(  ,curID)
{
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
  stuID%(PRIME1*PRIM2);
}


int findStu()
{
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
}


viewStuInfo(Student ar[],int count,int id)
{
//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}


 verifyStu()
{
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
}
*/


int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}
 
 int showAdmMenu()
 {
   int choice;
  
  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");
  
  return choice;
}



