% Gazi Adnan Latif Matricola 1224442
clear all;
clc;
%% definizione variabili globali
f = @(x ) 1./(1 + x.^2); % funzione di Runge modificato
a = -1; b = 1; % estremi dell'intervallo
punti = 10000; % griglia di punti equispaziati
degs = 1:50; % vettore esperimenti
k = 0; % indice vettori risultati

%% vettori con errori massimi sulla griglia di valutazione per ogni esperimento
err_p1 = zeros(1, length(degs)); % myInv
err_p2 = zeros(1, length(degs)); % Inv
err_p3 = zeros(1, length(degs)); % backslash su fattorizzazione QR
err_p4 = zeros(1, length(degs)); % fattorizzazione LU con sostituzione
err_p5 = zeros(1, length(degs)); % backslash

%% vettori con numeri di condizionamento per ogni esperimento
kA = zeros(1, length(degs)); % A
kR0 = zeros(1, length(degs)); % R0

%% corpo dell'esperimento
for n = degs
    %% aggiornamento indice, nodi di interpolazione, funzione interpolata e matrice equazioni
    k = k + 1;
    m = n^2;
    xinterp = linspace(a, b, m);
    yinterp = f(xinterp)';
    V = vander(xinterp);
    A = V(:, m - n + 1:end);
    % A = x.^(n - 1:-1:0); % metodo alternativo
    
    %% risoluzione sistema Ac = yinterp mediante fattorizzazione QR di A
    [Q0, R0] = qr(A, 0);
    c1 = myInv(R0) * (Q0' * yinterp(1:size(Q0, 1), 1));
    %c2 = Inv(R0) * (Q0' * yinterp(1:size(Q0, 1), 1));
    c3 = R0 \ (Q0' * yinterp(1:size(Q0, 1), 1));
    
    %% risoluzione sistema Ac = yinterp mediante fattorizzazione LU con pivoting di A' * A
    A2 = A' * A;
    [L, U, P] = lu(A2);
    y = SostituzioneAvanti(L, P * yinterp(1:size(A2, 1), 1));
    c4 = SostituzioneIndietro(U, y);
    c5 = A2 \ yinterp(1:size(A2, 1), 1);
    
    %% valutazione polinomi sulla griglia
    xeval = linspace(a, b, n);
    feval = f(xeval);
    Aeval = xeval.^(n - 1:-1:0);
    p1 = Aeval * c1;
    %p2 = Aeval * c2;
    p3 = Aeval * c3;
    p4 = Aeval * c4;
    p5 = Aeval * c5;
    
    %% calcolo errori massimi sulla griglia di valutazione
    err_p1(k) = max(abs(p1 - feval));
    %err_p2(k) = max(abs(p2 - feval));
    err_p3(k) = max(abs(p3 - feval));
    err_p4(k) = max(abs(p4 - feval));
    err_p5(k) = max(abs(p5 - feval));
    
    %% calcolo numeri di condizionamento
    kA(k) = cond(A);
    kR0(k) = cond(R0);
end

%% plot 1: errori
figure(1);
semilogy(degs, err_p1);
hold on;
%semilogy(degs, err_p2);
semilogy(degs, err_p3);
semilogy(degs, err_p4);
semilogy(degs, err_p5);
title('errori');
legend('myInv', 'Inv', 'backslash QR', 'LU', 'backslash');
hold off;

%% plot 2: numeri di condizionamento
figure(2);
semilogy(degs, kA);
hold on;
semilogy(degs, kR0);
title('numeri di condizionamento');
legend('A', 'R0');
hold off;