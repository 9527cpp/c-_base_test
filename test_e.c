#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#if 0
int main(){
    int step = 10000000;
    int total = 0;
    int i = 0;
    srand(time(0));
    for(i;i<step;i++){
        float sum = 0;
        int count = 0;
        while(1){
            sum += (float)(rand()% 32768)/32768.0;
            count ++;
            if(sum > 1.0)break;
        }
        total += count;
    }
    printf("total:%d,step:%d\r\n",total,step);
    printf("e:%f\r\n",(float)total/(float)step);
    return 0;
}
#else

int strStr(char * haystack, char * needle){
    int i = 0;
    int j = 0;
    int k = -1;
    int l = 0;
    int leni = strlen(haystack);
    int lenj = strlen(needle);
    if(lenj == 0)return 0;
    for(i=0;i<=leni-lenj;i++)
    {
        k = i;
        l = i;
        for(j = 0;j<lenj;j++,l++)
        {
            if(haystack[l]!=needle[j]){
                k = -1;
                break;
            }
        }
        if(j==lenj){
            //printf("j = %d\r\n",j);
            break;
        }
    }
    return k;
}

int isPalindrome(char * x){
    int bx = 0;
    int len = strlen(x);
    int i = 0;
    int j = len-1;
    int bi = 0;
    int bj = 0;
    while(i<j){
        printf("x[%d]:%d,x[%d]:%d\r\n",i,x[i],j,x[j]);
        if((x[i] >= 'a' && x[i] < 'z') || (x[i] >= 'A' && x[i] < 'Z')|| (x[i] >='0'&& x[i] <='9')){
            bi = 1;
        }
        else {
            bi = 0;
            i++;
        }

        if((x[j] >= 'a' && x[j] < 'z') || (x[j] >= 'A' && x[j] < 'Z')|| (x[j] >='0'&& x[j] <='9')){
            bj = 1;
        }
        else {
            bj = 0;
            j--;
        }
        if(bi && bj){
            if(x[i] == x[j] || (x[i] == x[j] - 32 && x[i] >= 'A' ) || (x[i] - 32 == x[j] && x[j] >= 'A')){
                i++;j--;
                continue;
            }
            else {
                bx = 0;
                return bx;
            }
        }
    }
    //if(bi && bj)
    bx = 1;
    return bx;
}




typedef struct {
    int *min_ele;
    int *ele;
    int num;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack * min_stack = NULL;
    min_stack = (MinStack *)malloc(sizeof(MinStack)); 
    if(min_stack){
        min_stack->min_ele = (int *)malloc(sizeof(int));
        min_stack->ele = (int *)malloc(sizeof(int));
        min_stack->num = 0;
    }
    return min_stack;
}

void minStackPush(MinStack* obj, int x) {
    if(!obj)return;    
    obj->min_ele = realloc(obj->min_ele,sizeof(int)*(obj->num+1));
    obj->ele = realloc(obj->ele,sizeof(int)*(obj->num+1));
    obj->ele[obj->num] = x;
    if(obj->num==0 || x <= obj->min_ele[obj->num-1])obj->min_ele[obj->num] = x;    
    else if(x > obj->min_ele[obj->num-1])
    {
        obj->min_ele[obj->num] = obj->min_ele[obj->num-1];
    }
    obj->num++;
}

void minStackPop(MinStack* obj) {
    if(!obj)return; 
    obj->num--;    
}

int minStackTop(MinStack* obj) {
    if(!obj)return; 
    return obj->ele[obj->num-1];
}

int minStackGetMin(MinStack* obj) {
    if(!obj)return;  
    return obj->min_ele[obj->num-1];
}

void minStackFree(MinStack* obj) {
    if(!obj)return; 
    free(obj->min_ele);
    free(obj->ele);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/




int main(){
#if 0
    char * P = "ab2a"; 
    char * S = "mississippi";
    char * T = "issip";
    //int len = strStr(S,T);
    int len = isPalindrome(P);
    printf("len : %d\r\n",len);
#endif
    int len;
  MinStack* obj = minStackCreate();
  minStackPush(obj, -2);
  minStackPush(obj, 0);
  minStackPush(obj, -3);
  len = minStackTop(obj);
  printf("%d\r\n",len);
  
  len = minStackGetMin(obj);
  printf("%d\r\n",len);

  minStackPop(obj);
 
  len = minStackTop(obj);
  printf("%d\r\n",len);

  len = minStackGetMin(obj);
  printf("%d\r\n",len);

  minStackFree(obj);

}
#endif
