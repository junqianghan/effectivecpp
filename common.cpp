//
// Created by han on 18-9-14.
//

#include "common.h"


/**
 * 链表api
 * @param phead
 */
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


void Serialize(BinaryTreeNode* pRoot, ostream& stream)
{
    if(pRoot== nullptr)
    {
        stream<<"$,";
        return;
    }
    stream<<pRoot->m_nValue<<",";

    Serialize(pRoot->m_pLeft,stream);
    Serialize(pRoot->m_pRight,stream);
}


bool ReadStream(istream& stream,int& number)
{
    char ch;
    stream>>ch;
    if(ch == '$')
    {
        stream>>ch;
        return false;
    }
    else if(ch == ' ')
    {
        return false;
    }
    else
    {
        stream.unget();
        stream>>number;
        stream>>ch;
        return true;
    }
}


void Deserialize(BinaryTreeNode **pRoot, istream& stream)
{
    int number=0;
    if(ReadStream(stream,number))
    {
        *pRoot = new BinaryTreeNode(number);
        Deserialize(&((*pRoot)->m_pLeft),stream);
        Deserialize(&((*pRoot)->m_pRight),stream);
    }
}