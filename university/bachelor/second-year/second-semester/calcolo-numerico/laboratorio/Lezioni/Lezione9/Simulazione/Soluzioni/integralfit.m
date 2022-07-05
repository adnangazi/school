function I=integralfit(f,xapprox,a,b,n)
xapprox=xapprox(:);xapprox=xapprox'; %per assicurarsi che sia vettore riga
c=polyfit(xapprox,f(xapprox),n);
v=((b.^(n+1:-1:1)-a.^(n+1:-1:1))./(n+1:-1:1))';
I=c*v;
