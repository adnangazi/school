% Adnan Latif Gazi Matricola 1224442
function [xv, fxv, n] = Secante (x0, x1, f, toll, nmax)
    n = 1;
    xv = [x0, x1, zeros(1, nmax - 2)];
    fxv = [f(x0), zeros(1, nmax - 1)];
    step = abs(xv(n + 1) - xv(n));
    
    while step >= toll && n < nmax && f(xv(n + 1)) ~= 0
        n = n + 1;
        fxv(n) = f(xv(n));
        xv(n + 1) = xv(n) - fxv(n) * ((xv(n) - xv(n - 1)) / (fxv(n) - fxv(n - 1)));
        step = abs(xv(n + 1) - xv(n));
    end
    n = n + 1;
    xv = xv(1, 1:n);
    fxv = fxv(1, 1:n);
end