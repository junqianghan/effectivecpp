//
// Created by han on 18-9-18.
//
#include "common.h"-
#include <deque>


int BinaryWidth(BinaryTreeNode *root)
{
    if(root== nullptr)
        return 0;

    int max_width = 1;
    int this_level = 1;
    int next_level = 0;
    deque<BinaryTreeNode*> d;
    d.push_back(root);

    while(d.size())
    {
        BinaryTreeNode* pNode = d.front();
        d.pop_front();
        if(pNode->m_pRight)
        {
            next_level++;
            d.push_back(pNode->m_pRight);
        }

        if(pNode->m_pLeft)
        {
            next_level++;
            d.push_back(pNode->m_pLeft);
        }

        this_level--;
        if(this_level == 0)
        {
            this_level = next_level;
            max_width = max(max_width,next_level);
            next_level = 0;
        }
    }
    return max_width;

}


int BinaryDepth(BinaryTreeNode* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    return max(BinaryDepth(root->m_pLeft),BinaryDepth(root->m_pRight))+1;
}

// 正常二叉树寻找最近公共祖先
BinaryTreeNode* GetLastCommonAncestor(
    BinaryTreeNode* pRoot,
    BinaryTreeNode* pNode1,
    BinaryTreeNode* pNode2
)
{
    if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
    {
        return nullptr;
    }

    if(pNode1 == pRoot || pNode2 == pRoot)
    {
        return pRoot;
    }

    BinaryTreeNode* left_lca = GetLastCommonAncestor(pRoot->m_pLeft,pNode1,pNode2);
    BinaryTreeNode* right_lca = GetLastCommonAncestor(pRoot->m_pRight,pNode1,pNode2);

    if(left_lca && right_lca)
    {
        return pRoot;
    }

    if(left_lca == nullptr)
    {
        return right_lca;
    } else
    {
        return left_lca;
    }
}


int main(int argc, char const *argv[])
{
    BinaryTreeNode p0(0),p1(1),p2(2),p3(3),p4(4),p5(5),p6(6),p7(7),p8(8),p9(9);
    p0.m_pLeft = &p1;
    p1.m_pLeft = &p2;
    p1.m_pRight = &p3;

    p2.m_pLeft = &p4;
    p2.m_pRight = &p5;

    p3.m_pLeft = &p6;
    p3.m_pRight = &p7;

    p4.m_pLeft = &p8;
    p6.m_pLeft = &p9;

    cout<<BinaryWidth(&p0)<<endl;
    cout<<BinaryDepth(&p0)<<endl;

    cout<<GetLastCommonAncestor(&p0,&p4,&p8)->m_nValue<<endl;
    return 0;
}