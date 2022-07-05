% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% dati in ingresso del problema
f = @(x) -5 .* cos(x) + 2 .* x;
x0 = 0;
x1 = 2;
toll = 10 .^ -8;
nmax = 100;

%% chiamata alla funzione Secante
[xv, fxv, n] = Secante(x0, x1, f, toll, nmax);

%% visualizzazione dei dati in ingressoe e risultati sull'esecuzione della funzione
fprintf('-------------------------------------\n');
fprintf('Visualizzazione dei dati in ingresso:\n');
fprintf('Funzione: -5cos(x) + 2x\n');
fprintf('Valori iniziali: x0=%1.0f, x1=%1.0f\n', x0, x1);
fprintf('Tolleranza: %f\n', toll);
fprintf('Max. n. it: %1.0f\n', nmax);
fprintf('-------------------------------------\n');

if n >= nmax
    warning('Raggiunto in massimo numero di iterazioni');
else
    fprintf('Raggiunto la convergenza\n');
end

fprintf('-------------------------------------\n');
fprintf('Tabella di Xk  e f(Xk):\n');
for i = 1:n
    fprintf('%1.0f:\t%f\t%f\n', i, xv(i), fxv(i));
end
fprintf('-------------------------------------\n');

%% plot ordinate e valori della funzione a tali ordinate
figure(1);
semilogy(1:n, abs(fxv));
title('Ordinate e valori della funzione a tali ordinate');
xlabel('Ordinate della iterate');
ylabel('Valori della funzione a tali ordinate');
legend('Xk x f(Xk)');