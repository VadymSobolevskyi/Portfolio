// Constructing Members - a class may pass long
//arguments to the members' constructors

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <cstring>

using namespace std;
const int MAXNAMESIZE=40;

int nextStudentId=0;

class StudentId
{
    public:
        StudentId()
        {
            value=++nextStudentId;
            cout << "Assigning student id " << value << endl;
        }
    protected:
        int value;
};

class Student
{
    public:
        Student(char* pName)
        {
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE-1]='\0';
            semestrHours=0;
            gpa=0.0;
        }
        
        // ...other public members...
    protected:
        char name[MAXNAMESIZE];
        int semestrHours;
        float gpa;
        StudentId id;
};

int main(int nArgs, char* pArgs[])
{
    Student s("Chester");
    //system("PAUSE");
    return 0;
}
