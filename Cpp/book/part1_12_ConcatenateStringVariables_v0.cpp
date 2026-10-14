//ConcatenateString- concatenate 2 string type  
//variables with " - " in the middle
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main(int nArg, char* pszArgs[])
{    
    //read first string
    string string1;
    cout << "Enter string #1:";
    cin >> string1;

    //now the second string
    string string2;
    cout << "Enter string #2:";
    cin >> string2;
    //accumulate both strings into a string 
    //buffer
    string buffer;
    string divider = " - ";
    buffer = string1 + divider + string2;
    
    cout << "\n" << buffer << endl;
    
    system("PAUSE");    
    return 0;
}
