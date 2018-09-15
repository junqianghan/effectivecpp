//
// Created by han on 18-9-14.
//
/**
 * 栈的压入弹出序列
 */

#include "common.h"

bool isPopOrder(const int* pPush, const int* pPop, int nLength)
{
    if(pPush == nullptr || pPop == nullptr || nLength <= 0 )
        return false;

    const int* pNextPush = pPush;
    const int* pNextPop = pPop;
    bool bPossible = false;

    stack<int > stackData;
    while(pNextPop - pPop < nLength)
    {
        while(stackData.empty() || stackData.top() != *pNextPop)
        {
            if(pNextPush - pPush == nLength)
                break;
            stackData.push(*pNextPush);
            pNextPush++;
        }
        if(stackData.top()!=*pNextPop)
            break;
        stackData.pop();
        pNextPop++;
    }
    if(stackData.empty() && pNextPop-pPop == nLength)
        bPossible = true;
    return bPossible;
}

int main(int argc, char const *argv[])
{

    return 0;
}
