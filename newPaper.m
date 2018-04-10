%非并行程序。
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

%设置迭代结束的精度条件eps.
eps=0.000001;
k=0;
while(1)
    Q=-A*X^2-B*X-C;
    E=inv(cuKron(X',A,N,N)+cuKron(eye(N),A*X+B,N,N))*Q(:);
    X=X+reshape(E,N,N);
    if(norm(E,2)<eps);
        break;
    end
    k=k+1;
end
X;
k    
toc    

