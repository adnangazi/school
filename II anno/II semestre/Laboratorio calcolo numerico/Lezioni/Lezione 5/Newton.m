% Gazi Adnan Latif Matricola 1224442
function [zero, res, iterates, flag] = Newton(f, df, x0, toll, itmax, method)
    iterates = ones(itmax).*x0;
    n = 1;
    s = toll+1;
    res = f(x0);
    
    switch method
        case 's'
            while abs(s) > toll && n <= itmax
                if df(iterates(n)) == 0
                    error('Errore: derivata prima in Xn = 0');
                else
                    s = res/df(iterates(n));
                    iterates(n+1) = iterates(n)-s;
                    zero = iterates(n+1);
                    res = f(zero);
                end
                n = n+1;
            end
            if res == 0
                flag = 'f';
            elseif n > itmax
                flag = 'e';
            else
                flag = 's';
            end
            iterates = iterates(1:n);
        case 'r'
            while abs(res) > toll && n <= itmax
                if df(iterates(n)) == 0
                    error('Errore: derivata prima in Xn = 0');
                else
                    s = res/df(iterates(n));
                    iterates(n+1) = iterates(n)-s;
                    zero = iterates(n+1);
                    res = f(zero);
                end
                n = n+1;
            end
            if res == 0
                flag = 'f';
            elseif n > itmax
                flag = 'e';
            else
                flag = 'r';
            end
            iterates = iterates(1:n);
        case 'm'
            while abs(s) > toll && abs(res) > toll && n <= itmax
                if df(iterates(n)) == 0
                    error('Errore: derivata prima in Xn = 0');
                else
                    s = res/df(iterates(n));
                    iterates(n+1) = iterates(n)-s;
                    zero = iterates(n+1);
                    res = f(zero);
                end
                n = n+1;
            end
            if res == 0
                flag = 'f';
            elseif n > itmax
                flag = 'e';
            elseif (abs(res) < toll) && (abs(s) < toll)
                flag = 'a';
            elseif abs(res) < toll
                flag = 'r';
            else
                flag = 's';
            end
            iterates = iterates(1:n);
    end
end