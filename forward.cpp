#include <iostream>

using namespace std;

template <typename  T>
void func(T & t){cout<<"左值"<<endl;}

template <typename  T>
void func(T && t){cout<<"右值"<<endl;}

template <typename U>
void test(U && u){
    //func(u);
    //func(move(u));
    //实现完美转发
    func(forward<U>(u));
}

int main()
{
    int num=1;
    test(1);
    test(num);
    return 0;
}

