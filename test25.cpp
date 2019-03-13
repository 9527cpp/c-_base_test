
/*********************************************************************************
  *Copyright(C),http://www.youngtone.cn
  *FileName:  TulingAsrData.h
  *Author:  李君
  *Version:  v1.0
  *Date:  2017.9.21
**********************************************************************************/
#ifndef __TULING_DATA_V2_H__
#define __TULING_DATA_V2_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
class TulingDataV2
{
public:
	static TulingDataV2 &Instance();
	~TulingDataV2();
	void Init(int _nUnitSize,int _nUnitCnt,int _nBlocks);
	void Destory();	
	char * GetReadPtr();	
	void ReadDone(int nLen);	
	char * GetWritePtr();	
	int GetDataSize();
	void WriteDone(int nLen);	
	void Reset();
	void Print();
	int GetReadCnt();
	int GetWriteCnt();
private:
	TulingDataV2();
private:
	static TulingDataV2  mInstance;
	char ** qQueue;	 
	int nUnitSize;
	int nUnitCnt;
	int nBlocks;	
	int nReadCnt;	
	int nWriteCnt;
	int nTotalCnt;
};

TulingDataV2 TulingDataV2::mInstance;

TulingDataV2 &TulingDataV2::Instance()
{
	return mInstance;
}

TulingDataV2::TulingDataV2()	
	:qQueue(NULL)	
	,nReadCnt(0)	
	,nWriteCnt(0)
	,nTotalCnt(0)
{
	
}

TulingDataV2::~TulingDataV2()
{	
	Destory();
}

// _nUnitSize = 640 
// _nUnitCnt = 6
// _nUnitSize * _nUnitCnt = 1 _nBlocks
// _nBlocks = 3
void TulingDataV2::Init(int _nUnitSize,int _nUnitCnt,int _nBlocks)
{	
	nUnitSize = _nUnitSize;
	nUnitCnt = _nUnitCnt;
	nBlocks = _nBlocks;	
	Destory();	
	qQueue = new char *[nBlocks];	
	for(int i = 0; i< nBlocks; i++)	
	{		
		qQueue[i] = new char[nUnitSize * nUnitCnt];	
		memset(qQueue[i],0,nUnitSize * nUnitCnt);
	}	
}

void TulingDataV2::Destory()
{	
	if(qQueue)	
	{		
		for(int i = 0; i< nBlocks; i++)		
		{			
			if(qQueue[i])delete qQueue[i];			
			qQueue[i] = NULL;		
		}		
		delete qQueue;		
		qQueue = NULL;	
	}
}

char * TulingDataV2::GetReadPtr()
{	
	if(nReadCnt >= nWriteCnt) return NULL;	
	return &(qQueue[(nReadCnt / nUnitCnt)%nBlocks][nReadCnt % nUnitCnt]);
}

/*
    nLen 字节数
*/
void TulingDataV2::ReadDone(int nLen)
{	
	nTotalCnt -= nLen;
	nReadCnt ++;
}


char * TulingDataV2::GetWritePtr()
{	
	return &(qQueue[(nWriteCnt / nUnitCnt)%nBlocks][nWriteCnt % nUnitCnt]);
}

int TulingDataV2::GetDataSize()
{
	return nTotalCnt;
}

/*
    nLen 字节数
*/
void TulingDataV2::WriteDone(int nLen)
{	
	nTotalCnt += nLen;	
	for(int i = 0;i< nLen/nUnitSize;i++)nWriteCnt ++;
}

void TulingDataV2::Reset()
{	
	nReadCnt = 0;	
	nWriteCnt = 0;
	nTotalCnt = 0;
	for(int i = 0; i< nBlocks; i++)	
	{	
		memset(qQueue[i],0,nUnitSize * nUnitCnt);	
	}
}

int TulingDataV2::GetReadCnt()
{
    return   nReadCnt;
}

int TulingDataV2::GetWriteCnt()
{
    return   nWriteCnt;
}

void TulingDataV2::Print()
{
	for(int i = 0; i< nBlocks; i++)	
	{	
		for(int j = 0;j<nUnitCnt;j++)
		{
		    printf("%d ",qQueue[i][j]);
		}     
		printf("\n");	
	} 
	printf("\n");	   
}



#endif

int main()
{
    TulingDataV2::Instance().Init(4,6,3);
    for(int i = 0;i<10;i++)
    {
        char * ptr = TulingDataV2::Instance().GetWritePtr();
        int nLen = sizeof(i);
        memcpy(ptr,&i,nLen);
        TulingDataV2::Instance().WriteDone(nLen);
    }
    
    TulingDataV2::Instance().Print();   
        
    for(int i = 0;i<10;i++)
    {
        char * ptr = TulingDataV2::Instance().GetReadPtr();
        printf("%d ",*ptr);
        TulingDataV2::Instance().ReadDone(sizeof(int));
    }
    printf("\n");
    TulingDataV2::Instance().Print();
             
    TulingDataV2::Instance().Reset();
    
    for(int i = 255;i<258;i++)
    {
        char * ptr = TulingDataV2::Instance().GetWritePtr();
        int nLen = sizeof(i);
        memcpy(ptr,&i,nLen);
        TulingDataV2::Instance().WriteDone(nLen);
    }  
    TulingDataV2::Instance().Print();   
    
    for(int i = 255;i<258;i++)
    {
        char * ptr = TulingDataV2::Instance().GetReadPtr();
        printf("%d ",*ptr);
        TulingDataV2::Instance().ReadDone(sizeof(int));
    }
    printf("\n");
    TulingDataV2::Instance().Print();
        
                
    return 0;
}