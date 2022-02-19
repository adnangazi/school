% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% funzione
f = @(x) sqrt(x);

%% variabili globali
a = 0; b = 1; % estremi di integrazione
esp = 1:50; % esperimenti
% vettori degli integrali calcolati per ogni esperimento
I = zeros(1, length(esp)); % I(s)
J = zeros(1, length(esp)); % J(s)
% vettori degli errori assoluti tra gli integrali calcolati e il loro valore vero per ogni esperimento
err_I = zeros(1, length(esp)); % I(s)
err_J = zeros(1, length(esp)); % J(s)
i = 1; % indice per i vettori
intVero = 2 / 3; % valore vero dell'integrale

%% corpo dell'esperimento
for s = esp
    %% calcolo nodi e pesi
    [xI, wI] = FormulaEquispaziataComposta(a, b, 2, s);
    [xJ, wJ] = FormulaEquispaziataComposta(a, b, s, 2);
    
    %% calcolo valore integrali
    I(i) = f(xI) * wI;
    J(i) = f(xJ) * wJ;
    
    %% calcolo errori assoluti
    err_I(i) = abs(I(i) - intVero);
    err_J(i) = abs(J(i) - intVero);
    
    i = i + 1;
end
 
%% plot errori assoluti
figure(1);
semilogy(esp, err_I, 'b');
hold on;
semilogy(esp, err_J, 'r');
title('Errore assoluto');
legend('I(s)', 'J(s)');
hold off;