/*
*	2017-6-2
*	���ļ������ȽϺ�������ͺ���ָ�������
*	made by lijun
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int g_TestData[]={5,3,2,6,8,6,7,7,0};

//��������
struct funobj
{
	bool operator ()(int a,int b)
	{
		return abs(a-b)<=1;
	}
};

//����ָ��
bool func(int a ,int b)
{
	return abs(a-b)<=1;
}

/*
int main()
{
	vector<int>::iterator itr ;
	vector<int> g_vecTestData(g_TestData,g_TestData+sizeof(g_TestData));
	//itr =adjacent_find(g_vecTestData.begin(),g_vecTestData.end(),func);

	//ע�⴫����������  Ĭ�ϸö����ǰ�ֵ���ݣ����������Ҫ�������ڵ����ݣ������ݲ��ᱻ�޸�
	//��Ϊ���ݵ��Ǻ��������һ������
	itr =adjacent_find(g_vecTestData.begin(),g_vecTestData.end(),funobj());
	cout<<*itr<<endl;

	return 0;
}*/