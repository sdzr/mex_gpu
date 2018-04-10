//¥Ú”°æÿ’ÛA°£
#include<stdio.h>
void matrixPrintf(float *A,int M,int N)
{
	int i, j;
	for (i = 0;i < M;i++)
	{
		printf("\n");
		for (j = 0;j < N;j++)
		{
			printf("%f", *(A + N*i + j));
			printf(" ");
		}
	}
}