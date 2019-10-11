/*
*	2017-6-2
*	该文件用来演示各种结构体对齐
*	made by lijun
*/

#include "stdio.h"
#include <iostream>

using namespace std;


/****************************************************************************************
内存对齐 跟 cpu 的数据总线有关 
如果32位cpu 数据总线32(字长一次取 32bit 数据)  地址总线32(最大寻址2^32 = 4GB)
如果内存没对齐
假如  我取一个int(4字节)
分为两种情况 
int a 
|1 |2 |3 |4 | （数据总线 可以一次读取）
|  |  |1 |2 |    |3 |4 |  |  | （数据总线先读了 1和2字节 发现不是符合的数据会出现 硬件中断 然后地址总线再++ ，数据总线再取剩下的3,4字节然后拼接  造成效率上的浪费）
所以说 内存对齐 纯粹是为了 取址 次数减少 从而提高效率(一定要记住)


platform	 	char	short	int		long	float	double	long long	long double
Win-32			1		2		4		4		4		8		8			8
模数			1		2		4		4		4		8		8			8
Linux-32		1		2		4		4		4		8		8			12
模数			1		2		4		4		4		4		4			4
Linux-64		1		2		4		8		4		8		8			16
模数			1		2		4		8		4		8		8			16


结构体对齐分为两步骤

1：结构体内部成员对齐：
第一、如果n大于等于该变量所占用的字节数，那么偏移量必须满足默认的对齐方式(默认对齐--->该变量对应的模数)
第二、如果n小于该变量的类型所占用的字节数，那么偏移量为n的倍数，不用满足默认的对齐方式。


2：结构的本身对齐：
如果n大于所有成员变量类型所占用的字节数，则结构的总大小必须为占用空间最大的变量占用的空间数的倍数；
否则必须为n的倍数。


n的有效数字为2 的倍数1,2,4,8  如果为其他数 取最小比该数字大的2 的倍数 比如 3  取 4


如果n的值比结构体内所有的变量类型都大 那么按照最大的那个变量类型 来对齐
*************************************************************************************/





/////////////////////////////////////////test/////////////////////////////////////////////

#pragma pack(8)  
struct example1 //虽然指定为8对齐 但是结构体最大的long为4字节 所以按4对齐 
{  
	short a;  
	long b;  //(32位为4 64位为8)
};  
 
 
  
struct example2  //最大对齐为4 也就是example中的 long b;
{  
	char c;  
	example1 struct1; //虽然包含 example1 但是 并不是包含该类型 而是展开 example1 按照最大成员来对齐
	short e;      
}; 
 
#pragma pack()

//默认按8对齐
//联合体大小为8  但是要8对齐 所以占用空间为8
union u1
{
	double a;
	int b;
};

//默认按4对齐
//联合体大小为13  但是要4对齐 所以占用空间为16
union u2
{
	char a[13];   
	int b;  
};
 
//默认按1对齐
//联合体大小为13  但是要1对齐 所以占用空间为13
union u3
{
	char a[13];   
	char b;  
};



// i j 放一起对齐后占8字节  b独占8字节  a对齐后占8字节 总共 24字节
//i本身占1字节起始为0的地址  j以4对齐且起始为4的地址,b起始为8的地址 a起始为16的地址 对齐后总共24字节
struct s1
{
	int i: 8;//4
	int j: 4;//4
	double b;//8
	int a:3;//4
};///整体添加4


//默认8对齐
struct s2
{
	int i;//4
	int j;//4
	double b;//8
	int a;//4
};///整体添加4



//默认8对齐
struct s3
{
	int i;//4
	int j;//4
	int a;//4+4
	double b;//8
};///全部对齐 整体加0



//i本身占1字节起始为0的地址 但是由于j a 以4对齐且j和a可拼凑成一个字节共用起始为4的地址,b起始为8的地址  总共16字节
struct s4
{
	int i: 8;//0起始
	int j: 4;//4起始
	int a: 3;//4起始
	double b;//8起始
};


