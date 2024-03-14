#include <string.h>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

class String{
public:
	String()
	: _pstr(new char[1]())
	{	cout << "String()" << endl;	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{	
		strcpy(_pstr, pstr);
		cout << "String(const char*)" << endl;
	}

	//const String  &rhs
	//能知道传递过来的就一定是右值吗?
	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{	
		strcpy(_pstr, rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	String & operator=(const String & rhs) {
		if(this != & rhs) {
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		cout << "String & operator=(const String &)" << endl;
		return *this;
	}

	//rhs能够绑定的一定是右值，
	//右值马上就要被转移, 这就意味着被修改
	//所以const右值引用没有存在的必要
	//
	//C++规则认定：当传递的是右值时，具有复制控制语义函数
	//和具有移动语义的函数都存在的情况下，具有移动语义函数
	//优先被调用
	//
	//统称为具有移动语义的函数
	//
	//移动构造函数
	String(String && rhs)//右值引用rhs是左值
	: _pstr(rhs._pstr) //浅拷贝 O(1)
	{
		rhs._pstr = nullptr;//o(1) 修改临时对象的指针的指向
		cout << "String(String&&)" << endl;
	}

	//移动赋值函数
	String & operator=(String && rhs)
	{//rhs是一个有名字的右值引用，本身是一个左值
		if(this != &rhs) {//1. 自移动
			cout << "String & operator=(String&&)" << endl;
			delete [] _pstr;//2. 回收左操作数空间
			_pstr = rhs._pstr;//3. 浅拷贝 o(1)
			rhs._pstr = nullptr;
		}
		return *this;//4. return *this
	}

	~String() {
		if(_pstr) {
			delete [] _pstr;
			_pstr = nullptr;
		}
		cout << "~String()" << endl;
	}

	friend ostream & operator<<(ostream & os, const String & rhs);

private:
	char * _pstr;
};

ostream & operator<<(ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

String copy_str(String str){
	cout<<"copy_str"<<endl;
	return str;
}

int main(void)
{
	String s1(copy_str(String("hello")));
	return 0;
}
