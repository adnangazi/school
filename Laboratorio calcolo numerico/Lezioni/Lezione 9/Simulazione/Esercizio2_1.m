% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% variabili globali
f = @(x) x .* (0 <= x) .* (x < 1) + (x.^2 / 2 + 1) .* (1 <= x) .* (x <= 2); % sistema della funzione
F1 = @(x) x .^ 2 ./ 2; 
F2 = @(x) x .^ 3 / 6 + x;
esp = 1:100; % esperimenti
a = 0; b = 2; % estremi di integrazione
c = 1; % punto intermedio del sistema della funzione
valvero = F1(c) - F1(a) + F2(b) - F2(c); % valore reale dell'integrale
alpha = 4; % ordine massimo della funzione

% vettori errore dell'approssimazione dell'integrale rispetto al suo valore reale e del passo d'integrazione
err = zeros(1, length(esp));
h = zeros(1, length(esp));
i = 1; % indice 

%% corpo dell'esperimento
for n = esp
    [x, w] = Parabole(a, b, n); % genera 2 * n + 1 nodi e pesi
    val = w * f(x); % valore dell'approssimazione dell'integrale
    err(i) = abs(val - valvero); % valutazione errore dell'approssimazione dell'integrale rispetto al suo valore reale
    h(i) = (b - a) / 180 * ((b - a) ./ n) ^ alpha; % valutazione del passo d'integrazione
    
    i = i + 1;
end

%% plot errore e passo di integrazione
figure(1);
semilogy(esp, err);
hold on;
plot(esp, h);
title('Errore e passo di integrazione');
legend('err', 'h^-^a');
hold off;