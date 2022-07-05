% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% funzioni
frunge = @(x) 1 ./ (1 + x .^ 2); % Runge
t = @(i, n) -cos(i .* pi ./ n); % ausiliaria Chebyshev
cheb = @(a, b, n) ((a + b) / 2) + ((b - a) / 2) .* t(0:n, n); % Chebyshev

%% variabili globali
a = -5; b = 5; % estremi dell'intervallo
num = 200; % numero di nodi di valutazione
n = 10; % grado del polinomio

%% corpo dell'esperimento
x = linspace(a, b, num); % griglia di valutazione
yrunge = frunge(x); % funzione nei punti di valutazione

xdata = cheb(a, b, n); % griglia di interpolazione di Chebyshev
ydata = frunge(xdata); % funzione nei punti di interpolazione di Chebyshev

xdatae = linspace(a, b, n + 1); % griglia di interpolazione equispaziati
ydatae = frunge(xdatae); % funzione nei punti di interpolazione equispaziati

c = polyfit(xdata, ydata, n); % coefficienti del polinomio nei punti di interpolazione
p = polyval(c, x); % polinomio nei punti di valutazione

ce = polyfit(xdatae, ydatae, n); % coefficienti del polinomio nei punti di interpolazione
pe = polyval(ce, x); % polinomio nei punti di valutazione

%% plot Chebyshev
figure(1);
plot(x, yrunge, 'b'); % funzione originale dei punti di valutazione, linea continua blu
hold on;
plot(x, p, '--r'); % polinomio di chebyshev nei punti di valutazione, linea tratteggiata rossa
plot(xdata, ydata, 'om'); % nodi di interpolazione di chebyshev, cerchi magenta
title('plot funzione, nodi e polinomio');
legend('funzione originale', 'polinomio', 'nodi');
hold off;

%% salvataggio Chebyshev
chebyshev = gca;
exportgraphics(chebyshev, 'chebyshev.png');

%% plot equispaziati
figure(2);
plot(x, yrunge, 'b'); % funzione originale dei punti di valutazione, linea continua blu
hold on;
plot(x, pe, '--r'); % polinomio equispaziati nei punti di valutazione, linea tratteggiata rossa
plot(xdatae, ydatae, 'om'); % nodi di interpolazione equispaziati, cerchi magenta
title('plot funzione, nodi e polinomio');
legend('funzione originale', 'polinomio', 'nodi');
hold off;

%% salvataggio equispaziati
equispaziati = gca;
exportgraphics(equispaziati, 'equispaziati.png');