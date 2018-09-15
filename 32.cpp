//
// Created by han on 18-9-14.
//

/**
 * 从上到下打印二叉树
 */


#include "common.h"

#include <deque>

void PrintFromTopToBottom(BinaryTreeNode *pRoot)
{
    if(pRoot == nullptr)
    {
        return;
    }

    deque<BinaryTreeNode*> dequeTreeNode;

    dequeTreeNode.push_back(pRoot);
    while(dequeTreeNode.size())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        cout<<pNode->m_nValue<<" ";
        if(pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);
        if(pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    BinaryTreeNode p1(1),p2(2),p3(3);
    p1.m_pLeft = &p2;
    p1.m_pRight = &p3;

    PrintFromTopToBottom(&p1);

    return 0;
}
