/*
*	2017-6-2
*	该文件用来比较函数对象和函数指针的区别
*	made by lijun
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int g_TestData[]={5,3,2,6,8,6,7,7,0};

//函数对象
struct funobj
{
	bool operator ()(int a,int b)
	{
		return abs(a-b)<=1;
	}
};

//函数指针
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

	//注意传函数对象是  默认该对象是按值传递，如果后续需要看对象内的内容，则内容不会被修改
	//因为传递的是函数对象的一个副本
	itr =adjacent_find(g_vecTestData.begin(),g_vecTestData.end(),funobj());
	cout<<*itr<<endl;

	return 0;
}*/