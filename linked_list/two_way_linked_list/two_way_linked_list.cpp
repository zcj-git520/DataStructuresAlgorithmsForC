#include "two_way_linked_list.h"
#include <iostream>

using namespace std;

/*
定义加减链表的节点数
*/
const int addOne = 1;
const int ReductOne = -1;

template<class T>

TwoWayList<T> ::~TwoWayList()
{
  clear();
}

template<class T>
void TwoWayList<T> ::inseartToHead(T data)
{
   TwoWayLinkedNode<T> *new_Node = new TwoWayLinkedNode<T>(data); 
   // 链表为空
   if (isEmpty())
   {
      head = tail = new_Node;
   }
   else
   {
      new_Node->next = head;   // 新节点的后驱指向头节点
      head->prev = new_Node;   // 头节点的前驱指向新节点
      head = new_Node;         // 将新节点设置新的头节点
   }
   setlen(addOne);
}

template<class T>
void TwoWayList<T> ::inseartTotail(T data)
{
   TwoWayLinkedNode<T> *new_Node = new TwoWayLinkedNode<T>(data);
   if(isEmpty())
   {
      head = tail = new_Node;
   }
   else
   {
      tail->next = new_Node;  // 尾节点的next指向新节点
      new_Node->prev = tail;  // 新节点的前驱指向尾节点
      tail = new_Node;        // 将新节点设置为新的尾节点
   }
   setlen(addOne);
}

template<class T>
void TwoWayList<T> ::inseartToindex(int index, T data)
{
   int len = getlen();
   if(index == 0)
   {
      inseartToHead(data);
      return;
   }
   // 链表为空，当index 小于0 或者大于等于链表数，采用尾插法
   if (isEmpty() || index < 0 || index >= len)
   {
      inseartTotail(data);
      return;
   }
   TwoWayLinkedNode<T> *node = head;
   int __index = 1;
   while (__index != index)
   {
      node = node->next;
      __index ++;
   }
   TwoWayLinkedNode<T> *new_node = new TwoWayLinkedNode<T>(data);
   node->next->prev = new_node;   // node节点的后继节点的先驱要指向新节点
   new_node->prev = node;         // 新节点的先驱要指向node
   new_node->next = node->next;   // 新节点的后继要指向node的后继
   node->next = new_node;         // node的后继要指向新节点
   setlen(addOne);
}

template<class T>
void TwoWayList<T> ::clear()
{
   while (!isEmpty())
   {
      TwoWayLinkedNode<T> *node = head->next;
      delete head;
      head = node;
   }
   
}

template<class T>
void TwoWayList<T> ::deleteToHead()
{
   // 链表为空就返回
   if(isEmpty())
   {
      return;
   }
   // 链表只存在一个节点
   if(head == tail)
   {
      delete head;
      head = tail = 0;
   }
   else{
       head = head->next;                // 将下一节点设置头节点
      delete head->prev;                // 释放新的头节点的前驱节点
      head->prev = 0;                   // 头节点的先驱设置nil
   }
   setlen(ReductOne);
}

template<class T>
void TwoWayList<T> ::deleteToTail()
{
    // 链表为空就返回
   if(isEmpty())
   {
      return;
   }
   // 链表只存在一个节点
   if(head == tail)
   {
      delete head;
      head = tail = 0;
   }
   else{
      tail = tail->prev;                // 尾节点的先驱节点重新设置为新的尾节点
      delete tail->next;                // 释放新的尾节点的后驱
      tail->next = 0;                   // 新的尾节点的后驱指向尾nil
   }
   setlen(ReductOne);
   
}

template<class T>
void TwoWayList<T> ::deleteToIndex(int index)
{
   len = getlen();
   // 链表为空,就返回
   if(isEmpty())
   {
      return;
   }
   // index >= len || index < 0 采用删除末尾值
   if (index >= len || index < 0)
   {
      deleteToTail();
      return;
   }
   if(index == 0)
   {
      deleteToHead();
      return;
   }
   if (index == len - 1)
   {
      deleteToTail();
      return;
   }
   int __index = 1;
   TwoWayLinkedNode<T> *node = head->next;
   while (__index != index)
   {
      node = node->next;
      __index ++;
   }
   node->prev->next = node->next;  // node节点的先驱节点的后驱指向node的后驱
   node->next->prev = node->prev;  // node节点的后驱节点的先驱指向node的先驱
   delete node;  // 释放node
   setlen(ReductOne);
}

template<class T>
void TwoWayList<T> ::queryAll()
{
   if (isEmpty())
   {
        cout << "The list length is empty" << endl;
        return;
    }

   cout << "The length of the two way list is zero:" << getlen() << endl;
   int __index = 1;
   TwoWayLinkedNode<T> *node = head;
   while (node != tail->next)
   {
      cout << "node num is:" << __index << "  data:" << node->data << endl;
      node = node->next;
      __index++; 
   }
   
}

template<class T>
bool TwoWayList<T> ::queryIndex(int index, T *data)
{
   len = getlen();
   // 链表为空,index >= len || index < 0  就返回
   if(isEmpty() || index >= len || index < 0)
   {
      return false;
   }
   int __index = 0;
   for(TwoWayLinkedNode<T> *node = head; node != tail->next; node = node->next)
   {
      if (__index == index)
      {
         *data = node->data;
         return true;
      }
      __index++;

   }
   return false;

}

template<class T>
bool TwoWayList<T> ::queryValue(T data)
{
    if(isEmpty())
   {
      return false;
   }
   for(TwoWayLinkedNode<T> *node = head; node != tail->next; node = node->next)
   {
      if (node->data == data)
      {
         return true;
      }
   }
   return false;
   
}
int main()
{
   TwoWayList<int> newList;
   newList.inseartToHead(3);
   newList.inseartToHead(2);
   newList.inseartToHead(1);
   newList.inseartToHead(-11);
   newList.inseartTotail(4);
   newList.inseartTotail(5);
   newList.inseartTotail(6);
   newList.inseartTotail(7);
   newList.inseartTotail(8);
   newList.queryAll();
   cout << "****************************************************"<< endl;
   newList.inseartToindex(2, 11);
   newList.inseartToindex(0, 2);
   newList.inseartToindex(1, 3);
   newList.queryAll();
   cout << "****************************************************"<< endl;
   newList.deleteToHead();
   newList.deleteToHead();
   newList.deleteToHead();
   newList.queryAll();
   // newList.clear();
   cout << "****************************************************"<< endl;
   newList.deleteToTail();
   newList.deleteToTail();
   newList.deleteToTail();
   newList.deleteToTail();
   newList.queryAll();
   cout << "****************************************************"<< endl;
   newList.deleteToIndex(4);
   newList.queryAll();
   cout << "****************************************************"<< endl;
   int index = 1;
   int info;
   if(newList.queryIndex(index, &info))
   {
      cout << "exits index: " << index << " => value is " << info<<  endl;
   }
   else
   {
      cout <<" no exits index:" << index << endl;
   }
   cout << "****************************************************"<< endl;
   newList.queryAll();
   cout << newList.queryValue(1)<< endl;
   system("pause");
   return 0;
}
