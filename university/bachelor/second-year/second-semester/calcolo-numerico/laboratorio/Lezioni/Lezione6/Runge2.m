% Gazi Adnan Latif Matricola 1224442
clear all
close all
clc
% dati globali
f=@(x) 1./(x.^2+1);
a=-5;b=5; % estremi intervallo
m=5001; % num punti valutazione
degs=2:10:102; % gradi polinomiali considerati (1)
%% corpo dell'esperimento
xeval=linspace(a,b,5001);
f_eval=f(xeval)';
E_equi=zeros(length(degs));
E_cheb=zeros(length(degs));

E_pequi=zeros(length(degs));
E_pcheb=zeros(length(degs));

E_interp_equi=zeros(length(degs));
E_interp_cheb=zeros(length(degs));
E_interp_pequi=zeros(length(degs));
E_interp_pcheb=zeros(length(degs));

i = 1;
for n=degs
    xinterp_equi=linspace(a,b,n+1);
    yinterp_equi=f(xinterp_equi)';
    
    xinterp_cheb=5*cos((2*(n:-1:0)+1)./(2*n+2)*pi); % pti di Chebyshev
    %xinterp_cheb=5*cos((n:-1:0)./n*pi); % pti di Gauss-Chebyshev
    yinterp_cheb=f(xinterp_cheb)';
    
    L_equi=LagrangePoly(xinterp_equi,xeval);
    L_cheb=LagrangePoly(xinterp_cheb,xeval);
    yeval_equi=L_equi*yinterp_equi;
    yeval_cheb=L_cheb*yinterp_cheb;
    
    L_equi2=LagrangePoly(xinterp_equi,xinterp_equi);
    L_cheb2=LagrangePoly(xinterp_cheb,xinterp_cheb);
    yeval_equi2=L_equi2*yinterp_equi;
    yeval_cheb2=L_cheb2*yinterp_cheb;
    
    c_equi = polyfit(xinterp_equi, yinterp_equi, n);
    p_equi = polyval(c_equi, xeval);
    c_cheb = polyfit(xinterp_cheb, yinterp_cheb, n);
    p_cheb = polyval(c_cheb, xeval);
    
    c_equi2 = polyfit(xinterp_equi, yinterp_equi, n);
    p_equi2 = polyval(c_equi2, xinterp_equi);
    c_cheb2 = polyfit(xinterp_cheb, yinterp_cheb, n);
    p_cheb2 = polyval(c_cheb2, xinterp_cheb);

    E_equi(i) = max(abs(yeval_equi-f_eval));
    E_cheb(i) = max(abs(yeval_cheb-f_eval));
    E_pequi(i) = max(abs(p_equi'-f_eval));
    E_pcheb(i) = max(abs(p_cheb'-f_eval));
    
    E_interp_equi(i) = max(abs(yeval_equi2-yinterp_equi));
    E_interp_cheb(i) = max(abs(yeval_cheb2-yinterp_cheb));
    E_interp_pequi(i) = max(abs(p_equi2'-yinterp_equi));
    E_interp_pcheb(i) = max(abs(p_cheb2'-yinterp_cheb));
    
    i = i + 1;
    
    pause(1);
end
%% grafico errori
figure(1);
semilogy(degs,E_equi);
hold on
semilogy(degs,E_cheb);
semilogy(degs,E_pequi);
semilogy(degs,E_pcheb);
xlabel('grado di interpolazione');
ylabel('errore assoluto')
legend('err interp equi','err interp cheb', 'err interp equi poly', 'err interp cheb poly');
title('Errori di valutazione')
hold off

figure(2);
semilogy(degs,E_interp_equi);
hold on
semilogy(degs,E_interp_cheb);
semilogy(degs,E_interp_pequi);
semilogy(degs,E_interp_pcheb);
xlabel('grado di interpolazione');
ylabel('errore assoluto')
legend('err interp equi','err interp cheb', 'err interp equi poly', 'err interp cheb poly');
title('Errori di interpolazione')
hold off
%% stampa a video
A=[degs;E_equi;E_cheb;E_pequi;E_pcheb];
fprintf('Interpolazione della f. di Runge\n')
fprintf('-----------------------------------------------------\n')
fprintf(['Parametri: a=-5, b=5, ' num2str(m) ' punti di valutazione\n'])
fprintf('-----------------------------------------------------\n')
fprintf('Risultati:\n')
fprintf('|grado|\t |err interp equi   |\t |err interp cheb   |\t |err interp equi p |\t |err interp cheb p |\n')
fprintf('-----------------------------------------------------\n')
fprintf('|%5d|\t |%1.12e|\t |%1.12e|\t |%1.12e|\t |%1.12e|\n',A)

B=[degs;E_interp_equi;E_interp_cheb;E_interp_pequi;E_interp_pcheb];
fprintf('Interpolazione della f. di Runge\n')
fprintf('-----------------------------------------------------\n')
fprintf(['Parametri: a=-5, b=5, ' num2str(m) ' punti di valutazione\n'])
fprintf('-----------------------------------------------------\n')
fprintf('Risultati:\n')
fprintf('|grado|\t |err interp equi   |\t |err interp cheb   |\t |err interp equi p |\t |err interp equi p |\n')
fprintf('-----------------------------------------------------\n')
fprintf('|%5d|\t |%1.12e|\t |%1.12e|\t |%1.12e|\t |%1.12e|\n',B)

%% stampa a file
f = fopen('Runge2.txt', 'w');
fprintf(f, 'Interpolazione della f. di Runge\n');
fprintf(f, '-----------------------------------------------------\n');
fprintf(f, ['Parametri: a=-5, b=5, ' num2str(m) ' punti di valutazione\n']);
fprintf(f, '-----------------------------------------------------\n');
fprintf(f, 'Risultati:\n');
fprintf(f, '|grado|\t |err interp equi   |\t |err interp cheb   |\t |err interp equi p |\t |err interp cheb p |\n');
fprintf(f, '-----------------------------------------------------\n');
fprintf(f, '|%5d|\t |%1.12e|\t |%1.12e|\t |%1.12e|\t |%1.12e|\n',A);

fprintf(f, 'Interpolazione della f. di Runge\n');
fprintf(f, '-----------------------------------------------------\n');
fprintf(f, ['Parametri: a=-5, b=5, ' num2str(m) ' punti di valutazione\n']);
fprintf(f, '-----------------------------------------------------\n');
fprintf(f, 'Risultati:\n');
fprintf(f, '|grado|\t |err interp equi   |\t |err interp cheb   |\t |err interp equi p |\t |err interp equi p |\n');
fprintf(f, '-----------------------------------------------------\n');
fprintf(f, '|%5d|\t |%1.12e|\t |%1.12e|\t |%1.12e|\t |%1.12e|\n',B);
fclose(f);