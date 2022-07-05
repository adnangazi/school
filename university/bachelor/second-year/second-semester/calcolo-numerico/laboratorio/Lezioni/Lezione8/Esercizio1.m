% Gazi Adnan Latif Matricola 1224442
%% definizione variabili globali
clear;
clc;
a = -1;
be = 1;
degs = 2:20;
ep = 10^-15;
k = 0;

err_p = zeros(length(degs));
err_nop = zeros(length(degs));
err_triup = zeros(length(degs));
err_triunop = zeros(length(degs));

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
   
   %% errori soluzioni
   err_p(k) = norm(ones(n, 1) - x1);
   err_nop(k) = norm(ones(n, 1) - x2);

   %% errori triu
   err_triup(k) = norm(U1 - triu(U1));
   err_triunop(k) = norm(U2 - triu(U2));
end

%% plot figura errori soluzioni
figure(1);
semilogy(degs, err_p, 'b');
hold on;
semilogy(degs, err_nop, 'r');
title('Errore soluzioni');
legend('Con pivoting', 'Senza pivoting');
hold off;

%% plot figura errori triu
figure(2);
semilogy(degs, err_triup, 'b');
hold on;
semilogy(degs, err_triunop, 'r');
title('Errore triu');
legend('Con pivoting', 'Senza pivoting');
hold off;