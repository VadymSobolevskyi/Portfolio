// while demo - input a loop cout.
// Loop while outputing astring arg number of times
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // input the loop count
    int loopCount;
    cout << "Enter loop count: ";
    cin >> loopCount;
    
    // now loop that many times
    while(loopCount-- > 0)
    {
        //loopCount = loopCount - 1;
        cout << "Only " << loopCount << " loops to go\n";
    }
    system("PAUSE");
    return 0;
}
