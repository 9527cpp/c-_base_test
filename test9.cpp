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
		virtual void virtual_print(){cout<<"B--->virtual_print"<<endl;}
		void print(){cout<<"B--->print"<<endl;}
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
#if 0
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
	
	//use obj_point
	pa = &b;
	pa->virtual_print();
	pa->print();
	
	pb =(B*)&a;
	pb->virtual_print();
	pb->print();
	
	
	cout<<"你好"<<endl;
	return 0;
}
#endif