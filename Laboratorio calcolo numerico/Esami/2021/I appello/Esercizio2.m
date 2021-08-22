% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% funzione
f = @(x) (x .^ 2 - 1) .* (log(x + 1) - x);

%% variabili globali
n = 8; % grado massimo del polinomio
x0 = 0.6; % punto di partenza per calcolare lo zero di funzione più vicino
toll = 10 .^ -12; % tolleranza esercizio 2
method = 's'; % usato metodo dello scarto come default
itmax = 100; % sono poche: raggiunge il massimo numero di iterazioni prima di aver raggiunto un valore accettabile
xvera = 0; % zero reale di funzione

xinterp = 0.5*cos((0:n)./n*pi); % n punti di interpolazione di Chebyshev distribuiti nell'intervallo [-0.5, 0.5]
yinterp = f(xinterp); % funzione nei punti di interpolazione

c = polyfit(xinterp, yinterp, n); % n + 1 coefficienti del polinomio
d = c (1, 1:n) .* (n:-1:1); % n coefficienti della derivata del polinomio

%% funzioni di valutazione del polinomio e della sua derivata necessari per essere usati in Newton
p = @(x) polyval(c, x);
dp = @(x) polyval(d, x); % necessario per Newton

%% calcolo zero di funzione mediante Newton
[zero, res, iterates, flag] = Newton(p, dp, x0, toll, itmax, method); % sul polinomio e sua derivata anzichè sulla funzione

%% calcolo scarto ed errore assoluto ad ogni iterazione di Newton
scarto = abs(iterates(1, 2:end) - iterates(1, 1:end - 1));
err_ass = abs(iterates(1, :) - xvera);

%% plot scarto ed errore assoluto per Newton e NewtonMod
figure(1);
semilogy(scarto, 'b');
hold on;
semilogy(err_ass, 'r');
title('Scarto ed Errore assoluto Newton');
legend('Scarto', 'Errore assoluto');