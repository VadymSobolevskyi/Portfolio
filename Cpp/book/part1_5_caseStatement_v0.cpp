// case Statement demo
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
    int choice;
    cout << "Enter a 1, 2 or 3: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
            // do 1 processing
            break;
        case 2:
            // do 2 processing
            break;    
        case 3:
            // do 3 processing
            break;    
        default:
            cout << "You didn't enter 1, 2 or 3\n";
            
    }
    system("PAUSE");
    return 0;
}
