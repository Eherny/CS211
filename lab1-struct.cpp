/*******************************************
Eric Hernandez
CS211 Slott 
lab1
1-21-2020

Purpose of this labe is to create a array and 
open a file to fill the arrays data.
*******************************************/

#include <iostream>
#include <fstream>

//???????? need more header files?
using namespace std;

//???????? Where do the prototypes go?
//???????? Declare the struct called student
//declar struct with variables
struct student{
  int studentid;
   string firstName;
   string lastName;
  int age;
  void displaystu (e){
    cout<<studentid<<""<<firstName<<""<<lastName;""<<""<<age;
}
};

//????? Decare a constant called MAX and set it to 20. //The maximum number of students the array can hold

int main()
{
  student stu;
  stu.studentid = 1000;
  stu.firstName = "Lucy";
  stu.lastName = "Smith";
  stu.age= 20;
  stu.displaystu(stu);
  return 0;
    
   
    
}
  //?????????? create a student called stu and set 1000, Lucy, Smith, 20 to it                                                           
  //?????????? display stu by calling displayStu                                                                                                 

  //?????????? Create an array of students using MAX

//  int num; //it holds the number of students or -1 if the input file didn't exist

  //?????????? call the getStuData function to fill the array with students' information
  //getStuData returns the number of students or -1 if the file doesn't exist
  

  //?????????  
  //  cout << "The file didn't exist." << endl;
  //?????????
// cout << "There are no students in the input file." << endl; //The file existed but it was empty
  //?????? //The input file had at least one student 
//    {
      //??????  show all the students' info by calling displayAllStu 
     
//    int look; //The id the user is looking for
//    cout << "\nEnter the id you are looking for: ";
//    cin >> look;

      //Find a student with the id you are looking for and display the information about that student. If no student has the id, show an appropriate message.
      //?????????????  Call findID  
      //if( ???????  ) //The id the user was looking for was found
           //display the info on the student with that id by calling displayStu
      //else
//	cout << "No student with id " << look << " was found" << endl;

      //find the youngest and oldest students by calling findYoungOld
//    int yngInd; //index of the yougest student
//    int oldInd; //index of the oldest student
      //??????????? call findYoundOld

//    cout<< "\nThe youngest Student -----" << endl;
      //??????????? call displayStu to show the youngest student's info

//    cout<< "\nThe oldest Student -----" << endl;
      //?????????? call displayStu to show the oldest student's info
//  }     

//  cout << endl;
    
// return 0;
//}

//This function loads students' data into the array and returns the number of students.
/*???  getStuData(?????)
{
  string filename;
// c++ string into c string
  cout << "Enter the input file name that has the students' info: ";
  cin >> filename; 
   
  fin.open(filename.c_str());
if(!fin)
return -1;
else

  ????????
  ????????nb
  ????????


}*/

/* This function searches through the array to find the student with the id the user is looking for.
      The user is asked to enter the id she is looking for in the main.
      Return the index where the student with the id was found or -1 if not found. */

/*??? findID( ???????? )
{

}*/


/*Pass the student array and call displayStu to show each student */
/*???? displayAllStu( ????????? )
{
 
   //call displayStu to show each student

}*/

/*One student struct is passed to this function and display all the information (id, fName, lName and age) about that student.*/
/*??? displayStu( ???? )
{

}*/


/*This function will pass back the *indices* of the youngest and oldest students */
/*????  findYoungOld( ???? )
{

  
}*/
