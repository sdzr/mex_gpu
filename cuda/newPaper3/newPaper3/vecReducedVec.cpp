//���������������
//����y��x�����������ص�z�С���������Ϊn��
void vecReduceVec(float *y, float *x,float *z, int n)
{
	for (int i = 0;i < n;i++)
	{
		z[i]= y[i] - x[i];
	}
}