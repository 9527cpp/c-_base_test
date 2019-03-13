#include <iostream>
#include <string.h>

int nDatas[]=
{
    10100 ,
    10200 ,
    10300 ,
    10400 ,
    10500 ,
    10600 ,
    10800 ,
    10900 ,
    11000 ,
    11200 ,
    20100 ,
    20200 ,
    20300 ,
    20400 ,
    20500 ,
    20600 ,
    20800 ,
    20900 ,
    21000 ,
    21100 ,
    21200 ,
    21300 ,
    21500  
};


unsigned char Translate(int nData)
{
    char pTemp[7]={0};
    itoa(nData,pTemp,10);
    memset(pTemp+3,0,2);
    printf("%s\n",pTemp);  
    char b = atoi(&pTemp[1]);
    memset(pTemp+1,0,2);
    char a = atoi(&pTemp[0]);      
    return ((a<<4)|b);   
}

int main()
{
    
   #if 0
    int nLen = sizeof(nDatas)/sizeof(nDatas[0]);
    for(int i = 0;i<nLen;i++)
    {
        printf("%2x\n",Translate(nDatas[i]));
    }
   #else

       unsigned char pChar[]={0x01,0x02,0x03,0x04};
       unsigned short * pShort = (unsigned short *) pChar;
       printf("%d\r\n",*pShort);
       
       pShort = (unsigned short *) (pChar+2); 
       printf("%d\r\n",*pShort);

   #endif 
    getchar();
    return 0;
}


