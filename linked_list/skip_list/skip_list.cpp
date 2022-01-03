/**
 * @file skip_list.cpp
 * @brief 
 * @author zhaochengji (909536346@qq.com)
 * @version 1.0
 * @date 2022-01-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "skip_list.h"
#include <iostream>

using namespace std;

int seed = 0;

template<class T>
SkipList<T> ::~SkipList()
{
    clear();
}

template<class T>
void SkipList<T> ::clear()
{
    if(isEmpty())
    {
        cout << "this is a empty list" << endl;

    }
}

template<class T>
bool SkipList<T> ::randmLevel()
{
    if(!seed)
    {
        seed = time(NULL);
    }
    ::srand(seed);
    int ret = ::rand() % 2;
    seed = ::rand();
    cout << "ret is "<<ret << ", seed is " << seed << endl;
    if(ret)
    {
        return false;
    }
    return true;
}

// template<class T>
// int SkipList<T> ::len()
// {
//     return len;
// }

// template<class T>
// int SkipList<T> ::level()
// {
//     return level;
// }
int main(int argc, char const *argv[])
{
    SkipList<int> s;
    cout << s.randmLevel() << endl;
    s.clear();
    system("pause");
    return 0;
}
