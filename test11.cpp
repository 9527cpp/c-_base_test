#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

class Test
{
public:
	static Test & getInstance();
	void Print();
	
private:
	Test(){}
	ofstream fout();
	static Test mInstance;
	static int nCount;
};

int Test::nCount =0;
Test Test::mInstance = Test();

	
Test & Test::getInstance()
{
	return mInstance;
}

void Test::Print()
{
	cout<<"helloworld"<<endl;	
}

int main()
{
	Test::getInstance().Print();
	getchar();
	return 0;
}