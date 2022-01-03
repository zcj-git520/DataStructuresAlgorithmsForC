/**
 * @file binary_tree.h
 * @brief  Binary search tree
 * @author zhaochengji (909536346@qq.com)
 * @version 1.0
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BINARY_TREE
#define BINARY_TREE


// 节点的定义
template<class T>
class BinarySearchTreeNode
{
public:
    BinarySearchTreeNode()
    {
        left = 0;
        right = 0;
    }
    BinarySearchTreeNode(T data)
    {
        this->data = data;
        left =  0;
        right = 0;
    }
    ~BinarySearchTreeNode(){};
    T data;  // 保存的节点的数据
    BinarySearchTreeNode *left; // 指向左节点
    BinarySearchTreeNode *right; // 指向右节点
};


// 树的定义
template<class T>
class BinarySearchTree
{
private:
    BinarySearchTreeNode<T> *root;  // 定义头节点
    int treeNodeNum;             // 树的节点数
    void deleteNode(BinarySearchTreeNode<T> *node); // 删除节点
    // 显示节点
    void showNode(BinarySearchTreeNode<T> *node);
public:
    BinarySearchTree()
    {
        root = 0;
        treeNodeNum = 0;
    };
    ~BinarySearchTree();
    // 清空数
    void clear();
    // 是否为空数
    bool isEmpty()
    {
        return root == 0;
    }
    // 插入数据
    void inseartNode(const T data);
    // 广度优先遍历树
    void breadthFirstTraversal();
    // 删除节点的数据
    bool deleteNode(const T data);
    // LVR查找树
    bool LVRSearchData(const T data);
};





#endif