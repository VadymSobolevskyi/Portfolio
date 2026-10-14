// FileInput - read blocks of data from a file
#include<iostream>
#include<fstream>

using namespace std;

ifstream* openFile(istream& input)
{
    for(;;)
    {
        char fileName[80];
        cout << "Enter the name of a file" << endl;
        input.getline(fileName, 80);
        ifstream* pFileStream=new ifstream(fileName);
        if (pFileStream->good())
        {
            return pFileStream;
        }
        cerr<<"Couldn't find "<<fileName<<endl;
    }
    return 0;
}

int main()
{
    ifstream* pFileStream=openFile(cin);
    char buffer[80];
    while (!pFileStream->eof() && pFileStream->good())
    {
        pFileStream->read(buffer, 80);
        int noBytes=pFileStream->gcount();
        for (int i=0;i<noBytes;i++)
        {
            cout<<buffer[i];
        }
    }
    cout<<"Welcome to Online IDE!! Happy Coding :)";
    return 0;
}
