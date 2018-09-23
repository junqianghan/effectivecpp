#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    while(*str)
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}

int main()
{
    char *str="中文";

    cout<<BKDRHash(str)<<endl;
/*
    unsigned char a=0;
    unsigned int b = 0;

    while(b<300)
    {
        printf("%d\n",a++);
        b++;
    }
    */
    return 0;
}
