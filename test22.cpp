#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T tData;
    struct Node * pNext;
};

/*
    添加元素
*/
template<typename T>
void ListAdd(Node<T> **pNode,T tData)
{
    Node<T>  * pTemp = *pNode;
	if(pTemp==NULL)
	{
		*pNode = new Node<T>();
		 if(NULL==*pNode){printf("alloc failed\n");return;}
		(*pNode)->tData = tData;
		(*pNode)->pNext = NULL;
		return;
	}
	Node<T>  * pTail = pTemp;
	while(pTemp)
    { 
       pTail = pTemp;
       pTemp = pTemp->pNext; 
    }
    pTemp = new Node<T>();
    if(NULL==pTemp){printf("alloc failed\n");return;}
    pTemp->tData = tData;
    pTemp->pNext = NULL;
    if(pTail)
	{
		pTail->pNext = pTemp;
	}
}

/*
    固定位置(前面)添加元素
*/
template<typename T>
void ListAddBeforeK(Node<T> **pNode,int nIndex,T tData)
{
    Node<T>  * pTemp = *pNode;
    Node<T>  * pTail = pTemp;
    int nCount =0;
    while(pTemp)
    {
        nCount++;
        if(nCount == nIndex)break;
        pTail = pTemp;
        pTemp = pTemp->pNext;
    }
    if(pTemp)//add head or body
    {
        if(pTemp == *pNode)
        {
            pTemp = NULL;
            pTemp = new Node<T>();
            if(NULL==pTemp){printf("alloc failed\n");return;}
            pTemp->tData = tData;
            pTemp->pNext = *pNode;
            *pNode = pTemp;
        }
        else
        {
            // exchange
            Node<T>  *pTempTemp = new Node<T>();
            if(NULL==pTempTemp){printf("alloc failed\n");return;}
            pTempTemp->tData = pTemp->tData;
            pTempTemp->pNext = pTemp->pNext;
            pTemp->tData = tData;
            pTemp->pNext = pTempTemp;
        }
    }
    else// add tail
    {
        Node<T>  *pTempTemp = new Node<T>();
        if(NULL==pTempTemp){printf("alloc failed\n");return;}
        pTempTemp->tData = tData;
        pTempTemp->pNext = NULL;
        pTail->pNext = pTempTemp;
    }
}

/*
    删除顺数第K个元素
*/
template<typename T>
void ListDeleteLK(Node<T> **pNode,int nIndex)
{
    int nListCount = 0;
    Node<T> *pP = NULL,*pC =*pNode;

    while(pC)
    {
       nListCount ++;
       if(nListCount == nIndex)
       {
            if(pP==NULL||pC==*pNode)
            {
                *pNode = (*pNode)->pNext;                
            }
            else
            {
                pP->pNext = pC->pNext;              
            }
            delete pC;
            return;
       }
       pP = pC; 
       pC = pC->pNext;       
    }
    printf("删除的位置不在列表长度范围内\n");
}


/*
    删除倒数第K个元素
*/
template<typename T>
void ListDeleteRK(Node<T>  **pNode,int nIndex)
{
    int nListLen = 1;
    Node<T> *pC =*pNode;
    while(pC)
    {
        pC = pC->pNext;
        nListLen++;
    }
    ListDeleteLK(pNode,nListLen-nIndex);
}


/*
    反转
*/
template<typename T>
void ListReverse(Node<T>  **pNode)
{
    Node<T> *pP = NULL,*pC = *pNode,*pN = (*pNode)->pNext;
    while(pN)
    {
        pC->pNext = pP;
        pP = pC;
        pC = pN;
        pN = pN->pNext;     
    } 
    *pNode = pC;   
	(*pNode)->pNext = pP;
}

/*
    查找中间元素
*/
template<typename T>
T ListFindMiddle(Node<T>  *pNode)
{
    Node<T> *pOne = pNode,*pTwo = pNode;
    while(1)
    {
        if(NULL == pTwo)break;
        pTwo = pTwo->pNext;
        if(NULL == pTwo)break;
        pTwo = pTwo->pNext;
        pOne = pOne->pNext;    
    } 
    return pOne->tData;
}

