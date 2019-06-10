/*
*	2017-6-2
*	���ļ���������c++������˳��
*	made by lijun
*/

#include <iostream>
using namespace std;

/*

����͸���֮�䣺
//��������ĳ�ʼ��˳�����£�  
//�����ྲ̬��Ա����  
//�����ྲ̬���캯��  
//������ʵ����Ա����  
//�ܸ��ྲ̬��Ա����  
//�ݸ��ྲ̬���캯��  
//�޸���ʵ����Ա����  
//�߸��๹�캯��  
//�����๹�캯��  
��Ա���������ڹ��캯��

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

// ����˳����̳�˳���й� ����ʾ�б�˳���޹�
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
