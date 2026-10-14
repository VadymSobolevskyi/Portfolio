//DataSet - store associated data 
//in an array of objects
#include <cstdio> 
#include <cstdlib> 
#include <iostream>
#include <string.h>
using namespace std; 

//NameDataSet - store name and 
//credit card information
class NameDataSet
{
    public:
        char firstName[128];
        char lastName[128];
        int creditCard;
};
//function prototypes:
bool getData(NameDataSet& nds);
void displayData(NameDataSet& nds);

int main(int nArgs, char* pszArgs[])
{
    //allocate space for 25 name data fsetpos
    const int MAX = 25;
    NameDataSet nds[MAX];
    
    //load first names, last names
    //and social security numbers
    cout << "Read name/credit card information\n"
        << "Enter 'exit' to quit"
        << endl;
    int index = 0;
    while(getData(nds[index]) && index < MAX)
    {
        index++;
    }
    
    //display the names and numbers entered
    cout << "\nEntries:" << endl;
    for (int i=0;i<index;i++)
    {
        displayData(nds[i]);
    }
    
    // wait until user is ready before terminating program
    // to allow the user to see the program results 
 //   system("PAUSE");    
    return 0;
}

//getData - populate a NameDataSet objects
bool getData(NameDataSet& nds)
{
    cout << "\nEnter first name:";
    cin >> nds.firstName;
    
    //compare the name input irrespective of case
    if (strncmp(nds.firstName, "exit", 4) == 0)
    {
        return false;
    }
    
    cout << "\nEnter last name:";
    cin >> nds.lastName;
    
    cout << "\nEnter credit card number:";
    cin >> nds.creditCard;
    
    return true;
}

//displayData - display a data set
void displayData(NameDataSet& nds)
{
    cout << nds.firstName
        << " "
        << nds.lastName
        << "/"
        << nds.creditCard
        << endl;
}



