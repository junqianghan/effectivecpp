#include "common.h"

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


BinaryTreeNode* ConstructCore(
    int* startPreOrder, int* endPreOrder,
    int* startInorder, int* endInorder
)
{
    int rootValue = *startPreOrder;
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = *startPreOrder;
    root->m_pLeft = nullptr;
    root->m_pRight = nullptr;

    if(startPreOrder == endPreOrder)
    {
        if(startInorder == endInorder && *startPreOrder == *startInorder)
        {
            return root;
        }
        else
        {
            throw std::exception("invalid input");
        }
    }

    int* rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw std::exception("invalid input");
    }

    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreOrder + leftLength;

    if(leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreOrder+1,leftPreorderEnd,startInorder,rootInorder-1);
    }

    if(leftLength < endPreOrder - startPreOrder)
    {
        root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreOrder,rootInorder+1,endInorder);
    }
    return root;
}



BinaryTreeNode* Construct(int* preorder,int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
    {
        return nullptr;
    }

    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}





int main(int argc, char const *argv[])
{




    return 0;
}