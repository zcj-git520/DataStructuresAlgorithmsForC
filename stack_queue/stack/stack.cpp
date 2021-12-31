/*
栈：是一种线性结构，数据的存储与获取只能靠一端，先进后出（first in last out）
基于单向链表
*/

#include "stack.h"
#include <iostream>

using namespace std;

template<class T>
Stack<T> ::~Stack()
{
    clear();
}

template<class T>
void Stack<T> ::clear()
{
    list.clear();
}

template<class T>
void Stack<T> ::push(T data)
{
    list.inseartToHead(data);
}

template<class T>
bool Stack<T> ::pop(T *info)
{
    // 判断栈顶是否有值
    if(getTopValue(info))
    {
        list.deleteToHead();  // 删除栈顶值
        return true;
    }
    return false;
}

template<class T>
bool Stack<T> ::getTopValue(T *info)
{
     // 判断栈顶是否有值
    if(list.queryIndex(0, info))
    {
        return true;
    }
    return false;
}

template<class T>
void Stack<T> ::showStack()
{
    list.queryAll();
}

int main()
{
    Stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.showStack();
    cout << "********************************" << endl;
    int info = -1;
     if(s.getTopValue(&info))
    {
        cout << "top value is: " <<info << endl;
    }
    if(s.getTopValue(&info))
    {
        cout << "top value is: " <<info << endl;
    }
    if(s.getTopValue(&info))
    {
        cout << "top value is: " <<info << endl;
    }
    cout << "********************************" << endl;
    s.showStack();
    cout << "********************************" << endl;
    if(s.pop(&info))
    {
        cout << "top value is: " <<info << endl;
    }
    if(s.pop(&info))
    {
        cout << "top value is: " <<info << endl;
    }
    if(s.pop(&info))
    {
        cout << "top value is: " <<info << endl;
    }
    if(s.pop(&info))
    {
        cout << "top value is: " <<info << endl;
    }
    cout << "********************************" << endl;
    s.showStack();
    cout << "********************************" << endl;
    system("pause");
    return 0;
}
