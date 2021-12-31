#ifndef QUEUE
#define QUEUE

#include "two_way_linked_list.h"


template<class T>
class Queue
{
private:
    TwoWayList<T> list;  // 定义的双向链表
public:
    Queue(/* args */){};
    ~Queue();
     // 获得队列的长度
    int len()
    {
        return list.getlen();
    }
    // 清空队列
    void clear();
    // 判断栈是否为空s
    bool isEmpty();
    // 将数据存入队列尾中
    void enQueue(T data);
    // 获取获得队列数据，并删除数据
    bool deQueue(T *info);
    // 获取获得队列数据，但不删除数据
    bool getQueueValue(T *info);
    // 显示所有队列的数据
    void showQueue();
};


#endif