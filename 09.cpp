#include "common.h"
#include <stack>
#include <exception>

template <typename T>
class CQueue
{
  public:
    CQueue(void){}
    ~CQueue(){}

    void appendTail(const T& node);

    T deletaHead();

  private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T &node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deletaHead()
{
    if(stack2.size() == 0)
    {
        while(stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
    {
        throw std::exception("queue is empty");
    }

    T head = stack2.top();
    stack2.pop();
    return head;
}

int main(int argc, char const *argv[])
{
    return 0;
}