%���еĳ�������matlab�����ú�����
%���methods('gpuArray')���Կ���matlab���ܹ�����GPU���е�һЩ���ú�����
%��Q(X)=AX^2+BX+C=0,��ţ�ٷ���
%���ĵ������裺AEX+(AX+B)=Q(X),X=X+tE,t=min(||Q(X+tE)||),ʹ��F����С��t.
%Ȼ�����������������������
tic
N=30;
%����Q(X).;
A=eye(N);
B=30*diag(ones(1,N))-10*diag(ones(1,N-1),-1)-10*diag(ones(1,N-1),1);
B(1,1)=20;
B(N,N)=20;
C=15*diag(ones(1,N))-5*diag(ones(1,N-1),-1)-5*diag(ones(1,N-1),1);
% ����X�ĳ�ֵ��
X=rand(N,N);

%�����ݸ��Ƶ�device��ȥ��
deviceA=gpuArray(A);
deviceB=gpuArray(B);
deviceC=gpuArray(C);
deviceX=gpuArray(X);
deviceI=gpuArray(eye(N));

%���õ��������ľ�������eps.
eps=0.0000001;
k=0;
while(1)
    deviceQ=(-1).*deviceA*deviceX*deviceX+(-1).*deviceB*deviceX+(-1).*deviceC;
    deviceE=inv(cuKron(deviceX',A,N,N)+cuKron(deviceI,deviceA*deviceX+deviceB,N,N))*deviceQ(:);
    deviceX=deviceX+reshape(deviceE,N,N);
    if(norm(deviceE,2)<eps)
        break;
    end
    k=k+1;
end
X;
k
toc






