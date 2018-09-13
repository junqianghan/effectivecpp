#include "common.h"
#include <exception>
#include <iterator>
#include <stdexcept>

int Partition(int data[],int length,int start,int end)
{
    if(data == nullptr || length <0 || start <0 || end >= length)
    {
        throw new std::exception(logic_error("invalid input"));
    }

    int index = start;
    swap(data[index],data[end]);

    int small = start - 1;
    for (int i = start; i < end; ++i) {
        if(data[i] < data[end])
        {
            ++small;
            swap(data[i],data[small]);
        }

    }
    small++;
    swap(data[small],data[end]);
    return small;
}

void quick_sort(int data[],int length,int start,int end)
{
    if(start == end)
    {
        return;
    }
    int index = Partition(data,length,start,end);

    if(index > start)
    {
        quick_sort(data,length,start,index-1);
    }
    if(index < end)
    {
        quick_sort(data,length,index+1,end);
    }
}

int main(int argc, char const *argv[])
{
    int a[5]={5,3,7,4,10};

    copy(a,a+5,ostream_iterator<int>(cout," "));
    cout<<endl;
    quick_sort(a,5,0,4);
    copy(a,a+5,ostream_iterator<int>(cout," "));
    cout<<endl;

    return 0;
}
