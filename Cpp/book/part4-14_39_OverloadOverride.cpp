// OverloadOverride - demonstrate when 
//a function is declare-time overloaded vs 
//runtime overriden
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    public:
        float calcTuition()
        {
            cout << "We're in Student::calcTuition" << endl;
            return 0;
        }
};

class GraduateStudent : public Student
{
    public:
        float calcTuition()
        {
            cout << "We're in GraduateStudent::calcTuition" << endl;
            return 0;
        }
};

void fn(Student& x)
{
    x.calcTuition(); 
}
//
int main(int nArgs, char* pArgs[])
{
    Student s;
    fn(s);
    
    GraduateStudent gs;
    fn(gs);
    
    //system("PAUSE");
    return 0;
}
