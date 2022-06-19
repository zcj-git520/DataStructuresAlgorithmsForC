#include "advanced_sort.h"
#include <iostream>

using namespace std;

template<class T>
int getArraylen(T& array)
{
    return sizeof(array)/sizeof(array[0]);
}

template<class T>
void AdvancedSort<T> ::swap(T &value1, T &value2)
{
    T temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

template<class T>
void AdvancedSort<T> ::printData(T data[], int len, bool isOrder)
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

template<class T>
void AdvancedSort<T> ::shellSort(T data[], int len)
{
    /*
     // 希尔排序
     希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，
     每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，算法便终止
     希尔排序的核心是：利用h个位置的元素将数组分为多个子数组
    */
    int increment = 2; // 步长因子
    int step = len/increment;  // 初始化步长
    while (step)       
    {
        // 根据步长进行分组
        for(int i = step; i < len; i ++)
        {
            // 小组排序
            T temp = data[i];
            int j = i;
            while (j >= step && temp < data[j-step])
            {
                data[j] = data[j-step];
                j -= step;
            }
            data[j] = temp;  
        }
        step /= increment;
    }
    
}

template<class T>
void AdvancedSort<T> ::_quickSort(T data[], int first, int end)
{
    if(first > end)
    {
        return;
    }
    T bound = data[first];
    int low = first;
    int hight = end;
    while (low < hight)
    {
        while(low < hight && bound <= data[hight])
        {
            hight --;
        }
        data[low] = data[hight];
        while (low < hight && bound >= data[low])
        {
            low ++;
        }
        data[hight] = data[low];
    }
    data[low] = bound;
    _quickSort(data, first, low - 1);
    _quickSort(data, low + 1, end);
    
}

template<class T>
void AdvancedSort<T> ::quickSort(T data[], int len)
{
    /*
        基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，
                   其中一部分的所有数据都比另外一部分的所有数据都要小，
                   然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，
                   以此达到整个数据变成有序序列
    */
    if(len < 2)
    {
        return;
    }
    _quickSort(data, 0, len-1);

}

int main(int argc, char const *argv[])
{
    int data[] = {1, -10, -99, 33, 32, 11,2,3,45,5,43};
    AdvancedSort<int> ad_sort;
    int len = getArraylen(data);
    // ad_sort.shellSort(data, len);
    ad_sort.quickSort(data, len);
    ad_sort.printData(data, len, true);
    system("pause");
    return 0;
}
