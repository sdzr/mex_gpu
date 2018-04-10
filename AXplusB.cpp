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
    
    //申请device空间。
    float *deviceA;*deviceB,*deviceX,*deviceD;
    cudaMalloc(&deviceA,sizeof(float)*numARows*numACols);
    cudaMalloc(&deviceB,sizeof(float)*numBRows*numBCols);
    cudaMalloc(&deviceX,sizeof(float)*numXRows*numXCols);
    cudaMalloc(&deviceD,sizeof(float)*numDRows*numDCols);
    
    //创建cublas句柄，这是调用所有cublas函数前要做的事情。
    cublasHandle_t handle;
    cublasCreate(&handle);
    
    //将主机矩阵元素复制到设备上。
    cublasSetmatrix(numARows,numACols,sizeof(float),numARows,deviceA,numARows);
    cublasSetmatrix(numBRows,numBCols,sizeof(float),numBRows,deviceB,numBRows);
    cublasSetmatrix(numXRows,numXCols,sizeof(float),numXRows,deviceX,numXRows);
    
    //矩阵A与矩阵X相乘
    cublasDgemm(handle,CUBLAS_OP_N,CUBLAS_OP_N,numARows,numXcols,numACols,&alpha,deviceA,numARows,deviceX,,numXRows,&beta,deviceD,numDRows);
    
    //矩阵A
    
     //最后删除句柄。
    cublasDestroy(handle);
    
    //释放device内存
    cudaFree(deviceA);
    cudaFree(deviceB);
    cudaFree(deviceX);
    cudaFree(deviceD);
    
    
}