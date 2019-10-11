#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int removeDuplicates(int *nums,int numsSize)
{
	int i = 1;
	int j = 1;
	if(numsSize < 2)return numsSize;
	while(i<numsSize)
	{
		if(nums[i]!=nums[i-1])
		{
			nums[j] = nums[i];
			j++;
		}
		i++;
	}	
	return j;
}

int searchInsert(int *nums,int numsSize,int target)
{
	int i = 0;
	while(i<numsSize)
	{
		if(nums[i] == target)break;
		if(nums[i] < target)
		{
			if(i+1<numsSize)
			{
				if(nums[i+1]>target){i++;break;}
			}
			else i++;break;
		}
		if(i==0 && target<nums[i])break;
		i++;
	}	
	return i;
}


int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int j = 0;
    while(i < numsSize)
    {
        if(nums[i]!=val)
        {
            nums[j] = nums[i];
            j++;
        }
        i++;
    }
    return j;
}


int *plusOne(int *digits,int digitsSize,int *returnSize)
{		
	int *nums1 = (int *)malloc((digitsSize+1)*sizeof(int));
	int i = digitsSize-1;
	int jinwei = 1;
	while(i >= 0)
	{
		int val = digits[i]+jinwei;
		nums1[i+1] = val % 10;
		jinwei  = val / 10;
		i--;
	}	

	if(jinwei)
	{
		nums1[0] = jinwei;
		*returnSize = digitsSize+1;
		return &nums1[0];
	}	
	else 
	{
		*returnSize = digitsSize;
		return &nums1[1];
	}
}

int majorityElement(int *nums,int numsSize)
{
	int i = 1;// index of nums
	int j = 0;// index of numst
	//place the first

	while(i<numsSize)
	{
		if(j >=0)
		{
				if(nums[i] == nums[j])
				{
					j++;
					nums[j] = nums[i];
				}
				else
				{
					j--;
				}	
		}
		else
		{
			j++;
			nums[j] = nums[i];	
		}
		i++;
	}	
	return nums[0];
}

int missingNumber(int *nums,int numsSize)
{
	int sum = 0;
	int i = 0;
	while(i<numsSize)
	{
		sum += nums[i++];
	}
	return (1+numsSize)*numsSize/2 - sum;
}


void moveZeroes(int * nums,int numsSize)
{
	int i = 0;
	int j = 0;
	while(i < numsSize)
	{
		if(nums[i]!=0)
		{
			nums[j++] = nums[i];
		}
		i++;
	}
	for(j;j<numsSize;j++)
	{
		nums[j] = 0;
	}
}


int isOneBitCharacter(int* bits, int bitsSize)
{
    int bIsOneBitCha = 0;
    int index = 0;
    if(bits[bitsSize -1] || bits[bitsSize -2])return bIsOneBitCha;

    while(index < bitsSize)
    {
        if(bits[index] == 1)
        {
            bIsOneBitCha = 0;
            index +=2;
        }
        else
        {
            bIsOneBitCha = 1;
            index +=1;
        }
    }
    return bIsOneBitCha;
}

int isMonotonic(int* A, int ASize){
    int diff1 = 0;
    int diff2 = 0;
    int i = 0;
    int dir = -1;// 0:decrese  1:increse 
    if(ASize <=2) return 1;
    while(i+2 < ASize)
    {
        diff1 = A[i+1] - A[i];
        diff2 = A[i+2] - A[i+1];
        if((diff1 * diff2) < 0) return 0;
        if(diff1 < 0 || diff2 < 0)
        {
            if(dir != 1)dir = 0;
            else return 0;
        }
        else if(diff1 > 0 || diff2 > 0)
        {
            if(dir != 0)dir = 1;
            else return 0;
        } 
        i++;
    }
    return 1;
}

void duplicateZeros(int* arr, int arrSize){
    int i = 0;
    int c = 0;
    int j = 0;
    int k = 0;// last zero need duplicate?  1 no need ; 0 need
    // find i
    while(c < arrSize){
        if(arr[i++] == 0){
            c++;
            if(c == arrSize)
            {
                k = 1;
                break;
            }
            k = 0;
        }
        c++;
    }
    i--;
    //printf("i:%d\r\n",i);
    for(j = arrSize -1;i >= 0;j--){
        if(arr[i] == 0)
        {
            arr[j] = 0;
            if(k == 1) k = 0;
            else
            {
                j--;
                if(j < 0)break;
                arr[j] = 0;
            }
        }
        else
        {
            arr[j] = arr[i];
        }
        i--;
    }
}

