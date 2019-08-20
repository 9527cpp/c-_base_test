#include "lj_queue_cache.h"
#include <stdio.h>


#if 1
int main()
{
	void * qcache = 0;
	
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	int * p = NULL;
	int i = 0;
	
	qcache = lj_qcache_create(0);
	lj_qcache_push(qcache, &a);
	lj_qcache_push(qcache, &b);
	lj_qcache_push(qcache, &c);
	lj_qcache_push(qcache, &d);
	lj_qcache_push(qcache, &e);

	//// if all push done  must call this func
	lj_qcache_reset(qcache);
	/// 循环模式
	lj_qcache_set_cycle_mode(qcache);
	/// 线性模式
	//lj_qcache_set_line_mode(qcache);

	

#if 0
	for( i = 0;i<6;i++)
	{
		p = (int *)lj_qcache_pop(qcache);
		if(p)
		printf("%d\r\n",*p);
		p = NULL;
	}
#endif

printf("begin get next\r\n");
	for( i = 0;i<6;i++)
	{
		p = (int *)lj_qcache_get_next(qcache);
		if(p)
		printf("%d\r\n",*p);
		p = NULL;
	}
    
printf("begin get pre\r\n");
	for( i = 0;i<6;i++)
	{
		p = (int *)lj_qcache_get_pre(qcache);
		if(p)
		printf("%d\r\n",*p);
		p = NULL;
	}

printf("begin get next\r\n");
	for( i = 0;i<6;i++)
	{
		p = (int *)lj_qcache_get_next(qcache);
		if(p)
		printf("%d\r\n",*p);
		p = NULL;
	}

	return 0;
}
#else
#include "string.h"
#include "winsock.h"
#pragma comment(lib,"ws2_32.lib")

void milliseconds_sleep(unsigned long mSec){
    struct timeval tv;
    tv.tv_sec=mSec/1000;
    tv.tv_usec=(mSec%1000)*1000;
    int err;
	fd_set read_set;
	
	WSADATA wsaData;
	WORD  wVersionRequested =MAKEWORD( 2, 2);
	WSAStartup(wVersionRequested,&wsaData);
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
    while(1)
	{
		FD_ZERO(&read_set);
		FD_SET(sockClient, &read_set);
		err=select(0,&read_set,NULL,NULL,&tv);
		printf("%d\r\n",WSAGetLastError());
    }
	closesocket(sockClient);  
	WSACleanup(); 
}

int main()
{

	printf("start\r\n");
	milliseconds_sleep(5000);
	printf("end\r\n");
	return 0;
}

#endif
