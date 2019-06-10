#include <stdio.h>
#include <stdlib.h>
#include <new.h>



#define MAXN 10
#define TOTALN 100

//#define FIND_MAX_IN_THREE(p,c1,c2) 

void FindMaxInThree(int &p,int &c1,int &c2)
{
	int c0 = c1/c2 >= 1? c1:c2;
	int pp = c0/p >= 1? c0:p;
		
	printf("pp:%d \r\n",pp);
	if(pp == c1)
	{
		p^=c1^=p^=c1;	
	}
	else if(pp == c2)
	{
		p^=c2^=p^=c2;	
	}
}


void MakeMaxN_map(int *pData,int nLen)
{
	int nChild = nLen;
	if(nLen > MAXN) nChild = MAXN;
	int nParent = nChild/2;
	do
	{
		FindMaxInThree(pData[nParent],pData[nParent *2],pData[nParent*2+1]);
			
		nParent --;
	}while(nParent > 0);
}


class Test
{
public:
	void func(){printf("func test\r\n");}	
public:
	int a;
	int b;
};


int main()
{
	
	int a = 1;
	int b = 10 * ++a;
	printf ("b:[%d],a:[%d]\r\n",b,a);

//// placement new 方式构造
	char pMemory[16];
	printf("pMemeory:%x\r\n");
	Test * pTest = new(pMemory)Test();
	printf("pTest:%x,pTest->a:%x,pTest->b:%x\r\n",pTest,pTest->a,pTest->b);
////注意如果用placement new方式构造的话 不能调用delete 必须显示调用类的析构函数	
	
	
//// 强制地址转换方式构造	
	void *pTest1 = reinterpret_cast<Test *>(pMemory);
	void *pTest2 = reinterpret_cast<Test *>(pMemory + sizeof(Test));
	printf("pMemory:%2x,pTest1:%2x,pTest2:%2x\r\n",pMemory,&(((Test*)pTest1)->a),&(((Test*)pTest1)->b)); 
#if 0
	srand(NULL);
		
	int i = 0;
	int pData[TOTALN] = {0};
	while(i < TOTALN)
	{
		pData[i++] = rand()%100;
	}
	
	MakeMaxN_map(pData,TOTALN);
	for(i = 0;i< MAXN;i++)
		printf("%d,",pData[i]);
	printf("\r\n");
#endif	
}