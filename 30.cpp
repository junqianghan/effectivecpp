//
// 包含min函数的栈
//

#include "common.h"
#include <stack>

template <typename T>
struct StackWithMin{


    void pop();
    void push(const T& value);
    const T min();
    stack<T> m_data;
    stack<T> m_min;
};

template <typename T>
void StackWithMin<T>::push(const T &value)
{
    m_data.push(value);
    if(m_min.size() == 0 || value < m_min.top())
    {
        m_min.push(value);
    }
    else
    {
        m_min.push(m_min.top());
    }
}

template <typename T>
void StackWithMin<T>::pop()
{
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T StackWithMin<T>::min()
{
    return m_min.top();
}

int main(int argc, char const *argv[])
{

    return 0;
}

