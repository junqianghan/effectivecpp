//
// Created by han on 18-9-14.
//

#include "common.h"

void printList(ListNode *phead)
{
    ListNode *p = phead;
    while(p != nullptr)
    {
        cout<<p->m_nValue<<" ";
        p = p->m_pNext;
    }
    cout<<endl;
}

ListNode* listInitial(int *p_data, unsigned length)
{
    ListNode *pHead = nullptr;
    ListNode *pLast = nullptr;

    for(unsigned i=0;i<length;++i)
    {
        ListNode *p = new ListNode(p_data[i]);
        if(pHead == nullptr)
        {
            pHead = p;
        }
        else{
            pLast->m_pNext=p;
        }
        pLast = p;
    }
    return pHead;
}

void listDestroy(ListNode* pHead)
{
    ListNode *p = pHead;
    while(p != nullptr)
    {
        delete p;
        p = p->m_pNext;
    }
}