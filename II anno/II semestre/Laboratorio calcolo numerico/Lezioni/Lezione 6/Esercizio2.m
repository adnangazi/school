% esperimento sulla stabilità dell'interp. con rumore bianco di campionamento 
f=@(x) exp(sin(x));
M=1000;
teta=0.01;
degs=1:20;
xeval=2;

mediaequi=zeros(length(degs));
varianzaequi=zeros(length(degs));
mediacheb=zeros(length(degs));
varianzacheb=zeros(length(degs));

for n=degs
    xinterp_equi=linspace(-1,1,n+1)';
    xinterp_cheb=cos((2*(n:-1:0)+1)./(2*n+2)*pi)';
    yinterp_equi_true=f(xinterp_equi);
    yinterp_cheb_true=f(xinterp_cheb);
    
    L_equi=LagrangePoly(xinterp_equi,xeval);
    L_cheb=LagrangePoly(xinterp_cheb,xeval);
    
    yinterp_equi=yinterp_equi_true+teta*randn(n+1,M);
    yinterp_cheb=yinterp_cheb_true+teta*randn(n+1,M);
    
    yeval_equi=L_equi*yinterp_equi;
    yeval_cheb=L_cheb*yinterp_cheb;
    
    mediaequi(n)=mean(abs(yeval_equi-f(2)),2);
    varianzaequi(n)=var(abs(yeval_equi-f(2)));
    
    mediacheb(n)=mean(abs(yeval_cheb-f(2)),2);
    varianzacheb(n)=var(abs(yeval_cheb-f(2)));
end

figure(1);
semilogy(degs, mediaequi);
hold on;
semilogy(degs, mediacheb);
title('Media');
legend('equi', 'cheb');
hold off;

figure(2);
semilogy(degs, varianzaequi);
hold on;
semilogy(degs, varianzacheb);
title('Varianza');
legend('equi', 'cheb');
hold off;