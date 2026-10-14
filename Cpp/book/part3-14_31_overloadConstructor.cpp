// overloadConstructor - provide the class
// multiple ways to create objects by overloading
// the constructor

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <cstring>

using namespace std;
const int MAXNAMESIZE=40;

class Student
{
    public:
        Student()
        {
            cout << "constructing student no name" << endl;
            semestrHours=0;
            gpa=0.0;
            name[0]='\0';
        }
        Student(char* pName)
        {
            cout << "constructing student" << pName << endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE-1]='\0';
            semestrHours=0;
            gpa=0.0;
        }
        Student(char* pName, int xfrHours, float xfrGPA)
        {
            cout << "constructing student" << pName << endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE-1]='\0';
            semestrHours=xfrHours;
            gpa=xfrGPA;
        }
        ~Student()
        {
            cout << "destructing student" << endl;
        }
        
    protected:
        char name[MAXNAMESIZE];
        int semestrHours;
        float gpa;
};

int main(int nArgs, char* pArgs[])
{
    //the following invokes three different constructors
    Student noName;
    Student freshman("O. Danny Boy");
    Student xferStudent("E. Z. Rider", 80, 2.5);
    //system("PAUSE");
    
    return 0;
}
