#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 5


void choose_sort(int *nums,int numsSize){
    int i = 0;
    int j = 0;
    int t = 0;
    for(i = 0;i<numsSize;i++){
        for(j =i+1;j<numsSize;j++){
            if(nums[j] < nums[i]){
                t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
            }
        }
    }
}



int minPathSum(int grid[3][3],  int row,  int col){
    int i = 0;
    int j = 0;
    int sum = 0;
    int dp[3][3];
    if(row == 0 || col == 0)return 0; 
    dp[0][0] = grid[0][0];
    for(i = 1;i<row;i++){
        dp[i][0] = grid[i][0] + dp[i-1][0];
        printf("%d,",dp[i][0]);
    } 
    printf("\r\n");
    for(j = 1;j<col;j++){
        dp[0][j] = grid[0][j] + dp[0][j-1];
        printf("%d,",dp[0][j]);
    }
    printf("\r\n");
    for(i = 1;i<row;i++){
        for(j = 1;j<col;j++){
            int k = dp[i-1][j] < dp[i][j-1]?dp[i-1][j]:dp[i][j-1];            
            dp[i][j] = k + grid[i][j];
            printf("%d,",dp[i][j]);
        }
        printf("\r\n");
    }
    printf("\r\n");
    return dp[row -1][col -1];
}


int ** z_in(int m,int n){
    int i = 0;
    int j = 0;
    int **p = NULL;
    int total = m *n;
    int c = 1;
    int c1 = 1;
    enum Z_DIR{RIGHT,DOWN,LEFT,UP}dir;
    dir = RIGHT;
    p = (int *)malloc(sizeof(int)*m);
    for(i = 0;i < m;i++)p[i] = (int *)malloc(sizeof(int)*n);
    i = 0;
    j = 0;
    while(c <= total){
        if(dir == RIGHT){
            p[i][j] = c;
            if(c1 == n){
                dir = DOWN;
                c1 = 0;
                m--;
                n--;
                i++;
            }else j++;
        }
        else if(dir == DOWN){
            p[i][j] = c;
            if(c1 == m){
                dir = LEFT;
                c1 = 0;
                j--;               
            }else i++;            
        }
        else if(dir == LEFT){
            p[i][j] = c;
            if(c1 == n){
                dir = UP;
                c1 = 0;
                m--;
                n--;
                i--;
            }else j--; 
        }
        else if(dir == UP){
            p[i][j] = c;
            if(c1 == m){
                dir = RIGHT;
                c1 = 0;
                j++;
            }else i--; 
        }
        c++;
        c1++;
    }
    return p;
}



int* spiralOrder(int** matrix, int matrixSize, int matrixColSize, int* returnSize){
//int* spiralOrder(int matrix[3][4], int matrixSize, int matrixColSize, int* returnSize){
    int i = 0;
    int j = 0;
    int *p = NULL;
    int m = matrixSize;
    int n = matrixColSize;
    int total = m *n;
    int c = 0;
    int c1 = 1;
    enum Z_DIR{RIGHT,DOWN,LEFT,UP}dir;
    dir = RIGHT;
    p = (int *)malloc(sizeof(int)*total);
    i = 0;
    j = 0;
    while(c < total){
        if(dir == RIGHT){
            p[c] = *(matrix +i * n +j);
            if(c1 == n){
                dir = DOWN;
                c1 = 0;
                m--;
                n--;
                i++;
            }else j++;
        }
        else if(dir == DOWN){
            p[c] = *(matrix +i * n +j);
            if(c1 == m){
                dir = LEFT;
                c1 = 0;
                j--;               
            }else i++;            
        }
        else if(dir == LEFT){
            p[c] = *(matrix +i * n +j);
            if(c1 == n){
                dir = UP;
                c1 = 0;
                m--;
                n--;
                i--;
            }else j--; 
        }
        else if(dir == UP){
            p[c] = *(matrix +i * n +j);
            if(c1 == m){
                dir = RIGHT;
                c1 = 0;
                j++;
            }else i--; 
        }
        c++;
        c1++;
    } 
    *returnSize = total;
    return p;

}


typedef struct {
    int **dp;
    int rowSize;
} NumMatrix;


NumMatrix* numMatrixCreate(int(* matrix)[5], int matrixSize, int* matrixColSize) {
    int i = 0;
    int j = 0;
    int sum1 = 0;
    int sum2 = 0;
    NumMatrix *num =NULL;
    if(matrixSize == 0)return NULL;    
    num = (NumMatrix *)malloc(sizeof(NumMatrix));
    num->dp = (int *)malloc(sizeof(int)*matrixSize);
    num->rowSize = matrixSize;
    
    for(i = 0;i<matrixSize;i++)
    {
        num->dp[i] = (int *)malloc(sizeof(int)*(*matrixColSize));
        sum1 += matrix[i][0];
        num->dp[i][0] = sum1;
    }
    for(i = 0;i<*matrixColSize;i++)
    {
        sum2 += matrix[0][i];
        num->dp[0][i] = sum2;
    } 
    
    for(i = 1;i<matrixSize;i++)
    {
        for(j = 1;j<*matrixColSize;j++)
        {
            num->dp[i][j] = num->dp[i-1][j] + num->dp[i][j-1] - num->dp[i-1][j-1] + matrix[i][j];
        }
    }
    return num;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    return (obj->dp[row2][col2] - (col1==0?0:obj->dp[row2][col1-1]) - (row1==0?0:obj->dp[row1-1][col2]) + ((row1==0||col1==0)?0:obj->dp[row1-1][col1-1]));
}

