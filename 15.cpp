#include "common.h"


int numberOf1(int n)
{
    int count = 0;
    unsigned int flag=1;
    while(flag)
    {
        if(n&flag)
        {
            count++;
        }
        flag = flag<<1;
    }
    return count;
}

int numberOf1_v2(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = (n-1)&n;
    }
}

int main(int argc, char const *argv[])
{
    cout<<numberOf1(10)<<endl;

    return 0;
}
