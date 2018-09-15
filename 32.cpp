//
// Created by han on 18-9-14.
//

/**
 * 从上到下打印二叉树
 */


#include "common.h"
#include <deque>

//不分行
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

//分行打印

void Print(BinaryTreeNode *pRoot)
{
    if(!pRoot)
        return;

    deque<BinaryTreeNode*> dequeNode;

    int toBePrint = 1;
    int nextLevel = 0;
    dequeNode.push_back(pRoot);
    while(dequeNode.size()) {
        BinaryTreeNode *pNode = dequeNode.front();
        dequeNode.pop_front();
        cout << pNode->m_nValue << " ";
        --toBePrint;

        if (pNode->m_pLeft) {
            ++nextLevel;
            dequeNode.push_back(pNode->m_pLeft);
        }

        if (pNode->m_pRight)
        {
            ++nextLevel;
            dequeNode.push_back(pNode->m_pRight);
        }

        if(toBePrint == 0)
        {
            toBePrint = nextLevel;
            nextLevel = 0;
            cout<<endl;
        }
    }
}


int main(int argc, char const *argv[])
{
    BinaryTreeNode p1(1),p2(2),p3(3),p4(4),p5(5),p6(6),p7(7);
    p1.m_pLeft = &p2;
    p1.m_pRight = &p3;

    p2.m_pLeft = &p4;
    p2.m_pRight = &p5;

    p3.m_pLeft = &p6;
    p3.m_pRight = &p7;

    Print(&p1);

    return 0;
}
