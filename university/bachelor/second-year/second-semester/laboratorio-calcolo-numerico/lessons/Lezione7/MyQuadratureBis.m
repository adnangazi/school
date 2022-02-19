% Adnan Latif Gazi Matricola 1224442
function [integrale, I, step, flag] = MyQuadratureBis(a, b, f, formula, toll, itmax)
    
    I = zeros(1, itmax);
    [x, w] = formula(a, b, 1);
    I(1, 1) = w * f(x);
    step = toll + 1;
    N = 2;
    i = 2;

    while step > toll && N < itmax
        [x, w] = formula(a, b, N);
        I(1, i) = w * f(x);
        step = abs(I(1, i) - I(1, i - 1));
        N = N * 2;
        i = i + 1;
    end
    
    I = I(1, 1:i);
    integrale = I(1, end);
    
    if N >= itmax
        flag = 'm';
    else
        flag = 't';
    end
end