//displayStringWithPointers - display an array of characters 
//using a pointer and an array index
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <array>
using namespace std; 

int main(int nArgs, char* pszArgs[])
{
    //declare a string 
    char* szString = "Randy";
    cout << "The array is '" << szString << "'" << endl;
    
    //display szString as an array 
    cout << "Display szStruing as an array: ";
    for (int i=0;i<5;i++)
    {
        cout << szString[i];
    }
    cout << endl;
    
    //now using typical pointer arithmeric 
    cout << "Display string using a pointer: ";
    char* pszString = szString;
    while (*pszString) 
    {
        cout << *pszString;
        pszString++;
    }
    cout << endl;
    
    // wait until user is ready before terminating program
    // to allow the user to see the program results 
 //   system("PAUSE");    
    return 0;
}
