// for demo2 - input a loop cout.
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
    for (int i = 0; i <= loopCount; i++)
    {
        cout << "We've finished " << i << " loops\n";
    }
    system("PAUSE");
    return 0;
}
