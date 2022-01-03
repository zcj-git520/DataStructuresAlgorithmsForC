#include "circular_double_linked_list.h"
#include <iostream>

using namespace std;

template<class T>

CircularDoubleList<T> ::~CircularDoubleList()
{
    clear();  // 清空链表
}

template<class T>
void CircularDoubleList<T> ::clear()
{
    // 判断链表是否为空， 为空直接返回
    if(isEmpty())
    {
        return;

    }
    // 循环的删除节点， 直至到当前节点
    CircularDoubleLinkedNode<T> *node = current_node ->next;
    while (node != current_node)
    {
        delete current_node;
        current_node = node;
        CircularDoubleLinkedNode<T> *node = current_node ->next;
    }
    // 删除当前节点
    delete current_node;

}

template<class T>
void CircularDoubleList<T> ::inseartNode(T data)
{
    CircularDoubleLinkedNode<T> *new_node = new CircularDoubleLinkedNode<T>(data);
    // 如果链表为空
    if(isEmpty())
    {
        // 当前节点为新的节点
        current_node = new_node;
        current_node->next = current_node; // 后驱指向自己
        current_node->prev = current_node; // 前驱也指向自己
    }
    else
    {
        /*与双向链表中的插入到链表中是一样的*/
       current_node->next->prev = new_node;
       new_node->prev = current_node;
       new_node->next = current_node->next;
       current_node->next = new_node;
       current_node = new_node;
    }
    addLen();
}

template<class T>
bool CircularDoubleList<T> ::deleteNode()
{
    // 链表为空
    if(isEmpty())
    {
        return false;
    }
    int len = getLen();
    // 链表中只有一个元素
    if(len == 1)
    {
        delete current_node;
        current_node = 0;
        reduceLen();
        return true;
    }
    // 链表中只有两个元素
    if (len == 2)
    {
        CircularDoubleLinkedNode<T> *node = current_node;
        current_node = current_node->next;
        current_node->next = current_node;
        current_node->prev = current_node;
        delete node;
        reduceLen();
        return true;
    }
    // 链表元素达到3个及3个以上
    CircularDoubleLinkedNode<T> *node = current_node;
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    current_node = current_node->next;
    delete node;
    reduceLen();
    return true;
}

template<class T>
void CircularDoubleList<T> ::queryAll()
{
    if(isEmpty())
    {
        cout << "circular double list is empty" <<  endl;
        return;
    }

    cout << "circular double list len is:" << getLen() << endl;
    int __index = 1;
    for (CircularDoubleLinkedNode<T> *node = current_node->next; node != current_node; node = node->next)
    {
        cout << "index:" << __index << "  data is: " << node->info << endl;
        __index++;
    }
    cout << "index:" << __index << "  data is: " << current_node->info << endl;
}

template<class T>
bool CircularDoubleList<T> ::queryValue(T data)
{
    // 判断链表为空
    if(isEmpty())
    {
        return false;
    }
    // 当前节点的值== data
    if(current_node->info == data)
    {
        return true;
    }
    // 循环遍历当节点的value== data then retuen ture
    for(CircularDoubleLinkedNode<T> *node = current_node->next; node != current_node; node = node->next)
    {
        if(node->info == data)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    CircularDoubleList<int> cirList;
    cirList.inseartNode(0);
    cirList.inseartNode(1);
    cirList.inseartNode(2);
    cirList.inseartNode(3);
    cirList.queryAll();
    cout << "*****************************************************" << endl;
    cirList.deleteNode();
    cirList.deleteNode();
    // cirList.deleteNode();
    // cirList.deleteNode();
    cirList.queryAll();
    cout << "******************************************************" <<endl;
    int data = 11;
    if(cirList.queryValue(data))
    {
        cout << data << "  is exists" << endl;
    }
    else
    {
        cout << data << "  is not exists" << endl;
    }
   system("pause");
   return 0;
}
