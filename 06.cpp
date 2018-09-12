#include "common.h"

struct ListNode
{
  int m_nKey;
  ListNode* m_pNext;
  ListNode(int value):m_nKey(value),m_pNext(nullptr){}
  ListNode(int value,ListNode* next):m_nKey(value),m_pNext(next){}
};

void print_list(ListNode* head)
{
  if(head->m_pNext != nullptr)
  {
    print_list(head->m_pNext);
  }

  cout<<head->m_nKey<<" ";
  return;
}


int main(int argc,const char *argv[]){

  ListNode p1(1),p2(2),p3(3),p4(4);
  p1.m_pNext = &p2;
  p2.m_pNext = &p3;
  p3.m_pNext = &p4;

  print_list(&p1);
  cout<<endl;
  return 0;
}


