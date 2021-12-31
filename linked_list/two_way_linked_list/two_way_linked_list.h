#ifndef TWO_WAY_LINKED_LIST
#define TWO_WAY_LINKED_LIST

template<class T>
class TwoWayLinkedNode
{
public:
    TwoWayLinkedNode(/* args */){}; 
    TwoWayLinkedNode(T data)
    {
        this->data = data;
        this->prev = 0;
        this->next = 0;
    }
    ~TwoWayLinkedNode(){};
    T data;       // 数据
    TwoWayLinkedNode *next;  // 指向后继节点
    TwoWayLinkedNode *prev;   // 指向前驱
};

template<class T>
class TwoWayList
{
private:
    /* data */
    TwoWayLinkedNode<T> *head;   // 头节点
    TwoWayLinkedNode<T> *tail;   // 尾节点
    int  len;                    // 链表长度
public:
    TwoWayList()
    {
        head = 0;
        tail = 0;
        len = 0;
    };
    ~TwoWayList();
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
    // 清空链表
    void clear();
    // 链表是否为空
    bool isEmpty()
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
    bool queryIndex(int index, T *data);
    // 判断value是否存在
    bool queryValue(T data);
};

#endif