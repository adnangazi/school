% Adnan Latif Gazi Matricola 1224442
function [det] = MyDet (A)
    [L, U, P] = lu(A);
    s = rem(sum(sum(P - diag(P))), 2);
    det = prod(diag(U)) * (-1) ^ s;
end