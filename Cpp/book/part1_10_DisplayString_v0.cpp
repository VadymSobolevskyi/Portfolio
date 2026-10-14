//DisplayString- output a character Array
//to standart output
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
//prototype declarations
void displayString(char stringArray[]);

int main(int nArg, char* pszArgs[])
{    
    //
    char charMyName[] = {'S', 't', 'e', 'p', 'h', 0};
    displayString(charMyName);
    cout << endl;
    system("PAUSE");    
    return 0;
}
//displayString - display a character string,
//one character at a time
void displayString(char stringArray[])
{
    for(int i=0; stringArray[i]!='\0'; i++)
    {
        std::this_thread::sleep_for(250ms);
        cout << stringArray[i];
    }
}
