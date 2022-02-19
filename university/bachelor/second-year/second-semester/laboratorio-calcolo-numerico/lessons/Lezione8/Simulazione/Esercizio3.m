% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% anonymous function di f e f'
f = @(x) x .* (exp(1) .^ x) - 1;
df = @(x) (exp(1) .^ x) .* (1 + x);

%% variabili globali
toll = 10^-4;
itmax = 10000; 
x0 = 0;

% intervallo di prova in cui plottare preventivamente un grafico di f. 
% Inizialmente imposto un intervallo molto largo in modo da essere sicuro 
% da avere un punto fisso al suo interno. Successivamente restringo 
% l'intervallo finchè l'esistenza del punto fisso è garantito dalla teoria.
a = -100; b = 99; 
esistenza = abs(f(a) - f(b)) / abs(a - b);
while esistenza >= 1
    a = a + 1;
    b = b - 1;
    esistenza = abs(f(a) - f(b)) / abs(a - b);
end % esiste un unico punto fisso in tale intervallo

fprintf('Intervallo ottenuto in cui esiste (ed è unico) un punto fisso: [%f, %f]\n', a, b);

x = linspace(a, b);

%% plot funzione
figure(1);
plot(x, f(x));
title('grafico f');
legend('f');

%% calcolo f(x) = x con metodo di punto fisso 
[zero, res, iterates, flag] = PuntoFisso(f, a, b, toll, itmax);
[zeroC, resC, iteratesC, flagC] = PuntoFissoClassico(f, x0, toll, itmax);

%% plot velocità di convergenza
figure(2);
plot(abs(df(iterates))); % df(zero) ~= 0 ==> C = |df(zero)|
title('Velocità di convergenza di f');
legend('Approssimazioni delle costanti asintotiche');

figure(3);
plot(abs(df(iteratesC))); % df(zeroC) ~= 0 ==> C = |df(zeroC)|
title('Velocità di convergenza di f');
legend('Approssimazioni delle costanti asintotiche');

% calcolo vettore scarti ad ogni passo delle soluzioni del metodo di punto
% fisso
scarto = iteratesC(2:end) - iteratesC(1:end-1);
figure(4);
plot(abs(scarto(2:end))./(abs(scarto(1:end-1)))); % |Sk+1| / |Sk| ^ p, p = 1
title('Velocità di convergenza di f');
legend('Approssimazioni delle costanti asintotiche');