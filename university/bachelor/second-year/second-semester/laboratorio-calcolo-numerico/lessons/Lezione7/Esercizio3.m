% Gazi Adnan Latif Matricola 1224442
clear;
clc;
f=@(x) sin(x);
a=0;b=pi/2;
intvero=1;
toll = 10^-15;
maxN = 100;
%%
ks=1:30;
It=zeros(1,length(ks));Ip=It;Iqe=It;Iqc=It;
h=(b-a)./(2*ks);
%%
for k=ks
    N=2*k;
    
    xequi = linspace(a, b, N + 1)';
    xcheb = (a+b)/2+(b-a)/2*cos((2*(N-1:-1:0)+1)./(2*N+1)*pi)';
    
    [we, We, flage] = FormulaInterpolatoria(xequi, a, b, toll, maxN);
    [wc, Wc, flagc] = FormulaInterpolatoria(xcheb, a, b, toll, maxN);
    
    Iqe(k) = we*f(xequi);
    Iqc(k) = wc*f(xcheb);
    
    [xt,wt]=Trapezi(a,b,2*N);
    [xp,wp]=Parabole(a,b,N);
    It(k)=wt*f(xt);
    Ip(k)=wp*f(xp);
end

figure(1);
semilogy(2*ks+1,abs(intvero-It),'b');hold on;
semilogy(2*ks+1,h.^2,'--b');
semilogy(2*ks+1,abs(intvero-Ip),'r');
semilogy(2*ks+1,h.^4,'--r');
semilogy(2*ks+1,abs(intvero-Iqe),'g');
semilogy(2*ks+1,h.^4,'--g');
semilogy(2*ks+1,abs(intvero-Iqc),'m');
semilogy(2*ks+1,h.^4,'--m');
legend('err trap','h^2','err parab', 'h^4', 'err equi', 'h^4', 'err cheb', 'h^4');
title(['Errori di quadratura di f su [0,pi/2]']);
xlabel('num punti di quadratura');
hold off;