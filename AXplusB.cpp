#include"mex.h"
#include"cuda_runtime.h"
#include"cublas_v2.h"

void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{
    if(nrhs!=2)
        mexErrMsgTxt("invaid number of input arguments");
    float *A=(float *)mxGetData(prhs[0]);
    float *B=(float *)mxGetData(prhs[1]);
    float *X=(float *)mxGetData(prhs[2]);
    
    int numARows=mxGetM(prhs[0]);
    int numACols=mxGetN(prhs[0]);
    int numBRows=mxGetM(prhs[1]);
    int numBCols=mxGetN(prhs[1]);
    int numXRows=mxGetM(prhs[2]);
    int numXCols=mxGetN(prhs[2]);
    
    int numDRows=numXRows;
    int numDCols=numXCols;
    
    plhs[0]=mxCreatNumericMatrix(numXRows,numXCols,mx_SINGLE_CLASS,mxREAl);
    float *D=(float *)mxGetData(plhs[0]);
    
    //����device�ռ䡣
    float *deviceA;*deviceB,*deviceX,*deviceD;
    cudaMalloc(&deviceA,sizeof(float)*numARows*numACols);
    cudaMalloc(&deviceB,sizeof(float)*numBRows*numBCols);
    cudaMalloc(&deviceX,sizeof(float)*numXRows*numXCols);
    cudaMalloc(&deviceD,sizeof(float)*numDRows*numDCols);
    
    //����cublas��������ǵ�������cublas����ǰҪ�������顣
    cublasHandle_t handle;
    cublasCreate(&handle);
    
    //����������Ԫ�ظ��Ƶ��豸�ϡ�
    cublasSetmatrix(numARows,numACols,sizeof(float),numARows,deviceA,numARows);
    cublasSetmatrix(numBRows,numBCols,sizeof(float),numBRows,deviceB,numBRows);
    cublasSetmatrix(numXRows,numXCols,sizeof(float),numXRows,deviceX,numXRows);
    
    //����A�����X���
    cublasDgemm(handle,CUBLAS_OP_N,CUBLAS_OP_N,numARows,numXcols,numACols,&alpha,deviceA,numARows,deviceX,,numXRows,&beta,deviceD,numDRows);
    
    //����A
    
     //���ɾ�������
    cublasDestroy(handle);
    
    //�ͷ�device�ڴ�
    cudaFree(deviceA);
    cudaFree(deviceB);
    cudaFree(deviceX);
    cudaFree(deviceD);
    
    
}