int pivotIndex(int* nums, int numsSize){
    int sum = 0;
    int sum_l = 0;
    int sum_r = 0;
    int index ;
    for(index = 0;index < numsSize;index++)
        sum += nums[index];
    for(index = 1;index < numsSize;index++){
        sum_l += nums[index-1];
        sum_r = sum - sum_l - nums[index];
        if(sum_l == sum_r)return index;
    }
    return -1;
}


void sortArrayByParity(int* A, int ASize){
    int i = 0;
    int j = ASize -1;
    while(i!=j && j> 0){
        if((A[j] & 1) == 0){
            printf("A[%d]:%d\r\n",j,A[j]);
            for(i;i<j;i++){
                if(A[i] & 1){
                    printf("i:%d,j:%d\r\n",i,j);
                    A[j]^=A[i]^=A[j]^=A[i];
                    break;
                }
            }
            j--;
        }
        else{
            j--;
        }
    }
}



int maxSubArray(int* nums, int numsSize){
    int sum;
    int max;
    int i;
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    
    sum = nums[0];
    max = nums[0];
    
    for (i = 1; i < numsSize; i++) {
        
        if (sum > 0) {
            sum += nums[i];
        }else {
            sum  = nums[i];
        }
        
        max = max > sum ? max : sum;
    }
    return max;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0;
    int j = 0;

}

int maxArea(int* height, int heightSize){
    int maxV = 0;
    int maxIJ = 0;
    int maxT = 0;
    int i = 0;
    int j = heightSize -1;
    while(i !=j ){
        if(height[i] - height[j] >= 0){
            maxT = (j-i)*height[j];
            if(maxV < maxT)maxV = maxT;
            j--;
        }
        else{
            maxT = (j-i)*height[i];
            if(maxV < maxT)maxV = maxT;
            i++;
        }
    }
    return maxV;
}   

int canJump(int* nums, int numsSize){
    int val = -1;
    int i = 1;
    int j = numsSize - 2;
    while(j){
        if(nums[j] >= i){
            i = 1;
            val = 0;
        }
        else {
            i++;
            val = -1;
        }
        j--;
    }
    return val == 0? 1:0;
}

int canJumpV2(int* nums, int numsSize){
    int j = numsSize -1;
    int k = 0;// record j
    int c = 0;
    int l = j;
    while(j){
        l = j-1;
        while(l >= 0){
            if(nums[l] >= j-l)
                k = l;
            l--;
        }
        printf("%d\r\n",k);
        j = k;
        c++;
    }
    return c;
}


