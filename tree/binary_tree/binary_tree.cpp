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
void BinarySearchTree<T> ::deleteNode(BinarySearchTreeNode<T> *node)
{
    // 如果的空树就结束递归
    if(!node)
    {
        return;
    }
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;   // 释放资源
}
template<class T>
void BinarySearchTree<T> ::clear()
{
    deleteNode(root);   // 清空所有节点
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
void BinarySearchTree<T> ::showNode(BinarySearchTreeNode<T> *node)
{
    if(node == 0)
    {
        return;
    }
    cout << node->data << endl;
    showNode(node->left);
    showNode(node->right);

}
template<class T>
void BinarySearchTree<T> ::breadthFirstTraversal()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    BinarySearchTreeNode<T> *node = root;
    showNode(node);  
}

int main(int argc, char const *argv[])
{
    BinarySearchTree<int> tree;
    tree.inseartNode(0);
    tree.inseartNode(1);
    tree.inseartNode(0);
    tree.inseartNode(1);
    tree.breadthFirstTraversal();
    system("pause");
    return 0;
}
