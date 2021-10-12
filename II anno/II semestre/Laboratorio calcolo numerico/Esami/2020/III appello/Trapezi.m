% Adnan Latif Gazi Matricola 1224442
function [int, h, xint] = Trapezi (f, a, b, m)
    xint = linspace(a, b, m + 1)'; % riga di m + 1 nodi di integrazione
    w = (b - a) / m * [1 / 2, ones(1, m - 1), 1 / 2]; % colonna di m + 1 pesi secondo la formula dei trapezi
    int = w * f(xint); % calcolo dell'integrale a partire dalla sommatoria per ogni nodo del prodotto tra nodi e il loro relativo peso secondo il meotdo di quadratura
    h = (b - a) / 12 * ((b - a) / m); % calcolo del passo di integrazione secondo la formula dei trapezi
end