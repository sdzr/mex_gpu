//从txt文件中读取矩阵。一维向量指针指向一维数组，用一维数组操作矩阵元素。
//A为矩阵，M，N为矩阵规模，fp为指向文件的指针，将数据读取到A中。
#include<stdio.h>
#include"myFunction.h"

void getMatrix(float *A,int M,int N,FILE *fp)
{
	if (!fp)
	{
		printf("txt文件为空");
		return ;
	}
	for (int i = 0;i<M;i++)
	{
		for (int j = 0;j <N;j++)
		{
			fscanf(fp, "%f", A+i*N+j);
		}

	}	
}
