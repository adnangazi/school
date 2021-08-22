% Gazi Adnan Latif Matricola 1224442
function [integrale, I, step, flag] = MyQuadrature (a, b, f, formula, toll, maxN)
    step = toll + 1;
    I = zeros(1, maxN);
    N = 1;
    i = 1;    
    while step > toll && N < maxN
        [x, w] = formula(a, b, N);
        i = i + 1;
        I(1, i) = w*f(x);
        step = abs(I(1, i) - I(1, i - 1));
        N = N * 2;
    end
    I = I(1, 1:i);
    integrale = I(1, end);
    if N >= maxN
        flag = 0;
    else
        flag = 1;
    end
end