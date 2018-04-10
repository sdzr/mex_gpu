//gmresm方法解大规模矩阵，m为每次内部循环的次数,即gmres算法的restart，eps为迭代的精度
//AX=b，X为向量，b为向量，A为矩阵.运行时，将m选为n。
#include<malloc.h>
#include"Myfunction.h"
#include<string.h>
float gmresm(float *A,float *b,int m, float eps)
{
	int n = sizeof(b) / sizeof(b[0]);

	//申请动态内存。
	float *e = (float *)malloc((m+1) * sizeof(float));
	memset(e, 0, sizeof(float) * (m+1));//初始化为0内存后，可以像数组一样使用，或者使用calloc也一样。
	e[1] = 1;
	float *x = (float *)malloc(n * sizeof(float));
	memset(x, 0, sizeof(float)*n);
	float *r = (float *)malloc(n * sizeof(float));
	memset(r, 0, sizeof(float)*n);
	float *Ax = (float *)malloc(sizeof(float)*n);
	memset(Ax, 0,sizeof(float)*n);

	//求A*x
	matrixMultiVec(A, x, Ax, n, n);
	vecReduceVec(b, Ax, r, n);//r=b-A*X,返回r。
	
	float err = norm2(r,n);

	float *V;
	V = (float *)malloc(sizeof(float)*n*(1+m));
	memset(V, 0, sizeof(float)*n*(m+1));
	for (int i = 0;i < n;i++)
	{
		V[i] = r[i] / err;
	}
	
	float *hj;
	hj = (float*)malloc(sizeof(float)*(m + 1));//申请内存。
	memset(hj, 0, sizeof(float)*(m + 1));

	float *w = (float *)malloc(sizeof(float)*n);//申请初始化内存
	memset(w, 0,sizeof(float)*n);

	float *y = (float *)malloc(sizeof(float)*m);//申请初始化内存
	memset(y, 0, sizeof(float)*m);

	float *hjv = (float *)malloc(sizeof(float)*n);
	memset(hjv, 0, sizeof(float)*n);

	float *H = (float *)malloc(sizeof(float)*n);
	memset(H, 0, sizeof(float)*n);

	float *c = (float *)malloc(sizeof(float)*(m + 1));
	memset(c, 0, sizeof(float)*(m + 1));

	float *R = (float *)malloc(sizeof(float)*n*m);
	memset(R, 0, sizeof(float)*n*m);
	int k = 0;
	while (err > eps)
	{
		k = k + 1;
		for (int j = 0;j < m;j++)
		{
			matrixMultiVec(A,V+n*j,w,n, n);
			for (int i = 0;i < j;i++)
			{
				vecMultiVec(w, V + i*n,&hj[i],n);
				conMultiVec(hj[i], V+i*n, hjv, n);
				vecReduceVec(w, hjv, w, n);
			}
			hj[j + 1] = norm2(w, n);
			for (int t = 0;t < n;t++)
			{
				*(V + (j + 1)*n + t) = *(w + t) / hj[j + 1];
				*(H + j*n + t) = hj[t];
			}
		}
		for (int i = 0;i < m + 1;i++)
		{
			c[i] = err*e[i];
		}
		for (int j = 0;j < m;j++)
		{
			givens(R, H + j*n, n, j, j + 1);
			matrixMulti(float *A, float *B, float *C, int M, int N)

		}
	}


	//释放动态内存。
	free(e);
	free(x);
	free(r);
	free(Ax);
	free(hj);
	free(w);
	free(y);
	free(V);
	free(H);
	free(c);
}