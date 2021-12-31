/*
队列：先进先出（first in first out）
基于双向链表实现
*/

#include "queue.h"
#include <iostream>

using namespace std;

template<class T>
Queue<T> ::~Queue()
{
    clear();
}

template<class T>
void Queue<T> ::clear()
{
    list.clear();
}

template<class T>
bool Queue<T> ::isEmpty()
{
    return list.isEmpty();
}

template<class T>
void Queue<T> ::enQueue(T data)
{
    list.inseartTotail(data);
}

template<class T>
bool Queue<T> ::getQueueValue(T *info)
{
    if(list.queryIndex(0, info))
    {
        return true;
    }
    return false;
}

template<class T>
bool Queue<T> ::deQueue(T *info)
{
    if(list.queryIndex(0, info))
    {
        list.deleteToHead();
        return true;
    }
    return false;
}

template<class T>
void Queue<T> ::showQueue()
{
    list.queryAll();
}
int main()
{
    Queue<int> q;
    q.enQueue(0);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.showQueue();
    cout << "**************************************"<< endl;
    int info = -1;
    if(q.getQueueValue(&info))
    {
        cout << "queue top value is: " <<info << endl;
    }
    if(q.getQueueValue(&info))
    {
        cout << "queue top value is: " <<info << endl;
    }
    if(q.getQueueValue(&info))
    {
        cout << "queue top value is: " <<info << endl;
    }
    q.showQueue();
    cout << "**************************************"<< endl;
    if(q.deQueue(&info))
    {
        cout << "queue top value is: " <<info << endl;
    }
    q.showQueue();
    cout << "**************************************"<< endl;
    if(q.deQueue(&info))
    {
        cout << "queue top value is: " <<info << endl;
    }
    q.showQueue();
    cout << "**************************************"<< endl;
    if(q.deQueue(&info))
    {
        cout << "queue top value is: " <<info << endl;
    }
    q.showQueue();
    cout << "**************************************"<< endl;
    q.clear();
    q.showQueue();
    system("pause");
    return 0;
}
