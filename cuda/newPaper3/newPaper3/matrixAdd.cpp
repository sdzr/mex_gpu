//��������A,B��ӣ����ص�����C��
void matrixAdd(float *A, float *B,float *C, int M, int N)
{
	int i = 0;
	for (i = 0;i < M*N;i++)
	{
		C[i] = A[i] + B[i];
	}
}