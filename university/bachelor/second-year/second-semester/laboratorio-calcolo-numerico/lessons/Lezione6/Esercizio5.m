% Gazi Adnan Latif Matricola 1224442
clear all;
clc;
f = @(x, a) abs(x).^a;
alfa = [2/3, 1, 5/4, 3/2];
degs = 2:2:50;
k = 5001;
a = -1; b = 1;
xeval = linspace(a, b, k);
e_equi = zeros(length(degs), length(alfa));
e_cheb = zeros(length(degs), length(alfa));

k = 0;
for af = alfa
    feval = f(xeval, af)';
    k = k + 1;
    i = 0;
    for m = degs
        i = i + 1;
        n = 2*m^2;
        xinterp_equi = linspace(a, b, n);
        yinterp_equi = f(xinterp_equi, af);
        xinterp_cheb = (b-a)/2.*cos((2*(n-1:-1:0)+1)./(2*(n-1)+2)*pi)+(b+a)/2;
        yinterp_cheb = f(xinterp_cheb, af);
        
        c_equi = polyfit(xinterp_equi, yinterp_equi, m);
        p_equi = polyval(c_equi, xeval)';
        c_cheb = polyfit(xinterp_cheb, yinterp_cheb, m);
        p_cheb = polyval(c_cheb, xeval)';
        
        e_equi(i, k) = max(abs(p_equi-feval));
        e_cheb(i, k) = max(abs(p_cheb-feval));
    end
end

figure(1);
semilogy(degs, e_equi);
hold on;
semilogy(degs, e_cheb);
title('Em(Fa)');
legend('Equi', 'Cheb');
hold off;

figure(2);
semilogy(degs, e_equi.^(1./alfa));
hold on;
semilogy(degs, e_cheb.^(1./alfa));
title('Em(Fa) ^ 1/a');
legend('Equi', 'Cheb');
hold off;