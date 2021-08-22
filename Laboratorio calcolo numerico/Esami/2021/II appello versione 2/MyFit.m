% Adnan Latif Gazi Matricola 1224442
function [peval, coeff] = MyFit(xsample, ysample, deg, xeval, method)
    % ---HELP--------------------------------------------------------------
    % function MyFit - Adnan Latif Gazi versione 1 - 21/08/2021
    % ---OUTPUT------------------------------------------------------------
    % peval: [length(xeval) + 1 x 1] polinomio di migliore approssimazione
    % di grado al più deg valutato in xeval
    % coeff: [deg + 1 x 1] coefficienti del polinomio
    % ---INPUT-------------------------------------------------------------
    % xsample: [length(xsample) x 1] nodi di interpolazione
    % ysample: [length(ysample) x 1] valutazione dei nodi di interpolazione
    % deg: [1 x 1] grado massimo di approssimazione polinomiale
    % xeval: [length(xeval) x 1] nodi di valutazione
    % method: [1 x 1] metodo della funzione
    %         - 1. Fattorizzazione LU
    %         - 2. Fattorizzazione QR
    %         - 3. Backslah
    %         - 4. Polyfit/Polyval
    % ---------------------------------------------------------------------
    
    A = xsample.^(deg:-1:0);
    Aeval = xeval.^(deg:-1:0);
    
    switch method
        case 1
            [L, U, P] = lu(A' * A);
            coeff = U \ (L \ (P * (A' * ysample)));
            peval = Aeval * coeff;
        case 2
            [Q0, R0] = qr(A, 0);
            coeff = R0 \ (Q0' * (ysample));
            peval = Aeval * coeff;
        case 3
            coeff = (A' * A) \ (A' * ysample);
            peval = Aeval * coeff;
        case 4
            coeff = polyfit(xsample, ysample, deg);
            peval = polyval(coeff, xeval);
    end
end