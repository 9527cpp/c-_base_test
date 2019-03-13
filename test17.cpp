#include <iostream>
using namespace std;

class LinkTable
{
public:
	struct LinkNode
	{
		int nData;
		LinkNode * pNext;
	};

	LinkTable()
	{
		pHead = new LinkNode;
		pHead->pNext = NULL;
	}

	void Create()
	{
		int nData=0;
		LinkNode * pTempHead = pHead;	
		do
		{
			cin>>nData;
			if(nData!=0)
			{
				LinkNode * pTempNode = new LinkNode;
				pTempNode->nData = nData;
				pTempNode->pNext = NULL;
				pTempHead->pNext = pTempNode;
				pTempHead = pTempNode;
			}
		}while(nData!=0);
	}

	void Destroy()
	{
		LinkNode * p = pHead->pNext;
		LinkNode * q = pHead->pNext;
		while(p)
		{
			q = p;
			p = p->pNext;
			delete q;
		}
	}

	void Display()
	{
		LinkNode * pTemp = pHead;
		while(pTemp->pNext)
		{
			pTemp = pTemp->pNext;
			cout<<pTemp->nData<<",";		
		}
		cout<<endl;
	}

	// 找倒数第K个元素（仅允许遍历一次列表）
	// 两指针p,q    p先走k步 然后两个p,q同时一起走,直到p到达结尾，注意链表长度大于k
	void FindTheLastK(int K)
	{
		LinkNode * p  = pHead;
		LinkNode * q  = pHead;

		while(K-- && p->pNext)
		{
			p = p->pNext;
		}
		if(!p){cout<<"the length of linktable is small than K"<<endl;return;}
		while(p)
		{
			p = p->pNext;
			q = q->pNext;
		}
		cout<<"the last K 's "<<q->nData<<endl;
	}

	//找出中间元素（仅允许遍历一次列表）
	//俩指针p,q  p没走1步,q每走2步直到q到尾 返回p
	void FindTheMidle()
	{
		LinkNode * p = pHead;
		LinkNode * q = pHead;
		while(q)
		{
			p = p->pNext;
			q = q->pNext;
			if(!q)break;
			q = q->pNext;
		}
		cout<<"the middle 's "<<p->nData<<endl;
	}

	// 只用一个指针变量 删除指定value的节点
	void RemovePvalue(int nValue)
	{
		LinkNode * pNode = pHead;
		while(pNode)// find the node
		{
			if(pNode->nData == nValue)break;
			pNode = pNode->pNext;
		}
		if(!pNode){cout<<"not find"<<endl;return;}
		/// 前提是pNode->pNext != NULL;
		pNode->nData = pNode->pNext->nData;
		LinkNode * qNode = pNode->pNext;
		pNode->pNext = qNode->pNext;	
		delete qNode;
	}

	
public:
	LinkNode * pHead;
};

#if 0
int main()
{
	LinkTable lt;
	
	while(1)
	{
		lt.Create();
		lt.Display();
		lt.FindTheLastK(2);
		lt.FindTheMidle();
		lt.RemovePvalue(2);
		lt.Display();
		lt.Destroy();
	}
}
#endif