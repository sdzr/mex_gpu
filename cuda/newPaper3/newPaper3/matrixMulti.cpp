//两个矩阵A,B相乘，返回到矩阵C。
#include"myFunction.h"
#include <stdio.h>
void matrixMulti(float *A, float *B,float *C,int M,int N)
{
	int i = 0, j = 0,k=0;
	for (i = 0;i < M;i++)
	{
		for (j = 0;j < N;j++)
		{
			*(C+i*N+j) = 0;
			for (k = 0;k < N;k++)
			{
				*(C + i*N + j) = *(C + i*N + j) + (*(A + i*N + k)) * (*(B + k*N + j));
			}
		}
	}
}
