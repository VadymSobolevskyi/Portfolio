// Constructor with arguments - provide a Constructor
// with arguments

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <cstring>

using namespace std;

const int MAXNAMESIZE=40;

class Student
{
    public:
        Student(char* pName)
        {
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE-1]='\0';
            //cout << "constructing student" << endl;
            semestrHours=0;
            gpa=0.0;
        }
        // ... other public members
    protected:
        char name[MAXNAMESIZE];
        int semestrHours;
        float gpa;
};

int main(int nArgs, char* pArgs[])
{
    
    Student s("O. Danny Boy");
    Student* pS=new Student("E. Z. Rider");
    //system("PAUSE");
    
    return 0;
}