int uniquePaths(int m, int n){
#if 0
    int i = 0;
    int j = 0;
    int k = 0;
    int dp[m][n];
    //if(m == 1 || n == 1 )return 1;
    //sum += uniquePaths(m,n-1) + uniquePaths(m-1,n); /// this meth will be timeout
    for(i = 0;i<m;i++)dp[i][0] = 1;
    for(j = 0;j<n;j++)dp[0][j] = 1;
    k = m > n?m:n;
    for(i = 1;i<m;i++)
    {
        for(j = 1;j<n;j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    
    return dp[i-1][j-1];
#endif
    return 0;
}


/*sort with n^2*/
void insert_sort(int *nums,int numsSize){
    int i = 0;
    int j = 0;
    int t = 0;
    for(i = 0;i<numsSize;i++){
        for(j = i;j >= 0;j--){
            if(nums[j] < nums[j-1]){
                t = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = t;
            }
        }
    }
}
void bubble_sort(int *nums,int numsSize){
    int i = 0;
    int j = 0;
    int t = 0;
    for(i = 0;i<numsSize;i++){
        for(j = 0;j<numsSize - i -1;j++){
            if(nums[j] > nums[j+1]){
                t = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = t;
            }
        }
    }    
}
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
/*sort with n*log(n)*/
void merge_sort(int *nums,int numsSize){

}

void quick_sort(int *nums,int numsSize){
    
}


void sortColors(int *nums,int numsSize){
    int i = 0;
    int j = numsSize -1;
    int k = 0;
    while(k < numsSize){
        if(nums[k] == 0){
            nums[i] ^= nums[k] ^=nums[i] ^=nums[k];
            i++;
            k++;
        }
        if(nums[k] == 2 ){
            if(k < j){         
                nums[j] ^= nums[k] ^=nums[j] ^=nums[k];
                j--;
            }
            else k++;
        }
        if(nums[k] == 1){
            k++;
        }
    }
}


char * alphabetBoardPath(char * target){
    int i = 0;
    int j = 0;
    char ch = *target;
    int row_old = 0;
    int col_old = 0;
    char p [512];
    int c = 0;
    while(ch){
        int row = (ch - 'a')/5;
        int col = (ch - 'a')%5;
        if(row > row_old){
            for(i=row_old;i<row;i++){if(i < 4)p[c++]='D';else j = 1;}
        }
        else if(row <row_old){
            for(i=row;i<row_old;i++)p[c++]='U';
        }
        if(col > col_old){
            for(i=col_old;i<col;i++)p[c++]='R';
        }
        else if(col < col_old){
            for(i=col;i<col_old;i++)p[c++]='L';
        }
        if(j){p[c++]='D';j=0;}
        p[c++]='!';        
        row_old = row;
        col_old = col;     
        target++;
        ch  = * target;
    }
    p[c] = '\0';
    printf("%s\r\n",p);
    return NULL;
}


int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int i = 0;//arr1
    int j = 0;//arr2
    int k = 0;//record arr1 pos
    int t = 0;
    int l = 0;
    while(j < arr2Size){
        t = arr2[j];
        i = 0;
        while(i <arr1Size){
            if(arr1[i] == t){
                l = arr1[i];//s
                arr1[i] = arr1[k];
                arr1[k] = l;
                k++;
            }
            i++;
        }
        j++;
    }
    choose_sort(arr1+k,arr1Size -k);

    *returnSize = arr1Size;
    return arr1;
}

int my_pow(int x){
    int val = 1;
    while(x){
        val <<= 1;
        x--;
    }
    return val;
}

int my_log(int x){
    int val = 0;
    while(x){
        x >>= 1;
        val ++;
    }
    return val;
}

int* pathInZigZagTree(int label, int* returnSize){
    int dir = 0;// 0 ->   1 <-
    int *p = NULL;
    int index_p = 0;
    int label_t = label;
    int i = 0;
    *returnSize = my_log(label);
    index_p = *returnSize -1;
    p = (int *)malloc(sizeof(int)*(*returnSize));
    if(*returnSize %2)dir = 0;
    else dir = 1;
    printf("returnSize:%d,dir:%d\r\n",*returnSize,dir);
    while(label){
        if(label == 1)break; 
        printf("label:%d,dir:%d,index_p:%d\r\n",label,dir,index_p);       
        p[index_p] = label;
        
        if(dir){// 逆序跳顺序
            label = 3 * my_pow(index_p) - label -1;
            label /=2;    
        }
        else{// 顺序跳逆序
            label = my_pow(index_p) + my_pow(index_p+1) -1 -label;
            label/=2;
        } 
        
        dir = !dir;
        index_p --;
    }
    p[index_p] = label;
    return p;
}


int validMountainArray(int * A,int ASize){
    int i = 0;
    int j = ASize-1;
    int k = 0;
    if(ASize < 3)return 0;
    while(i < j){
        if(A[i+1] > A[i]){
            i++;
        }
        else {
            if(i==0)return 0;
            for(j;j>i;j--){
                if(A[j-1] <= A[j])return 0;    
            }
        }

        if(A[j-1] > A[j]){
            j--;
        }
        else{
            if(j == ASize -1)return 0;
            for(i;i<j;i++){
                if(A[i+1] <= A[i])return 0; 
            }
        }
    }
    return 1; 
}


void sortArrayByParityII(int* A, int ASize){
    int i = 0;// 2n
    int j = 1;// 2n+1
    while(i < ASize){
        if(A[i]%2 == 0){
            if(i%2==0)
                i++;
            else{
                j = i+1;
                while(j < ASize){
                    if(A[j]%2 == 1){
                        int t = A[j];
                        A[j] = A[i];
                        A[i] = t;
                        i++;
                        break;
                    }
                    j++;
                }
            }            
        }
        else{
            if(i%2==1)i++;
            else{
                j = i+1;
                while(j < ASize){
                    if(A[j]%2 == 0){
                        int t = A[j];
                        A[j] = A[i];
                        A[i] = t;
                        i++;
                        break;
                    }
                    j++;
                }
            }
        }
    }
}



int minFlipsMonoIncrII(char * S){
    int i = 0; 
    int c0 = 0;
    int c1 = 0;
    int sum = 0;
    int len = strlen(S);
    while(*S){
        if(*S == '0')c0++;
        if(*S == '1')c1++;
        if(c0 > c1){
            sum += c1;
            c0 = 0;
            c1 = 0;
            S++;
            while(*S == '0'){
                S++;
            }
        }
        else{
            S++;
        }  
    }
    sum += c0;
    return sum;
}


int partitionDisjoint(int* A, int ASize){
    int i = ASize -2;
    int MaxLeft = 0;
    int MinRight = 0; 
    int *dp = (int *)malloc(sizeof(int) *ASize);
    int j = 1;
    int index = 0;
    dp[0] = A[0];
    while(j < ASize){
        dp[j] = max(dp[j-1],A[j]);
        j++;
    }
    MaxLeft = dp[i];
    MinRight = A[i + 1];

    while(i >= 0){  
        if(MaxLeft <= MinRight)index = i;
        i--;  
        if(i < 0)break;   
        MaxLeft = dp[i];
        MinRight = MinRight > A[i + 1] ?A[i + 1]:MinRight;   
    }
    return index + 1;
}


int maxSubarraySumCircular(int* A, int ASize){
   
}


/*
1: 赋值 1
2: 赋值表达式 3
3: je jge 1
4: cmp 比较 1
 */
int maxWidthRamp(int* A, int ASize){
    int maxWidth = ASize -1;
    int i = 0;
    int j = i + maxWidth;
    
    while(maxWidth){//cmp<reg,mem>(2) + je(1)
        i = 0;// mov(1)
        j = i + maxWidth;//mov(1)+add<reg,mem>(2)+mov(1)
        while(j < ASize){//mov(1)+cmp<reg,mem>(2)+jge(1)
            if(A[i] <= A[j])return maxWidth;//5*mov(1) + cmp<reg,mem>(2)+jg(1)+mov(1)+jmp(1)
            i++;//mov(1)+add<reg,imm>(1) + mov(1)
            j++;//mov(1)+add<reg,imm>(1) + mov(1)
        }
        maxWidth--;//mov(1)+sub<reg,imm>(1) + mov(1)
    }//jmp(1)

    //3 + 1 + 4 + 4 + 10 + 3 + 3 + 3 + 1 = 32 个机器周期 
    return maxWidth;
}

int rob(int* nums, int numsSize){
    int i = 2;    
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    if(numsSize == 0)return 0;
    if(numsSize == 1)return nums[0];
    if(numsSize == 2)return nums[0] > nums[1]?nums[0]:nums[1];        
    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1]?nums[0]:nums[1];
    while(i < numsSize){
        dp[i] = dp[i-2] + nums[i] > dp[i-1] ? dp[i-2]+nums[i] : dp[i-1];
        i++;
    }
    return dp[i-1];
}


