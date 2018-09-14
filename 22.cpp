
#include "common.h"

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int value):m_nValue(value){}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned k)
{
    if(pListHead == nullptr || 0 == k)
    {
        return nullptr;
    }
    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;

    for(unsigned i=0;i<k-1;i++)
    {
        if(pAhead->m_pNext != nullptr)
        {
            pAhead = pAhead->m_pNext;
        }
        else
        {
            return nullptr;
        }
    }
    pBehind = pListHead;
    while(pAhead->m_pNext != nullptr)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

int main(int argc, char const *argv[])
{
    


    return 0;
}