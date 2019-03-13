#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#if 0
int main()
{
	FILE *fd = NULL;
	unsigned char incode[20]="中国";
	unsigned char qh,wh;
	unsigned long offset = 0;

	int i, j, k = 0;
	int index = 0 ;

	char mat[16][2];
	memset(mat, 0x00, sizeof(32));
	
	if((fd = fopen("HZK16V", "rb") )== NULL)
	{
		printf("can't opent ASC16\n");
		return 0;
	}

	while(index < strlen((char *)incode))
	{
		qh = incode[index++] - 0xa1;
		wh = incode[index++] - 0xa1;
		offset = (94*qh + wh)*32;
		fseek(fd, offset, SEEK_SET);
		fread(mat, 32, 1, fd);
		for(i=0;i<16;i++)
		{
			for(j=0;j<2;j++)
			{
				for(k=0;k<8;k++)
				{
					if(mat[i][j]&(0x80>>k))
					//if(mat[16-1-j][i]&(0x80>>k))
					{
						printf("★");
					}
					else
					{
						printf("　");
					}				
				}
			}
			printf("\n");		
		}
		for(int k = 0;k<5;k++)
		{
			for(int s=0;s<16;s++)
				printf("　");
			printf("\n");
		}
	}
	fclose(fd);
	system("pause");
	return 0;
}
#endif