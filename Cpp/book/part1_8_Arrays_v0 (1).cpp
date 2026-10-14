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
    //now output values and the sum of the values
    displayArray(inputValues, numberOfValues);
    cout << "The sum is "
        << sumArray(inputValues, numberOfValues)
        << endl;
        
    system("PAUSE");    
    return 0;
}

//displayArray - display the members of an array
//of lengh sizeOfloatArray
void displayArray(int integerArray[], int sizeOfArray)
{
    cout << "The value of the array is: " << endl;
    for (int i=0; i<sizeOfArray; i++)
    {
        cout.width(3);
        cout << i << ": " << integerArray[i] << endl;
    }
    cout << endl;
}

//sumArray - return the sum of the members of an integer array
int sumArray(int integerArray[], int sizeOfArray)
{
    int accumulator = 0;
    for (int i=0; i<sizeOfArray; i++)
    {
        accumulator += integerArray[i];
    }
    return accumulator;
}


