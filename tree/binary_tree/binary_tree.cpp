/**
 * @file binatry_tree.cpp
 * @brief Binary search tree
 * @author zhaochengji (909536346@qq.com)
 * @version 1.0
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "binary_tree.h"
#include <iostream>

using namespace std;

template<class T>
BinarySearchTree<T> ::~BinarySearchTree()
{
    clear();
}

// 采用递归的方式删除节点
template<class T>
void BinarySearchTree<T> ::deleteNodeAll(BinarySearchTreeNode<T> *node)
{
    // 如果的空树就结束递归
    if(!node)
    {
        return;
    }
    deleteNodeAll(node->left);
    deleteNodeAll(node->right);
    delete node;   // 释放资源
}
template<class T>
void BinarySearchTree<T> ::clear()
{
    deleteNodeAll(root);   // 清空所有节点
    treeNodeNum = 0;    // 树的节点数为0
}

template<class T>
void BinarySearchTree<T> ::inseartNode(const T data)
{
    BinarySearchTreeNode<T> *new_node = new BinarySearchTreeNode<T>(data);
    // 如果为空树
    if(isEmpty())
    {
        root = new_node;  // 新建节点设置为root 节点
        treeNodeNum ++;   // 树的节点数+1
        return;
    }
    BinarySearchTreeNode<T> *node = root;
    // 遍历树， 找到插入的节点的位置
    while (node != 0)
    {
        // 当节点的值大于插入的值时，就插入到左子数
        if(node->data > data)
        {
            // 左节点为nill, 将新节点赋值给节点的左节点
            if(node->left == NULL)
            {
                node->left = new_node;
                break;     // 推出循环
            }
            else
            {
                node = node->left;
                continue;     // 继续查找下一个节点
            }
        }
        else
        {
            // 如果右节点为nill, 右节点->新节点
            if(node->right == NULL)
            {
                node->right = new_node;
                break;
            }
            else
            {
                node = node->right;
                continue;
            }

        }    
    }
    treeNodeNum ++; // 数的节点数+1

}
template<class T>
void BinarySearchTree<T> ::DLR(BinarySearchTreeNode<T> *node)
{
    if(!node)
    {
        return;
    }
    // 前序遍历(DLR)(根->左->右)
    cout << node->data << "->";
    DLR(node->left);
    DLR(node->right);
}
template<class T>
void BinarySearchTree<T> ::LDR(BinarySearchTreeNode<T> *node)
{
    if(!node)
    {
        return;
    }
     // 中序遍历(LDR)(左->根->右)
    LDR(node->left);
    cout << node->data << "->";
    LDR(node->right);
}
template<class T>
void BinarySearchTree<T> ::LRD(BinarySearchTreeNode<T> *node)
{
    if(!node)
    {
        return;
    }
     // 后序遍历(LRD)(左->右->根)
    LRD(node->left);
    LRD(node->right);
    cout << node->data << "->";

}

template<class T>
void BinarySearchTree<T> ::deleteNodeByMerge(BinarySearchTreeNode<T> *node)
{
    BinarySearchTreeNode<T> *temp = node;
    if(node != 0)
    {
        // 如果节点的左节点为空
        if(!node->left)
        {
            node = node->right;  //直接指向node的右节点
        }
        // 如果右子节点为空
        else if(!node->right)
        {
            node = node->left;  // 直接指向node的左节点
        }
        else{
            temp = node->left; // temp 为node的左节点
            // 找出左节点中的最大值
            while (temp->right)
            {
                temp = temp->right;
            }
            temp->right = node->right; // 左子树的最大值指向右节点
            temp = node;           
            node = node->left;         // 左子树作为两颗树的头节点
            
        }
        delete temp;

    }
    
}

template<class T>
bool BinarySearchTree<T> ::removeNode(const T data)
{
    if(isEmpty())
    {
        cout << "the tree is empty" << endl;
        return false;
    }
    BinarySearchTreeNode<T> *prev_node = 0;  // 头节点
    BinarySearchTreeNode<T> *node = root;
    // 找到值的节点
    while (node != 0)
    {
        // 如果node的值等于data
        if(node->data == data)
        {
            break;
        }
        prev_node = node;  // node的头节点
        // node 的值大于deta 就往左子树找
        if(node->data > data)
        {
            node = node->left;
        }
        // node 的值小于 data 就往右子树找
        else{
            node = node->right;
        }
    }
    // 找到值的节点了
    if(node != 0 && node->data == data)
    {
        // 如果是头节点
        if(node == root)
        {
            deleteNodeByMerge(root);
        }
        // 其他节点的左节点==data
        else if(prev_node->left == node)
        {
            deleteNodeByMerge(prev_node->left);
        }
        else
        {
            deleteNodeByMerge(prev_node->right);
        }
        treeNodeNum--; //节点数减一
        return true;
    }
    else
    {
        cout << data << "no exits tree" << endl;
    }
    return false;
}

template<class T>
void BinarySearchTree<T> ::showNodeByDLR()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    BinarySearchTreeNode<T> *node = root;
    cout << "DLR: ";
    DLR(node);  
    cout << endl;
}

template<class T>
void BinarySearchTree<T> ::showNodeByLDR()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    BinarySearchTreeNode<T> *node = root;
    cout << "LDR: ";
    LDR(node); 
    cout << endl; 
}

template<class T>
void BinarySearchTree<T> ::showNodeByLRD()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    BinarySearchTreeNode<T> *node = root;
    cout << "LRD: ";
    LRD(node); 
    cout << endl; 
}


int main(int argc, char const *argv[])
{
    BinarySearchTree<int> tree;
    tree.inseartNode(5);
    tree.inseartNode(3);
    tree.inseartNode(2);
    tree.inseartNode(4);
    tree.inseartNode(6);
    tree.inseartNode(5);
    tree.inseartNode(7);
    // 前序遍历
    tree.showNodeByDLR();
    // 中序遍历
    tree.showNodeByLDR();
    // 后序遍历
    tree.showNodeByLRD();
    cout << "*******************************" << endl;
    cout << tree.removeNode(6) << endl;
    // 前序遍历
    tree.showNodeByDLR();
    // 中序遍历
    tree.showNodeByLDR();
    // 后序遍历
    tree.showNodeByLRD();

    cout << "nodes is:" << tree.Nodes() << endl;
    system("pause");
    return 0;
}