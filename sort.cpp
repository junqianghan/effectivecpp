#include "common.h"


void insert_sort(int *data, unsigned length)
{
    for(unsigned i = 1;i<length;++i)
    {
        int key = data[i];
        int j = i-1;
        while(j>=0 && data[j]>key)
        {
            data[j+1]=data[j];
            --j;
        }
        data[j+1] = key;
    }
}


void bubble_sort(int *data, unsigned length)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=length-2;j>=i;j--)
        {
            if(data[j] > data[j+1])
            {
                swap(data[j],data[j+1]);
            }
        }
    }
}

void simple_select_sort(int *data, unsigned length)
{
    for(int i=0;i<length-1;i++) {
        int min_index = i;
        for (int j = i; j < length; j++)
        {
            if(data[j]<data[min_index])
            {
                min_index=j;
            }
        }
        swap(data[i],data[min_index]);
    }
}

#define LEFT(index) 2*index+1
#define RIGHT(index) 2*index+2

void max_heapify(int* data,int i,int &heapsize)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;

    if(data[largest] < data[l] && l<=heapsize)
        largest = l;
    if(data[largest] < data[r] && r<=heapsize)
        largest = r;

    if(largest != i)
    {
        swap(data[largest],data[i]);
        max_heapify(data,largest,heapsize);
    }
}

void build_max_heap(int *data, unsigned length)
{
    int heapsize = length-1;
    for(int i=(length-2)/2;i>=0;i--)
    {
        max_heapify(data,i,heapsize);
    }
}

void heap_sort(int *data, unsigned length)
{
    build_max_heap(data,length);
    int heapsize=length-1;
    for(int i=length-1;i>=1;i--)
    {
        swap(data[i],data[0]);
        heapsize--;
        max_heapify(data,0,heapsize);
    }
}


void merge(int *data,int l,int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1+1],R[n2+1];

    for(int i=0;i<n1;i++)
    {
        L[i] = data[l+i];
    }

    for(int i=0;i<n2;i++)
    {
        R[i] = data[mid+i+1];
    }

    L[n1] = INT32_MAX;
    R[n2] = INT32_MAX;

    int i=0,j=0;
    for(int k=l;k<=r;k++)
    {
        if(L[i] < R[j])
        {
            data[k] = L[i++];
        }
        else
        {
            data[k] = R[j++];
        }
    }

}

void merge_sort(int *data,int l,int r)
{
    if(l>=r) {
        return;
    }
    int mid = (l+r)/2;

    merge_sort(data,l,mid);

    merge_sort(data,mid+1,r);

    merge(data,l,mid,r);
}

/**
 * 快排
 * @param data
 * @param l
 * @param r
 * @return
 */

int partition(int* data, int l, int r)
{
    int key = data[r];
    int small_index = l-1;
    for(int i=l;i<r;i++)
    {
        if(data[i]<key)
        {
            swap(data[i],data[++small_index]);
        }
    }
    small_index++;
    swap(data[small_index],data[r]);
    return small_index;
}

void quick_sort(int* data, int l, int r)
{
    if(r<=l)
    {
        return;
    }

    int index = partition(data,l,r);

    quick_sort(data,l,index-1);
    quick_sort(data,index+1,r);
}


int main(int argc, char const *argv[])
{

    int a[5]{2,1,4,3,5};
    quick_sort(a,0,4);
//    merge_sort(a,0,4);
//    heap_sort(a,5);
//    simple_select_sort(a,5);
//    bubble_sort(a,5);
//    insert_sort(a,5);
    copy(a,a+5,ostream_iterator<int>(cout," "));
    cout<<endl;
    return 0;
}