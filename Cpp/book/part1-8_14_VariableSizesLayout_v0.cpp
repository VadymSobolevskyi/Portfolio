
// VariableSize - layout of local memory in compiler
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
using namespace std; 

int main(int nArg, char* pszArgs[])
{    
    int end; 
    int n; 
    long l; 
    float f; 
    double d; 
    
    // set output to hex mode
    cout.setf(ios::hex);
    cout.unsetf(ios::dec);
    // output the address of each variabl
    cout << "end = 0x" << &end << "\n";
    cout << "&n = 0x" << &n << "\n";
    cout << "&l = 0x" << &l << "\n";
    cout << "&f = 0x" << &f << "\n";
    cout << "&d = 0x" << &d << "\n";
    // wait until user is ready before terminating program
    // to allow the user to see the program results 
    system("PAUSE");    
    return 0;
}
