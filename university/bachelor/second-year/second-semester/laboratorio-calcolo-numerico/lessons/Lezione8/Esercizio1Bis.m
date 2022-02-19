% Gazi Adnan Latif Matricola 1224442
clear all;
clc;

eps = 10^-15;
degs = 2:20;
a = -1;
be = 1;
k = 1;

err = zeros(length(degs));
err_p = zeros(length(degs));
err_nop = zeros(length(degs));
err_triu = zeros(length(degs));
err_triup = zeros(length(degs));

for n = degs
    z = linspace(a, be, n);
    V = vander(z);
    A = V + eps.*eye(n);
    b = A * ones(n, 1);
    
    [L, U, P] = lu(A);
    x = SostituzioneIndietro(U, SostituzioneAvanti(L, P * b));
    
    [L1, U1] = LUnoPiv(A);
    x1 = SostituzioneIndietro(U1, SostituzioneAvanti(L1, b));
    
    x2 = A \ b;
   
   %% errori soluzioni
   err(k) = norm(ones(n, 1) - x);
   err_p(k) = norm(ones(n, 1) - x1);
   err_nop(k) = norm(ones(n, 1) - x2);

   %% errori triu
   err_triu(k) = norm(U - triu(U));
   err_triup(k) = norm(U1 - triu(U1));
   
   k = k + 1;
end

figure(1);
semilogy(degs, err, 'b');
hold on;
semilogy(degs, err_p, 'm');
semilogy(degs, err_nop, 'r');
title('Errore soluzioni');
legend('Con pivoting', 'Senza pivoting', 'Backslash');
hold off;

figure(2);
semilogy(degs, err_triu, 'b');
hold on;
semilogy(degs, err_triup, 'm');
title('Errore triu');
legend('Con pivoting', 'Senza pivoting');
hold off;