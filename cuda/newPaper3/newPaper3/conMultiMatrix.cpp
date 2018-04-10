//B=x*A,常数x与矩阵A的乘积，返回到B矩阵中，矩阵规模为M，N。
void conMultiMatrix(float x, float *A, float *B, int M, int N)
{
	for (int i = 0;i < M*N; i++)
	{
		B[i] = x*A[i];
	}
}