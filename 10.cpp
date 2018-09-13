#include "common.h"

long long Fibonacci(unsigned n)
{
    int result[2]={0,1};
    if(n<2)
    {
        return result[n];
    }

    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (unsigned i = 2; i <= n; ++i) {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusOne = fibN;
        fibNMinusTwo = fibNMinusOne;
    }

    return fibN;
}





int main(int argc, char const *argv[])
{
    cout<<Fibonacci(10)<<endl;


    return 0;
}