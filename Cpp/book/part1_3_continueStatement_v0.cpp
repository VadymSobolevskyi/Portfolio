// continue demo - input a series of numbers.
// continue to calculate the sum of these numbers
// iggnoring negative numbers until a user enters ZERO
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
    cout << "It ignores negative numbers and terminates the loop by entering"
        << "the ZERO\n";
    
    int value = 0;
    // while "forever"
    while (true)
    {
        // fetch another number
        
        cout << "Input a value: ";
        cin >> value;
        if (value < 0)
        {
            continue;
        }
        if (value == 0)
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
