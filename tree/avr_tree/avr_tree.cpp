/**
 * @file avr_tree.cpp
 * @brief 
 * @author zhaochengji (909536346@qq.com)
 * @version 1.0
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "avr_tree.h"
#include <iostream>

using namespace std;

template<class T>
AvrTree<T> ::~AvrTree()
{
    clear();
}

// 数据的删除
template<class T>
void AvrTree<T> ::deleteNodeAll(AvrTreeNode<T> *node)
{
    if(node == 0)
    {
        return;
    }
    // 删除左节点
    deleteNodeAll(node->left);
    // 删除右节点
    deleteNodeAll(node->right);
    // 释放节点
    delete node;

}

template<class T>
void AvrTree<T> ::clear()
{
    // 如果为空树，直接返回
    if(root == 0)
    {
        return;
    }
    deleteNodeAll(root);
}

template<class T>
bool AvrTree<T> ::deleteNode(AvrTreeNode<T> *& node, const T data)
{
    // 如果节点为空，直接返回，表示未找到数据
    if(!node)
    {
        cout << "no find:" << data << endl;
        return false;
    }
    // 找到数据节点
    if(data == node->data)
    {
        AvrTreeNode<T> *temp = node;
        // 只有右节点
        if(!node->left)
        {
            node = node->right;
        }
        // 只有左节点
        else if(!node->right)
        {
            node = node->left;
        }
        else
        {
            // 采用合并的方式进行删除节点
            temp = node->left;
            // 找到左子树的做大值
            while (temp->right)
            {
                temp = temp->right;
            }
            temp->right = node->right;
            temp = node;
            node = node->left;
        }
        delete temp;
        return true;
    }
    // 在左子树查找
    else if(data < node->data)
    {
        deleteNode(node->left, data);
        // 是否对树进行调整
        if(getTreeHight(node->left)-getTreeHight(node->right) > 1)
        {
            // 如果值比左子树小，就采用单右旋，
            if(data < node->left->data)
            {
                LL(node);
            }
            // 采用先左旋在右旋
            else
            {
                RLR(node);
            }
        }
    }
    // 在右子树查找
    else
    {
        deleteNode(node, data);
        // 是否要对树进行调整
        if(getTreeHight(node->right) - getTreeHight(node->left) > 1)
        {
            // 值比最大值大或者等于，就采用单左旋
            if(data >= node->right->data)
            {
                RR(node);
            }
            // 采用先右旋在左旋
            else
            {
                LRR(node);
            }
        }

    }
    // 对节点的深度进行调整
    node->hight = maxHight(getTreeHight(node->right), getTreeHight(node->right)) + 1;
}

template<class T>
bool AvrTree<T> ::remove(const T data)
{
    // 如果为空树
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return false;
    }
    return deleteNode(root, data);
}
// 数据的查询
template<class T>
void AvrTree<T> ::DLR(AvrTreeNode<T> *node)
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
void AvrTree<T> ::LDR(AvrTreeNode<T> *node)
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
void AvrTree<T> ::LRD(AvrTreeNode<T> *node)
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
void AvrTree<T> ::showNodeByDLR()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    AvrTreeNode<T> *node = root;
    cout << "DLR: ";
    DLR(node);  
    cout << endl;
}

template<class T>
void AvrTree<T> ::showNodeByLDR()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    AvrTreeNode<T> *node = root;
    cout << "LDR: ";
    LDR(node); 
    cout << endl; 
}

template<class T>
void AvrTree<T> ::showNodeByLRD()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    AvrTreeNode<T> *node = root;
    cout << "LRD: ";
    LRD(node); 
    cout << endl; 
}

template<class T>
bool AvrTree<T> ::LVRSearchData(const T data)
{
    int h1,h2;
    h1 = 6;
    h2 = 10;
    cout << maxHight(h1, h2);
    return false;
}

// 节点的旋转
template<class T>
void AvrTree<T> ::LL(AvrTreeNode<T> *& node)
{
    // 临时节点为节点的左节点
    AvrTreeNode<T> *temp = node->left;
    // 节点的左节点指向临时节点的右节点
    node->left = temp->right;
    // 临时节点的右节点指向节点(将临时节点的设置为根)
    temp->right = node;
    // 重新获得树的高度
    temp->hight = maxHight(getTreeHight(temp->left), getTreeHight(temp->right)) + 1;
    node->hight = maxHight(getTreeHight(node->left), getTreeHight(node->right)) + 1;
    // 经node 重新指向temp, 即将temp设置为根节点，防止树的断
    node = temp; 
}

template<class T>
void AvrTree<T> ::RR(AvrTreeNode<T> *& node)
{
    // 临时节点为节点的右节点
    AvrTreeNode<T> *temp = node->right;
    // 节点的右节点指向临时节点的节点
    node->right = temp->left;
    // 临时节点的左节点指向节点
    temp->left = node;
    // 重新计算树的高度
    temp->hight = maxHight(getTreeHight(temp->left), getTreeHight(temp->right)) + 1;
    node->hight = maxHight(getTreeHight(node->left), getTreeHight(node->right)) + 1;
     // 经node 重新指向temp, 即将temp设置为根节点，防止树的断
    node = temp;
}

template<class T>
void AvrTree<T> ::RLR(AvrTreeNode<T> *& node)
{
    // 先进行左旋
    RR(node->left);
    // 在进行右旋
    LL(node);
}

template<class T>
void AvrTree<T> ::LRR(AvrTreeNode<T> *& node)
{
    // 先进行右旋
    LL(node->right);
    // 在进行左旋
    RR(node);
}

// 数据的插入
template<class T>
void AvrTree<T> ::inseartNode(AvrTreeNode<T> *& node, const T data)
{
    // 如果节点为空
    if(node == 0)
    {
        node = new AvrTreeNode<T>(data);
        return;
    }
    // 插入在左子树
    if(data < node->data)
    {
        inseartNode(node->left, data);
        // 树不平衡时
        if(getTreeHight(node->left) - getTreeHight(node->right) > 1)
        {
            // 当值比左节点的值小时，则进行单右旋
            if(data < node->left->data)
            {
                LL(node);
            }
            // 否则进行左右旋
            else
            {
                RLR(node);
            }
        }  
    }
    // 插入在右子树
    else
        {
            inseartNode(node->right, data);
            // 树不平衡时
            if(getTreeHight(node->right) - getTreeHight(node->left) > 1)
            {
                // 当值比右节点的值大时，则进行单左旋
                if(data >= node->right->data)
                {
                    RR(node);
                }
                // 否则进行右左旋
                else
                {
                    LRR(node);
                }
            }

        }
   // 重新计算节点的高度，节点的深度+1
    node->hight = maxHight(getTreeHight(node->left), getTreeHight(node->right)) + 1;
}

template<class T>
void AvrTree<T> ::inseartData(const T data)
{
    // 如果为空树
    if(isEmpty())
    {
        root = new AvrTreeNode<T>(data);
        root->hight = 0;
        return;
    }
    inseartNode(root, data);
}

int main(int argc, char const *argv[])
{
    AvrTree<int> avr;
    avr.inseartData(12);
    avr.inseartData(42);
    avr.inseartData(93);
    avr.inseartData(4);
    avr.inseartData(15);
    avr.inseartData(66);
    avr.inseartData(97);
    avr.showNodeByDLR();
    cout << "***********************************" << endl;
    avr.showNodeByLDR();
    cout << "***********************************" << endl;
    avr.showNodeByLRD();
    cout << "***********************************" << endl;
    bool is = avr.remove(42);
    cout << "remove is:" << is << endl;
     avr.showNodeByDLR();
    cout << "***********************************" << endl;
    avr.showNodeByLDR();
    cout << "***********************************" << endl;
    avr.showNodeByLRD();
    cout << "***********************************" << endl;
    system("pause");
    return 0;
}
