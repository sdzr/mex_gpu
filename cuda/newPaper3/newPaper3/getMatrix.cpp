//��txt�ļ��ж�ȡ����һά����ָ��ָ��һά���飬��һά�����������Ԫ�ء�
//AΪ����M��NΪ�����ģ��fpΪָ���ļ���ָ�룬�����ݶ�ȡ��A�С�
#include<stdio.h>
#include"myFunction.h"

void getMatrix(float *A,int M,int N,FILE *fp)
{
	if (!fp)
	{
		printf("txt�ļ�Ϊ��");
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
