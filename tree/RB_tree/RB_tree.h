/**
 * @file RB_tree.h
 * @brief 
 * @author zhaochengji (909536346@qq.com)
 * @version 1.0
 * @date 2022-01-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef RB_TREE
#define RB_TREE
#include <string>

// 颜色的定义
enum RBColor
{
    Red,
    Black,
};
// 定义节点
template<class T>
class RBTreeNode
{
public:
    RBTreeNode(/* args */){};
    RBTreeNode(T data)
    {
        this->data = data;
        left = 0;
        right = 0;
        parent = 0;
        color = Red;   // 初始化颜色为红色   
    }
    ~RBTreeNode(){};
    T data;    // 定义数据
    RBTreeNode *left;   // 定义左节点
    RBTreeNode *right;  // 定义右节点
    RBTreeNode *parent; // 父节点
    RBColor color;      // 节点的颜色
};

// 定义红黑树
template<class T>
class RBTree
{
private:
    RBTreeNode<T> *root;   // 根节点
     // 插入节点
    void inseartNode(RBTreeNode<T>*& node, const T data);
    void deleteNodeAll(RBTreeNode<T> *node); // 删除所有节点
    // 显示节点
    void DLR(RBTreeNode<T> *node);
    void LDR(RBTreeNode<T> *node);
    void LRD(RBTreeNode<T> *node);
    // 删除*&代表指针引用
    bool deleteNode(RBTreeNode<T>*& node, const T data);
    // 右旋
    void LL(RBTreeNode<T> *&node);
    // 左旋
    void RR(RBTreeNode<T> *&node);
    // 颜色调整
    void colorAdjust(RBTreeNode<T> *&node);
    // 获得节点的颜色
    RBColor getColor(RBTreeNode<T> *node);
    // 树的调整
    void treeAdjust(RBTreeNode<T> *&node);
    // 是否为红色
    bool isRed(RBTreeNode<T> *node);
public:
    RBTree()
    { 
        root = 0;
    }
    ~RBTree();
     // 清空树
    void clear();
    // 是否为空树
    bool isEmpty()
    {
        return root == 0;
    }
    // 插入数据
    void inseartData(const T data);
    // 深度优先遍历树
    // 前序遍历(DLR 根->左->右)
    void showNodeByDLR();
    // 中序遍历(LDR 左->根->右)
    void showNodeByLDR();
    // 后序遍历(LRD 左->右->根)
    void showNodeByLRD();
    // 删除节点的数据
    bool remove(const T data);
    // LVR查找树
    bool LVRSearchData(const T data);
};
#endif