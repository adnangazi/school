% Adnan Latif Gazi Matricola 1224442
function [Ainv] = MyQRInv(A, toll)
    [Q0, R0] = qr(A, 0);
    if min(abs(diag(R0))) < toll
        error('Modulo dell elemento diagonale di R0 minore di toll!');
    end
    % scelgo di usare la sostituzione in avanti
    n = length(R0);
    Ainv = zeros(n);
    for i = 1:n
        % R0 * b = q
        Ainv(:, i) = SostituzioneAvanti(R0, Q0(:, i));
    end
end