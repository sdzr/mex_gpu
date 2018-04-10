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

	//声明函数
	void getMatrix(float *A, int M, int N, FILE *fp);

	//读取矩阵数据。
	FILE *fp1 = fopen("A.txt", "r");
	getMatrix(A,M,N,fp1);
	FILE *fp2 = fopen("B.txt", "r");
	getMatrix(B,M,N, fp2);

	//关闭文件指针。
	fclose(fp1);
	fclose(fp2);

	

	matrixMultiVec(A, A, A, M, N);
	printf("%f", A[2]);
	//释放空间。
	
    return 0;
}
