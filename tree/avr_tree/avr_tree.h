/**
 * @file avr_tree.h
 * @brief 左右子树高度相差不超过1：某节点的左子树与右子树的高度(深度)差即为该节点的平衡因子（BF,Balance Factor），平衡二叉树中不存在平衡因子大于 1 的节点。在一棵平衡二叉树中，节点的平衡因子只能取 0 、1 或者 -1 ，分别对应着左右子树等高，左子树比较高，右子树比较高。
 * @author zhaochengji (909536346@qq.com)
 * @version 1.0
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef AVR_TREE
#define AVR_TREE

// 定义树的节点
template<class T>
class AvrTreeNode
{
public:
    AvrTreeNode(){};
    AvrTreeNode(T data)
    {
        this->data = data;
        left = 0;
        right = 0;
        hight = -1;
    }
    ~AvrTreeNode(){};
    T data;                 // 存储的数据
    AvrTreeNode *left;      // 左子树
    AvrTreeNode *right;     // 右子树
    int hight;              // 高度 
};

// 定义树
template<class T>
class AvrTree
{
private:
    AvrTreeNode<T> *root;     // 定义根节点
    // 插入节点
    void inseartNode(AvrTreeNode<T>*& node, const T data);
    void deleteNodeAll(AvrTreeNode<T> *node); // 删除所有节点
    // 显示节点
    void DLR(AvrTreeNode<T> *node);
    void LDR(AvrTreeNode<T> *node);
    void LRD(AvrTreeNode<T> *node);
    // 删除*&代表指针引用
    bool deleteNode(AvrTreeNode<T>*& node, const T data);
    // void deleteNodeByMerge(AvrTreeNode<T>*& node); // 合并删除
    // void deleteNodeByCopy(AvrTreeNode<T>*& node);  // 复制删除
    // 单右旋
    void LL(AvrTreeNode<T> *&node);
    // 单左旋
    void RR(AvrTreeNode<T> *&node);
    // 左右旋
    void RLR(AvrTreeNode<T> *&node);
    // 右左旋
    void LRR(AvrTreeNode<T> *&node);
    // 求高度的最大值
    int maxHight(int h1, int h2)
    {
        return h1>h2 ? h1:h2;
    }
      // 得到树的高度
    int getTreeHight(AvrTreeNode<T> *node)
    {
        if(!node)
        {
            return -1;
        }
        return node->hight;
    }
public:
    AvrTree(/* args */)
    {
        root = 0;
    }
    ~AvrTree();
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