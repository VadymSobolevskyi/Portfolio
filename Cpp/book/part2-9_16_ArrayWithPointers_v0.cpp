//displayArrayWithPointers - display the members 
//of an array of length size
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <array>
using namespace std; 

void displayArray(int intArray[], int nSize)
{
    cout << "The value of the array is:\n";
    int* pArray = intArray;
    for (int n;n<nSize;n++)
    {
        cout << n << ": " << intArray[n] << "\n";
    }
    cout << "\n";
}
int main(int nArg, char* pszArgs[])
{    
    int array[] = {4, 3, 2, 1};
    displayArray(array, 4);
    // wait until user is ready before terminating program
    // to allow the user to see the program results 
 //   system("PAUSE");    
    return 0;
}
