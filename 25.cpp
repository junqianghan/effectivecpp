/**
 * 合并两个排序链表
 */

#include "common.h"

ListNode* merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
    {
        return pHead2;
    }
    else if(pHead2 == nullptr)
    {
        return pHead1;
    }

    ListNode* pMergedHead = nullptr;
    ListNode* pMergedLast = nullptr;

    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;

    while(p1 || p2)
    {
        ListNode* min= nullptr;
        if(p1 == nullptr)
        {
            min = p2;
            p2 = p2->m_pNext;
        }
        else if(p2 == nullptr)
        {
            min = p1;
            p1 = p1->m_pNext;
        }
        else
        {
            min = p1->m_nValue < p2->m_nValue ? p1:p2;
            min == p1?p1 = p1->m_pNext:p2 = p2->m_pNext;
        }

        if(pMergedHead == nullptr)
        {
            pMergedHead = min;
            pMergedLast = min;
        }
        else
        {
            if (min->m_nValue == pMergedLast->m_nValue)
            {
                delete min;
                min = nullptr;
            }

            if(min != nullptr)
            {
                pMergedLast->m_pNext = min;
                pMergedLast = min;
            }
        }
        pMergedLast->m_pNext = nullptr;
    }
    return pMergedHead;
}

ListNode* merge_v2(ListNode* pHead1,ListNode* pHead2)
{
    if(pHead1 == nullptr)
    {
        return pHead2;
    }
    else if(pHead2 == nullptr)
    {
        return pHead1;
    }
    ListNode* pMergedHead = nullptr;
    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = merge_v2(pHead1->m_pNext,pHead2);
    }else
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = merge_v2(pHead1,pHead2->m_pNext);
    }
    return pMergedHead;

}


void merge(vector<int> &v1,vector<int> &v2,vector<int> &result)
{

}

int main(int argc, char const *argv[])
{

    int a[5]={1,2,5,7,9};
    int b[5]={2,4,6,8,10};

    ListNode* pHead1 = listInitial(a,5);
    ListNode* pHead2 = listInitial(b,5);

    printList(pHead1);
    printList(pHead2);

    ListNode* pMergedHead;
    pMergedHead = merge(pHead1,pHead2);

    printList(pMergedHead);

    return 0;
}

