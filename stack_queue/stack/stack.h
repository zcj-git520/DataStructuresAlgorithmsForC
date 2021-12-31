#ifndef STACK
#define STACK
#include "singly_linked_list.h"

template<class T>
class Stack
{
private:
    SinglyList<T> list;  // 存储数据的链表
public:
    Stack(/* args */){};
    ~Stack();
    // 获得栈的长度
    int len()
    {
        return list.getlen();
    }
    // 清空栈
    void clear();
    // 判断栈是否为空s
    bool isEmpty();
    // 将数据放入栈顶
    void push(T data);
    // 获取栈顶数据，并删除数据
    bool pop(T *info);
    // 获取栈顶数据但不删除数据
    bool getTopValue(T *info);
    // 显示所有栈的数据
    void showStack();
};

#endif