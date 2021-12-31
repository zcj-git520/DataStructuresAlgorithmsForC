#ifndef CIRCULAR_DOUBLE_LINKED_LIST
#define CIRCULAR_DOUBLE_LINKED_LIST

// 循环双向链表节点
template<class T>
class CircularDoubleLinkedNode
{
public:
    CircularDoubleLinkedNode()
    {
        prev = next = 0;
    }
    CircularDoubleLinkedNode(T data)
    {
        info = data;
        prev = next = 0;
    }
    ~CircularDoubleLinkedNode(){};
    T info;     // 数据
    CircularDoubleLinkedNode *prev;   // 先驱节点
    CircularDoubleLinkedNode *next;   // 后继节点
};

template<class T>
class CircularDoubleList
{
private:
    CircularDoubleLinkedNode<T> *current_node;  // 指向当前节点
    int len;    // 链表的长度
public:
    CircularDoubleList()
    {
        current_node = 0;
        len = 0;
    }
    ~CircularDoubleList();
    void addLen()
    {
        len++;
    }
    void reduceLen()
    {
        len--;
    }
    int getLen()
    {
        return len;
    }
    bool isEmpty()
    {
        return current_node == 0;
    }
    void inseartNode(T data);
    bool deleteNode();
    void queryAll();
    // 判断value是否存在
    bool queryValue(T data);
};

#endif