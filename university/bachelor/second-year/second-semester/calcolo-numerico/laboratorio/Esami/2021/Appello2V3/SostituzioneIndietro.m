% Gazi Adnan Latif Matricola 1224442
function [x] = SostituzioneIndietro (U, b)
    n = size(U, 1);
    x = zeros(n, 1);
    x(n) = b(n) / U(n, n);
    for k = 1:n - 1
        x(n - k) = (b(n - k) - U(n - k, :) * x) / U(n - k, n - k);
    end
end