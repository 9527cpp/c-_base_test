#include <iostream>
using namespace std;

template<typename T>
void ArrayGetTwoMax(T * pArray,int nLen,T &tMaxOne,T &tMaxTwo)
{
    if(pArray == NULL)return;
    tMaxOne = tMaxTwo = *pArray;
    for(int i = 1;i<nLen;i++)
    {
        if(pArray[i] > tMaxOne)
        {           
            tMaxOne = pArray[i];
        }
        else if(pArray[i] > tMaxTwo)
        {
            tMaxTwo = pArray[i]; 
        }
    }
    printf("tMaxOne = %d,tMaxTwo = %d\n",tMaxOne,tMaxTwo);
}


template<typename T>
void ArrayGetTwoIndex(T * pArray,int nLen,T tValue,T &tIndexOne,T &tIndexTwo)
{
    if(pArray == NULL)return;
    tIndexOne = tIndexTwo = 0;
    for(int i = 1;i<nLen;i++)
    {
        if(pArray[i] == tValue)
        {    
            if(i > tIndexTwo)tIndexTwo = i;
            if(i > tIndexOne &&pArray[i] != pArray[tIndexOne])tIndexOne = i;
        }
    }
    printf("tIndexOne = %d,tIndexTwo = %d\n",tIndexOne,tIndexTwo);
}



template<typename T>
void ArrayDisplay(T * pArray,int nLen)
{
    for(int i = 0;i<nLen;i++)
    {
        printf("%d,",pArray[i]);
    }    
    printf("\n");
}

int main()
{
    int pArray[]={4,2,6,8,1,10,5,7,9,3,8,9,8};
    int nLen = sizeof(pArray)/sizeof(pArray[0]);
/*******************************************/
    printf("after init\n");
    ArrayDisplay<int>(pArray,nLen);
/*******************************************/    
    printf("get two max value:\n");
    int nMaxOne = 0,nMaxTwo = 0;
    ArrayGetTwoMax<int>(pArray,nLen,nMaxOne,nMaxTwo);
/*******************************************/    
    printf("get two index:\n");
    int tIndexOne = 0,tIndexTwo = 0;
    ArrayGetTwoIndex<int>(pArray,nLen,8,tIndexOne,tIndexTwo);    
    return 0;
}