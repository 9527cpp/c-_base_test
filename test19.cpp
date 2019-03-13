#include <iostream>
using namespace std;

char base64[64]=
{
	'A','B','C','D','E','F','G','H',
	'I','J','K','L','M','N','O','P',
	'Q','R','S','T','U','V','W','X',
	'Y','Z','a','b','c','d','e','f',
	'g','h','i','j','k','l','m','n',
	'o','p','q','r','s','t','u','v',
	'w','x','y','z','0','1','2','3',
	'4','5','6','7','8','9','+','/'
};


char * getOneBase64(char * strSrc,int nBytes)
{
	char * pSrc = strSrc;
	if(nBytes == 3)
	{
		// 3 * 8 ----> 4 * 6 ---> 4 * 8
		char bSrcByte1 = *pSrc;pSrc++;
		char bSrcByte2 = *pSrc;pSrc++;
		char bSrcByte3 = *pSrc;pSrc++;
		

	}
	else if(nBytes == 2)
	{
		// 2 * 8 ----> 6+6+4 ---> 8+8+8+ =
	}
	else if(nBytes == 1)
	{

	}
	else
	{
		printf("error nBytes == %d\n",nBytes);
	}
}

char * generateBase64(char * strSrc)
{
	char * pStr = strSrc;
	while(pStr)
	{

	}
}

int main()
{
	return 0;
}