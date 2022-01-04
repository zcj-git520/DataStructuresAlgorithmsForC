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
    void deleteNodeAll(BinarySearchTreeNode<T> *node); // 删除所有节点
    // 显示节点
    void DLR(BinarySearchTreeNode<T> *node);
    void LDR(BinarySearchTreeNode<T> *node);
    void LRD(BinarySearchTreeNode<T> *node);
    // 删除
    void deleteNodeByMerge(BinarySearchTreeNode<T> *node); // 合并删除
public:
    BinarySearchTree()
    {
        root = 0;
        treeNodeNum = 0;
    };
    ~BinarySearchTree();
    // 清空树
    void clear();
    // 节点的个数
    int Nodes()
    {
        return treeNodeNum;
    }
    // 是否为空树
    bool isEmpty()
    {
        return root == 0;
    }
    // 插入数据
    void inseartNode(const T data);
    // 深度优先遍历树
    // 前序遍历(DLR 根->左->右)
    void showNodeByDLR();
    // 中序遍历(LDR 左->根->右)
    void showNodeByLDR();
    // 后序遍历(LRD 左->右->根)
    void showNodeByLRD();
    // 删除节点的数据
    bool removeNode(const T data);
    // LVR查找树
    bool LVRSearchData(const T data);
};





#endif