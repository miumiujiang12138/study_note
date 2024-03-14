#include <string>
#include <iostream>

using namespace std;

class Base{
public:
    Base();//无参构造函数
    Base(int num);//有一个int类型参数的构造函数
    Base(double d);//有一个double类型参数的构造函数
    Base(int num,double d);//有两个参数的构造函数

private:
    int _num;
    double _d;
};

Base::Base():_num(0),_d(0)
{cout<<"Base()"<<endl;}

Base::Base(int num):_num(num),_d(0)
{cout<<"Base(int)"<<endl;}

Base::Base(double d):_num(0),_d(d)
{cout<<"Base(double)"<<endl;}

Base::Base(int num,double d):_num(num),_d(d)
{cout<<"Base(int,double)"<<endl;}

class Derive:public Base{
public:
    //基础构造函数，本质就是将基类的构造函数隐匿
    using Base::Base;
    Derive();
    Derive(string name);
    Derive(int num,string name);
private:
    string _name;
};

Derive::Derive():_name("xixi"){
    cout<<"Derive()"<<endl;
}

Derive::Derive(string name):_name(name)
{cout<<"Derive(sting)"<<endl;}

Derive::Derive(int num,string name):Base(num),_name(name)
{cout<<"Derive(int,string)"<<endl;}


int main()
{
#if 1
    Derive d1();
    Derive d2("qiqi");
    Derive d3(6);
    Derive d4(12.8);
    Derive d5(100,2.9);
#endif
    Derive d6(10,"qiqi");
    return 0;
}

