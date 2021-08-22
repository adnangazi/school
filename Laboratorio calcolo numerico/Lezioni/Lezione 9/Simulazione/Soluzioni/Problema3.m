% Problema 3
clear all
close all
nmax=20;
f=@(x) sin(x);
F=@(x) -cos(x);
a=0; b=pi/4;
xapprox=linspace(a,b);
Ivero=F(b)-F(a);
Iapprox=zeros(nmax,1);
for n=1:nmax
    Iapprox(n)=integralfit(f,xapprox,a,b,n);
end
Err=abs(Iapprox-Ivero);
semilogy(Err)