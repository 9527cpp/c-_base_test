/*
*	2017-6-2
*	该文件用来获取一个数的原码和补码
*	made by lijun
*/

#include <iostream>
using namespace std;


template<class T>
T getAbsulate(T tData)
{
	T tTempData =tData;
	//求原码
	return (tTempData)^0x80;
}


//取补码 计算机中都是以补码存储的
void get_src_binary_code(char number,char * src_binary_code,int src_len)
{	
	unsigned char u_number =number;
	memset(src_binary_code,0,src_len*sizeof(char));
	while(u_number>0)
	{
		src_binary_code[--src_len]=u_number%2;
		u_number>>=1;
	}
}

/*
int main()
{
#if 0
	char a = -126;
	char src_bin_code[8];
	get_src_binary_code(a,src_bin_code,8);
	for(int i =0;i<8;i++)
		cout<<(int)src_bin_code[i]<<" ";
#endif		

	char tData = -126;
	char tAbsData =getAbsulate(tData);
	cout<<(int)tAbsData<<endl;

	return 0;
}
*/