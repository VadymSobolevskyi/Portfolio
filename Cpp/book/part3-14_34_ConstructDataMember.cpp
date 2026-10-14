// Construct Data Member - construct a data Member
//to a value other than the default

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <cstring>

using namespace std;
const int MAXNAMESIZE=40;

class StudentId
{
    public:
        StudentId(int id=0)
        {
            value=id;
            cout << "Assigning student id " << value << endl;
        }
    protected:
        int value;
};

class Student
{
    public:
        Student(char* pName="no name", int ssId=0)
            :id(ssId)
        {
            cout << "constructing student "<< pName<<endl;
            strncpy(name, pName, MAXNAMESIZE);
            name[MAXNAMESIZE-1]='\0';
        }
        
        // ...other public members...
    protected:
        char name[MAXNAMESIZE];
        StudentId id;
};

int main(int nArgs, char* pArgs[])
{
    Student s("Chester", 1234);
    cout<<"This is a message from main"<<endl;
    //system("PAUSE");
    return 0;
}
