% Adnan Latif Gazi Matricola 1224442
function [integral] = IntegralFit (a, b, x, f, n)
    c = polyfit((x(:))', f((x(:))'), n);
    p = (b .^ (n + 1:-1:1) - a .^ (n + 1:-1:1)) ./ (n + 1:-1:1);
    integral = c * p';
    
    %% metodo alternativo
    % [x1, w] = Trapezi(a,b,n);
    % po = polyval(c, x1);
    % integral = w * po;
end