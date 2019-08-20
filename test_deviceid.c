#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARGET_WINDOWS 1
#define TARGET_LINUX 0

#if TARGET_WINDOWS
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#elif TARGET_LINUX
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#endif

#ifdef SOCKET_T
#undef SOCKET_T
#endif

#define SOCKET_T int
#define PORT 6666
#define BUF_SIZE 1024

int sock_init(){
    int ret = 0;
#if TARGET_WINDOWS
    WSADATA WSAData;
    ret = WSAStartup(MAKEWORD(2,2),&WSAData);
#endif    
    return ret;
}

SOCKET_T sock_create(){
    SOCKET_T sock = 0;
    sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    return sock;
}

int sock_bind(SOCKET_T sock,struct sockaddr_in * p_addr){
    int ret = -1;
    memset(p_addr,0, sizeof(struct sockaddr_in));  
    p_addr->sin_family = AF_INET;  
    p_addr->sin_addr.s_addr = htons(INADDR_ANY);//inet_addr("192.168.1.146");
    p_addr->sin_port = htons(PORT);
    ret = bind(sock,(struct sockaddr *)p_addr,sizeof(struct sockaddr_in));
    return ret; 
}

int sock_listen(SOCKET_T sock){
    int ret = -1;
    ret = listen(sock,5);
    return ret;
}

void sock_reinit(SOCKET_T sock){
#if TARGET_WINDOWS
    closesocket(sock);
    WSACleanup();
#elif TARGET_LINUX
    close(sock);    
#endif
}


int main(){
    SOCKET_T sock_s = -1;
    int ret = -1;
    struct sockaddr_in addr_s;
    ret = sock_init();
    if(ret != 0){
        printf("sock init Error\r\n");
        return 0;
    }
    sock_s = sock_create();
    if(sock_s == -1){
        printf("sock create Error\r\n");
        return 0;
    }
    ret = sock_bind(sock_s,&addr_s);
    if(ret == -1){
        printf("sock bind Error\r\n");
        return 0;
    }
    ret = sock_listen(sock_s);
    if(ret == -1){
        printf("sock listen Error\r\n");
        return 0;
    }
    printf("::::::start server::::::\r\n");
    while(1){
        SOCKET_T sock_c = -1;
        struct sockaddr_in addr_c;
        char buf[BUF_SIZE];
        int len = 0;
        int i = 0;
        int addr_size = sizeof(addr_c); 
        sock_c = accept(sock_s,(struct sockaddr*)&addr_c,&addr_size);
        if(sock_c == -1){
#if TARGET_WINDOWS   
            printf("sock accpet Error:%d\r\n",WSAGetLastError()); 
#elif TARGET_LINUX
            printf("sock accpet Error:%d\r\n",errno);
#endif            
            continue;
        }
        else{
            printf("client connect\r\n");
            memset(buf,0,BUF_SIZE);
            len = recv(sock_c,buf,BUF_SIZE,0);
            printf("len :%d\r\n",len);
            if(len == 0 || len == -1){
                printf("sock recv Error\r\n");
            }
            for(i= 0;i<len;i++){
                printf("%x,",buf[i]);
            } 
            printf("\r\n");
            closesocket(sock_c);
        }
    }
    sock_reinit(sock_s);
    return 0;
}
