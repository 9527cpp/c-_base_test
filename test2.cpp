/*
*	2017-6-2
*	该文件用来得到二进制文件的十六进制表示(分为unsigned short版和unsigned char 版)
*	made by lijun
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


static void process_byte(string sFilePathIn,string sFilePathOut)
{
	char * pData;
	ifstream fin(sFilePathIn,ios::binary|ios::in|ios::ate);
	cout<<sFilePathOut<<endl;
	ofstream fout(sFilePathOut,ios::binary|ios::out);
    if(!fout){cout<<"open failed"<<endl;return;}
	int nFileLength =fin.tellg();
	fin.seekg(0);
	pData = new  char [nFileLength];
	memset(pData,0,nFileLength*sizeof( char));
	fin.read(pData,nFileLength);
	
	int nCount =0;
	printf("nFileLength = %d\n",nFileLength);

	while(nCount < nFileLength)
	{
		ostringstream stream;
		unsigned char tempData ;
		string baseStr ="0x";
		string result;
		tempData =pData[nCount];
			
		stream<<hex<<(int)tempData;
		result =stream.str();

		if(tempData<=15)
			result.insert(0,"0");

		baseStr.append(result);
		baseStr.append(",");
		fout.write(baseStr.c_str(),baseStr.size());

		stream.clear();
		nCount++;

		if(nCount%16==0)
			fout<<"\r\n";
	}

    delete pData;
	fin.close();
	fout.close();
}



static void process_short(string sFilePathIn,string sFilePathOut)
{
	char * pData;
	ifstream fin(sFilePathIn,ios::binary|ios::in|ios::ate);
	ofstream fout(sFilePathOut,ios::binary|ios::out);

	int nFileLength =fin.tellg()/sizeof(char);
	fin.seekg(0);
	pData = new  char [nFileLength];
	memset(pData,0,nFileLength*sizeof( char));
	fin.read(pData,nFileLength);
	
	int nCount =0;
	
	short * p =(short *)pData;

	const int nMinShortVal = 10000;
	const int nMaxShortVal = 20000;



	while(nCount < nFileLength)
	{
		//ostringstream stream;
		short tempData ;
		string baseStr ="0x";
		string result;
		tempData =*p;
		//stream<<hex<<(short)tempData;
#if 0	
		result =stream.str();
		if(result.size()<4)
			result.insert(0,4-result.size(),'0');
		baseStr.append(result);
		baseStr.append(",");
		fout.write(baseStr.c_str(),baseStr.size());
		stream.clear();
		nCount+=sizeof(short);
		if(nCount%(16*sizeof(short))==0)
			fout<<"\r\n";
		p++
#else
		tempData = tempData<nMinShortVal?nMinShortVal:tempData;
		tempData = tempData>nMaxShortVal?nMaxShortVal:tempData;
		
		
		fout.write((const char *)&tempData,sizeof(short));

		p++;
		nCount += sizeof(short);
#endif		
	}

	fin.close();
	fout.close();
}



int Get_Num(int n)
{
    
    if (n ==1);return 1;
    return n+Get_Num(n-1);
}




int main(int argc,char * argv[])
{
    //printf("%d\r\n",Get_Num(2));
    

#if 1    
    char strFileOut[128];
    int nArgInputLen = strlen(argv[1]);
    memcpy(strFileOut,argv[1],nArgInputLen);
    strFileOut[nArgInputLen]='\0';
    //strcat(strFileOut,".pcm");
	//process_short(argv[1],strFileOut);
	
	strcat(strFileOut,".txt");
	if (argc == 2)process_byte(argv[1],strFileOut);
	else if(argc ==3)process_byte(argv[1],argv[2]);
#endif	
}


