/**
 * @file skip_list.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SKIP_LIST
#define SKIP_LIST
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <climits>     /* INT_MIN */

const int max_level = 4; // 定义最大的跳表层数 
template<class T>
// 定义跳表的节点
class SkipListNode
{
public:
    SkipListNode(/* args */)
    {
        up = NULL;
        down = NULL;
        prev = NULL;
        next = NULL;
    };
    SkipListNode(T data)
    {
        this->data = data;
        // 初始化指针为nil
        up = 0;
        down = 0;
        prev = 0;
        next = 0;   
    };
    ~SkipListNode(){};
    T data;  // 节点保存的数据
    // 节点各个方向的执政
    SkipListNode *up;
    SkipListNode *down;
    SkipListNode *prev;
    SkipListNode *next;
};

// 定义跳表
template<class T>
class SkipList
{
private:
    /* data */
    SkipListNode<T> *root;  // 链表的头指针
    int level;                      // 当前链表的层数
    int len;                         // 链表的长度
public:
    SkipList(/* args */)
    {
        root = 0;
        level = 0;
        len = 0;
    };
    ~SkipList();
    // 获得链表的长度
    // int len();
    // 判断表是否为空
    bool isEmpty()
    {
        return root == NULL;
    }
    // 返回当前链表的层数
    // int level();
    // 清空链表
    void clear();
    // 数据插入到链表中
    void inseartNode(T data);
    // 删除节点
    bool deleteNode(T data);
    // 展示链表
    void showSkipList();
    // 判断value是否存在
    bool queryValue(T data);
    // 随机层
    bool randmLevel();
};




#endif