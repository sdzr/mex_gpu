function deviceC = cuKron(deviceA,deviceB,M,N)
 for i=1:M
     for j=1:N
         deviceC(N*(i-1)+1:N*i,M*(j-1)+1:M*j)=deviceA(i,j)*deviceB;
     end
 end

end

