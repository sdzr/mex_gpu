//B=x*A,����x�����A�ĳ˻������ص�B�����У������ģΪM��N��
void conMultiMatrix(float x, float *A, float *B, int M, int N)
{
	for (int i = 0;i < M*N; i++)
	{
		B[i] = x*A[i];
	}
}