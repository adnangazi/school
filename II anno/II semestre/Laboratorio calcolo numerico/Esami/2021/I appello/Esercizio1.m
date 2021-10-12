% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% funzione e derivata
f = @(x) (x .^ 2 - 1) .* (log(x + 1) - x);
df = @(x) 2 .* x .* (log(x + 1) - x) + (x .^ 2 - 1) .* ((1 ./ (x .^ 2 - 1)) - 1); % necessario per Newton e NewtonMod

%% variabili globali
x0 = 0.6; % punto di partenza per calcolare lo zero di funzione più vicino
toll1 = 10 .^ -4; % tolleranza punti I e II
toll2 = 10 .^ -8; % tolleranza punto III
method = 's'; % usato metodo dello scarto come default
itmax = 100; % sono poche: raggiunge il massimo numero di iterazioni prima di aver raggiunto un valore accettabile
xvera = 0; % zero reale di funzione
m = 2; % molteplicità al variare della radice

%% calcolo zero di funzione mediante Newton e NewtonMod
[zero, res, iterates, flag] = Newton(f, df, x0, toll1, itmax, method);
[zeroMod, resMod, iteratesMod, flagMod] = NewtonMod(f, df, x0, m, toll1, itmax, method);

[zero2, res2, iterates2, flag2] = Newton(f, df, x0, toll2, itmax, method);
[zeroMod2, resMod2, iteratesMod2, flagMod2] = NewtonMod(f, df, x0, m, toll2, itmax, method);

%% calcolo scarto ed errore assoluto ad ogni iterazione di Newton e NewtonMod
scarto = abs(iterates(1, 2:end) - iterates(1, 1:end - 1));
err_ass = abs(iterates(1, :) - xvera);

scartoMod = abs(iteratesMod(1, 2:end) - iteratesMod(1, 1:end - 1));
err_assMod = abs(iteratesMod(1, :) - xvera);

scarto2 = abs(iterates2(1, 2:end) - iterates2(1, 1:end - 1));
err_ass2 = abs(iterates2(1, :) - xvera);

scartoMod2 = abs(iteratesMod2(1, 2:end) - iteratesMod2(1, 1:end - 1));
err_assMod2 = abs(iteratesMod2(1, :) - xvera);

%% plot scarto ed errore assoluto per Newton e NewtonMod
figure(1);
semilogy(scarto, 'b');
hold on;
semilogy(err_ass, 'r');
title('Scarto ed Errore assoluto Newton');
legend('Scarto', 'Errore assoluto');

figure(2);
semilogy(scartoMod, 'b');
hold on;
semilogy(err_assMod, 'r');
title('Scarto ed Errore assoluto NewtonMod');
legend('Scarto', 'Errore assoluto');

figure(3);
semilogy(scarto2, 'b');
hold on;
semilogy(err_ass2, 'r');
title('Scarto ed Errore assoluto Newton 2');
legend('Scarto', 'Errore assoluto');

figure(4);
semilogy(scartoMod2, 'b');
hold on;
semilogy(err_assMod2, 'r');
title('Scarto ed Errore assoluto NewtonMod 2');
legend('Scarto', 'Errore assoluto');