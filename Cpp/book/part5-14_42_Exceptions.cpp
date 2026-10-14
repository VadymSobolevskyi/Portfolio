// Factorial Exceptions - demonstrate exceptions using 
// a Factorial lfunction

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int factorial(int n)
{
    if (n<0)
    {
        throw string("Argument is negative");
    }
    int accum=1;
    while(n>0)
    {
        accum *= n;
        n--;
    }
    return accum;
}

int main()
{
    try
    {
        //this will work
        cout<<"Factorial of 3 is "
            <<factorial(3)<<endl;
            
        //this will generate an exception
        cout<<"Factorial of -1 is "
            <<factorial(-1)<<endl;
            
        //control will not get here
        cout<<"Factorial of 5 is "
            <<factorial(5)<<endl;
    }
    //control passes here
    catch(string error)
    {
        cout<<"Error occured: "<<error<<endl;
    }
    catch(...)
    {
        cout<<"Default catch "<<endl;
    }
    return 0;
}
