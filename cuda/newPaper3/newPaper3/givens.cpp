//givens变换，使得Rx=y,R的初始值都为0；n为x的长度。
#include<math.h>;
void givens(float *R, float *x, int n,int i, int j)
{
	float xi = x[i];
	float xj = x[j];
	int t = 0,s = 0,c = 0;
	if (xj == 0)
	{
		 c = 1;
		 s = 0;
	}else if (abs(xj) > abs(xi))
		{
			t = -xi / xj;
			s = 1 / sqrt(1 + t ^ 2);
			c = s*t;
		}else
		{
			t = -xj / xi;
			c = 1 / sqrt(1 + t ^ 2);
			s = c*t;
		}
		for (int i = 0;i < n;i++)
		{
			*(R + i*n + i) = 1;
		}
		*(R + i*n + i )= c;
		*(R + i*n + j) = -s;
		*(R + j*n + i) = s;
		*(R + j*n + j) = c;
}