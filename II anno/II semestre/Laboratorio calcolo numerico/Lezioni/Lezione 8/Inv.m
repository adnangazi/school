% Gazi Adnan Latif Matricola 1224442
function [A1] = Inv (A)
    I = eye(size(A, 1));
    [L, U, P] = lu(A);
    A1 = SostituzioneIndietroBis(U, SostituzioneAvantiBis(L, P * I));
end