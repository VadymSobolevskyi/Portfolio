// ConstructStatic - demonstrate
//that statics are only constructed once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class DoNothing
{
    public:
        DoNothing(int initial)
        {
            cout << "DoNothing constructed with the value of : " << initial << endl;
        }
};

void fn(int i)
{
    cout << "Function fn passed a value of " << i << endl;
    static DoNothing dn(i);
}

int main(int nArgs, char* pArgs[])
{
    fn(10);
    fn(20);
    //system("PAUSE");
    return 0;
}
