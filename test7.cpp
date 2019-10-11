/*
*	2017-6-2
*	���ļ�������ʾ���ֽṹ�����
*	made by lijun
*/

#include "stdio.h"
#include <iostream>

using namespace std;


/****************************************************************************************
�ڴ���� �� cpu �����������й� 
���32λcpu ��������32(�ֳ�һ��ȡ 32bit ����)  ��ַ����32(���Ѱַ2^32 = 4GB)
����ڴ�û����
����  ��ȡһ��int(4�ֽ�)
��Ϊ������� 
int a 
|1 |2 |3 |4 | ���������� ����һ�ζ�ȡ��
|  |  |1 |2 |    |3 |4 |  |  | �����������ȶ��� 1��2�ֽ� ���ֲ��Ƿ��ϵ����ݻ���� Ӳ���ж� Ȼ���ַ������++ ������������ȡʣ�µ�3,4�ֽ�Ȼ��ƴ��  ���Ч���ϵ��˷ѣ�
����˵ �ڴ���� ������Ϊ�� ȡַ �������� �Ӷ����Ч��(һ��Ҫ��ס)


platform	 	char	short	int		long	float	double	long long	long double
Win-32			1		2		4		4		4		8		8			8
ģ��			1		2		4		4		4		8		8			8
Linux-32		1		2		4		4		4		8		8			12
ģ��			1		2		4		4		4		4		4			4
Linux-64		1		2		4		8		4		8		8			16
ģ��			1		2		4		8		4		8		8			16


�ṹ������Ϊ������

1���ṹ���ڲ���Ա���룺
��һ�����n���ڵ��ڸñ�����ռ�õ��ֽ�������ôƫ������������Ĭ�ϵĶ��뷽ʽ(Ĭ�϶���--->�ñ�����Ӧ��ģ��)
�ڶ������nС�ڸñ�����������ռ�õ��ֽ�������ôƫ����Ϊn�ı�������������Ĭ�ϵĶ��뷽ʽ��


2���ṹ�ı�����룺
���n�������г�Ա����������ռ�õ��ֽ�������ṹ���ܴ�С����Ϊռ�ÿռ����ı���ռ�õĿռ����ı�����
�������Ϊn�ı�����


n����Ч����Ϊ2 �ı���1,2,4,8  ���Ϊ������ ȡ��С�ȸ����ִ��2 �ı��� ���� 3  ȡ 4


���n��ֵ�Ƚṹ�������еı������Ͷ��� ��ô���������Ǹ��������� ������
*************************************************************************************/





/////////////////////////////////////////test/////////////////////////////////////////////

#pragma pack(8)  
struct example1 //��Ȼָ��Ϊ8���� ���ǽṹ������longΪ4�ֽ� ���԰�4���� 
{  
	short a;  
	long b;  //(32λΪ4 64λΪ8)
};  
 
 
  
struct example2  //������Ϊ4 Ҳ����example�е� long b;
{  
	char c;  
	example1 struct1; //��Ȼ���� example1 ���� �����ǰ��������� ����չ�� example1 ��������Ա������
	short e;      
}; 
 
#pragma pack()

//Ĭ�ϰ�8����
//�������СΪ8  ����Ҫ8���� ����ռ�ÿռ�Ϊ8
union u1
{
	double a;
	int b;
};

//Ĭ�ϰ�4����
//�������СΪ13  ����Ҫ4���� ����ռ�ÿռ�Ϊ16
union u2
{
	char a[13];   
	int b;  
};
 
//Ĭ�ϰ�1����
//�������СΪ13  ����Ҫ1���� ����ռ�ÿռ�Ϊ13
union u3
{
	char a[13];   
	char b;  
};



// i j ��һ������ռ8�ֽ�  b��ռ8�ֽ�  a�����ռ8�ֽ� �ܹ� 24�ֽ�
//i����ռ1�ֽ���ʼΪ0�ĵ�ַ  j��4��������ʼΪ4�ĵ�ַ,b��ʼΪ8�ĵ�ַ a��ʼΪ16�ĵ�ַ ������ܹ�24�ֽ�
struct s1
{
	int i: 8;//4
	int j: 4;//4
	double b;//8
	int a:3;//4
};///�������4


//Ĭ��8����
struct s2
{
	int i;//4
	int j;//4
	double b;//8
	int a;//4
};///�������4



//Ĭ��8����
struct s3
{
	int i;//4
	int j;//4
	int a;//4+4
	double b;//8
};///ȫ������ �����0



//i����ռ1�ֽ���ʼΪ0�ĵ�ַ ��������j a ��4������j��a��ƴ�ճ�һ���ֽڹ�����ʼΪ4�ĵ�ַ,b��ʼΪ8�ĵ�ַ  �ܹ�16�ֽ�
struct s4
{
	int i: 8;//0��ʼ
	int j: 4;//4��ʼ
	int a: 3;//4��ʼ
	double b;//8��ʼ
};


//Ĭ��4����
struct s5
{
	int i: 4;//4�ֽ���
	int j: 3;//4�ֽ���
	int a: 2;//4�ֽ���
	short b;//4��ʼ
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
	void test1(){cout<<"B:test1"<<endl;}//����
	//void test2(){cout<<"B:test1"<<endl;}//����
	virtual void test12(){}
	void test3(){}// ����	
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
	vtb�������������޹�
	�����۶����Ƿ񴴽���ֻҪ�������������麯�� ��ô�ʹ���һ���麯����
	���һ�����������������ǲ�һ���ĵ�ַ(��ʹ����û�޸��麯��)
	��������������ڶ��������һ��vtbptr��4�ֽ�ָ��
	������������д������麯�� ������ü̳еķ�ʽ ��ô��������Ҳ����ڴ������麯��
	�����ΪʲôMFC�����麯�� ��������Ϣӳ���ԭ��	
	*/
	
	B tb;
	p = (int *)&tb;
	cout<<"B:"<<sizeof(tb)<<endl; 	
	cout<<"tb ="<<&(tb)<<endl;//p
	cout<<"tb.test1 ="<<(int *)(*p)<<endl;//_vtbptr(��һ���麯��)
	cout<<"tb.test2 ="<<(int *)(*p)+1<<endl;//_vtbptr(�ڶ����麯��)
	
	
	pFun = (Func) *(int *)(*p);
	pFun();
	pFun = (Func) *((int *)(*p)+1);
	pFun();		
	
	char aaa = 128;
	char bbb = 127;
	printf("%d\r\n",aaa+bbb);
  	return 0;  
}  
