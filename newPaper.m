%�ǲ��г���
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

%���õ��������ľ�������eps.
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

