% problema 5
cs=1:15;
n=20;
xinterp=linspace(-1,1,n+1);
xeval=linspace(-1,1,1000);
for k=1:length(cs)
    c=cs(k);
    f=@(x) c./(c+x.^2);
    yinterp=f(xinterp);
    yeval=f(xeval);
    coef=polyfit(xinterp,yinterp,n);
    yinterpeval=polyval(coef,xeval);
    err(k)=max(abs(yinterpeval-yeval));
end
semilogy(cs,err)