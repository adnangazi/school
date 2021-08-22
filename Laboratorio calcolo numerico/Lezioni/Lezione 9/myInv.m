% Gazi Adnan Latif Matricola 1224442
function [A1] = myInv (A)
    A1 = [];
    I = eye(size(A, 1));
    [L, U, P] = lu(A);
    for n = 1:size(A, 1)
        A1 = [A1, SostituzioneIndietro(U, SostituzioneAvanti(L, P * I(:, n)))];
    end
end