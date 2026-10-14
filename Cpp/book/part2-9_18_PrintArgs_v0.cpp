//printArgs - write the arguments tolower
//the program to the standard output
#include <cstdio> 
#include <cstdlib> 
#include <iostream>
using namespace std; 

int main(int nArgs, char* pszArgs[])
{
    //print a warning banner
    cout << "The arguments to " << pszArgs[0] << " are:\n";
    
    //now write the remaining arguments
    for (int i=1;i<nArgs;i++)
    {
        cout << i << ":" << pszArgs[i] << "\n";
        
    }
    
    // wait until user is ready before terminating program
    // to allow the user to see the program results 
 //   system("PAUSE");    
    return 0;
}
