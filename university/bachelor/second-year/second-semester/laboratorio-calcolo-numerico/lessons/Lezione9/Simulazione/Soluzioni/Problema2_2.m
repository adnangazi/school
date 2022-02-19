% PROBLEMA 2 secondo script (SIMULAZIONE 2) 

clear all
close all
a=0;b=2;
Nmax=100;
alpha=4;
f=@(x) (2+sqrt(sqrt(2)-x)).*(0<=x).*(x<sqrt(2))+(x.^2/2+1).*(sqrt(2)<=x).*(x<=2);
F1=@(x) 2*x-2/3*(sqrt(2)-x).^(3/2); F2=@(x) x.^3/6+x;
Ivero= F1(sqrt(2))-F1(0)+F2(2)-F2(sqrt(2));
Itrap=zeros(Nmax,1);
StimaErrore=Itrap;
for N=1:Nmax
    [x,w]=Parabole(a,b,N);
    Itrap(N)=w*f(x);
    StimaErrore(N)=(b-a)/180*((b-a)./(2*N))^alpha;
end
Err=abs(Ivero-Itrap);
semilogy(Err)
hold on
semilogy(StimaErrore)
title('Errore di quadratura vs stima, primo esempio')
legend('Errore', 'Stima')