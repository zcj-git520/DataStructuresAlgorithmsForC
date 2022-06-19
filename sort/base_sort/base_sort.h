#ifndef BASE_SORT
#define BASE_SORT

template <class T>

class BaseSore
{
private:
    /* data */
   
public:
    BaseSore(/* args */){};
    ~BaseSore(){};
    void insertSore(T data[], int len);   // 插入排序
    void selectSort(T data[], int len);   // 选择排序
    void bubbleSort(T data[], int len);   // 冒泡排序
    void printData(T data[], int len, bool isOrder);    // 打印数组
};




#endif