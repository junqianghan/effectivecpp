//
// Created by han on 18-9-12.
//

#ifndef EFFECTIVECPP_COMMON_H
#define EFFECTIVECPP_COMMON_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <iterator>

using namespace std;


struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int value):m_nValue(value),m_pNext(nullptr){}
};

//List api
void printList(ListNode *phead);
ListNode* listInitial(int *p_data, unsigned length);
void listDestroy(ListNode* pHead);
#endif //EFFECTIVECPP_COMMON_H
