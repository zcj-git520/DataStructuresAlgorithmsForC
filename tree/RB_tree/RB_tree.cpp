#include "RB_tree.h"
#include <iostream>
#include <string>

using namespace std;

string RBColorStr[2] = {"red", "black"};

template<class T>
RBTree<T> ::~RBTree()
{
    clear();
}

template<class T>
void RBTree<T> ::deleteNodeAll(RBTreeNode<T> *node)
{
    // 如果节点为空就返回
    if(!node)
    {
        return;
    }
    // 删除左子树
    if(node->left)
    {
        deleteNodeAll(node->left);
    }
    // 删除右子树
    if(node->right)
    {
        deleteNodeAll(node->right);
    }
    // 释放资源
    delete node;
}

template<class T>
void RBTree<T> ::clear()
{
    // 如果树为空就返回
    if(isEmpty())
    {
        return;
    }
    deleteNodeAll(root);
}

template<class T>
RBColor RBTree<T> ::getColor(RBTreeNode<T> *node)
{
    return node->color;
}

// 数据的查询
template<class T>
void RBTree<T> ::DLR(RBTreeNode<T> *node)
{
    if(!node)
    { 
        return;
    }
    // 前序遍历(DLR)(根->左->右)
    cout << node->data << "(" << RBColorStr[getColor(node)] << ")" << "->";
    DLR(node->left);
    DLR(node->right);
}

template<class T>
void RBTree<T> ::LDR(RBTreeNode<T> *node)
{
    if(!node)
    {
        return;
    }
     // 中序遍历(LDR)(左->根->右)
    LDR(node->left);
    cout << node->data << "(" << RBColorStr[getColor(node)] << ")" << "->";
    LDR(node->right);
}

template<class T>
void RBTree<T> ::LRD(RBTreeNode<T> *node)
{
    if(!node)
    {
        return;
    }
     // 后序遍历(LRD)(左->右->根)
    LRD(node->left);
    LRD(node->right);
    cout << node->data << "(" << RBColorStr[getColor(node)] << ")" << "->";
}

template<class T>
void RBTree<T> ::showNodeByDLR()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    RBTreeNode<T> *node = root;
    cout << "DLR: ";
    DLR(node);  
    cout << endl;
}

template<class T>
void RBTree<T> ::showNodeByLDR()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    RBTreeNode<T> *node = root;
    cout << "LDR: ";
    LDR(node); 
    cout << endl; 
}

template<class T>
void RBTree<T> ::showNodeByLRD()
{
    if(isEmpty())
    {
        cout << "this tree is empty" << endl;
        return;
    }
    // 遍历树
    RBTreeNode<T> *node = root;
    cout << "LRD: ";
    LRD(node); 
    cout << endl; 
}

template<class T>
bool RBTree<T> ::LVRSearchData(const T data)
{
   // 如果树为空就直接返回
   if(isEmpty())
   {
       return false;
   }
   RBTreeNode<T> *node = root;
   while (node)
   {
       if(data == node->data)
       {
           return true;
       }
       else if(data < node->data)
       {
           node = node->left;
       }
       else
       {
           node = node->right;
       }
   }
   return false;
}

// 节点的旋转
template<class T>
void RBTree<T> ::LL(RBTreeNode<T> *& node)
{
    // 临时节点为节点的左节点
    RBTreeNode<T> *temp = node->left;
    // 节点的左节点指向临时节点的右节点
    node->left = temp->right;
    // 临时节点的右节点指向节点(将临时节点的设置为根)
    temp->right = node;
    // 颜色调整(保持原有位置的颜色)
    temp->color = node->color; 
    node->color = Red;  
    // 经node 重新指向temp, 即将temp设置为根节点，防止树的断
    node = temp; 
}

template<class T>
void RBTree<T> ::RR(RBTreeNode<T> *& node)
{
    // 临时节点为节点的右节点
    RBTreeNode<T> *temp = node->right;
    // 节点的右节点指向临时节点的节点
    node->right = temp->left;
    // 临时节点的左节点指向节点
    temp->left = node;
     // 颜色调整(保持原有位置的颜色)
    temp->color = node->color; 
    node->color = Red;  
    // 经node 重新指向temp, 即将temp设置为根节点，防止树的断
    node = temp;
}

// 是否为红色
template<class T>
bool RBTree<T> ::isRed(RBTreeNode<T> * node)
{
    if (!node)
    {
        return false;
    }
    if(node->color == Red)
    {
        return true;
    }
    return false;
}
// 颜色调整
template<class T>
void RBTree<T> ::colorAdjust(RBTreeNode<T> *&node)
{
    // 将根节点设置为红色，子节点设置为黑色
    node->color = Red;
    node->left->color = Black;
    node->right->color = Black;
}
// 树的调整

// 插入数据
template<class T>
void RBTree<T> ::inseartNode(RBTreeNode<T> *& node, T data)
{
    // 如果节点为空，就直接赋值新的节点
    if(!node)
    {
        node = new RBTreeNode<T>(data);
        return;
    }
    // 插入左子树
    if(data < node->data)
    {
        inseartNode(node->left, data);
    }
    // 插入右子树
    else
    {
        inseartNode(node->right, data);
    }
    if(node->left && node->right)
    {
        if(isRed(node->right) && !isRed(node->left))
        {
            LL(node);
        }
        if(isRed(node->left) && isRed(node->left->left))
        {
            RR(node);
        }
        if(isRed(node->left) && isRed(node->right))
        {
            colorAdjust(node);
        }

    }
}

template<class T>
void RBTree<T> ::inseartData(const T data)
{
    // 如果为空树
    if(isEmpty())
    {
        root = new RBTreeNode<T>(data);  // 新建节点设置为root 节点
        root->color = Black; // 根节点为黑色
        return;
    }
    // 采用递归插入
    inseartNode(root, data); 
}

int main(int argc, char const *argv[])
{
    RBTree<int> rb_tree; 
    rb_tree.inseartData(1);
    rb_tree.inseartData(12);
    rb_tree.inseartData(3);
    rb_tree.inseartData(4);
    rb_tree.inseartData(65);
    rb_tree.inseartData(16);
    rb_tree.inseartData(97);
    rb_tree.showNodeByDLR();
    cout << "***********************************" << endl;
    rb_tree.showNodeByLDR();
    cout << "**5*********************************" << endl;
    rb_tree.showNodeByLRD();
    cout << "***********************************" << endl;  
    system("pause");
    return 0;
}
