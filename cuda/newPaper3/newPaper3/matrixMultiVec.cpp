//����A������X���,����������ص�Y�У�M��NΪ����Ĺ�ģ��Y=A*X.
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