
clear all
close all
nmax=20;
for n=1:nmax
    m=2*n;
    x=cos(pi/m.*(0:m))';
    V=x.^(0:n);
    G=V'*V;
    d(n)=(det(G)).^(1/n);
    d1(n)=(mysymdet(V)).^(1/n);
end
figure(1)
plot(d);hold on
plot(d1)
err=abs(d-d1)./abs(d1);
figure(2)
semilogy(err)