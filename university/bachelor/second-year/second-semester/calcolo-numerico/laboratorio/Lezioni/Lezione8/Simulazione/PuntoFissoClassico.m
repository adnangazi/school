% Adnan Latif Gazi Matricola 1224442
function [zero, res, iterates, flag] = PuntoFissoClassico(f, x0, toll, itmax)
    % test dello scarto unico test d'arresto implementato
    N = 1;
    iterates = zeros(1, itmax); 
    iterates(N) = x0;
    
    if itmax > 1
        iterates(N + 1) = f(iterates(N));
        N = N + 1;
    end
    
    while abs(iterates(N) - iterates(N - 1)) > toll && N < itmax
        iterates(N + 1) = f(iterates(N)); % Xn+1 = f(Xn)
        N = N + 1;
    end
    
    iterates = iterates(1, 1:N);
    zero = iterates(1, end);
    res = f(zero);
    
    if res == zero
        flag = 'f'; % residuo 0 in un numero finito di iterazioni
    elseif N < itmax
        flag = 's'; % uscita per test dello scarto
    else
        flag = 'e'; % raggiunto il massimo numero di iterazioni
    end
end