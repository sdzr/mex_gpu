//���ɵ�λ����
void creatMatrixI(float *A, int M, int N)
{
	for (int i = 0;i < M;i++)
	{
		*(A + i*N + i) = 1;
	}
}