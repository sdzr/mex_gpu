//�������������y=c*x,����x������c�����ص�����y�С�
void conMultiVec(float c, float *x, float *y,int M)
{
	for (int i = 1;i < M;i++)
	{
		y[i] = c*x[i];
	}
}