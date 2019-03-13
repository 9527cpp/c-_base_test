/*
*	2017-6-2
*	该文件用来将16进制的txt文本生成对应数字的二进制文件
*	made by lijun
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


///add by lijun
static void process_byte(string sFilePathIn,string sFilePathOut)
{
	ifstream fin(sFilePathIn.c_str(),ios::in|ios::binary|ios::ate);
	ofstream fout(sFilePathOut.c_str(),ios::binary|ios::out);
	    
	int nFileLength =fin.tellg()/sizeof(char);
	fin.seekg(0);
    int nCount =0;
    printf("nFileLength = %d\n",nFileLength);

	while(nCount < nFileLength &&   nCount>=0)
	{
		int nData =0;
		
		fin.seekg(2,ios::cur);
		    
		fin>>hex>>nData;
		
	    //printf("0x%02x,",nData);
		fout.write((const char *)&nData,1);
		
        fin.seekg(1,ios::cur);
        nCount=fin.tellg();
        
        //printf("%d,",nCount);
	}
	printf("finished\r\n");

	fin.close();
	fout.close();
}
#if 1

int main(int argc,char * argv[])
{
    char strFileOut[128];
    memcpy(strFileOut,argv[1],strlen(argv[1]));
    strcat(strFileOut,".txt");
    if (argc == 2)process_byte(argv[1],strFileOut);
    else if(argc ==3)process_byte(argv[1],argv[2]);
    return 0;
}
#endif


