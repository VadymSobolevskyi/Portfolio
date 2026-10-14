//ArraysDemo - reading a sequence of integers
//and displaying them in order
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//prototype declarations    
int sumArray(int integerArray[], int sizeOfloatArray);        
void displayArray(int integerArray[], int sizeOfloatArray);

int main(int nNumberofArgs, char* pszArgs[])
{    
    //input the loop count
    int Accumulator = 0;
    cout << "Terminate the loop by entering the negative number\n" 
        << endl;    
    //store numbers into an ArraysDemo
    int inputValues[128];
    
    int numberOfValues;
    for(numberOfValues=0;numberOfValues<128;numberOfValues++)
    {
        int integerValue;
        cout << "Enter next number: ";
        cin >> integerValue;
        
        if (integerValue<0)
        {
            break;
        }
        inputValues[numberOfValues]=integerValue;
    }
        
    system("PAUSE");    
    return 0;
}
