// Branch demo - input two numbers. 
// Go down one part of the program if the first argument
// is greater than the second, or the other path if noexcept
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    // input the first argument
    int arg1;
    cout << "Enter arg1: ";
    cin >> arg1;
    
    // and the second
    int arg2;
    cout << "Enter arg2: ";
    cin >> arg2;
    
    // now decide what to down
    if (arg1 > arg2){
        cout << "Argument 1 > Argument 2"
        << endl;
    }
    else{
        cout << "Argument 1 <= Argument 2"
        << endl;
    }
    system("PAUSE");
    return 0;
}
