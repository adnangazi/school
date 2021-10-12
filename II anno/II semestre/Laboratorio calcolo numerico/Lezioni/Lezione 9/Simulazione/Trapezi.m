% Adnan Latif Gazi Matricola 1224442
function [x, w] = Trapezi (a, b, N)
    x = linspace(a, b, N + 1)';
    w = (b - a) / N * [1 / 2, ones(1, N - 1), 1 / 2];
end