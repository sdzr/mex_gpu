//向量与向量相减。
//向量y与x相减，结果返回到z中。向量长度为n。
void vecReduceVec(float *y, float *x,float *z, int n)
{
	for (int i = 0;i < n;i++)
	{
		z[i]= y[i] - x[i];
	}
}