// constructorWithDefaults - multiple
// constructors can often be combined constructorWithDefaults
// the definition of default arguments

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <cstring>

using namespace std;
const int MAXNAMESIZE=40;

class Student
{
    public:
        Student(char* pName="no name", 
            int xfrHours=0,
            float xfrGPA=0.0)
        {
            cout << "constructing student " << pName << endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE-1]='\0';
            semestrHours=xfrHours;
            gpa=xfrGPA;
        }
        ~Student()
        {
            cout << "destructing student" << endl;
        }
        // ...other public members...
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
