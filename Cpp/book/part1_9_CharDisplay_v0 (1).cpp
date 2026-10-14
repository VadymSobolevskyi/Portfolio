//CharDisplay - output a character ArraysDemo
//to standart output
#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
//prototype declarations
void displayCharArray(char stringArray[], int sizeOfloatArray);

int main(int nArg, char* pszArgs[])
{    
    //
    char charMyName[] = {'S', 't', 'e', 'p', 'h'};
    displayCharArray(charMyName, 7);
    cout << "\n";
    //system("PAUSE");    
    return 0;
}
//displayCharArray - display an array of characters
//by outputing one character at a time
void displayCharArray(char stringArray[], int sizeOfloatArray)
{
    for(int i=0; i<sizeOfloatArray; i++)
    {
        std::this_thread::sleep_for(250ms);
        cout << stringArray[i];
    }
}
