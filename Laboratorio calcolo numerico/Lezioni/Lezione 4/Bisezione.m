% Gazi Adnan Latif Matricola 1224442
function [zero, res, wres, iterates, flag] = Bisezione(f, a, b, toll, method)
    if f(a)*f(b) > 0
        error('Dati di input non corretti: f(a)f(b)>=0\n');
    else
        itmax = ceil(log2(b-a)-log2(toll)-1);
        iterates(3, itmax) = 0;
        iterates(1, 1) = (a+b)/2;
        iterates(2, 1) = a;
        iterates(3, 1) = b;
        n = 1;
        
        switch method
            case 's'
                while (iterates(3, n)-iterates(2, n) > toll) && (f(iterates(1, n)) ~= 0)
                    iterates(1, n+1) = (iterates(2, n)+iterates(3, n))/2;
                    if f(iterates(1, n+1))*f(iterates(2, n)) < 0
                        iterates(3, n+1) = iterates(1, n+1);
                        iterates(2, n+1) = iterates(2, n);
                    else
                        iterates(2, n+1) = iterates(1, n+1);
                        iterates(3, n+1) = iterates(3, n);
                    end
                    n = n+1;
                end
                zero = iterates(1, n);
                res = f(zero);
                if n > 1
                    wres = abs(res)*(abs(zero - iterates(1, n-1))/abs(res - f(iterates(1, n-1))));
                else
                    wres = NaN;
                end
                if res == 0
                    flag = 'f';
                else
                    flag = 's';
                end
                iterates=iterates(:,1:n);
            case 'r'
                if f(iterates(1, n)) ~= 0
                    iterates(1, n+1) = (iterates(2, n)+iterates(3, n))/2;
                    if f(iterates(1, n+1))*f(iterates(2, n)) < 0
                        iterates(3, n+1) = iterates(1, n+1);
                        iterates(2, n+1) = iterates(2, n);
                    else
                        iterates(2, n+1) = iterates(1, n+1);
                        iterates(3, n+1) = iterates(3, n);
                    end
                    n = n+1;
                    while (abs(f(iterates(1, n)))*(abs(iterates(1, n) - iterates(1, n-1))/abs(f(iterates(1, n)) - f(iterates(1, n-1)))) > toll) && (f(iterates(1, n)) ~= 0)
                        iterates(1, n+1) = (iterates(2, n)+iterates(3, n))/2;
                        if f(iterates(1, n+1))*f(iterates(2, n)) < 0
                            iterates(3, n+1) = iterates(1, n+1);
                            iterates(2, n+1) = iterates(2, n);
                        else
                            iterates(2, n+1) = iterates(1, n+1);
                            iterates(3, n+1) = iterates(3, n);
                        end
                        n = n+1;
                    end
                end
                zero = iterates(1, n);
                res = f(zero);
                if n > 1
                    wres = abs(res)*(abs(zero - iterates(1, n-1))/abs(res - f(iterates(1, n-1))));
                else
                    wres = NaN;
                end
                if res == 0
                    flag = 'f';
                else
                    flag = 'r';
                end
                iterates=iterates(:,1:n);
            case 'm'
                if f(iterates(1, n)) ~= 0
                    iterates(1, n+1) = (iterates(2, n)+iterates(3, n))/2;
                    if f(iterates(1, n+1))*f(iterates(2, n)) < 0
                        iterates(3, n+1) = iterates(1, n+1);
                        iterates(2, n+1) = iterates(2, n);
                    else
                        iterates(2, n+1) = iterates(1, n+1);
                        iterates(3, n+1) = iterates(3, n);
                    end
                    n = n+1;
                    while (iterates(3, n)-iterates(2, n) > toll) && (abs(f(iterates(1, n)))*abs(iterates(1, n) - iterates(1, n-1))/abs(f(iterates(1, n)) - f(iterates(1, n-1))) > toll) && (f(iterates(1, n)) ~= 0)
                        iterates(1, n+1) = (iterates(2, n)+iterates(3, n))/2;
                        if f(iterates(1, n+1))*f(iterates(2, n)) < 0
                            iterates(3, n+1) = iterates(1, n+1);
                            iterates(2, n+1) = iterates(2, n);
                        else
                            iterates(2, n+1) = iterates(1, n+1);
                            iterates(3, n+1) = iterates(3, n);
                        end
                        n = n+1;
                    end
                end
                zero = iterates(1, n);
                res = f(zero);
                if n > 1
                    wres = abs(res)*(abs(zero - iterates(1, n-1))/abs(res - f(iterates(1, n-1))));
                else
                    wres = NaN;
                end
                if res == 0
                    flag = 'f';
                elseif (iterates(3, n)-iterates(2, n) < toll) && (abs(f(iterates(1, n)))*(abs(iterates(1, n) - iterates(1, n-1))/abs(f(iterates(1, n)) - f(iterates(1, n-1)))) < toll)
                    flag = 'b';
                elseif iterates(3, n)-iterates(2, n) < toll
                    flag = 's';
                else
                    flag = 'r';
                end
                iterates=iterates(:,1:n);
        end
    end
end