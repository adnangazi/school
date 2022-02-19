% Gazi Adnan Latif Matricola 1224442
function [zero, res_vec, iterates, flag] = Secanti(f, x0, x1, toll, itmax, method)
    iterates = ones(itmax).*x1;
    iterates(1) = x0;
    res_vec = zeros(itmax);
    res_vec(1) = f(x0);
    res_vec(2) = f(x1);
    step = iterates(2)-iterates(1);
    s = toll+1;
    n = 1;
    
    switch method
        case 's'
            while s > toll && n < itmax
                step = -(res_vec(n+1)*step)/(res_vec(n+1)-res_vec(n));
                iterates(n+2) = iterates(n+1)+step;
                zero = iterates(n+2);
                res_vec(n+2) = f(zero);
                s = abs(step);
                n = n+1;
            end
            if res_vec(n) == 0
                flag = 'f';
            elseif n > itmax
                flag = 'e';
            else
                flag = 's';
            end
            iterates = iterates(1:n+1);
            res_vec=res_vec(1:n+1);
        case 'r'
            while abs(res_vec) > toll && n < itmax
                step = -(res_vec(n+1)*step)/(res_vec(n+1)-res_vec(n));
                iterates(n+2) = iterates(n+1)+step;
                zero = iterates(n+2);
                res_vec(n+2) = f(zero);
                n = n+1;
            end
            if res_vec(n) == 0
                flag = 'f';
            elseif n > itmax
                flag = 'e';
            else
                flag = 'r';
            end
            iterates = iterates(1:n+1);
            res_vec=res_vec(1:n+1);
        case 'm'
            while s > toll && abs(res_vec) && n < itmax
                step = -(res_vec(n+1)*step)/(res_vec(n+1)-res_vec(n));
                iterates(n+2) = iterates(n+1)+step;
                zero = iterates(n+2);
                res_vec(n+2) = f(zero);
                s = abs(step);
                n = n+1;
            end
            if res_vec(n) == 0
                flag = 'f';
            elseif n > itmax
                flag = 'e';
            elseif (abs(res_vec) < toll) && (abs(s) < toll)
                flag = 'a';
            elseif abs(res_vec) < toll
                flag = 'r';
            else
                flag = 's';
            end
            iterates = iterates(1:n+1);
            res_vec=res_vec(1:n+1);
    end
end