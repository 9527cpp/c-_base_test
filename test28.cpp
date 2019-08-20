#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/**
	批量 asciii 转 unicode 并写入16进制文本
**/
using namespace std;

wchar_t *AnsiToUnicode(char * str,int &len)
{
	DWORD dwNum = MultiByteToWideChar (CP_ACP, 0, str, -1, NULL, 0);  
	wchar_t *pwText;  
	pwText = new wchar_t[dwNum];  
	if(!pwText) delete []pwText;  
	MultiByteToWideChar (CP_ACP, 0, str, -1, pwText, dwNum);  
	len = dwNum;
	return pwText; 
}

int main()
{
	
#if 0	
	char * pTxt = "你好小智";
	wchar_t *pTxt_w = AnsiToUnicode(pTxt);	
	printf("%s\r\n",pTxt_w);
#endif

	ifstream fin("asr_matong.txt");
	ofstream fout("asr_matong.txt.unicode");
	vector<string> vstr;
	
	
	string strGBK;
	int len = 0;
	int index = 0;
	while(getline(fin,strGBK))
	{
		cout<<strGBK<<endl;
		wchar_t *strUnicode = AnsiToUnicode(const_cast<char *>(strGBK.c_str()),len);
		
		string strHead = "unsigned short p";
		string count = to_string(index);
		strHead.append(count);
		strHead.append("[MAX_COMMANDS]={");
		fout.write(strHead.c_str(),strHead.size());
		
		vstr.push_back(strGBK);
		
		for(int i = 0;i<len;i++)
		{
			ostringstream stream;
			short tempData ;
			string baseStr ="0x";
			string result;
			tempData =*strUnicode;
			stream<<hex<<(short)tempData;
	
			result =stream.str();
			if(result.size()<4)
				result.insert(0,4-result.size(),'0');
			baseStr.append(result);
			if(i!=len-1)
			baseStr.append(",");
			fout.write(baseStr.c_str(),baseStr.size());
			stream.clear();
			strUnicode++;
		}
		string strEnd = "};\r\n";
		fout.write(strEnd.c_str(),strEnd.size());
		index++;
	}

	fout.write("unsigned short * g_yt_asr_command_str_data[]=\r\n{\r\n",strlen("unsigned short * g_yt_asr_command_str_data[]=\r\n{\r\n"));
	for(int i =0;i<index;i++)
	{
		string count = to_string(i);
		string strHead = "\tp";
		strHead.append(count);
		if(i!=index-1)
		strHead.append(",\r\n");
		fout.write(strHead.c_str(),strHead.size());
	}
	fout.write("\r\n};\r\n",strlen("\r\n};\r\n"));
	
	

	fout.write("char * g_yt_asr_command_str_cn[]=\r\n{\r\n",strlen("char * g_yt_asr_command_str_cn[]=\r\n{\r\n"));
	for(int i =0;i<index ; i++)
	{
		string strGBK ;
		strGBK = "\t\"";	
		strGBK.append(vstr[i]);//vec 最好不要用index方式 容易越界 还是用itr吧
		strGBK.append("\"");
		if(i!=index-1)
		strGBK.append(",\r\n");
		fout.write(strGBK.c_str(),strGBK.size());
	}	
	fout.write("\r\n};",strlen("\r\n};"));

	
	fin.close();
	fout.close();
	return 0;
}