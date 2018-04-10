//生成单位矩阵
void creatMatrixI(float *A, int M, int N)
{
	for (int i = 0;i < M;i++)
	{
		*(A + i*N + i) = 1;
	}
}