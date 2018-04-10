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
//����A������X���,����������ص�Y�У�M��NΪ����Ĺ�ģ��Y=A*X.
void matrixMultiVec(float *A, float *X, float *Y, int M, int N);
//����y��x�����������ص�z�С���������Ϊn��
void vecReduceVec(float *y, float *x, float *z, int n);
//������������ˡ�X1*X2=X3.
void *vecMultiVec(float *x1, float *x2, float *x3, int M);
void conMultiVec(float c, float *x, float *y, int M);
void givens(float *R, float *x, int n, int i, int j);