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
AvrTree<T> ::~AvrTree(){
    clear();
}

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

int main(int argc, char const *argv[])
{
    AvrTree<int> avr;
    

    system("pause");
    return 0;
}
