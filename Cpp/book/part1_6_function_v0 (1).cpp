// Function demo - demonstrate the use of functions
// by breaking the inner loop of the 
// NestedDemo progtam off into its own Function
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

// sumSequence - add a sequence of numbers entered from
// the keyboard until the user enters a
// negative number.
// return - the summation of numbers entered
int sumSequence(void)
{
    // loop forever
    int accumulator = 0;
    for(;;)
    {
        // fetch another Number
        int value = 0;
        cout << "Enter next number: ";
        cin >> value;
        
        // if it's negative
        if (value < 0)
        {
            // then exit from the loop
            break;
        }
        // otherwise add number to the accumulator
        accumulator = accumulator + value;
    }
    // return the accumulated value
    return accumulator;
}

int main(int nNumberofArgs, char* pszArgs[])
{
    cout << "This program sums multiple series\n"
        << "of numbers. Terminate each sequence\n"
        << "by entering a negative number.\n"
        << "Terminate the series by entering two\n"
        << "negative numbers in a row.\n"
        << endl;
        
    // accumulate sequences of nmbers
    int accumulatedValue;
    for(;;)
    {
        // sum a sequence of numbers 
        // entered from the keyboard
        cout << "Enter next sequence" << endl;
        accumulatedValue = sumSequence();
        // terminate the loop if sumSequence() returns 
        // a zero
        if (accumulatedValue == 0)
        {
            break;
        }
        // now outpout the accumulated result
        cout << "The total is "
            << accumulatedValue
            << "\n"
            << endl;
        
    }
    cout << "Thank you" << endl;
    system("PAUSE");
    return 0;
}
