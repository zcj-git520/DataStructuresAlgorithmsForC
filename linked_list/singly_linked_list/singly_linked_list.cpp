#include "singly_linked_list.h"
#include <iostream>

/*
定义加减链表的节点数
*/
const int addOne = 1;
const int ReductOne = -1;

using namespace std;

SinglyList::~SinglyList()
{
    while(!ismpty())
    {
        SinglyLinkedNode *node;
        node = head->next;
        delete head;
        head = node;
    }
}

// 插入到链表的尾部
void SinglyList::inseartTotail(int data)
{
    // 定义node
    SinglyLinkedNode *new_node;
    new_node = new SinglyLinkedNode(data);
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
void SinglyList::inseartToHead(int data)
{
    SinglyLinkedNode *node;
    node = new SinglyLinkedNode(data);
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
void SinglyList::inseartToindex(int index, int data)
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
    SinglyLinkedNode *node;
    node = new SinglyLinkedNode(data);
    int __index = 1;
    for (node = head; node != tail; node = node->next)
    {
        if (__index == index)
        {
            SinglyLinkedNode *new_node;
            new_node = new SinglyLinkedNode(data);
            new_node ->next = node->next;
            node->next = new_node;
            setlen(addOne);
            return;
        }
        __index ++;
    }
}

// 删除链表的头部元素
void SinglyList::deleteToHead()
{
    // 链表为空
    if(ismpty())
    {
        return;
    }
    SinglyLinkedNode *tmp = head;
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
void SinglyList::deleteToTail()
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
    SinglyLinkedNode *tmp = head;
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
void SinglyList::deleteToIndex(int index)
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

    SinglyLinkedNode *node = head;
    SinglyLinkedNode *tmp = head->next;
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
void SinglyList::queryAll()
{
    if (ismpty()){
        cout << "The list length is empty" << endl;
        return;
    }
    int i = 1;
    cout << "The length of the list is zero:" << getlen() << endl;
    SinglyLinkedNode *node;
    for(node = head; node != tail->next; node = node->next){
        cout << "node num is:" << i << "  data:" << node->data << endl;
        i++;
    }
}

// 返回index的值
int SinglyList::queryIndex(int index)
{
    int len = getlen();
    // 链表为空, 索引不存在
    if(ismpty() || index > len -1 || index < 0)
    {
        return -1;
    }
   if (index == 0)
   {
       return head ->data;
   }
   if (index == len -1)
   {
       return tail ->data;
   }
   int __index = 1;
   for (SinglyLinkedNode *node = head->next; node != tail; node = node->next)
   {
       if (index == __index)
       {
           return node->data;

       }
        __index ++; 
   }
   return -1;
}

//// 判断value是否存在
bool SinglyList::queryValue(int value)
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

    for(SinglyLinkedNode *node = head; node != tail->next; node = node->next)
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
    SinglyList newList;
    newList.inseartTotail(1);
    newList.inseartTotail(2);
    newList.inseartTotail(3);
    newList.inseartToHead(0);
    newList.inseartToHead(-11);
    newList.inseartToHead(-12);
    newList.inseartToHead(-13);
    newList.inseartToindex(6,5);
    newList.inseartToindex(-7,51);
    newList.queryAll();
    cout << "************************************************"<< endl;
    newList.deleteToHead();
    newList.queryAll();
    cout << "************************************************"<< endl;
    newList.deleteToTail();
    newList.queryAll();
    cout << "************************************************"<< endl;
    newList.deleteToTail();
    newList.queryAll();
    cout << "************************************************"<< endl;
    newList.deleteToIndex(3);
    newList.queryAll();
    cout << "************************************************"<< endl;
    cout << newList.queryIndex(5) << endl;
     cout << "************************************************"<< endl;
    cout << newList.queryValue(21) << endl;
    system("pause");
    return 0;
}
