// Square Demo - demonstrate the use of the function
// which processes arguments
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

// square - returns the square of its argument
// doubleVar - the value to be squared

double square(double doubleVar)
{
    return doubleVar * doubleVar;
}
// sumSequence - accumulate the square of the number
// entered at the keyboard into a sequence until 
// the user enters a negative number
double sumSequence(void)
{
    // loop forever
    double accumulator = 0.0;
    for(;;)
    {
        // fetch another number
        double dValue = 0;
        cout << "Enter next number: ";
        cin >> dValue;
        
        // if it's negative
        if (dValue < 0)
        {
            // then exit from the loop
            break;
        }
        // ofherwise calculate the square
        double value = square(dValue);
        // now add the square to the accumulator
        accumulator = accumulator + value;
    }
    // return the accumulated value
    return accumulator;
}

int main(int nNumberofArgs, char* pszArgs[])
{
    
    system("PAUSE");
    return 0;
}
