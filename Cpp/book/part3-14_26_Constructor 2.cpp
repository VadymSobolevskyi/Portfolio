//Constructor

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Student
{
    public:
        Student()
        {
            cout << "constructing student" << endl;
            semestrHours = 0;
            gpa = 0.0;
        }
    protected:
       int semestrHours;
       float gpa;
};

int main(int nArgs, char* pArgs[])
{
    cout << "Creating a new Student object :)" << endl;
    Student s;
    
    cout << "Creating a new object off the heap:)" << endl;
    Student* pS = new Student;
    
    return 0;
}
