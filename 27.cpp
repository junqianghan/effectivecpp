
/**
 * 二叉树镜像
 */

#include "common.h"

void MirrorRecursively(BinaryTreeNode *pNode)
{
    if(pNode == nullptr)
        return;
    if(pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
        return;

    swap(pNode->m_pLeft,pNode->m_pRight);

    if(pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);
    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

int main(int argc, char const *argv[])
{
    BinaryTreeNode p1(1),p2(2),p3(3);
    p1.m_pLeft = &p2;
    p1.m_pRight = &p3;

    MirrorRecursively(&p1);
    return 0;
}