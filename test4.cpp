/*
*	2017-6-2
*	该文件基于trie树统计一片文章中单词出现的次数
*	made by lijun
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

#define BRANCHS 26

class CTrie
{
public:
	struct TrieNode
	{
		string	str;
		int		count;///单词结束后 统计多少个单词  默认为0
		TrieNode * branchs[BRANCHS];
		TrieNode * parent;
		TrieNode ()
		{
			for(int i =0;i<BRANCHS;i++)
			{
				branchs[i]=NULL;
				count =0;
			}
			parent = NULL;
		}
	};
public:
	CTrie():root(NULL){}
	void BuildTrie(vector<string> & data_list);
	void SearchTrie(vector<string> & data_list);//检查某个单词是否在Trie中，根据单词末尾的count是否等于0判断
private:
	TrieNode * root;
};

void CTrie::BuildTrie(vector<string> & data_list)
{
	int i = 0;
	int size = data_list.size();
	if(!root)
		root = new TrieNode();
	while(i < size)
	{
		const char * pTempData =data_list[i].c_str();
		TrieNode * pTempRoot = root;
		int step =1;
		while(pTempRoot &&*pTempData)
		{
			int index =*pTempData-'a';

			if(pTempRoot->branchs[index] == NULL)
			{
				pTempRoot->branchs[index] = new TrieNode();
				pTempRoot->branchs[index]->str.append(data_list[i],0,step);
			}
			
			if(*(pTempData+1)==NULL)
			{
				pTempRoot->branchs[index]->count++;
			}
			TrieNode * pTempParent = pTempRoot;
			pTempRoot = pTempRoot->branchs[index];
			pTempRoot->parent = pTempParent;
			pTempData++;
			step++;
		}
		i++;
	}
}

void CTrie::SearchTrie(vector<string> & data_list)
{
	int size = data_list.size();
	for(int i=0;i<size;i++)
	{
		const char *  pTempData = data_list[i].c_str();
		TrieNode * pTempNode = root;
		while(pTempNode&&*pTempData)
		{
			int index = 0;
			index = *pTempData -'a';
			pTempNode = pTempNode->branchs[index];
			pTempData++;
		}
		cout<<"str ="<<pTempNode->str.c_str()<<"\tnumber ="<<pTempNode->count<<endl;
	}
}

void GenerateData(vector<string> & data_list)
{
	srand((time(NULL)));
	for(int i=0;i<10000;i++)///生成10000个字符串
	{	
		int word_number = rand()%8+1;///每个单词随机1---8 个字符
		string data;	
		for(int j =0;j<word_number;j++)///每个字符随机为a-z
		{		
			char ch = rand()%26+'a';
			data+=ch;
		}
		data_list.push_back(data);
	}
}

void Split(const char * base_str,vector<string> & data_list)
{
	int start_pos =0;
	int end_pos =0;
	const char * temp_str = base_str;
	while(*temp_str)
	{
		if(*temp_str ==' '||*temp_str =='\r'||*temp_str =='\n'
			||*temp_str =='!'||*temp_str ==','||*temp_str=='?'
			||*temp_str =='.')
		{
			const char *str = base_str+start_pos;
			string one_data = string(str,end_pos-start_pos);
			start_pos = end_pos+1;

			//trim
			one_data =one_data.erase(0, one_data.find_first_not_of(" \t\n\r"));
			one_data.erase(one_data.find_last_not_of(" \t\n\r")+1);
			if(one_data.compare(""))
			{
				data_list.push_back(one_data);
			}
		}		
		temp_str++;
		end_pos++;
	}
}

void ReadData(string file_path,vector<string> & data_list)
{
	ifstream fin(file_path,ios::binary|ios::in);
	while(!fin.eof())
	{
		string line_data;
		getline(fin,line_data);
		Split(line_data.c_str(),data_list);
	}
}


#if 0
int main()
{
	CTrie t;
	vector<string>data_list;
	//test read file data
	ReadData("Text.txt",data_list);
	//test generate data
	//GenerateData(data_list);
	t.BuildTrie(data_list);
	//vector 去重
	sort(data_list.begin(),data_list.end());
	vector<string>::iterator itr = unique(data_list.begin(),data_list.end());
	data_list.erase(itr,data_list.end());
	t.SearchTrie(data_list);
	return 0;
}
#endif