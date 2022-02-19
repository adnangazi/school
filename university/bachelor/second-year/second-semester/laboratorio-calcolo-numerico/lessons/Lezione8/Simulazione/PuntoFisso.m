% Adnan Latif Gazi Matricola 1224442
function [zero, res, iterates, flag] = PuntoFisso(f, a, b, toll, itmax)
    % test dello scarto unico test d'arresto implementato
    N = 1;
    % divido l'intervallo in punti equispaziati a distanza tale che se
    % esiste un nodo creato che è un punto fisso, esso si trova
    % nell'intorno del vero punto fisso (xvera+/-toll)
    iterates = linspace(a, b, (b-a)/(2*toll));
    
    % se esiste un punto fisso, basta iterare tra i nodi creati e
    % controllare con test dello scarto finchè non si trova tale nodo che
    % rappresenta un punto fisso o finchè non si raggiunge il massimo
    % numero di iterazioni consentite
    while abs(f(iterates(N)) - iterates(N)) > toll && N < itmax
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