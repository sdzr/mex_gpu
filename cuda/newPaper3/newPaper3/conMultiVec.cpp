//常数与向量相乘y=c*x,向量x，常量c，返回到向量y中。
void conMultiVec(float c, float *x, float *y,int M)
{
	for (int i = 1;i < M;i++)
	{
		y[i] = c*x[i];
	}
}