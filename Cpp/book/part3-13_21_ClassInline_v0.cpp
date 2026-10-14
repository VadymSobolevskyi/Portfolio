//SavingsClassInline - invoke a member function
//that's both declared and define 
//within the class

#include <cstdio> 
#include <cstdlib> 
#include <iostream>
//#include <string.h>
using namespace std; 
#include "Savings.h"

//define a member function Savings::deposit()
//normally this is contained in a separate file that is
//then combined with a different file that is combined
float Savings::deposit(float amount)
{
    balance += amount;
    return balance;
}

int main(int nArgs, char* pszArgs[])
{
    Savings s;
    s.accountNumber = 123456;
    s.balance = 0.0;
    
    cout << "Depositing 10 to the account " << s.accountNumber << endl;
    s.deposit(10);
    cout << "Balance is " << s.balance << endl; 
    
    // wait until user is ready before terminating program
    // to allow the user to see the program results 
 //   system("PAUSE");    
    return 0;
}



