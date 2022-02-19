% Gazi Adnan Latif Matricola 1224442
function [phi] = MappaNewtonModDer(f, f1, f2, m, x)
    phi = 1-m.*((f1(x).^2-f(x).*f2(x))./(f1(x).^2));
end