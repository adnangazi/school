% Adnan Latif Gazi Matricola 1224442
function [Kappa] = MyCond(A, p, toll)
    A1 = MyQRInv(A, toll);
    switch p
        case 1
           Kappa = norm(A, 1) * norm(A1, 1);
        case Inf
           Kappa = norm(A, Inf) * norm(A1, Inf);
    end
    % Kappa = norm(A, p) * norm(A1, p); % così non serve switch case
end