% Adnan Latif Gazi Matricola 1224442
clear all;
clc;

%% variabili globali
a = 0; b = 1; % estremi dell'intervallo
esp = 1:20; % esperimenti
det1 = zeros(1, length(esp)); % vettore per i determinanti di matlab ad ogni esperimento
det2 = zeros(1, length(esp)); % vettore per i determinanti di MySymDet ad ogni esperimento
val1 = zeros(1, length(esp)); % vettore per i valori det^(1/n) di matlab ad ogni esperimento
val2 = zeros(1, length(esp)); % vettore per i valori det^(1/n) di MySymDet ad ogni esperimento
err_rel = zeros(1, length(esp)); % vettore per gli errori relativi tra il determinante reale e quello calcolato per ogni esperimento
i = 1; % indice per scorrere i vettori

%% corpo dell'esperimento
for n = esp
    m = 2 * n;
    x = cos(pi / m .* (0:m))'; % m punti di Chebyshev-Lobatto in [0, 1]
    alfa = 0:n-1;
    V = repmat(x, 1, n) .^ alfa; % V{m x n}
    G = V' * V; % G{n x n}
    det1(i) = det(G);
    det2(i) = MySymDet(V);
    val1(i) = det1(i) ^ (1/n);
    val2(i) = det2(i) ^ (1/n);
    err_rel(i) = abs(val1(i) - val2(i)) / abs(val2(i)); % suppongo vero il MySymDet
    i = i + 1;
end

%% plot determinanti, valori det^(1/n ) ed errori relativi
figure(1);
semilogy(esp, det1);
hold on;
semilogy(esp, det2, '--');
title('Determinanti');
legend('Matlab', 'MySymDet');
hold off;

figure(2);
semilogy(esp, val1);
hold on;
semilogy(esp, val2, '--');
title('Valori det^1^/^n');
legend('Matlab', 'MySymDet');
hold off;

figure(3);
semilogy(esp, err_rel);
title('Errore relativo');
legend('|det1 - det2| / |det2|');