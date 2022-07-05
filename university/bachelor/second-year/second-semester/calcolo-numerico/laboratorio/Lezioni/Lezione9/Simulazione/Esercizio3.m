% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% variabili globali
f = @(x) sin(x); % funzione da integrare di prova
F1 = @(x) -cos(x); % integrale della funzione per calcolare il valore reale dell'integrale
a = 0; b = pi / 4; % estremi di integrazione
integralVero = F1(b) - F1(a); % valore reale dell'integrale
esp = 1:10; % esperimenti
num = 100; % numero nodi di interpolazione della funzione
x = linspace(a, b, num); % griglia con nodi equispaziati di interpolazione della funzione
err = zeros(1, length(esp)); % vettore errore tra valore integrale calcolato e valore reale
i = 1; % indice per scorrere il vettore errori

%% corpo dell'esperimento
for n = esp
    integral = IntegralFit(a, b, x, f, n);
    err(i) = abs(integralVero - integral);
    i = i + 1;
end

%% plot errore
figure(1);
semilogy(esp, err);
title('Errore tra integral e integralVero');
legend('err');