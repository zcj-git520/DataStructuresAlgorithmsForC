#ifndef ADVANCED_SORT
#define ADVANCED_SORT

template<class T>
class AdvancedSort
{
private:
    void _quickSort(T data[], int frist, int end); // 快排实现
    void swap(T &value1, T &value2);                 // 数值的交换
public:
    AdvancedSort(/* args */){};
    ~AdvancedSort(){};
    void shellSort(T data[], int len);   // 希尔排序
    void quickSort(T data[], int len);   // 快排
    void printData(T data[], int len, bool isOrder);    // 打印数组
}; 

#endif