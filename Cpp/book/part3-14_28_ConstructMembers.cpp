// ConstructMembers - 

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
        }
    protected:
        Course c;
};

class TutorPair
{
    public:
        TutorPair()
        {
            cout << "constructing tutorpair" << endl;
            noMeetings=0;
        }
    protected:
    Student student;
    Teacher teacher;
    int noMeetings;
};

int main(int nArgs, char* pArgs[])
{
    cout<<"Creating TutorPair object" << endl;
    TutorPair tp;
    //system("PAUSE");
    
    return 0;
}