void numMatrixFree(NumMatrix* obj) {
    int i = 0;
    for(i;i<obj->rowSize;i++)
    {
        free(obj->dp[i]);
    }
    free(obj->dp);
    free(obj);
}


int min_3(int a,int b,int c){
    if(a<b){
        if(a<c) return a;
        else return c;
    }
    else if(a==b)
    {
        if(a<=c)return a;
        else return c;
    }
    else if(a>b){
        if(a<c) return b;
        if(b<c) return b;
        else return c;        
    }
    return 0;
}

int minimumTotal(/*int** triangle, int triangleSize, int* triangleColSize*/){
    int i = 0;
    int j = 0;
    int m = 0x7FFFFFFF;
    int **dp = NULL;
/*
    int triangle[][4]={
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    int triangleColSize[]={1,2,3,4};
*/
    int triangle[][4]={
        {4,1,8,3},
        {6,5,7},
        {3,4},
        {2}
    };
    int triangleColSize[]={4,3,2,1};
    
    int triangleSize = 4;

    dp = (int *)malloc(sizeof(int)*triangleSize);
    for(i = 0;i<triangleSize;i++){
        dp[i] = (int *)malloc(sizeof(int)*triangleColSize[i]);
        if(i==0){
            for(j = 0;j<triangleColSize[0];j++){
                dp[0][j] = triangle[0][j];
                printf("%d,",dp[0][j]); 
            }
        }
    }
    printf("\r\n");
    for(i = 1;i<triangleSize;i++){
        for(j = 0;j<triangleColSize[i];j++){
            dp[i][j] = min_3(
                    j-1<0?0x7FFFFFFF:dp[i-1][j-1],
                    dp[i-1][j],
                    j+1>=triangleColSize[i-1]?0x7FFFFFFF:dp[i-1][j+1]
                    ) + triangle[i][j];

            printf("%d,",dp[i][j]);  
        }
        printf("\r\n");
    }
    for(j = 0;j<triangleColSize[i-1];j++){
        if(m > dp[i-1][j])m = dp[i-1][j];
    }    
    return m;
}


int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int ** matrix;
    int i = 0;
    int j = 0;
    matrix = (int **)malloc(sizeof(int*)*numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int)*numRows);

    for(i = 0;i<numRows;i++){
        matrix[i] = (int *)malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = i+1;
        for(j = 0;j<i+1;j++){
            if(j == 0 || j == i)matrix[i][j] =1;
            else{
                matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
            }
        }
    }
    *returnSize = numRows;
    return matrix;
}


int* getRow(int rowIndex, int* returnSize){
    int * array;
    int i;
    int j;
    int k;
    array = (int *)malloc(sizeof(int)*(rowIndex+1));
    if(rowIndex >=0)
    array[0] = 1;
    if(rowIndex >=1);
    array[1] = 1;
    for(i = 2;i<=rowIndex;i++){
        j = i;
        array[j] = 1;
        for(j = i-1;j>=1;j--){
            array[j] = array[j-1] + array[j];
        }
    }
    *returnSize = rowIndex +1;
    return array;    
}




int main(){
    int i = 0;
    int j = 0;
    int k = 0;
#if 1
    int mat[M][N]={
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    int len = 0;
    int **pp = mat;
    int *p;
    struct NumMatrix * obj;
    int *col_len;
    //len = N;
    
    //len = min_3(3,1,3);
    //printf("%d\r\n",len);
    //len = minimumTotal();
    //printf("%d\r\n",len);
    //int *p =spiralOrder(pp,M,N,&len);
    //obj = numMatrixCreate(mat,M,&len);
#if 0 
    len = numMatrixSumRegion(obj,2,1,4,3);
    printf("%d\r\n",len);
    len = numMatrixSumRegion(obj,0,1,2,2);
    printf("%d\r\n",len);
    len = numMatrixSumRegion(obj,1,2,2,4);
    printf("%d\r\n",len);    
#endif
#endif 

#if 0    
    pp = generate(5,&len,&col_len);
    printf("%d\r\n",len);
    for(i = 0;i<len;i++){
        for(j = 0;j<col_len[i];j++)
            printf("%d,\t",pp[i][j]);
        printf("\r\n");
    }
    printf("\r\n");
#endif

    //len = minPathSum(mat,M,N);
    //printf("len:%d\r\n",len);
    p = getRow(0,&len);
    for(i = 0;i<len;i++)printf("%d,",p[i]);
    printf("\r\n");
#if 0
    int **mat = z_in(M,N);
    
#if 1   
    for(i = 0;i<M;i++){
        for(j = 0;j<N;j++)
            printf("%d,\t",mat[i][j]);
        printf("\r\n");
    }
    printf("\r\n");
#endif
#endif
    return 0;
}
