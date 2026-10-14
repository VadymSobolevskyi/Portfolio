// for demo1 - input a loop cout.
// Loop while outputing astring arg number of times
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // input the loop count
    int loopCount;
    cout << "Enter loop count: ";
    cin >> loopCount;
    
    // cout up to the loopCount limit
    for (;loopCount > 0;)
    {
        loopCount = loopCount - 1;
        cout << "Only " << loopCount << " loops to go\n";
    }
    system("PAUSE");
    return 0;
}
