#include <stdio.h>
#include"myFunction.h"
#include<malloc.h>



int main()
{
    const int M = 3, N = 3;
	float A[M*N] = {0};
	float B[M*N] = { 0 };
	float C[M*N] = { 0 };
	float X[M*N] = { 0 };

	//��������
	void getMatrix(float *A, int M, int N, FILE *fp);

	//��ȡ�������ݡ�
	FILE *fp1 = fopen("A.txt", "r");
	getMatrix(A,M,N,fp1);
	FILE *fp2 = fopen("B.txt", "r");
	getMatrix(B,M,N, fp2);

	//�ر��ļ�ָ�롣
	fclose(fp1);
	fclose(fp2);

	

	matrixMultiVec(A, A, A, M, N);
	printf("%f", A[2]);
	//�ͷſռ䡣
	
    return 0;
}
