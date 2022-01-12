#include <iostream>

using namespace std;

int fun1(int n)
{
    if(n <= 1){
        return 1;
    }
    return fun1(n-1) + fun1(n-2);
}
int main(int argc, char const *argv[])
{
    int i = 10;
    cout <<  fun1(10)<< endl;
    
    system("pause");
    return 0;
}
