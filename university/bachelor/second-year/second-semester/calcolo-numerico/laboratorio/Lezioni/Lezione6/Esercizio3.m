% esperimento sulla stabilità dell'interp. con rumore bianco di campionamento 
f=@(x) x.^4;
M=100;
N=100;
m=4;
teta=0.05;
xeval=linspace(-1,1,1000)';
%%
xinterp_equi=linspace(-1,1,N)';
xinterp_cheb=cos((2*(N-1:-1:0)+1)./(2*N+2)*pi)';
yinterp_equi_true=f(xinterp_equi);
yinterp_cheb_true=f(xinterp_cheb);
    
yinterp_equi=yinterp_equi_true+teta*randn(N,M);
yinterp_cheb=yinterp_cheb_true+teta*randn(N,M);
    
for i=1:M
    c_equi=polyfit(xinterp_equi, yinterp_equi(:,i), m);
    p_equi=polyval(c_equi, xeval);
    c_cheb=polyfit(xinterp_cheb, yinterp_cheb(:,i), m);
    p_cheb=polyval(c_cheb, xeval);
end