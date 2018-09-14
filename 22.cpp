
#include "common.h"

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int value):m_nValue(value),m_pNext(nullptr){}
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
    ListNode p1(1),p2(2),p3(3),p4(4),p5(5);
    p1.m_pNext = &p2;
    p2.m_pNext = &p3;
    p3.m_pNext = &p4;
    p4.m_pNext = &p5;

    ListNode* p = FindKthToTail(&p1,4);
    cout<<p->m_nValue<<endl;


    return 0;
}