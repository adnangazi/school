% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% variabili globali
f = @(x) sin(x);
a = 0; b = pi; % estremi dell'intervallo
degs = 1:20; % gradi di interpolazione oppure gli esperimenti
m = 1000; % numero punti di valutazione fissato
xeval = linspace(a, b, m); % griglia di valutazione
feval = f(xeval);

% vettori per i massimi errori di valutazione dei polinomi rispetto alla valutazione della funzione originale
err_equi = zeros(1, length(degs)); % equi
err_cheb = zeros(1, length(degs)); % cheb
i = 1; % indice per scorrere tali vettori

%% corpo dell'esperimento
for n = degs
    % nodi in valutazione equistaziati e valore della funzione interpolata in tali punti equistaziati
    xinterp_equi = linspace(a, b, n+1);
    yinterp_equi = f(xinterp_equi);
    
    % nodi in valutazione di Chebyshev e valore della funzione interpolata in tali punti di Chebyshev
    xinterp_cheb = (a+b)/2+(b-a)/2*cos(linspace(-pi,0,n+1));
    yinterp_cheb = f(xinterp_cheb);
    
    % interpolazione della funzione per nodi equispaziati di Chebyshev
    c_equi = polyfit(xinterp_equi, yinterp_equi, n);
    c_cheb = polyfit(xinterp_cheb, yinterp_cheb, n);
    
    % valutazione dei polinomi equispaziati e di Chebyshev per la griglia di valutazione
    p_equi = polyval(c_equi, xeval);
    p_cheb = polyval(c_cheb, xeval);
    
    % massimi errori di valutazione dei polinomi rispetto alla valutazione della funzione originale
    err_equi(i) = max(abs(p_equi - feval));
    err_cheb(i) = max(abs(p_cheb - feval));
    
    i = i + 1;
    
    %% plot funzione, valori interpolati, funzioni interpolanti
    figure(1);
    plot(xeval, feval); % funzione nei punti di valutazione
    hold on;
    plot(xinterp_equi, yinterp_equi); % funzione nei punti di interpolazione equispaziati
    plot(xinterp_cheb, yinterp_cheb); % funzione nei punti di interpolazione di Chebyshev
    plot(xeval, p_equi); % valori interpolati equispaziati
    plot(xeval, p_cheb); % valori interpolati di Chebyshev
    title('F, val interp, f interp');
    legend('f', 'f equi', 'f cheb', 'p equi', 'p cheb');
    hold off;
    
    pause(1);
end

%% plot massimi errori di valutazione delle due famiglie
figure(2);
semilogy(degs, err_equi);
hold on;
semilogy(degs, err_cheb);
title('Massimo errore');
legend('Equi', 'Cheb');
hold off;