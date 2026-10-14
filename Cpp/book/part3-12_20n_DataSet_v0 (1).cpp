//CallMemberFunction - define and invoke 
//function that's a member of the class Student

#include <cstdio> 
#include <cstdlib> 
#include <iostream>
//#include <string.h>
using namespace std; 

class Student
{
    public:
        //add a completed course to the record
        float addCourse(int hours, float grade)
        {
            //calculate the sum of all courses times
            //the average grade
            float weightedGPA;
            weightedGPA = semesterHours * gpa;
            
            //now add in a new course
            semesterHours += hours;
            weightedGPA += grade * hours;
            gpa = weightedGPA / semesterHours;
            
            //return the new gpa
            return gpa;
        }
        int semesterHours;
        float gpa;
        
};

int main(int nArgs, char* pszArgs[])
{
    Student s;
    s.semesterHours = 10;
    s.gpa = 3.0;
    //the values before the call
    cout << "Before: s = (" << s.semesterHours
        << ", " << s.gpa
        << endl;
    
    //the following subjects the data 
    //members of the s object to the 
    //member function addCourse()
    s.addCourse(3, 4.0); //call the member function
    
    //the values are now changed
    cout << "After: s = (" << s.semesterHours
        << ", " << s.gpa
        << ")" << endl;
        
    //access another object just for the heck of it
    Student t;
    t.semesterHours = 6;
    t.gpa = 1.0; //not doing so good
    t.addCourse(3, 1.5);
    
    // wait until user is ready before terminating program
    // to allow the user to see the program results 
 //   system("PAUSE");    
    return 0;
}



