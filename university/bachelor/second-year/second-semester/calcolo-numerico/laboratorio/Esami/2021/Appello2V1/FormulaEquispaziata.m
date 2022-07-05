% Adnan Latif Gazi Matricola 1224442
function [x, w] = FormulaEquispaziata (a, b, n)
    x = linspace(a, b, n + 1); % griglia di n + 1 nodi equispaziati
    alphas = (0:n)'; % esponenti necessari per calcolare la base a partire dalla griglia dei nodi
    V = x .^ alphas; % V{i, j} = x(j - 1) ^ (i - 1), con i = 1, ..., n + 1
    c = (((b .^ (1:n + 1)) - (a .^ (1:n + 1))) ./ (1:n + 1))'; % C(i) = (b^i - a^i) / i, con i = 1, ..., n + 1
    [L, U, P] = lu(V); % fattorizzazione LU di V per risolvere Vw = c
    w = U \ (L \ (P * c)); % risoluzione dei sistemi a matrici triangolari inferiori e superiori mediante backslah per trovare w
end