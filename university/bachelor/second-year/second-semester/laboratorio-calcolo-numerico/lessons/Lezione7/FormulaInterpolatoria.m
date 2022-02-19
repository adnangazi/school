% Gazi Adnan Latif Matricola 1224442
function [w, W, flag] = FormulaInterpolatoria (xinterp, a, b, toll, maxN) % maxN > 1
    flag = 0;
    N = 1;
    
    [x, wp] = Parabole(a, b, N);
    % [x, wp] = Trepezi(a, b, N);
    L = LagrangePoly(xinterp, x);
    w = wp * L; % vettore riga
    W = w;
    
    step = toll + 1;
    while step > toll && N < maxN / 2
        N = N * 2;
        [x, wp] = Parabole(a, b, N);
        % [x, wp] = Trepezi(a, b, N);
        L = LagrangePoly(xinterp, x);
        w = wp * L; % vettore riga
        W = [W; w];
        step = norm(W(end, :)-W(end-1, :));
    end
    w = W(end, :);
    if N >= maxN / 2
        flag = 1;
    end
end