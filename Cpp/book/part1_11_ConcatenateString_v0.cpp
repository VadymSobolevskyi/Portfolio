//ConcatenateString- concatenate 2 strings 
//with " - " in the middle
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main(int nArg, char* pszArgs[])
{    
    //read first string
    char szString1[128];
    cout << "Enter string #1:";
    //cin >> szString1;
    //safer alternative
    cin.getline(szString1, 128);
    
    //now the second string
    char szString2[128];
    cout << "Enter string #2:";
    //cin >> szString1;
    //safer alternative
    cin.getline(szString2, 128);
    //accumulate both strings into a single 
    //buffer
    char szString[260];
    //copy the first string into the buffer
    strncpy(szString, szString1, 128);
    //concatenate " - " onto the first
    strncat(szString, " - ", 4);
    //now add the second string
    strncat(szString, szString2, 128);
    cout << "\n" << szString << endl;
    
    system("PAUSE");    
    return 0;
}
