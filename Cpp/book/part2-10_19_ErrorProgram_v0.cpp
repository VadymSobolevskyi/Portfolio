//errorProgram - averages the numbers
//but contains at leat one fatal error
#include <cstdio> 
#include <cstdlib> 
#include <iostream>
using namespace std; 

int main(int nArgs, char* pszArgs[])
{
    //print a warning banner
    cout << "This program is designed to crash." << endl;
    int nSum = 0;;
    //int nNums;
    //accumulate input numbers until
    //the user enters a negative number,
    //then return the average
    //nNums = 0;
    for (int nNums=0; ;nNums++)
    {
        //enter another number to add
        int nValue;
        cout << "Enter another number: ";
        cin >> nValue;
        cout << endl;
        //if the input number is negative...
        if (nValue < 0)
        {
            //then output the average
            cout << "Average is: "
                << nSum/nNums
                << endl;
            break;
        }
        nSum += nValue;
    }

    // wait until user is ready before terminating program
    // to allow the user to see the program results 
 //   system("PAUSE");    
    return 0;
}
