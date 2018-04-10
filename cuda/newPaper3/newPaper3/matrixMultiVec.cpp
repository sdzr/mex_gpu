//矩阵A与向量X相乘,并将结果返回到Y中，M，N为矩阵的规模。Y=A*X.
void matrixMultiVec(float *A, float *X, float *Y,int M, int N)
{
	for (int i = 0;i < M;i++)
	{
		Y[i] = 0;
		for (int j = 0;j < N;j++)
		{
			Y[i]=Y[i]+*(A + i*N + j)*X[j];
		}
	}
}