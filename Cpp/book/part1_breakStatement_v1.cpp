// break demo - input a series of numbers.
// continue to calculate the sum of these numbers
// until a user enters negative number
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // input the loop count
    int accumulator = 0;
    cout << "This program sums values entered"
        << "by the user\n";
    cout << "Terminate the loop by entering"
        << "the negative number\n";
    
    // loop "forever"
    for (;;)
    {
        // fetch another number
        int value = 0;
        cout << "Enter next nmber: ";
        cin >> value;
        if (value < 0)
        {
            break;
        }
        accumulator = accumulator + value;
    }
    // output the accumulated result
    cout << "\nThe total is "
        << accumulator
        << "\n";
    system("PAUSE");
    return 0;
}
