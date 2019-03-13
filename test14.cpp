#include <stdio.h>  
   
void sayhello(int * p)  
{  
        printf("*p = %d\n",*p);  
}  
#if 0
int main(void)  
{  

		
        /* normally, we use a function pointer such like this. */  
        //void (*p)(void);  
        unsigned int addr;  
		int a = 10;
        /* but we can use the address of a function directly. */  
        addr =(unsigned int) sayhello;  

        ((void (*)(int *))addr)(&a);  
		
        /* use function pointer */  
        //p = sayhello;  
        //p();  
   
        return 0;  
}
#endif