% Adnan Latif Gazi Matricola 1224442
function [int, h, xint] = Parabole (f, a, b, m)
    xint = linspace(a, b, 2 * m + 1)'; % riga di 2 * m + 1 nodi di integrazione
    w = (b - a) / (6 * m) .* [1, repmat([4, 2], 1, m - 1), 4, 1]; % colonna di 2 * m + 1 pesi secondo la formula dei parabole
    int = w * f(xint); % calcolo dell'integrale a partire dalla sommatoria per ogni nodo del prodotto tra nodi e il loro relativo peso secondo il meotdo di quadratura
    h = (b - a) / 180 * ((b - a) / m); % calcolo del passo di integrazione secondo la formula dei parabole
end