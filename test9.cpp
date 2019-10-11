/*
*	2017-6-2
*	该文件用来测试多态性
*	made by lijun
*/

#include <iostream>
using namespace std;


class A
{
	public:
		virtual void virtual_print(){cout<<"A--->virtual_print"<<endl;}
		void print(){cout<<"A--->print"<<endl;}	
};


class B:public A
{
	public:
		virtual void virtual_print(){cout<<"B--->virtual_print"<<endl;}//覆盖
		void print(){cout<<"B--->print"<<endl;}//隐藏
};


/*
A--->virtual_print
A--->print
B--->virtual_print
B--->print
B--->virtual_print
A--->print
A--->virtual_print
B--->print
*/
#if 1
int main()
{
	
	A a;
	B b;
	A *pa;
	B *pb;
	
	//use object
	a.virtual_print();
	a.print();
	b.virtual_print();
	b.print();

///
//当用基类指针指向子类对象
//或者用子类指针指向基类对象时
//遵循 隐藏(重定义)看指针 覆盖(virtual)看对象	
	//use obj_point
	pa = &b;
	pa->virtual_print();// 覆盖   看对象b  所以调用B的vritual
	pa->print();// 隐藏 看指针pa 所用调用A的print
	
	pb =(B*)&a;
	pb->virtual_print();// 覆盖   看对象a  所以调用A的vritual
	pb->print();// 隐藏 看指针pa 所用调用A的print
	
	return 0;
}
#endif