% Adnan Latif Gazi Matricola 1224442
function [x, w] = Parabole (a, b, N)
    x = linspace(a, b, 2 * N + 1)';
    w = (b - a) / (6* N) .* [1, repmat([4, 2], 1, N - 1), 4, 1];
end