#include <iostream>
#include <sstream>
#include "common.h"

int main()
{
    BinaryTreeNode p1(1),p2(2),p3(3);
    p1.m_pLeft = &p2;
    p1.m_pRight = &p3;

    ostringstream os;
    Serialize(&p1,os);
    cout<<os.str()<<endl;

    istringstream is(os.str());
    BinaryTreeNode *pRoot;
    Deserialize(&pRoot,is);




    return 0;
}