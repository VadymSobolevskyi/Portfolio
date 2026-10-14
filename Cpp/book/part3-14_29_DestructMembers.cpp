// DestructMembers - this progran both
// construcs and destructs a set of data members

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

class Course
{
    public:
        Course()
        {
            cout << "constructing course" << endl;
        }
        ~Course() { cout << "destructing course" << endl; }
};

class Student
{
    public:
        Student()
        {
            cout << "constructing student" << endl;
            semestrHours=0;
            gpa=0.0;
        }
        ~Student() { cout << "destructing student" << endl; }
    protected:
        int semestrHours;
        float gpa;
};

class Teacher
{
    public:
        Teacher()
        {
            cout << "constructing teacher" << endl;
            pC=new Course;
        }
        ~Teacher()
        {
            cout << "destructing teacher" << endl;
            delete pC;
        }
    protected:
        Course* pC;
};

class TutorPair
{
    public:
        TutorPair()
        {
            cout << "constructing tutorpair" << endl;
            noMeetings=0;
        }
        ~TutorPair() { cout << "destructing tutorpair" << endl; }
    protected:
    Student student;
    Teacher teacher;
    int noMeetings;
};

TutorPair* fn()
{
    cout << "Creating TutorPair object in function fn()" << endl;
    TutorPair tp;
    cout << "Allocating TutorPair off the heap" << endl;
    TutorPair* pTP=new TutorPair;
    cout<<"Returning from fn()"<<endl;
    return pTP;
}

int main(int nArgs, char* pArgs[])
{
    //call function fn() and then return
    //the TutorPair object returned to the heap
    TutorPair* pTPReturned = fn();
    cout<<"Return heap object to the heap" << endl;
    delete pTPReturned;
    
    //system("PAUSE");
    
    return 0;
}
