//��������֮�����������A��B���������ĵ���ģ��ΪM^2,N^2�ľ���C��
void matrixKron(float *A, float *B, float *C,int M,int N)
{
	for (int i = 0;i < M; i++)
	{
		for (int j = 0;j < N;j++)
		{
			for (int x = 0;x < M;x++)
			{
				for (int y = 0;y < N;y++)
				{
					*(C + ((i*M+x)*N )*N + j *N + y)=*(A +i*N+j)*(*(B+x*N+y));
				}
			}
		}
	}
}