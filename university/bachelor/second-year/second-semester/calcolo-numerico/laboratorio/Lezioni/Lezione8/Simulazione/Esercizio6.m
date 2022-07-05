% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% variabili globali
f = @(x, c) c./(c+x.^2);
degs = 1:15; % esperimenti
a = -1; b = 1; % stabilisco un intervallo a piacere in cui interpolare la funzione
m = 1000; % punti di valutazione
n1 = 101; % punti di interpolazione
n2 = 11; % grado per l'approssimazione ai minimi quadrati
xeval = linspace(a, b, m); % griglia di valutazione
xinterp = linspace(a, b, n1); % griglia di interpolazione

err = zeros(1, length(degs)); % vettore dei massimi errori dell'interpolante sulla griglia di valutazione per ogni valore di c
i = 1; % indice per scorrere il vettore degli errori

%% corpo dell'esperimento
for c = degs
    % funzione valutata nei punti di valutazione e nei punti di interpolazione
    feval = f(xeval, c);
    yinterp = f(xinterp, c);
    
    % interpolazione della funzione
    cp = polyfit(xinterp, yinterp, n2);
    
    % valutazione del polinomio per la griglia di valutazione
    p = polyval(cp, xeval);
    
    % calcolo massimo errore dell'interpolante sulla griglia di valutazione per l'attuale valore di c
    err(i) = max(abs(p - feval));
    
    i = i + 1;
    
    %% plot coefficienti dell'approssimante
    figure(1);
    semilogy(abs(cp));
    hold on;
    title('Coefficienti dell approssimante');
    legend('cp');
    hold off;
    
    %% di che grado è l'approssimante?
    fprintf('Il massimo grado pari dell approsimante è: %f\n', max(abs(cp(2:2:end))));
    fprintf('Il massimo grado dispari dell approsimante è: %f\n', max(abs(cp(1:2:end))));
    
    pause(1);
end

%% plot massimo errore dell'interpolante sulla griglia di valutazione per ogni valore di c
figure(2);
semilogy(degs, err); % c x err
hold on;
title('Andamento errore rispetto a c');
legend('degs x err');