//默认4对齐
struct s5
{
	int i: 4;//4字节内
	int j: 3;//4字节内
	int a: 2;//4字节内
	short b;//4起始
};//4+2+2 =8


struct s6
{
	char i : 5;
	char j : 2;
	char a : 3;
	char b : 4;
};

class A
{
public:
	int a;
	int b;
	virtual void test1(){cout<<"A:test1"<<endl;}
	virtual void test2(){cout<<"A:test2"<<endl;}
	void test3(){}
};

class B:public A
{
	void test1(){cout<<"B:test1"<<endl;}//覆盖
	//void test2(){cout<<"B:test1"<<endl;}//覆盖
	virtual void test12(){}
	void test3(){}// 隐藏	
};

typedef void (*Func)();

int main(int argc, char* argv[])  
{  
	/*
	cout<<"example1:"<<sizeof(example1)<<endl;
	cout<<"example2:"<<sizeof(example2)<<endl;

	
	cout<<"u1:"<<sizeof(u1)<<endl;
	cout<<"u2:"<<sizeof(u2)<<endl;
	cout<<"u3:"<<sizeof(u3)<<endl;  
	



	cout<<"s1:"<<sizeof(s1)<<endl;
	cout<<"s2:"<<sizeof(s2)<<endl;
	cout<<"s3:"<<sizeof(s3)<<endl;  
	cout<<"s4:"<<sizeof(s4)<<endl;  
*/
	
	/*
	s2 ss2;
	cout<<"ss2"<<endl;
	cout<<"ss2:i ="<<&(ss2.i)<<endl;
	cout<<"ss2:j ="<<&(ss2.j)<<endl;
	cout<<"ss2:b ="<<&(ss2.b)<<endl;
	cout<<"ss2:a ="<<&(ss2.a)<<endl;

	s3 ss3;
	cout<<"ss3"<<endl;
	cout<<"ss3:i ="<<&(ss3.i)<<endl;
	cout<<"ss3:j ="<<&(ss3.j)<<endl;
	cout<<"ss3:a ="<<&(ss3.a)<<endl;
	cout<<"ss3:b ="<<&(ss3.b)<<endl;
	*/
/*
	cout<<"s5:"<<sizeof(s5)<<endl;  
	cout<<"s6:"<<sizeof(s6)<<endl; 
*/	
	A t;
	int * p = (int *)&t;
	cout<<"A:"<<sizeof(t)<<endl; 	
	cout<<"t ="<<&(t)<<endl;//p
	cout<<"t.test1 ="<<(int *)(*p)<<endl;//_vtbptr
	cout<<"t.test2 ="<<(int *)(*p)+1<<endl;//_vtbptr
	
	Func pFun = (Func) *(int *)(*p);
	pFun();
	pFun = (Func) *((int *)(*p)+1);
	pFun();	
	
	/* 
	vtb与类相关与对象无关
	即无论对象是否创建，只要声明的类中有虚函数 那么就存在一张虚函数表
	而且基类的虚表跟子类的虚表是不一样的地址(即使子类没修改虚函数)
	创建对象仅仅是在对象中添加一个vtbptr的4字节指针
	所以如果基类有大量的虚函数 如果采用继承的方式 那么各个子类也会存在大量的虚函数
	这就是为什么MFC不用虚函数 而采用消息映射的原因	
	*/
	
	B tb;
	p = (int *)&tb;
	cout<<"B:"<<sizeof(tb)<<endl; 	
	cout<<"tb ="<<&(tb)<<endl;//p
	cout<<"tb.test1 ="<<(int *)(*p)<<endl;//_vtbptr(第一个虚函数)
	cout<<"tb.test2 ="<<(int *)(*p)+1<<endl;//_vtbptr(第二个虚函数)
	
	
	pFun = (Func) *(int *)(*p);
	pFun();
	pFun = (Func) *((int *)(*p)+1);
	pFun();		
	
	char aaa = 128;
	char bbb = 127;
	printf("%d\r\n",aaa+bbb);
  	return 0;  
}  
