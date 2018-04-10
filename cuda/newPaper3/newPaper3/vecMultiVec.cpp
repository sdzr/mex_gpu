//向量与向量相乘。X1*X2=X3.
void *vecMultiVec(float *x1, float *x2, float *x3, int M)
{
	for (int i = 0;i < M;i++)
	{
		x3[i] = x1[i] * x2[i];
	}
}