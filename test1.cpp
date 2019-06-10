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
#include <io.h>
using namespace std;


///add by lijun

//test
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

char gdir[128];

void listFiles(const char * dir)
{
    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst(dir, &findData);    // 查找目录中的第一个文件
    if (handle == -1)
    {
        cout << "Failed to find first file!\n";
        return;
    }

    do
    {
        if (findData.attrib & _A_SUBDIR
            && strcmp(findData.name, ".") == 0
            && strcmp(findData.name, "..") == 0
            )   
            cout << findData.name << "\t<dir>\n";
        else
        {
        	cout << findData.name << "\t" << findData.size << endl;
        	char strFileIn[128];
        	char strFileOut[128];
        	memset(strFileIn,0,128);
        	memset(strFileOut,0,128);
		    //memcpy(strFileOut,findData.name,strlen(findData.name));
		    sprintf(strFileIn,"%s%s",gdir,findData.name);
		    sprintf(strFileOut,"%s",findData.name);
		    strcat(strFileOut,".mp3");
		    cout<<strFileIn<<endl;
		    cout<<strFileOut<<endl;
		    process_byte(strFileIn,strFileOut);
        }
            
    } while (_findnext(handle, &findData) == 0);    // 查找目录中的下一个文件

    cout << "Done!\n";
    _findclose(handle);    // 关闭搜索句柄
}


#if 1



int main(int argc,char * argv[])
{
	
#if 0	
    char strFileOut[128];
    memcpy(strFileOut,argv[1],strlen(argv[1]));
    strcat(strFileOut,".txt");
    if (argc == 2)process_byte(argv[1],strFileOut);
    else if(argc ==3)process_byte(argv[1],argv[2]);
#endif

	char str[128] = "C:\\Users\\Administrator\\Desktop\\test\\CppTests\\ConstPromtVoice\\";
	memcpy(gdir,str,128);
	strcat(str, "*.*");

#if 0	
	char drive[_MAX_DRIVE];  
    char dir[_MAX_DIR];  
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT]; 
    _splitpath( str, drive, dir, fname, ext );
    cout <<drive<<endl;
    cout <<dir<<endl;
    cout <<fname<<endl;
    cout <<ext<<endl;
#endif    
	listFiles(str);   
	 	
    return 0;
}
#endif


