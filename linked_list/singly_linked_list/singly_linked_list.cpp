#include "singly_linked_list.h"
#include <iostream>

/*
定义加减链表的节点数
*/
const int addOne = 1;
const int ReductOne = -1;

int glableNum = 1;

using namespace std;

template<class T>
SinglyList<T>::~SinglyList()
{
    clear();
}

// 插入到链表的尾部
template<class T>
void SinglyList<T>::inseartTotail(T data)
{
    // 定义node
    SinglyLinkedNode<T> *new_node;
    new_node = new SinglyLinkedNode<T>(data);
    // 链表为空
    if (ismpty())
    {
        head = tail = new_node; // 头尾节点都指向新创节点
        setlen(addOne);              // 节点数+1
        return;
    }
    tail->next = new_node;
    tail = tail->next;
    setlen(addOne);
}

// 插入到链表的头部
template<class T>
void SinglyList<T>::inseartToHead(T data)
{
    SinglyLinkedNode<T> *node;
    node = new SinglyLinkedNode<T>(data);
    if (ismpty()){
        head = tail = node;
        setlen(addOne);
        return ;
    }
    node->next = head;
    head = node;
    setlen(addOne);
}

// 插入到链表的index
template<class T>
void SinglyList<T>::inseartToindex(int index, T data)
{
    int len;
    len = getlen()-1;
     // 如果链表为空, 或者插入到末尾,或者index <0 采用尾插法添加到链表中
    if (ismpty() || index ==len || index < 0)
    {
        inseartTotail(data);
        return;
    }
    if(index == 0){
        inseartToHead(data);
        return;
    }
    SinglyLinkedNode<T> *node;
    node = new SinglyLinkedNode<T>(data);
    int __index = 1;
    for (node = head; node != tail; node = node->next)
    {
        if (__index == index)
        {
            SinglyLinkedNode<T> *new_node;
            new_node = new SinglyLinkedNode<T>(data);
            new_node ->next = node->next;
            node->next = new_node;
            setlen(addOne);
            return;
        }
        __index ++;
    }
}

//  清空链表
template<class T>
void SinglyList<T> ::clear()
{
    while (!ismpty())
    {
        SinglyLinkedNode<T> *node = head->next;
        delete head;
        head = node;
    }
}

// 删除链表的头部元素
template<class T>
void SinglyList<T>::deleteToHead()
{
    // 链表为空
    if(ismpty())
    {
        return;
    }
    SinglyLinkedNode<T> *tmp = head;
    // 链表只存在一个值
    if(head == tail)
    {
        head = tail = 0;
    }
    else
    {
        head = head->next;
    }
    delete tmp; // 释放资源
    setlen(ReductOne);
}

// 删除链表的尾部元素
template<class T>
void SinglyList<T> ::deleteToTail()
{
    // 链表为空
    if(ismpty())
    {
        return;
    }
    // 链表只存在一个值
    if(head == tail)
    {
        delete head;
        setlen(ReductOne);
        head = tail = 0;
        return;
    }
    SinglyLinkedNode<T> *tmp = head;
    while (tmp->next != tail)
    {
        tmp  = tmp->next;
    }
    delete tail;
    tail = tmp;
    tail->next = 0;
    setlen(ReductOne);
}

// 删除链表的index元素
template<class T>
void SinglyList<T> ::deleteToIndex(int index)
{
    // 链表为空
    if(ismpty())
    {
        return;
    }
    // 链表只存在一个值
    if(head == tail)
    {
        delete head;
        setlen(ReductOne);
        head = tail = 0;
        return;
    }
    int len = getlen();
    if (index >= len-1 || index < 0)
    {
        deleteToTail();
        return;
    }
    if (index == 0)
    {
        deleteToHead();
        return;
    }

    SinglyLinkedNode<T> *node = head;
    SinglyLinkedNode<T> *tmp = head->next;
    int __index = 1;
    while (__index != index)
    {
        node = node->next;
        tmp = tmp->next;
        __index ++;
    }
    node->next = tmp->next;
    delete tmp;
    setlen(ReductOne);
}

// 查询链表的所有值
template<class T>
void SinglyList<T> ::queryAll()
{
    if (ismpty()){
        cout << "The list length is empty" << endl;
        return;
    }
    int i = 1;
    cout << "The length of the list is zero:" << getlen() << endl;
    SinglyLinkedNode<T> *node;
    for(node = head; node != tail->next; node = node->next){
        cout << "node num is:" << i << "  data:" << node->data << endl;
        i++;
    }
}

template<class T>
void SinglyList<T> ::query(SinglyLinkedNode<T> *node)
{
    if(node == tail->next)
    {
        return;
    }
    cout << "node num is:" << glableNum << "  data:" << node->data << endl;
    glableNum ++;
    query(node->next);
}

// 查询链表的所有值通过递归
template<class T>
void SinglyList<T> ::queryAll1()
{
     if (ismpty()){
        cout << "The list length is empty" << endl;
        return;
    }
    int i = 1;
    cout << "The length of the list is zero:" << getlen() << endl;
    SinglyLinkedNode<T> *node = head;
    query(node);
}

// 返回index的值
template<class T>
bool SinglyList<T> ::queryIndex(int index, T *info)
{
    int len = getlen();
    // 链表为空, 索引不存在
    if(ismpty() || index > len -1 || index < 0)
    {
        return false;
    }
   if (index == 0)
   {
       *info = head ->data;
       return true;
   }
   if (index == len -1)
   {
       *info = tail ->data;
       return true;
   }
   int __index = 1;
   for (SinglyLinkedNode<T> *node = head->next; node != tail; node = node->next)
   {
       if (index == __index)
       {
           *info = node->data;
           return true;

       }
        __index ++; 
   }
   return false;
}

//// 判断value是否存在
template<class T>
bool SinglyList<T> ::queryValue(T value)
{
    // 链表为空
    if(ismpty())
    {
        return false;
    }
    // 链表只存在一个值
    if(head == tail)
    {
        if (head->data == value){
            return true;
        }
        return false;
    }

    for(SinglyLinkedNode<T> *node = head; node != tail->next; node = node->next)
    {
        if(node->data == value)
        {
            return true;
        }
    }
    return false;
}

// 测试
int main()
{
    SinglyList<int> newList;
    newList.inseartTotail(1);
    newList.inseartTotail(2);
    newList.inseartTotail(3);
    newList.inseartToHead(0);
    newList.inseartToHead(-11);
    newList.inseartToHead(-12);
    newList.inseartToHead(-13);
    newList.inseartToindex(6,5);
    newList.inseartToindex(-7,51);
    cout << "*********************queryAll***************************"<< endl;
    newList.queryAll();
    cout << "*********************queryAll1***************************"<< endl;
    newList.queryAll1();
    cout << "************************************************"<< endl;
    newList.deleteToHead();
    newList.queryAll();
    cout << "************************************************"<< endl;
    newList.deleteToTail();
    // newList.clear();
    newList.queryAll();
    cout << "************************************************"<< endl;
    newList.deleteToTail();
    newList.queryAll();
    cout << "************************************************"<< endl;
    newList.deleteToIndex(3);
    newList.queryAll();
    cout << "************************************************"<< endl;
    int info;
    int index = 0;
    if (newList.queryIndex(index, &info))
    {
        cout << "exits index: " << index << " => value is " << info<<  endl;
    }
    
    cout << "************************************************"<< endl;
    cout << newList.queryValue(2) << endl;
    system("pause");
    return 0;
}
