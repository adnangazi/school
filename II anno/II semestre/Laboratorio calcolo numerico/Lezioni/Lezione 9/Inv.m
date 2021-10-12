% Gazi Adnan Latif Matricola 1224442
function [A1] = Inv (A)
    I = eye(size(A, 1));
    [L, U, P] = lu(A);
    A1 = SostituzioneIndietro(U, SostituzioneAvanti(L, P * I));
end