% PROBLEMA 1 primo script (SIMULAZIONE 2) 

clear all
close all
a=0;b=2;
Nmax=100;
alpha=2;
f=@(x) x.*(0<=x).*(x<1)+(x.^2/2+1).*(1<=x).*(x<=2);
F1=@(x) x.^2./2; F2=@(x) x.^3/6+x;
Ivero= F1(1)-F1(0)+F2(2)-F2(1);
Itrap=zeros(Nmax,1);
StimaErrore=Itrap;
for N=1:Nmax
    [x,w]=Trapezi(a,b,N);
    Itrap(N)=w*f(x);
    StimaErrore(N)=(b-a)/12*((b-a)./N)^alpha;
end
Err=abs(Ivero-Itrap);
semilogy(Err)
hold on
semilogy(StimaErrore)
title('Errore di quadratura vs stima, primo esempio')
legend('Errore', 'Stima')