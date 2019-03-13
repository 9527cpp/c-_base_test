/*
*	2017-6-2
*	该文件用来测试c++文本文件的读写
*	made by lijun
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> g_data_vec;

void read(string sFilePath)
{
	ifstream fin(sFilePath);
	char chTempData[20]={0};
	while(!fin.eof())
	{
		
		fin.getline(chTempData,20);
		string szData(chTempData);
		g_data_vec.push_back(szData);
	}
	fin.close();
}


void write(string sFilePath)
{
	ofstream fout(sFilePath);

	int i =0;
	while(i<g_data_vec.size())
	{
		string szData =g_data_vec[i];
		string szTempData ="\"";
		szTempData+=szData;
		szTempData+="\"";
		szTempData+=",";
		fout<<szTempData<<endl;
		i++;
	}
	fout.close();
}

#if 0
int main()
{
	read("hh.txt");
	write("hh1.txt");
	return 0;
}
#endif