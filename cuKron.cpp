#include"mex.h"
#include"cuda_runtime.h"
#include"cublas_v2.h"

void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{
    if(nrhs!=2)
        mexErrMsgTxt("invaid number of input arguments");
    
    float *A=(float *)mxGetData(prhs[0]);
    float *B=(float *)mxGetData(prhs[1]);
    
    int numARows=mxGetM(prhs[0]);
    int numACols=mxGetN(prhs[0]);
    int numBRows=mxGetM(prhs[1]);
    int numBCols=mxGetN(prhs[1]);
   
    plhs[0]=mxGreatNumericMatrix(numARows,numACols,mxSINGLE_CLASS,mxREAL);
    float *D=(float *)mxGetData(plhs[0]);
    
}