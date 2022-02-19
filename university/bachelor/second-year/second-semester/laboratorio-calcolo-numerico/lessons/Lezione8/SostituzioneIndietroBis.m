% Gazi Adnan Latif Matricola 1224442
function [X] = SostituzioneIndietroBis (U, B)
    n = size(U, 1);
    X = zeros(n);
    X(n, :) = B(n, :) / U(n, n);
    for k = 1:n-1
        X(n - k, :) = (B(n - k, :) - (U(n - k, :) * X)) / (U(n - k, n - k));
    end
end