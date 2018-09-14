#include "common.h"


//奇数
bool isOdd(int n)
{
    return n&1;

}

//偶数
bool isEven(int n)
{
    return !n&1;

}


//奇数在前
void reorderOddEven(int *pData, unsigned length)
{
    int oddIndex = -1;
    for(int i=0;i<length;i++)
    {
        bool odd = isOdd(pData[i]);
        if(isOdd(pData[i]))
        {
            ++oddIndex;
            swap(pData[oddIndex],pData[i]);
        }
    }
}



int main(int argc, char const *argv[])
{
    int a[5]{1,2,3,4,5};
    copy(a,a+5,ostream_iterator<int >(cout," "));
    cout<<endl;

    reorderOddEven(a,sizeof(a)/sizeof(int));
    copy(a,a+5,ostream_iterator<int >(cout," "));
    cout<<endl;

    return 0;
}