% Gazi Adnan Latif Matricola 1224442
function [phi] = MappaNewtonMod(f, f1, m, x)
    phi = x-m.*(f(x)./f1(x));
end