int robII(int* nums, int numsSize){
    int i = 2; 
    int max1 = 0;
    int max2 = 0;   
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    if(numsSize == 0)return 0;
    if(numsSize == 1)return nums[0];
    if(numsSize == 2)return nums[0] > nums[1]?nums[0]:nums[1];  

    dp[0] = nums[0];
    dp[1] = nums[0] > nums[1]?nums[0]:nums[1];
    while(i < numsSize -1){
        dp[i] = dp[i-2] + nums[i] > dp[i-1] ? dp[i-2]+nums[i] : dp[i-1];
        i++;
    }      
    max1 = dp[i-1];

    i = 3;
    dp[1] = nums[1];
    dp[2] = nums[2] > nums[1]?nums[2]:nums[1];
    while(i < numsSize){
        dp[i] = dp[i-2] + nums[i] > dp[i-1] ? dp[i-2]+nums[i] : dp[i-1];
        i++;
    }      
    max2 = dp[i-1];

    return max1 > max2?max1:max2;
}

int climbStairs(int n){
    int i = 0;
    int *dp = (int *)malloc(sizeof(int) * n);
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;
    dp[0] = 1;
    dp[1] = 2;
    for(i = 2;i<n;i++){
        dp[i] = dp[i-2] + dp[i-1] ;
    }
    return dp[n-1];
}

