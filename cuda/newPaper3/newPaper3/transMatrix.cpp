//������A����ת�á����ص�B�С�
void transMatrix(float *A,float *B,int M, int N)
{
	float temp = 0;
	for (int i = 0;i < M;i++)
	{
		for (int j = i+1;j < N;j++)
		{
			*(B+ i*N + j)= *(A + j*N + i);

		}
	}
}