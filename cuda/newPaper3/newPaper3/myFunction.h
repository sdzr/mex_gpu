#include<stdio.h>
void matrixPrintf(float *A, int M, int N);
void getMatrix(float *A, int M, int N, FILE *fp);
void matrixAdd(float *A, float *B, float *C, int M, int N);
void matrixMulti(float *A, float *B, float *C, int M, int N);
void conMultiMatrix(float x, float *A, float *B, int M, int N);
void matrixKron(float *A, float *B, float *C, int M, int N);
void transMatrix(float *A, float *B,int M, int N);
void creatMatrixI(float *A, int M, int N);
float norm2(float *b, int M);
//矩阵A与向量X相乘,并将结果返回到Y中，M，N为矩阵的规模。Y=A*X.
void matrixMultiVec(float *A, float *X, float *Y, int M, int N);
//向量y与x相减，结果返回到z中。向量长度为n。
void vecReduceVec(float *y, float *x, float *z, int n);
//向量与向量相乘。X1*X2=X3.
void *vecMultiVec(float *x1, float *x2, float *x3, int M);
void conMultiVec(float c, float *x, float *y, int M);
void givens(float *R, float *x, int n, int i, int j);