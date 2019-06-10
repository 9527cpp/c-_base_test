/*
*	2017-6-2
*	该文件用来测试c++对象构造顺序
*	made by lijun
*/

#include <iostream>
using namespace std;

/*

子类和父类之间：
//各个对象的初始化顺序如下：  
//①子类静态成员变量  
//②子类静态构造函数  
//③子类实例成员变量  
//④父类静态成员变量  
//⑤父类静态构造函数  
//⑥父类实例成员变量  
//⑦父类构造函数  
//⑧子类构造函数  
成员变量优先于构造函数

*/
class Base1{
public:
	Base1(int i){ cout<<"Constructing Base1 "<<endl; }
	~Base1() { cout<<"Destructing Base1"<<endl; }
};

class Base2{
public:
	Base2(int j){ cout<<"Constructing Base2 "<<endl; }
	~Base2(){ cout<<"Destructing Base2"<<endl; }
};

class Base3{
public:
	Base3(int k){ cout<<"Constructing Base3 "<<endl; }
	~Base3(){ cout<<"Destructing Base3"<<endl; }
};

// 构造顺序跟继承顺序有关 跟显示列表顺序无关
class Derived:public Base3, public Base2, public Base1{
public:
	Derived(int a, int b, int c, int d):member2(a),member1(a),member3(a),Base1(a),Base2(b),Base3(c)
	{}
private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};



/*
Constructing Base3 
Constructing Base2 
Constructing Base1 

Constructing Base1 
Constructing Base2 
Constructing Base3 

Destructing Base3
Destructing Base2
Destructing Base1

Destructing Base1
Destructing Base2
Destructing Base3
*/

#if 0
int main(){
	Derived obj(1, 2, 3, 4);
	return 0;
}
#endif
