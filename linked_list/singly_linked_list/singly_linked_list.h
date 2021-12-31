#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

// 数据节点的数据结构
template<class T>
class SinglyLinkedNode
{
public:
   SinglyLinkedNode(){
       next = 0;
   };
    // 创建新的node
   SinglyLinkedNode(T data)
   {
       this->data = data;
       next = 0;
   };
   ~SinglyLinkedNode(){};
   T data;             // 链表的数据
   SinglyLinkedNode *next;  // 指向下一个节点
};

// 链表的数据结构
template<class T>
class SinglyList
{
private:
    /* data */
    SinglyLinkedNode<T> *head;   // 头节点
    SinglyLinkedNode<T> *tail;   // 尾节点
    int len;                  // 链表长度

public:
    SinglyList(){
        head = 0;
        tail = 0;
        len = 0;
    };
    ~SinglyList();
    // 链表的长度+1
    void setlen(int len)
    {
        this->len += len;
    }; 
    // 返回链表的长度
    int getlen()
    {
        return len;
    };
    // 情况链表
    void clear();
    // 链表是否为空
    bool ismpty()
    {
        return head == 0;
    }
    // 插入到链表的头部
    void inseartToHead(T data);  
    // 插入到链表的尾部
    void inseartTotail(T data); 
    // 插入到链表的index
    void inseartToindex(int index, T data); 
    // 删除链表的头部元素
    void deleteToHead();
    // 删除链表的尾部元素
    void deleteToTail();
    // 删除链表的index元素
    void deleteToIndex(int index);
    // 查询链表的所有值
    void queryAll();
    // 返回index的值
    bool queryIndex(int index, T *info);
    // 判断value是否存在
    bool queryValue(T data);
};
#endif
