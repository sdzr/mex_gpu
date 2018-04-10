#include<math.h>
float norm2(float *b, int M)
{
	float sum = 0;
	for (int i = 0;i < M;i++)
	{
		sum = sum + b[i] * b[i];
	}
	sum = sqrt(sum);
	return sum;
}