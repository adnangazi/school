% Gazi Adnan Latif Matricola 1224442
function [X] = SostituzioneAvantiBis (L, B)
    X = zeros(size(L, 1));
    X(1, :) = B(1, :) / L(1, 1);
    for k = 1:size(L, 1)-1
        X(k + 1, :) = (B(k + 1, :) - (L(k + 1, :) * X)) / (L(k + 1, k + 1));
    end
end