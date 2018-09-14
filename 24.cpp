/**
 * 反转链表
 */


#include "common.h"

ListNode* reverseList(ListNode* pHead)
{
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;

    while(pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;

        if (pNext == nullptr) {
            pReversedHead = pNode;
        }

        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

int main(int argc, char const *argv[])
{
//    ListNode p1(1),p2(2),p3(3),p4(4),p5(5);
//    p1.m_pNext = &p2;
//    p2.m_pNext = &p3;
//    p3.m_pNext = &p4;
//    p4.m_pNext = &p5;

//    printList(&p1);
    int p_data[5]{1,2,3,4,5};
    ListNode *head = listInitial(p_data,5);
    printList(head);

    listDestroy(head);
    return 0;
}