#include "base_sort.h"
#include <iostream>

using namespace std;

template<class T>
int getArraylen(T& array)
{
    return sizeof(array)/sizeof(array[0]);
}

template<class T>
void BaseSore<T> ::insertSore(T data[], int len)
{
    // 插入排序
    /*
        插入排序基本思想是每一步将一个待排序的记录，插入到前面已经排好序的有序序列中去，直到插完所有元素为止。
    */
    if(len <= 0)
    {
        return;
    }
    int j;
    // 遍历数组
    for(int i = 0; i < len; i ++)
    {
        T temp = data[i];
        // 将比i大的值移到i的右边
        for(j = i; j > 0 && temp < data[j-1]; j--)
        {
            data[j] = data[j -1];
        }
        data[j] = temp;
    }
}

template<class T>
void BaseSore<T> ::selectSort(T data[], int len)
{
    /*
        选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。
        首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
        然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
        以此类推，直到所有元素均排序完毕
    */
    // 选择排序
    if(len <= 0)
    {
        return;
    }
    int j, min;
    for(int i = 0; i < len -1; i ++)
    {
        //最小值为设定为i
        min = i;
        // 找到i后的最小值
        for(j = i + 1; j < len; j ++)
        {
            if(data[j] < data[min])
            {
                min = j;
            }
        }
        // 如果min改变就交换
        if(min != i)
        {
            T temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
}

template<class T>
void BaseSore<T> ::bubbleSort(T data[], int len)
{
    /*
        冒泡排序的基本思想是：对相邻的元素进行两两比较，顺序相反则进行交换，
        这样，每一趟会将最小或最大的元素“浮”到顶端，最终达到完全有序
    */
    if(len <= 0)
    {
        return;
    }
    for(int i = 0; i < len -1; i ++)
    {
        for(int j = len -1; j > i; j --)
        {
            // j 的值比 j-1的值大就交换
            if(data[j] < data[j -1])
            {
                T temp = data[j];
                data[j] = data[j -1];
                data[j -1] = temp;
            }
        }
    }
}

template<class T>
void BaseSore<T> ::printData(T data[], int len, bool isOrder)
{
    if(len <= 0)
    {
        cout << "no datas" << endl;
    }
    // 增序
    if(isOrder)
    {
        cout << "order data is :" ;
        for(int i = 0; i < len; i++)
        {
            cout << data[i] << " "; 
        }
        cout << endl;
    }
    // 由大到小
    else
    {
        cout << "reduced order data is:";
        for(int i = len -1 ; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {63,-1,4,75,6,17};
    BaseSore<int> s;
    int len = getArraylen(a);
    // s.insertSore(a, len);
    // s.selectSort(a, len);
    s.bubbleSort(a, len);
    s.printData(a, len, false);
    // len(a);  
    system("pause");
    return 0;
}
