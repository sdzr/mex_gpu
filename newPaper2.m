%并行的程序，利用matlab的内置函数。
%命令：methods('gpuArray')可以看到matlab中能够进行GPU并行的一些内置函数。
%解Q(X)=AX^2+BX+C=0,用牛顿法。
%核心迭代步骤：AEX+(AX+B)=Q(X),X=X+tE,t=min(||Q(X+tE)||),使得F范最小的t.
%然后用张量积化简迭代方法。
tic
N=30;
%给出Q(X).;
A=eye(N);
B=30*diag(ones(1,N))-10*diag(ones(1,N-1),-1)-10*diag(ones(1,N-1),1);
B(1,1)=20;
B(N,N)=20;
C=15*diag(ones(1,N))-5*diag(ones(1,N-1),-1)-5*diag(ones(1,N-1),1);
% 给出X的初值。
X=rand(N,N);

%讲数据复制到device中去。
deviceA=gpuArray(A);
deviceB=gpuArray(B);
deviceC=gpuArray(C);
deviceX=gpuArray(X);

%设置迭代结束的精度条件eps.
eps=0.0000001;
k=0;
while(1)
    X=gather(deviceX);
    deviceQ=(-1).*deviceA*deviceX*deviceX+(-1).*deviceB*deviceX+(-1).*deviceC;
    deviceE=inv(gpuArray(cuKron(X',A,N,N))+gpuArray(cuKron(eye(N),gather(deviceA*deviceX+deviceB),N,N)))*deviceQ(:);
    deviceX=deviceX+reshape(deviceE,N,N);
    if(norm(deviceE,2)<eps)
        break;
    end
    k=k+1;
end
X;
k
toc







