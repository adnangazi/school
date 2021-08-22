% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% anonymous function di f e f'
f = @(x) x .* (exp(1) .^ x) - 1;
df = @(x) (exp(1) .^ x) .* (1 + x);

%% variabili globali
% fisso la tolleranza per l'arresto del metodo di Newton al valore 
% solitamente usato a lezione
toll = 10^-8;
% per semplicità uso il criterio minimo tra quello dello scarto e quello 
% del residuo pesato approssimato
method = 'm';
% fisso il numero massimo di iterazioni per l'arresto del metodo di Newton 
% al valore solitamente usato a lezione
itmax = 100; 
% intervallo di prova in cui plottare preventivamente un grafico di f
a = 0; 
b = 2;
x = linspace(a, b);

%% plot funzione
figure(1);
plot(x, f(x));
title('grafico f');
legend('f');

%% calcolo f(x) = 0 con metodo di Newton
% osservo da figure(1) che f(x) = 0 circa per x = 0.5671 ==> imposto il 
% punto di partenza a 1
x0 = 1; 
[zero, res, iterates, flag] = Newton(f, df, x0, toll, itmax, method);

%% plot velocità di convergenza
% calcolo vettore scarti ad ogni passo delle soluzioni del metodo di Newton
scarto = iterates(2:end) - iterates(1:end-1);

% imposto l'ordine di convergenza a 2 o 1 in base al valore della derivata
% prima della funzione nello zero trovato
if df(zero) ~= 0
    p = 2;
else
    p = 1;
end

figure(2);
plot(abs(scarto(2:end))./(abs(scarto(1:end-1).^p))); % |Sk+1| / |Sk|^p
title('Velocità di convergenza di f');
legend('Approssimazioni delle costanti asintotiche');