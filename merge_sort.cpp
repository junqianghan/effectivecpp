//
// Created by han on 18-9-19.
//

#include "common.h"


void merge_sort(int a[], int start, int middle, int end)
{
    if(start > end )
        return;

    int *array = new int[end-start+1];

    int i=start,j=middle+1,k=0;
    while(i<=middle && j<=end)
    {
        if(a[i] < a[j])
        {
            array[k++] = a[i++];
        }
        else
        {
            array[k++] = a[j++];
        }
    }

    while(i<=middle)
    {
        array[k++] = a[i++];
    }

    while(j<=end)
    {
        array[k++] = a[j++];
    }

    for(int i=0;i<end-start+1;i++)
    {
        a[start + i] = array[i];
    }
    delete array;
}


typedef int TYPE;
#define MIN_MAX INT32_MAX

void k_merge(TYPE** arrs, int *lens, int k)
{
    int*    cnts       = new int[k];
    int*    has_next   = new int[k];
    TYPE*   datas      = new int[k];

    int i = 0;
    int min_index = 0;
    TYPE min;

    for(int i=0;i<k;i++)
    {
        if(lens[i] >= 1)
        {
            datas[i] = arrs[i][0];
            cnts[i] = 1;
            has_next[i] = 1;
        }
        else
        {
            has_next[i] = 0;
        }
    }


    while(1)
    {
        min = MIN_MAX;
        min_index = 0;
        for(i=0;i<k;i++)
        {
            if(has_next[i])
            {
                if(datas[i] < min)
                {
                    min = datas[i];
                    min_index = i;
                }
            }
        }
        if(min == MIN_MAX)
        {
            break;
        }
        else
        {
            printf("%d\n",datas[min_index]);

            if(cnts[min_index] < lens[min_index])
            {
                datas[min_index] = arrs[min_index][cnts[min_index]];
                cnts[min_index]++;
            }
            else
            {
                has_next[min_index] = 0;
            }
        }
    }

    delete[] cnts;
    delete[] datas;
    delete[] has_next;
}


int main(int argc, char const *argv[])
{

//    int a[6] = {1,3,5,2,4,6};
//
//    copy(a,a+6,ostream_iterator<int>(cout," "));
//    cout<<endl;
//
//    merge_sort(a,0,2,5);
//    copy(a,a+6,ostream_iterator<int>(cout," "));
//    cout<<endl;

    TYPE a[5] = {1,3,5,7,17};
    TYPE b[3] = {-1,10,20};
    TYPE c[4] = {-20,30,88,111};

    TYPE *arrs[3] = {a,b,c};

    int len[3] = {5,3,4};

    k_merge(arrs,len,3);




    return 0;
}