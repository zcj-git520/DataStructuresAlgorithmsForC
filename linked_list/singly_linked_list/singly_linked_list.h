#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

// template<class T>

// 数据节点的数据结构
class SinglyLinkedNode
{
public:
   SinglyLinkedNode(){
       next = 0;
   };
    // 创建新的node
   SinglyLinkedNode(int data)
   {
       this->data = data;
       next = 0;
   };
   ~SinglyLinkedNode(){};
   int data;             // 链表的数据
   SinglyLinkedNode *next;  // 指向下一个节点
};

// 链表的数据结构
class SinglyList
{
private:
    /* data */
    SinglyLinkedNode *head;   // 头节点
    SinglyLinkedNode *tail;   // 尾节点
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
    // 链表是否为空
    bool ismpty()
    {
        return head == 0;
    }
    // 插入到链表的头部
    void inseartToHead(int data);  
    // 插入到链表的尾部
    void inseartTotail(int data); 
    // 插入到链表的index
    void inseartToindex(int index, int data); 
    // 删除链表的头部元素
    void deleteToHead();
    // 删除链表的尾部元素
    void deleteToTail();
    // 删除链表的index元素
    void deleteToIndex(int index);
    // 查询链表的所有值
    void queryAll();
    // 返回index的值
    int queryIndex(int index);
    // 判断value是否存在
    bool queryValue(int data);
};
#endif