/*
    遍历一次查找倒数第K个元素
*/
template<typename T>
T ListFindKOneProid(Node<T>  *pNode,int nIndex)
{
    Node<T> *pK =pNode,*p0 = NULL;
    int nCount =0;
    while(pK)
    {
        nCount++;
        if(nCount == nIndex)p0 = pNode;
        if(nCount > nIndex && nIndex > 0)p0 = p0->pNext;
        pK = pK->pNext;
    }
    return p0?p0->tData:-1;
}

/*
    冒泡排序
*/
template<typename T>
void ListBubbleSort(Node<T>  *pNode)
{
    Node<T> *pI = pNode,*pJ = pNode;
    for(;NULL!=pI;pI = pI->pNext)
    {
        for(pJ = pI->pNext;NULL!=pJ;pJ = pJ->pNext)
        {
            if(pJ->tData < pI->tData)
            {
                (pJ->tData)^=(pI->tData)^=(pJ->tData)^=(pI->tData);
            }
        }
    }
}

/*
    约瑟夫环 
    参数 1: head
    参数 2: 目标数
    参数 3: 最后剩余人数
*/
template<typename T>
void ListJonsephRing(Node<T>  **pNode,int nCounts,int nLast)
{
    int nListLen = 0;
    int nStep = 0;
    Node<T> * pC =*pNode,*pT = *pNode,*pP = NULL;
    while(pC)
    {
        pT = pC;pC = pC->pNext;
        nListLen ++;
    }
    pC = *pNode;
    printf("out list is:\n");
    while(nListLen != nLast)
    {
        nStep++;   
 
        if(nStep == nCounts)
        {
           nListLen--; 
           if(pC == *pNode)
           {
              printf("%d-->",pC->tData);
              *pNode = (*pNode)->pNext;  
              delete pC;
              pC = *pNode;
           }
           else if(pC == pT)
           {
              printf("%d-->",pC->tData);
              pT = pP;
              delete pC;
              pC = *pNode;
              pT->pNext = NULL;  
           }
           else
           {
               printf("%d-->",pC->tData);
               pP->pNext = pC->pNext;
               delete pC;
               pC = pP->pNext;         
           }            
           nStep = 0;
        }                 
        if(nStep!=0)
        {
            pP = pC;
            pC = pC->pNext;
            if(pC == NULL)pC = *pNode;
        }            
    }
    printf("NULL\n");
}

/*
    链表打印
*/
template<typename T>
void ListDisplay(Node<T>  *pNode)
{
    Node<T> * pC = pNode;
    while(pC)
    {
        printf("%d-->",pC->tData);
        pC = pC->pNext;
    }
	printf("NULL\n");
}



int main()
{
    int nData = 0;
/*******************************************/
    Node<int> *pHead = NULL;
    ListAdd<int>(&pHead,1);
    ListAdd<int>(&pHead,2);
    ListAdd<int>(&pHead,3);
    ListAdd<int>(&pHead,4);
    ListAdd<int>(&pHead,5);
    printf("after init\n");
    ListDisplay<int>(pHead);
/*******************************************/
    printf("after reverse\n");
    ListReverse<int>(&pHead);
    ListDisplay<int>(pHead);
/*******************************************/
    printf("after delete left 1\n");
    ListDeleteLK<int>(&pHead,1);
    ListDisplay<int>(pHead);
/*******************************************/
    printf("after delete right 1\n");
    ListDeleteRK<int>(&pHead,1);
    ListDisplay<int>(pHead);
/*******************************************/
    printf("after add value(10) before index 2\n");
    ListAddBeforeK<int>(&pHead,2,10);
    ListDisplay<int>(pHead);
/*******************************************/
    nData = ListFindMiddle<int>(pHead);
    printf("after find middle data : %d\n",nData);
/*******************************************/
    printf("after bubble sort\n");
    ListBubbleSort(pHead);
    ListDisplay<int>(pHead);
/*******************************************/
    nData = ListFindKOneProid<int>(pHead,3);
    printf("after find last 3 data : %d\n",nData);
/*******************************************/
    Node<int> *pJonsephHead = NULL;
    for(int i = 0;i<30;i++)ListAdd<int>(&pJonsephHead,i+1);
    printf("before Jonseph:\n");
    ListDisplay<int>(pJonsephHead);
    ListJonsephRing(&pJonsephHead,7,6);
    printf("after Jonseph count 7 the last 6 is:\n");
    ListDisplay<int>(pJonsephHead);
/*******************************************/
    return 0;
} 