% Gazi Adnan Latif Matricola 1224442
%% definizione variabili globali
clear;
clc;
a = -1;
be = 1;
degs = 2:20;
ep = 10^-15;
k = 0;

kc = zeros(length(degs));
inv1 = zeros(length(degs));
inv2 = zeros(length(degs));
err_p = zeros(length(degs));
err_nop = zeros(length(degs));
err_b = zeros(length(degs));
err_triup = zeros(length(degs));
err_triunop = zeros(length(degs));

rel_p = zeros(length(degs));
rel_nop = zeros(length(degs));
rel_b = zeros(length(degs));

res_p = zeros(length(degs));
res_nop = zeros(length(degs));
res_b = zeros(length(degs));

%% corpo dell'esperimento
for n = degs
   z = linspace(a, be, n);
   V = vander(z);
   A = V + ep * eye(n);
   k = k + 1;
   b = A * ones(size(A, 1), 1);
   
   %% risoluzione sistema quadrato ivertibile Ax = b con pivoting
   [L1, U1, P] = lu(A);
   y1 = SostituzioneAvanti(L1, P * b);
   x1 = SostituzioneIndietro(U1, y1);
   
   %% risoluzione sistema quadrato ivertibile Ax = b senza pivoting
   [L2, U2] = LUnoPiv(A);
   y2 = SostituzioneAvanti(L2, b);
   x2 = SostituzioneIndietro(U2, y2);
   
   %% risoluzione sistema quadrato ivertibile Ax = b con backslah
   x3 = A \ b;
   
   %% errori relativi, assoluti e residui soluzioni
   err_p(k) = norm(ones(n, 1) - x1);
   err_nop(k) = norm(ones(n, 1) - x2);
   rel_p(k) = norm(ones(n, 1) - x1) / norm(ones(n, 1));
   rel_nop(k) = norm(ones(n, 1) - x2) / norm(ones(n, 1));
   res_p(k) = norm(A * x1 - b) / norm(b);
   res_nop(k) = norm(A * x2 - b) / norm(b);

   %% errori triu
   err_triup(k) = norm(U1 - triu(U1));
   err_triunop(k) = norm(U2 - triu(U2));
   
   %% errori relativi, assoluti e residui backslah
   err_b(k) = norm(ones(n, 1) - x3);
   rel_b(k) = norm(ones(n, 1) - x3) / norm(ones(n, 1));
   res_b(k) = norm(A * x3 - b) / norm(b);
   
   %% numero di condizionamento e inversa matrice
   kc(k) = cond(A);
   inv1(k) = norm(myInv(A));
   inv2(k) = norm(Inv(A));
end

%% plot figura errori relativi, assoluti, triu e residui soluzioni
figure(1);
semilogy(degs, err_p, 'b');
hold on;
semilogy(degs, err_nop, 'r');
semilogy(degs, err_b, 'g');
semilogy(degs, err_triup, 'm');
semilogy(degs, err_triunop, 'y');
semilogy(degs, rel_p, 'b');
semilogy(degs, rel_nop, 'r');
semilogy(degs, rel_b, 'g');
semilogy(degs, res_p, 'b');
semilogy(degs, res_nop, 'r');
semilogy(degs, res_b, 'g');
semilogy(degs, kc, '--b');
semilogy(degs, inv1, '--r');
semilogy(degs, inv2, '--m');
title('Plot unico');
legend('Err p', 'Err nop', 'Err b', 'Err triu p', 'Err triu nop', 'Rel p', 'Rel nop', 'Rel b', 'Res p', 'Res nop', 'Res b', 'k(a)', 'myInv(A)', 'Inv(A)');
hold off;