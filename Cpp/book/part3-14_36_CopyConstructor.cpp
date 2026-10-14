// CopyConstructor - demonstrate
//an example of constructor

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXNAMESIZE=40;

class Student
{
    public:
        //Conventional constructor
        Student(char *pName="no name", int ssId=0)
        {
            strcpy(name, pName);
            id=ssId;
            cout << "constructed " << name << endl;
        }
        //copy constructor
        Student(Student& s)
        {
            strcpy(name, "Copy of ");
            strcat(name, s.name);
            id=s.id;
            cout << "constructed " << name << endl;
        }
        
        ~Student()
        {
            cout << "destructing " << name << endl;
        }
        
    protected:
        char name[MAXNAMESIZE];
        int id;
};

//fn - receives its arguments by value
void fn(Student copy)
{
    cout << "In Function fn()" << endl;
}

int main(int nArgs, char* pArgs[])
{
    Student chester("Chester", 1234);
    cout << "Calling fn()" << endl;
    
    //system("PAUSE");
    return 0;
}