int minCostClimbingStairs(int* cost, int costSize){
    int i = 0;
    int *dp = (int *)malloc(sizeof(int)*costSize + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    i = 2;
    
    while(i < costSize){
        dp[i] = min(dp[i-2],dp[i-1]) + cost[i];
        //printf("%d\r\n",dp[i]);
        i++;
    }
    dp[i] = min(dp[i-2],dp[i-1]);
    return dp[i];
}

int countCharacters(char ** words, int wordsSize, char * chars){
    int ch_pha[26]={0};
    int ch_pha_t[26]={0};
    int i = 0;
    int len = 0;
    int total_len = 0;
    char * words_t;
    while(*chars){
        ch_pha[*chars -'a']++;
        chars++;
    }
    
    while(i < wordsSize){
        len = 0;
        words_t = words[i];
        memcpy(ch_pha_t,ch_pha,26 * sizeof(int));
        while(*words_t){
            if(ch_pha_t[*words_t-'a'] == 0){
                len = 0;
                break;
            }
            ch_pha_t[*words_t-'a']--;
            words_t++;
            len++;
        }
        total_len+=len;
        if(len!=0)printf("%d\r\n",i);
        i++;
    }
    return total_len;
}

int maxProfit(int* prices, int pricesSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int ii = 0;
    int pro = 0;
    while(k < pricesSize){
        if(prices[k] <= prices[i] && ii == 0){
            i = k;//in
            j = k;
        }
        else{
            ii = 1;
            if(prices[k] >= prices[j]){
                j = k;
            }
            else{
                pro+=prices[j] - prices[i];
                //printf("%d,",pro);
                i = j = k;
                ii = 0;
            }
        }
        k++;
    }
    if(ii)pro+=prices[j]-prices[i];
    //printf("\r\n");
    return pro;
}



int canThreePartsEqualSum(int* A, int ASize){
    int sum_t = 0;
    int sum_1 = 0;
    int sum_2 = 0;
    int sum_3 = 0;
    int i = 0;
    int j = i+1;
    for(i;i<ASize;i++)sum_t+=A[i];
    for(i=0;i<ASize-2;i++){
        sum_1+=A[i];
        sum_2 = 0;
        for(j=i+1;j<ASize-1;j++){
            sum_2 += A[j];
            sum_3 = sum_t -sum_1 - sum_2;
            //printf("sum1:%d,sum2:%d,sum3:%d\r\n",sum_1,sum_2,sum_3);
            if(sum_1 == sum_2 && sum_1 == sum_3){
                return 1;
            }
        }
    }
    return 0;
}



int checkPossibility(int* nums, int numsSize){
}

int findLengthOfLCIS(int* nums, int numsSize){
    int i = 1;
    int j = 0;
    int c = 1;
    int maxc = 0;

    if(numsSize == 0)return 0;
    if(numsSize == 1)return 1;
    while(i < numsSize){
        if(nums[i] > nums[j]){
            c++;           
        }
        else{
            if(c>maxc)maxc = c;
            c = 1;
        }
        j = i;
        i++;
    }
    if(c>maxc)maxc = c;
    return maxc;
}

int findUnsortedSubarray(int* nums, int numsSize){
    int len = 0;
    return len;
}

int findSubStr(){
	char p_maigemeng[9]={0xE5,0x8D,0x96,0xE4,0xB8,0xAA,0xE8,0x90,0x8C};
    char p_xiangqianzou[9]={0xE5,0x90,0x91,0xE5,0x89,0x8D,0xE8,0xB5,0xB0};
    char p_niupigu[9]={0xE6,0x89,0xAD,0xE5,0xB1,0x81,0xE8,0x82,0xA1};	
    char p_tiaogewu[9]= {0xE8,0xB7,0xB3,0xE4,0xB8,0xAA,0xE8,0x88,0x9E};
    char p_changshouge[9]={0xE5,0x94,0xB1,0xE9,0xA6,0x96,0xE6,0xAD,0x8C};
    
    char p_strS[15]={0xE7,0xBB,0x99,0xE6,0x88,0x91,0xE8,0xB7,0xB3,0xE4,0xB8,0xAA,0xE8,0x88,0x9E};
    int t_len = 9;
    int s_len = 15;
	int i = 0;
    char *strT = p_tiaogewu;
	for(i;i<=s_len-t_len;i++)
	{
		if(memcmp(p_strS+i,strT,t_len) == 0)return 1;
	}
    return 0;
}


int isValid(char * s){
    int len = strlen(s);
    int *stack=(int*)malloc(sizeof(int)*len);
    int i=0;
    int j=-1;
    while(i<len){
        if(s[i]=='('||s[i]=='['||s[i]=='{')stack[++j]=s[i];
        else {
            if(j>=0 && (stack[j]=='('&&s[i]==')'
              ||stack[j]=='['&&s[i]==']'
              ||stack[j]=='{'&&s[i]=='}')){
                j--;
            }
            else return 0;
        }
        i++;
    }
    free(stack);
    return 1;
}


char * removeOuterParentheses(char * S){
    char *T = NULL;
    char *St = S;
    int i = 0;//S_start
    int j = 0;//S_end
    int l = 0;
    int k = 0;//T_index
    int len_S = strlen(S);

    T = (char *)malloc(len_S+1);
    while(*S)
    {
        if(*S == '(')l++;
        else if(*S == ')')l--;        
        if(l == 0)
        {
            memcpy(T+k,St+i+1,j-i-1);
            k+=j-i-1;
            i = j+1;
        }
        S++;
        j++;
    }
    T[k]='\0';
    return T;
}


int main()
{
    int i = 0;
	int nums[] = {2, 4, 4, 3, 10, 3, 15};
    int nums2[]={22,28,8,6};
	int val = 7;
	int len1 = sizeof(nums)/sizeof(nums[0]);
    int len2 = sizeof(nums2)/sizeof(nums2[0]);
    int len = 0;

    char *words[]={"tt"};
    char *chars="t";
    clock_t t_start,t_end;
#if 0
    for(i;i<50000;i++){
        nums[i] = 50000-i;
    }
#endif

    t_start = clock();

	//int len = removeElement(nums,len1,val);
	//int len = removeDuplicates(nums,len1);
	//int len = searchInsert(nums,len1,val);
	//int len = majorityElement(nums,len1);
	//int len = missingNumber(nums,len1);
	//moveZeroes(nums,len1);
	//printf("len:%d\r\n",len);
    //int bIsOneBitCha = isMonotonic(nums,len1);
    //duplicateZeros(nums,len1);
    //sortArrayByParity(nums,len1);
    //int len = maxSubArray(nums,len1);

    //swap(nums,len1);
    //int k = 3;
    //swap(nums,len1-k);
    //swap(nums+len1-k,k);
    //swap(nums,len1);
    //int len = maxArea(nums,len1);    
    //printf("len:%d\r\n",len);

    //int len = canJump(nums,len1);
    //int len = lengOfLastWord(nums,len1);
    //printf("len:%d\r\n",len);
    //sortColors(nums,len1);
    //len = uniquePaths(51,9);
    //printf("len:%d\r\n",len);
    //alphabetBoardPath("zdz");
    //relativeSortArray(nums,len1,nums2,len2,&len);

    //int * p = pathInZigZagTree(4,&len);
    //len = validMountainArray(nums,len1);
    //printf("%d\r\n",len);
    //sortArrayByParityII(nums,len1);
    //len = minFlipsMonoIncrII("11011");
    //len = maxSubarraySumCircular(nums,len1);
    //len = partitionDisjoint(nums,len1);
    //len = maxWidthRamp(nums,len1);
    //len = rob(nums,len1);
    //len = robII(nums,len1);
    //len = climbStairs(5);
    //len = minCostClimbingStairs(nums,len1);
    //len = countCharacters(words,20,chars);
    //len = maxProfit(nums,len1);
    //len = canThreePartsEqualSum(nums,len1);
    //len = checkPossibility(nums,len1);
    //len = findLengthOfLCIS(nums,len1);
    //len = findUnsortedSubarray(nums,len1);
    //len = findSubStr();
    //len = isValid("{[(]}");
    //printf("%d\r\n",len);

    chars = removeOuterParentheses("(()())(())");
    printf("%s\r\n",chars);
#if 0
    //insert_sort(nums,len1);
	//bubble_sort(nums,len1);
    //choose_sort(nums,len1);
    for(i = 0;i<len1;i++)
	{
		printf("%d,",nums[i]);
	}
	printf("\r\n");
#endif
/*
	int len = 0;	
	int *digits =  plusOne(nums,len1,&len);

	printf("len:%d\r\n",len);
	for(int i = 0;i<len;i++)
	{
		printf("%d,",digits[i]);
	}
	printf("\r\n");
*/	

    t_end = clock();
    printf("time %2.3f s\r\n",(t_end - t_start)*1.0/CLOCKS_PER_SEC);


	return 0;
}
